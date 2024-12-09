#ifndef ARCHIVOCLIENTES_H
#define ARCHIVOCLIENTES_H

#include "Cliente.h"  // Incluir Cliente para usarlo en los métodos
#include <string>

class ArchivoClientes {
private:

    char _nombreArchivo[50];
    const char *n= "archivoClientes.dat";
    int id;

public:
    // Constructor que recibe el nombre del archivo
    ArchivoClientes();

    // Método para registrar un cliente en el archivo
    bool registrarCliente(Cliente reg);
    bool listarClientes();
    int crearId();
    bool eliminarClientePorDNI(char *dni);
    bool buscarClientePorDNI(char *dni);
    bool buscarClientePorDNI(char* dni, Cliente& clienteEncontrado);
    bool exportarClientesACSV();
    bool modificarClientePorDNI(char *dni, Cliente& nuevosDatos);
    Cliente buscarClienteID(int id);

//    bool eliminarClientePorID(int id);
//    void mostrarClientes();
//    bool buscarClienteID(int id);
//    bool modificarCliente(Cliente cli);

};

#endif // ARCHIVOCLIENTES_H

