#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#include "Fecha.h"
#include <string>
#include <cstring>

using namespace std;

class Venta{

private:
    int _id, _idCliente, _idVendedor,_formaPago;
    Fecha _fecha;
    float _importeTotal;
    char _nombreArchivo[50];
    const char *n= "Ventas.dat";
    int _tamanioRegistro;
public:
    Venta();
    Venta(int idCliente, int idVendedor, int formaPago, float importeTotal);
    Venta(int idCliente, int idVendedor, int formaPago);

int getId();
string getFecha();
int getIdCliente();
int getIdVendedor();
char* getFormaPago();
float getImporteTotal();
void setIdCliente(int idCliente);
void setIdVendedor(int idVendedor);
void setFecha(Fecha fecha);
void setFormaPago(int formaPago);
void setImporteTotal(float importeTotal);
bool registrarVenta(Venta reg);//tiene que ir en ArchivoVentas
bool listarVenta();//tiene que ir en ArchivoVentas
void CrearId();//tiene que ir en ArchivoVentas
void Mostrar(bool verLineas = false);
void buscarVentaID(int id); //tiene que ir en ArchivoVentas
string toCSV();
};

#endif // VENTA_H_INCLUDED
