#include "ArchivoVendedores.h"
#include "Fecha.h"
#include "Vendedor.h"
#include <cstdio> // Para fopen, fwrite, fclose
#include <cstring>
#include <iostream>

using namespace std;

ArchivoVendedores::ArchivoVendedores(){

    strcpy(_nombreArchivo, n);
}
int ArchivoVendedores::crearId(){
    FILE *pArchivoVendedores = fopen(_nombreArchivo, "rb");

    if (pArchivoVendedores == NULL){
        return 1;
    }

    fseek(pArchivoVendedores, 0, SEEK_END);
    long fileSize = ftell(pArchivoVendedores);
    fclose(pArchivoVendedores);

    return (fileSize / sizeof(Vendedor)) + 1;
}
bool ArchivoVendedores::registrarVendedor(Vendedor reg){
    FILE *pArchivoVendedores = fopen(_nombreArchivo, "ab"); // Modo de apertura "append binary"
    if (pArchivoVendedores == NULL){
        return false;
    }

    bool escribio = fwrite(&reg, sizeof(Vendedor), 1, pArchivoVendedores); // Escribir el registro
    fclose(pArchivoVendedores);
    return escribio; // Retorna true si escribió correctamente
}
bool ArchivoVendedores::listarVendedores(){
        FILE *pArchivoVendedores;
        Vendedor reg;
        pArchivoVendedores = fopen(_nombreArchivo, "rb");

        if(pArchivoVendedores==NULL){
            cout<<"No se pudo abrir el archivo. "<<endl;
            return false;
        }

        while(fread(&reg, sizeof(Vendedor), 1, pArchivoVendedores) == 1){
            if(reg.getEstado()){
                reg.mostrar();
            }
        }

        fclose(pArchivoVendedores);
        return true;
}
bool ArchivoVendedores::eliminarVendedorPorDNI(char *dni){
    FILE *pArchivoVendedores;
    Vendedor reg;
    pArchivoVendedores= fopen("archivoVendedores.dat", "rb+"); // Abrimos en modo de lectura y escritura


    if(pArchivoVendedores==NULL){
        cout << "No se pudo abrir el archivo." << endl;
        return false;
    }


    while (fread(&reg, sizeof(Vendedor), 1, pArchivoVendedores) == 1) {
        // Si encontramos el cliente con el DNI buscado
        if (strcmp(reg.getDni(), dni) == 0) {
            reg.setEstado(false); // Cambiamos el estado a false

            // Movemos el puntero de archivo hacia atrás una posición para sobrescribir
            fseek(pArchivoVendedores, -sizeof(Vendedor), SEEK_CUR);
            fwrite(&reg, sizeof(Vendedor), 1, pArchivoVendedores); // Sobrescribimos el registro
            fclose(pArchivoVendedores);
            cout << endl;
            cout << "Vendedor con DNI " << dni << " eliminado exitosamente." << endl;
            return true;
        }
    }

    fclose(pArchivoVendedores);
    cout << "Vendedor con DNI " << dni << " no encontrado." << endl;
    return false; // No se encontró el cliente con el DNI dado
}
bool ArchivoVendedores::buscarVendedorPorDNI(char *dni) {
    FILE *pArchivoVendedores = fopen(_nombreArchivo, "rb");
    if (pArchivoVendedores == NULL){
        //cout << "No se pudo abrir el archivo." << endl;
        return false;
    }

    Vendedor reg;
    bool encontrado = false;

    while (fread(&reg, sizeof(Vendedor), 1, pArchivoVendedores)) {
        if (strcmp(reg.getDni(), dni) == 0) { // Comparar DNI

            if(reg.getEstado()){
                encontrado = true;
                reg.mostrar();
                break;
            }
        }
    }

    fclose(pArchivoVendedores);

    if (!encontrado) {
        cout << "El DNI ingresado no se encontro en los registros." << endl;
    }

    return encontrado;
}
bool ArchivoVendedores::buscarVendedorPorDNI(char* dni, Vendedor& vendedorEncontrado) {
    FILE *pArchivoVendedores = fopen(_nombreArchivo, "rb");
    if (pArchivoVendedores == NULL) {
        //cout << "No se pudo abrir el archivo." << endl;
        return false;
    }

    Vendedor reg;
    bool encontrado = false;

    while (fread(&reg, sizeof(Vendedor), 1, pArchivoVendedores)) {
        if (strcmp(reg.getDni(), dni) == 0 && reg.getEstado()) {
            encontrado = true;
            vendedorEncontrado = reg; // Copia el cliente encontrado al parámetro por referencia
            break;
        }
    }

    fclose(pArchivoVendedores);

    if (!encontrado) {
        cout << "El DNI ingresado no se encontro en los registros." << endl;
    }

    return encontrado;
}
bool ArchivoVendedores::modificarVendedorPorDNI(char *dni, Vendedor &nuevosDatos) {
    FILE *pArchivoVendedores = fopen(_nombreArchivo, "rb+");
    if (pArchivoVendedores == NULL) {
        cout << "No se pudo abrir el archivo de clientes." << endl;
        return false;
    }

    Vendedor vendedorActual;
    bool encontrado = false;
    long posicion = 0;

    while (fread(&vendedorActual, sizeof(Vendedor), 1, pArchivoVendedores)) {
        if (strcmp(vendedorActual.getDni(), dni) == 0) {
            cout << "Cliente encontrado, procediendo a modificar." << endl;

            // posicionar el puntero
            fseek(pArchivoVendedores, posicion * sizeof(Vendedor), SEEK_SET);

            // Sobrescribir el vendedor en el archivo
            if (fwrite(&nuevosDatos, sizeof(Vendedor), 1, pArchivoVendedores) != 1) {
                cout << "Error al sobrescribir el archivo." << endl;
                fclose(pArchivoVendedores);
                return false;
            }

            //cout << "Cliente modificado exitosamente." << endl;
            encontrado = true;
            break;
        }
        posicion++;
    }

    fclose(pArchivoVendedores);

    if (encontrado) {
        return true;
    } else {
        cout << "Cliente no encontrado en el archivo." << endl;
        return false;
    }
}
bool ArchivoVendedores::exportarVendedoresACSV(){
    FILE *pArchivoVendedores = fopen("archivoVendedores.dat", "rb");
    if (pArchivoVendedores == NULL) {
        cout << "No se pudo abrir el archivo de Vendedores." << endl;
        return false;
    }

    FILE *pArchivoCSV = fopen("Vendedores.csv", "w");
    if (pArchivoCSV == NULL) {
        cout << "No se pudo crear el archivo CSV." << endl;
        fclose(pArchivoVendedores);
        return false;
    }

    // Escribir encabezados en el archivo CSV
    fprintf(pArchivoCSV, "ID,DNI,Nombre/s,Apellido/s,Fecha de Nacimiento,Domicilio,Mail,Telefono,Fecha de Ingreso,Sueldo\n");

    Vendedor csv;
    while (fread(&csv, sizeof(Vendedor), 1, pArchivoVendedores)) {
        // Usar el método toCSV para obtener la línea CSV
        if(csv.getEstado()){//que solo escriba los clientes no eliminados
        string lineaCSV = csv.toCSV();
        fprintf(pArchivoCSV, "%s\n", lineaCSV.c_str());
        }
    }

    fclose(pArchivoVendedores);
    fclose(pArchivoCSV);

    cout << "Los registros fueron exportados exitosamente a Vendedores.csv" << endl;
    return true;
}
Vendedor ArchivoVendedores::buscarVendedorID(int id){
    FILE *pVendedor;
    pVendedor=fopen(_nombreArchivo,"rb+");
    Vendedor vendedor;
    vendedor.setID(-1);
    if(pVendedor==NULL)
    {
        cout<<"No se pudo abrir el archivo "<<endl;
        return vendedor;
    }
    long tamanioArchivo = ftell(pVendedor);
    long filesize = ((id - 1) * sizeof(Vendedor));
    if(filesize > tamanioArchivo){
        fclose(pVendedor);
        return vendedor;
    }
    fseek(pVendedor, filesize, SEEK_SET);
    fread(&vendedor, sizeof(Vendedor), 1, pVendedor);
    fclose(pVendedor);
    return vendedor;
}

////int ArchivoServicioMesa::CantidadRegistros(){
////    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
////    if(pArchivo == NULL){
////        return 0;
////    }
////    fseek(pArchivo, 0, SEEK_END);
////    int cantidadRegistros = ftell(pArchivo) / sizeof(ServicioMesa);
////    fclose(pArchivo);
////    return cantidadRegistros;
////}
