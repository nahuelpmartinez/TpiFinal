#include "ArchivoClientes.h"
#include "Fecha.h"
#include "Cliente.h"
#include <cstdio> // Para fopen, fwrite, fclose
#include <cstring>
#include <iostream>

using namespace std;

ArchivoClientes::ArchivoClientes(){

    strcpy(_nombreArchivo, n);
}

int ArchivoClientes::crearId(){
    FILE *pArchivoClientes = fopen(_nombreArchivo, "rb");

    if (pArchivoClientes == NULL){
        return 1;
    }

    fseek(pArchivoClientes, 0, SEEK_END);
    long fileSize = ftell(pArchivoClientes);
    fclose(pArchivoClientes);

    return (fileSize / sizeof(Cliente)) + 1;
}
bool ArchivoClientes::registrarCliente(Cliente reg){
    FILE *pArchivoClientes = fopen(_nombreArchivo, "ab");
    if (pArchivoClientes == NULL){
        return false;
    }

    bool escribio = fwrite(&reg, sizeof(Cliente), 1, pArchivoClientes); // Escribir el registro
    fclose(pArchivoClientes);
    return escribio; // Retorna true si escribió correctamente
}
bool ArchivoClientes::listarClientes(){
        FILE *pArchivoClientes;
        Cliente reg;
        pArchivoClientes = fopen(_nombreArchivo, "rb");

        if(pArchivoClientes==NULL){
            cout<<"No se pudo abrir el archivo. "<<endl;
            return false;
        }

        while(fread(&reg, sizeof(Cliente), 1, pArchivoClientes) == 1){
            if(reg.getEstado()){
                reg.mostrar();
            }
        }

        fclose(pArchivoClientes);
        return true;
}
bool ArchivoClientes::eliminarClientePorDNI(char *dni){
    FILE *pArchivoClientes;
    Cliente reg;
    pArchivoClientes= fopen("archivoClientes.dat", "rb+"); // Abrimos en modo de lectura y escritura


    if(pArchivoClientes==NULL){
        cout << "No se pudo abrir el archivo." << endl;
        return false;
    }


    while (fread(&reg, sizeof(Cliente), 1, pArchivoClientes) == 1) {
        // Si encontramos el cliente con el DNI buscado
        if (strcmp(reg.getDni(), dni) == 0) {
            reg.setEstado(false); // Cambiamos el estado a false

            // Movemos el puntero de archivo hacia atrás una posición para sobrescribir
            fseek(pArchivoClientes, -sizeof(Cliente), SEEK_CUR);
            fwrite(&reg, sizeof(Cliente), 1, pArchivoClientes); // Sobrescribimos el registro
            fclose(pArchivoClientes);
            cout << endl;
            cout << "Cliente con DNI " << dni << " eliminado exitosamente." << endl;
            return true;
        }
    }

    fclose(pArchivoClientes);
    cout << "Cliente con DNI " << dni << " no encontrado." << endl;
    return false; // No se encontró el cliente con el DNI dado
}
bool ArchivoClientes::buscarClientePorDNI(char *dni) {
    FILE *pArchivoClientes = fopen(_nombreArchivo, "rb");
    if (pArchivoClientes == NULL){
        cout << "No se pudo abrir el archivo." << endl;
        return false;
    }

    Cliente reg;
    bool encontrado = false;

    while (fread(&reg, sizeof(Cliente), 1, pArchivoClientes)) {
        if (strcmp(reg.getDni(), dni) == 0) { // Comparar DNI

            if(reg.getEstado()){
                encontrado = true;
                reg.mostrar();
                break;
            }
        }
    }

    fclose(pArchivoClientes);

    if (!encontrado) {
        cout << "El DNI ingresado no se encontró en los registros." << endl;
    }

    return encontrado;
}
bool ArchivoClientes::buscarClientePorDNI(char* dni, Cliente& clienteEncontrado) {
    FILE *pArchivoClientes = fopen(_nombreArchivo, "rb");
    if (pArchivoClientes == NULL) {
        cout << "No se pudo abrir el archivo." << endl;
        return false;
    }

    Cliente reg;
    bool encontrado = false;

    while (fread(&reg, sizeof(Cliente), 1, pArchivoClientes)) {
        if (strcmp(reg.getDni(), dni) == 0 && reg.getEstado()) {
            encontrado = true;
            clienteEncontrado = reg; // Copia el cliente encontrado al parámetro por referencia
            break;
        }
    }

    fclose(pArchivoClientes);

    if (!encontrado) {
        cout << "El DNI ingresado no se encontró en los registros." << endl;
    }

    return encontrado;
}
bool ArchivoClientes::modificarClientePorDNI(char *dni, Cliente &nuevosDatos) {
    FILE *pArchivoClientes = fopen(_nombreArchivo, "rb+");
    if (pArchivoClientes == NULL) {
        cout << "No se pudo abrir el archivo de clientes." << endl;
        return false;
    }

    Cliente clienteActual;
    bool encontrado = false;
    long posicion = 0;

    while (fread(&clienteActual, sizeof(Cliente), 1, pArchivoClientes)) {
        if (strcmp(clienteActual.getDni(), dni) == 0) {
            cout << "Cliente encontrado, procediendo a modificar." << endl;

            // Verificar datos antes de sobrescribir
            cout << "Nombres: " << nuevosDatos.getNombres() << endl;
            cout << "Apellidos: " << nuevosDatos.getApellidos() << endl;
            cout << "Domicilio: " << nuevosDatos.getDomicilio() << endl;

            // Posicionar el puntero correctamente para sobrescribir
            fseek(pArchivoClientes, posicion * sizeof(Cliente), SEEK_SET);

            // Sobrescribir el cliente en el archivo
            if (fwrite(&nuevosDatos, sizeof(Cliente), 1, pArchivoClientes) != 1) {
                cout << "Error al sobrescribir el archivo." << endl;
                fclose(pArchivoClientes);
                return false;
            }

            cout << "Cliente modificado exitosamente." << endl;
            encontrado = true;
            break;
        }
        posicion++;
    }

    fclose(pArchivoClientes);

    if (encontrado) {
        return true;
    } else {
        cout << "Cliente no encontrado en el archivo." << endl;
        return false;
    }
}
bool ArchivoClientes::exportarClientesACSV() {
    FILE *pArchivoClientes = fopen("archivoClientes.dat", "rb");
    if (pArchivoClientes == NULL) {
        cout << "No se pudo abrir el archivo de clientes." << endl;
        return false;
    }

    FILE *pArchivoCSV = fopen("Clientes.csv", "w");
    if (pArchivoCSV == NULL) {
        cout << "No se pudo crear el archivo CSV." << endl;
        fclose(pArchivoClientes);
        return false;
    }

    // Escribir encabezados en el archivo CSV
    fprintf(pArchivoCSV, "Cod,DNI,Nombre/s,Apellido/s,Fecha de Nacimiento,Domicilio,Mail,Telefono\n");

    Cliente cliente;
    while (fread(&cliente, sizeof(Cliente), 1, pArchivoClientes)) {
        // Usar el método toCSV para obtener la línea CSV
        if(cliente.getEstado()){//que solo escriba los clientes no eliminados
        string lineaCSV = cliente.toCSV();
        fprintf(pArchivoCSV, "%s\n", lineaCSV.c_str());
        }
    }

    fclose(pArchivoClientes);
    fclose(pArchivoCSV);

    cout << "Los registros fueron exportados exitosamente a Clientes.csv" << endl;
    return true;
}
Cliente ArchivoClientes::buscarClienteID(int id){
    FILE *pcliente;
    pcliente=fopen(_nombreArchivo,"rb+");
    Cliente cliente;
    if(pcliente==NULL)
    {
        cout<<"No se pudo abrir el archivo "<<endl;
        return cliente;
    }
    long filesize = ((id -1) * sizeof(Cliente));
    fseek(pcliente, filesize, SEEK_SET);
    fread(&cliente, sizeof(Cliente), 1, pcliente);
    fclose(pcliente);
    return cliente;
}

