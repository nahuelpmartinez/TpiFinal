#include "DetalleVenta.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;
DetalleVenta::DetalleVenta(){
}
DetalleVenta::DetalleVenta(int cantidad, int idArticulo, int idVenta, float precioUnitario){
    setCantidad(cantidad);
    setIdArticulo(idArticulo);
    setIdVenta(idVenta);
    setPrecioUnitario(precioUnitario);
}
int DetalleVenta::getCantidad(){
    return _cantidad;
}
int DetalleVenta::getIdArticulo(){
    return _idArticulo;
}
int DetalleVenta::getIdVenta(){
    return _idVenta;
}
float DetalleVenta::getPrecioUnitario(){
    return _precioUnitario;
}
void DetalleVenta::setCantidad(int cantidad){
    _cantidad = cantidad;
}
void DetalleVenta::setIdArticulo(int idArticulo){
    _idArticulo = idArticulo;
}
void DetalleVenta::setIdVenta(int idVenta){
    _idVenta = idVenta;
}
void DetalleVenta::setPrecioUnitario(float precioUnitario){
    _precioUnitario = precioUnitario;
}
void DetalleVenta::mostrar(){
cout << "Articulo : " << getIdArticulo() << " - Cantidad: " << getCantidad() << " - Precio Unitario: $" << getPrecioUnitario() << " - Subtotal: $" << getCantidad() * getPrecioUnitario() << endl;
}
