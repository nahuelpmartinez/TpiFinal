#ifndef ARCHIVODETALLEVENTA_H_INCLUDED
#define ARCHIVODETALLEVENTA_H_INCLUDED

#include "DetalleVenta.h"
#include <vector>

using namespace std;

class ArchivoDetalleVentas{

private:
    char _nombreArchivo[50];
    const char *n= "DetalleVentas.dat";
    int _tamanioRegistro;

public:
    ArchivoDetalleVentas();
    int registrarDetalleVenta(DetalleVenta* detalles, int cantidad);
    bool listarDetalleVenta();
    vector<DetalleVenta>  buscarDetalle(int idVenta);
};

#endif // ARCHIVODETALLEVENTA_H_INCLUDED
