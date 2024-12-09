#include "ArchivoVentas.h"
#include "Venta.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

ArchivoVentas::ArchivoVentas(){
    strcpy(_nombreArchivo, n);
    _tamanioRegistro=sizeof(Venta);
}

bool ArchivoVentas::registrarVenta(Venta reg){
        FILE *pVenta;
        pVenta=fopen(_nombreArchivo,"ab" );//si no puede hacer la apertura fopen devuelve NULL
        if(pVenta==NULL) return false;
        int escribio=fwrite(&reg,_tamanioRegistro,1,pVenta);
        fclose(pVenta);
        return escribio;
}
bool ArchivoVentas::listarVenta(bool verLineas){
        FILE *pVenta;
        Venta reg;
        pVenta=fopen(_nombreArchivo, "rb");
        if(pVenta==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
            return false;
        }

        fseek(pVenta, 0, SEEK_END);
        long tamanioArchivo = ftell(pVenta);

        long tamanioRegistro = sizeof(Venta);
        long totalDeRegistros = tamanioArchivo / tamanioRegistro;

        // Leer los registros en orden inverso para ver las ventas de la mas reciente a la mas vieja
        for (long i = totalDeRegistros - 1; i >= 0; --i) {
            fseek(pVenta, i * tamanioRegistro, SEEK_SET);
            fread(&reg, tamanioRegistro, 1, pVenta);
            reg.Mostrar(verLineas);
        }


        fclose(pVenta);
        return true;
    }

Venta ArchivoVentas::buscarVentaID(int id) {
    FILE *pVenta = fopen(_nombreArchivo, "rb");
    Venta reg;
    if (pVenta == NULL) {
        cout << "NO SE PUDO ABRIR EL ARCHIVO" << endl;
        return reg;
    }

    long fileSize = ((id - 1) * sizeof(Venta));
    fseek(pVenta, fileSize, SEEK_SET);

    // Leer el registro
    if (fread(&reg, _tamanioRegistro, 1, pVenta) != 1) {
        cout << "Venta con ID " << id << " no encontrada." << endl;
        reg.setIdCliente(-1);
        reg.setIdVendedor(-1);
    }

    fclose(pVenta);

    return reg;
}

bool ArchivoVentas::exportarCSV() {
    FILE *pArchivoVentas = fopen(_nombreArchivo, "rb");
    if (pArchivoVentas == NULL) {
        cout << "No se pudo abrir el archivo de ventas." << endl;
        return false;
    }

    FILE *pArchivoCSV = fopen("Ventas.csv", "w");
    if (pArchivoCSV == NULL) {
        cout << "No se pudo crear el archivo CSV." << endl;
        fclose(pArchivoVentas);
        return false;
    }

    // Escribir encabezados en el archivo CSV
    fprintf(pArchivoCSV, "Id,Fecha,Forma de Pago,IdCliente,Nombre y Apellido Cliente,IdVendedor,Nombre y Apellido Vendedor,Importe\n");

    Venta venta;
    while (fread(&venta, sizeof(Venta), 1, pArchivoVentas)) {
        string lineaCSV = venta.toCSV();
        fprintf(pArchivoCSV, "%s\n", lineaCSV.c_str());
    }

    fclose(pArchivoVentas);
    fclose(pArchivoCSV);

    cout << "Los registros fueron exportados exitosamente a Ventas.csv" << endl;
    return true;
}
