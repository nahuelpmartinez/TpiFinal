#ifndef ARCHIVOARTICULOS_H_INCLUDED
#define ARCHIVOARTICULOS_H_INCLUDED


#include "Articulo.h"
#include <string>

class ArchivoArticulos {
private:

    char _nombreArchivo[50];
    const char *n= "archivoArticulos.dat";
    int id;

public:
    // Constructor
    ArchivoArticulos();

    // Métodos
    bool registrarArticulo(Articulo reg);
    bool listarArticulos();
    int crearId();
    bool eliminarArticuloPorCod(char *codArticulo);
    bool buscarArticuloPorCod(char *codArticulo);
    bool buscarArticuloPorCod(char* codArticulo, Articulo& articuloEncontrado);
    bool exportarArticulosACSV();
    bool modificarArticuloPorCod(char *codArticulo, Articulo& nuevosDatos);
    //bool buscarArticuloID(int id);

};





#endif // ARCHIVOARTICULOS_H_INCLUDED
