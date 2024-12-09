#ifndef ARCHIVOVENDEDORES_H_INCLUDED
#define ARCHIVOVENDEDORES_H_INCLUDED
#include "Vendedor.h" // Incluir Cliente para usarlo en los métodos
#include <string>

class ArchivoVendedores {
private:

    char _nombreArchivo[50];
    const char *n= "archivoVendedores.dat";
    int id;

public:
    // Constructor
    ArchivoVendedores();

    // Métodos
    bool registrarVendedor(Vendedor reg);
    bool listarVendedores();
    int crearId();
    bool eliminarVendedorPorDNI(char *dni);
    bool buscarVendedorPorDNI(char *dni);
    bool buscarVendedorPorDNI(char* dni, Vendedor& vendedorEncontrado);
    bool exportarVendedoresACSV();
    bool modificarVendedorPorDNI(char *dni, Vendedor& nuevosDatos);
    Vendedor buscarVendedorID(int id);
};


#endif // ARCHIVOVENDEDORES_H_INCLUDED
