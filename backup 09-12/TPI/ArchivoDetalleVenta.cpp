#include "ArchivoDetalleVenta.h"
#include <cstdio> // Para fopen, fwrite, fclose
#include <cstring>
#include <iostream>

using namespace std;


ArchivoDetalleVentas::ArchivoDetalleVentas(){
    strcpy(_nombreArchivo, n);
    _tamanioRegistro=sizeof(DetalleVenta);
}

int ArchivoDetalleVentas::registrarDetalleVenta(DetalleVenta* detalles, int cantidad){
        FILE *pDetalle;
        int escribio = 0;
        pDetalle=fopen(_nombreArchivo,"ab" );//si no puede hacer la apertura fopen devuelve NULL
        if(pDetalle==NULL) return false;
        for(int i = 0; i < cantidad; i++ ){
            escribio+=fwrite(&detalles[i],_tamanioRegistro,1,pDetalle);
        }
        fclose(pDetalle);
        return escribio;
}

bool ArchivoDetalleVentas::listarDetalleVenta(){
        FILE *pDetalle;
        DetalleVenta reg;
        pDetalle=fopen(_nombreArchivo, "rb");
        if(pDetalle==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
            return false;
        }

        while(fread(&reg,_tamanioRegistro,1,pDetalle)==1){
//            reg.Mostrar();

        }

        fclose(pDetalle);
        return true;
    }
vector<DetalleVenta> ArchivoDetalleVentas::buscarDetalle(int idVenta) {
    FILE* pDetalle;
    DetalleVenta reg;
    vector<DetalleVenta> detalles;

    pDetalle = fopen(_nombreArchivo, "rb");
    if (pDetalle == NULL) {
        cout << "NO SE PUDO ABRIR EL ARCHIVO " << endl;
        return detalles;
    }

    while (fread(&reg, sizeof(DetalleVenta), 1, pDetalle) == 1) {
        if (idVenta == reg.getIdVenta()) {
            detalles.push_back(reg);
        }
    }

    fclose(pDetalle);
    return detalles;
}
