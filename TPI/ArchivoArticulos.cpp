#include "ArchivoArticulos.h"
#include "Fecha.h"
#include "Articulo.h"
#include <cstdio> // Para fopen, fwrite, fclose
#include <cstring>
#include <iostream>

using namespace std;

ArchivoArticulos::ArchivoArticulos(){

    strcpy(_nombreArchivo, n);
}
int ArchivoArticulos::crearId(){
    FILE *pArchivoArticulos = fopen(_nombreArchivo, "rb");

    if (pArchivoArticulos == NULL){
        return 1;
    }

    fseek(pArchivoArticulos, 0, SEEK_END);
    long fileSize = ftell(pArchivoArticulos);
    fclose(pArchivoArticulos);

    return (fileSize / sizeof(Articulo)) + 1;
}
bool ArchivoArticulos::registrarArticulo(Articulo reg){
    FILE *pArchivoArticulos = fopen(_nombreArchivo, "ab"); // Modo de apertura "append binary"
    if (pArchivoArticulos == NULL){
        return false;
    }

    bool escribio = fwrite(&reg, sizeof(Articulo), 1, pArchivoArticulos); // Escribir el registro
    fclose(pArchivoArticulos);
    return escribio; // Retorna true si escribió correctamente
}
bool ArchivoArticulos::listarArticulos(){
        FILE *pArchivoArticulos;
        Articulo reg;
        pArchivoArticulos = fopen(_nombreArchivo, "rb");

        if(pArchivoArticulos==NULL){
            cout<<"No se pudo abrir el archivo. "<<endl;
            return false;
        }

        while(fread(&reg, sizeof(Articulo), 1, pArchivoArticulos) == 1){
            if(reg.getEstado()){
                reg.mostrar();
            }
        }

        fclose(pArchivoArticulos);
        return true;
}
bool ArchivoArticulos::eliminarArticuloPorCod(char *codArticulo){
    FILE *pArchivoArticulos;
    Articulo reg;
    pArchivoArticulos= fopen("archivoArticulos.dat", "rb+"); // Abrimos en modo de lectura y escritura


    if(pArchivoArticulos==NULL){
        cout << "No se pudo abrir el archivo." << endl;
        return false;
    }


    while (fread(&reg, sizeof(Articulo), 1, pArchivoArticulos) == 1) {
        // Si encontramos el cliente con el DNI buscado
        if (strcmp(reg.getCodArticulo(), codArticulo) == 0) {
            reg.setEstado(false); // Cambiamos el estado a false

            // Movemos el puntero de archivo hacia atrás una posición para sobrescribir
            fseek(pArchivoArticulos, -sizeof(Articulo), SEEK_CUR);
            fwrite(&reg, sizeof(Articulo), 1, pArchivoArticulos); // Sobrescribimos el registro
            fclose(pArchivoArticulos);
            cout << endl;
            cout << "Articulo con Código " << codArticulo << " eliminado exitosamente." << endl;
            return true;
        }
    }

    fclose(pArchivoArticulos);
    cout << "Articulo con Código " << codArticulo << " no encontrado." << endl;
    return false; // No se encontró el cliente con el DNI dado
}
bool ArchivoArticulos::buscarArticuloPorCod(char *codArticulo) {
    FILE *pArchivoArticulos = fopen(_nombreArchivo, "rb");
    if (pArchivoArticulos == NULL){
        cout << "No se pudo abrir el archivo." << endl;
        return false;
    }

    Articulo reg;
    bool encontrado = false;

    while (fread(&reg, sizeof(Articulo), 1, pArchivoArticulos)) {
        if (strcmp(reg.getCodArticulo(), codArticulo) == 0) { // Comparar DNI

            if(reg.getEstado()){
                encontrado = true;
                reg.mostrar();
                break;
            }
        }
    }

    fclose(pArchivoArticulos);

    if (!encontrado) {
        cout << "El Articulo ingresado no se encontró en los registros." << endl;
    }

    return encontrado;
}
bool ArchivoArticulos::buscarArticuloPorCod(char* codArticulo, Articulo& articuloEncontrado) {
    FILE *pArchivoArticulos = fopen(_nombreArchivo, "rb");
    if (pArchivoArticulos == NULL) {
        cout << "No se pudo abrir el archivo." << endl;
        return false;
    }

    Articulo reg;
    bool encontrado = false;

    while (fread(&reg, sizeof(Articulo), 1, pArchivoArticulos)) {
        if (strcmp(reg.getCodArticulo(),codArticulo) == 0 && reg.getEstado()) {
            encontrado = true;
            articuloEncontrado = reg; // Copia el cliente encontrado al parámetro por referencia
            break;
        }
    }

    fclose(pArchivoArticulos);

    if (!encontrado) {
        cout << "El Codigo ingresado no se encontro en los registros." << endl;
    }

    return encontrado;
}
bool ArchivoArticulos::modificarArticuloPorCod(char *codArticulo, Articulo &nuevosDatos) {
    FILE *pArchivoArticulos = fopen(_nombreArchivo, "rb+");
    if (pArchivoArticulos == NULL) {
        cout << "No se pudo abrir el archivo de Articulos." << endl;
        return false;
    }

    Articulo articuloActual;
    bool encontrado = false;
    long posicion = 0;

    while (fread(&articuloActual, sizeof(Articulo), 1, pArchivoArticulos)) {
        if (strcmp(articuloActual.getCodArticulo(), codArticulo) == 0) {
            //cout << "Articulo encontrado, procediendo a modificar." << endl;

            // posicionar el puntero
            fseek(pArchivoArticulos, posicion * sizeof(Articulo), SEEK_SET);

            // Sobrescribir el vendedor en el archivo
            if (fwrite(&nuevosDatos, sizeof(Articulo), 1, pArchivoArticulos) != 1) {
                cout << "Error al sobrescribir el archivo." << endl;
                fclose(pArchivoArticulos);
                return false;
            }

            //cout << "Cliente modificado exitosamente." << endl;
            encontrado = true;
            break;
        }
        posicion++;
    }

    fclose(pArchivoArticulos);

    if (encontrado) {
        return true;
    } else {
        cout << "Articulo no encontrado en el archivo." << endl;
        return false;
    }
}
bool ArchivoArticulos::exportarArticulosACSV(){
    FILE *pArchivoArticulos = fopen("archivoArticulos.dat", "rb");
    if (pArchivoArticulos == NULL) {
        cout << "No se pudo abrir el archivo de Articulos." << endl;
        return false;
    }

    FILE *pArchivoCSV = fopen("Articulos.csv", "w");
    if (pArchivoCSV == NULL) {
        cout << "No se pudo crear el archivo CSV." << endl;
        fclose(pArchivoArticulos);
        return false;
    }

    // Escribir encabezados en el archivo CSV
    fprintf(pArchivoCSV, "ID,Cod. Articulo,Nombre,Precio Unitario,Stock\n");

    Articulo csv;
    while (fread(&csv, sizeof(Articulo), 1, pArchivoArticulos)) {
        // Usar el método toCSV para obtener la línea CSV
        if(csv.getEstado()){//que solo escriba los clientes no eliminados
        string lineaCSV = csv.toCSV();
        fprintf(pArchivoCSV, "%s\n", lineaCSV.c_str());
        }
    }

    fclose(pArchivoArticulos);
    fclose(pArchivoCSV);

    cout << "Los registros fueron exportados exitosamente a Articulos.csv" << endl;
    return true;
}
//bool ArchivoArticulos::buscarArticuloID(int id){
//        FILE *pArchivoArticulos;
//        Articulo reg;
//        reg.setID(-1);
//        pArchivoArticulos=fopen(_nombreArchivo, "rb");
//        if(pArchivoArticulos==NULL){
//            cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
//            return false;
//        }
//
//        long fileSize = ((id-1) * sizeof(Articulo));
//        fseek(pArchivoArticulos, fileSize, SEEK_SET);
//        fread(&reg,sizeof(articulo,1,pArchivoArticulos);
//        fclose(pArchivoArticulos);
//        return true;
//    }
//int ArchivoServicioMesa::CantidadRegistros(){
//    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
//    if(pArchivo == NULL){
//        return 0;
//    }
//    fseek(pArchivo, 0, SEEK_END);
//    int cantidadRegistros = ftell(pArchivo) / sizeof(ServicioMesa);
//    fclose(pArchivo);
//    return cantidadRegistros;
//}
