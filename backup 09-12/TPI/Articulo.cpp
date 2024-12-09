#include "Articulo.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

Articulo::Articulo(){

}

Articulo::Articulo(int id, char* codArticulo, char* nombreArticulo, int stock, float precioUnitario, bool estado){
    strcpy(_nombreArticulo, nombreArticulo);
    strcpy( _codArticulo, codArticulo);
    _stock = stock;
    _precioUnitario = precioUnitario;
    _estado = estado;
    _id = id;
}

int Articulo::getID(){
    return _id;
}
char* Articulo::getCodArticulo(){
    return _codArticulo;
}
char* Articulo::getNombreArticulo(){
    return _nombreArticulo;
}
float Articulo::getPrecioUnitario(){
    return _precioUnitario;
}
int Articulo ::getStock(){
    return _stock;
}
bool Articulo::getEstado(){
    return _estado;
}
void Articulo::setCodArticulo(char *codArticulo){
    strcpy(_codArticulo, codArticulo);
}
void Articulo::setNombreArticulo (char *nombreArticulo){
    strcpy(_nombreArticulo, nombreArticulo);
}
void Articulo::setStock (int stock){
    _stock = stock;
}
void Articulo::setPrecioUnitario(float precioUnitario){
    _precioUnitario = precioUnitario;
}
void Articulo::setEstado(bool estado){
    _estado = estado;
}
void Articulo::setID(int id){
    _id = id;
}
void Articulo::mostrar(){

    cout<< "--------------------------------------------------------"<< endl;
     cout<<"ID: "<< getID() << endl;
    cout<< "Cod: "<< getCodArticulo() << endl;
    cout<< "Nombre del articulo: " << getNombreArticulo()<< endl;
    cout<< "Precio Unitario: $" << getPrecioUnitario()<< endl;
    cout<< "Stock Disponible: " << getStock()<< endl;
    cout<< "--------------------------------------------------------" <<endl <<endl;
}
//Articulo Articulo::buscarArticuloPorCod(int id){
//        FILE *pArticulo;
//        Articulo reg;
//        pArticulo=fopen(_nombreArchivo, "rb");
//        if(pArticulo==NULL){
//            cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
//            return reg;
//        }
//
//        long fileSize = ((id-1) * sizeof(Articulo));
//        fseek(pArticulo, fileSize, SEEK_SET);
//        fread(&reg,_tamanioRegistro,1,pArticulo);
//        fclose(pArticulo);
//        return reg;
//    }
//
//bool Articulo:: modificarArticulo(Articulo art)
//{
//     FILE *pArticulo;
//        pArticulo=fopen(_nombreArchivo,"rb+");
//        if(pArticulo==NULL){
//            cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
//            return false;
//        }
//     long fileSize = ((art.getId() -1) * sizeof(Articulo));
//        fseek(pArticulo, fileSize, SEEK_SET);
//        int escribio=fwrite(&art,_tamanioRegistro,1,pArticulo);
//        fclose(pArticulo);
//        return escribio;
//
//}
//bool Articulo::EliminarArticuloPorID(int id){
//    FILE *pArticulo = fopen(_nombreArchivo, "rb+"); // Abrimos en modo de lectura y escritura
//    if (pArticulo == NULL) {
//        cout << "No se pudo abrir el archivo." << endl;
//        return false;
//    }
//
//    Articulo reg;
//    while (fread(&reg, sizeof(Articulo), 1, pArticulo) == 1) {
//        // Si encontramos el cliente con el id buscado
//        if (reg.getId() == 0) {
//            reg.setEstado(false); // Cambiamos el estado a false
//
//            // Movemos el puntero de archivo hacia atrás una posición para sobrescribir
//            fseek(pArticulo, -sizeof(Articulo), SEEK_CUR);
//            fwrite(&reg, sizeof(Articulo), 1, pArticulo); // Sobrescribimos el registro
//            fclose(pArticulo);
//            cout << "Articulo con ID " << id << " eliminado exitosamente." << endl;
//            return true;
//        }
//    }
//
//    fclose(pArticulo);
//    cout << "Articulo con ID " << id << " no encontrado." << endl;
//    return false; // No se encontró el cliente con el DNI dado
//}
//
//        FILE *pArticulo;
//        pArticulo=fopen(_nombreArchivo, "rb");
//        if(pArticulo==NULL)
//            {
//            _id = 1;
//            return;
//            }
//        fseek(pArticulo, 0, SEEK_END); // se mueve al final del archivo
//        long fileSize = ftell(pArticulo); // se fija cuantos bit se movio
//        _id = (fileSize / sizeof(Articulo)) + 1; // divide ese tamaño por lo que pesa ese vend, y le aumenta 1
//        fclose(pArticulo);
//
//}
std::string Articulo::toCSV() {
    std::string str = std::to_string(getID()) +
                      "," + std::string(getCodArticulo()) +
                      "," + std::string(getNombreArticulo()) +
                      "," + std::to_string(getPrecioUnitario()) +
                      "," + std::to_string(getStock());

    return str;
}


