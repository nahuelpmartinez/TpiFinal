#ifndef ARCHIVOVENTAS_H_INCLUDED
#define ARCHIVOVENTAS_H_INCLUDED

#include "Venta.h"

using namespace std;

class ArchivoVentas{

private:
    char _nombreArchivo[50];
    const char *n= "Ventas.dat";
    int _tamanioRegistro;

public:
    ArchivoVentas();
    bool registrarVenta(Venta reg);
    bool listarVenta(bool verLineas = false);
    Venta buscarVentaID(int id);
    bool exportarCSV();
};

#endif // ARCHIVOVENTAS_H_INCLUDED

