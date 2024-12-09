#include "Venta.h"
#include "Fecha.h"
#include "ArchivoClientes.h"
#include "ArchivoVendedores.h"

#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

Venta::Venta(){
    strcpy(_nombreArchivo, n);
    _tamanioRegistro=sizeof(Venta);
}
Venta::Venta(int idCliente, int idVendedor, int formaPago, float importeTotal){
    _idCliente = idCliente;
    _idVendedor = idVendedor;
    _formaPago = formaPago;
    _importeTotal = importeTotal;

    strcpy(_nombreArchivo, n);
    _tamanioRegistro=sizeof(Venta);

    CrearId();

    time_t ahora=time(nullptr);
    tm* tiempolocal=localtime(&ahora);
    Fecha aux(tiempolocal->tm_mday+0,tiempolocal->tm_mon+1,tiempolocal->tm_year+1900);
    _fecha= aux;
}
Venta::Venta(int idCliente, int idVendedor, int formaPago){
    _idCliente = idCliente;
    _idVendedor = idVendedor;
    _formaPago = formaPago;

    strcpy(_nombreArchivo, n);
    _tamanioRegistro=sizeof(Venta);

    CrearId();

    time_t ahora=time(nullptr);
    tm* tiempolocal=localtime(&ahora);
    Fecha aux(tiempolocal->tm_mday+0,tiempolocal->tm_mon+1,tiempolocal->tm_year+1900);
    _fecha= aux;
}
////GET
int Venta::getId(){
    return _id;
}
string Venta::getFecha(){
     return _fecha.toString();
 }
int Venta::getIdCliente(){
    return _idCliente;
}
int Venta::getIdVendedor(){
    return _idVendedor;
}
char* Venta::getFormaPago() {
    char* forma = new char[50];
    switch (_formaPago) {
        case 1: strcpy(forma, "Efectivo"); break;
        case 2: strcpy(forma, "Tarjeta de credito"); break;
        case 3: strcpy(forma, "Transferencia"); break;
        default: strcpy(forma, "Desconocido"); break;
    }
    return forma;

}
float Venta::getImporteTotal(){
    return _importeTotal;
}
////SET
void Venta::setIdCliente(int idCliente){
    _idCliente = idCliente;
}
void Venta::setIdVendedor(int idVendedor){
    _idVendedor = idVendedor;
}
void Venta::setFecha(Fecha fecha){
     _fecha = fecha;

 }
void Venta::setFormaPago(int formaPago){
    _formaPago = formaPago;
}
void Venta::setImporteTotal(float importeTotal){
    _importeTotal = importeTotal;
}
////METODOS

void Venta::CrearId(){
        FILE *pVenta;
        pVenta=fopen(_nombreArchivo, "rb");
        if(pVenta==NULL)
            {
            _id = 1;
            return;
            }
        fseek(pVenta, 0, SEEK_END); // se mueve al final del archivo
        long fileSize = ftell(pVenta); // se fija cuantos bit se movio
        _id = (fileSize / sizeof(Venta)) + 1; // divide ese tama�o por lo que pesa ese vend, y le aumenta 1
        fclose(pVenta);

}
void Venta::Mostrar(bool verLineas){
ArchivoClientes archivoClientes;
Cliente cliente = archivoClientes.buscarClienteID(getIdCliente());
ArchivoVendedores archivoVendedores;
Vendedor vendedor = archivoVendedores.buscarVendedorID(getIdVendedor());
    if(verLineas)cout<< "--------------------------------------------------------"<< endl;
    cout<< "Venta Nro     : "<< getId()<< endl;
    cout<< "Fecha         : "<< getFecha()<< endl;
    cout<< "Cliente       : " << cliente.getNombres() << " " << cliente.getApellidos() << endl;
    cout<< "Vendedor      : " << vendedor.getNombres() << " " << vendedor.getApellidos() << endl;
    cout<< "Forma de pago : " << getFormaPago()<< endl;
    cout<< "Importe total : $"<< getImporteTotal()<< endl;
    if(verLineas)cout<< "--------------------------------------------------------" <<endl;
}
//Venta Venta::buscarVentaID(int id){
//        FILE *pVenta;
//        Venta reg;
//        pVenta=fopen(_nombreArchivo, "rb");
//        if(pCliente==NULL){
//            cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
//            return reg;
//        }
//
//        long fileSize = ((id-1) * sizeof(Venta));
//        fseek(pVenta, fileSize, SEEK_SET);
//        fread(&reg,_tamanioRegistro,1,pVenta);
//        fclose(pVenta);
//        return reg;
//    }
//bool Venta::modificarCliente(Venta ven){
//     FILE *pCliente;
//        pCliente=fopen(_nombreArchivo,"rb+");
//        if(pCliente==NULL)
//             {
//            cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
//            return false;
//        }
//     long fileSize = ((cli.getID() -1) * sizeof(Cliente));
//        fseek(pCliente, fileSize, SEEK_SET);
//        int escribio=fwrite(&cli,_tamanioRegistro,1,pCliente);
//        fclose(pCliente);
//        return escribio;
//
//}



string Venta::toCSV() {

    ArchivoClientes archivoClientes;
    Cliente cliente = archivoClientes.buscarClienteID(getIdCliente());
    ArchivoVendedores archivoVendedores;
    Vendedor vendedor = archivoVendedores.buscarVendedorID(getIdVendedor());

    ostringstream ss;
    ss << getId() << ","
       << getFecha() << ","
       << getFormaPago() << ","
       << getIdCliente() << ","
       << cliente.getNombres() << " " << cliente.getApellidos() << ","
       << getIdVendedor() << ","
       << vendedor.getNombres() << " " << vendedor.getApellidos() << ","
       << getImporteTotal();

    return ss.str();
}

