#ifndef DETALLEVENTA_H_INCLUDED
#define DETALLEVENTA_H_INCLUDED

using namespace std;

class DetalleVenta{

private:
    int _cantidad, _idArticulo, _idVenta;
    float _precioUnitario;

public:

DetalleVenta();
DetalleVenta(int cantidad, int idArticulo, int idVenta, float precioUnitario);
int getCantidad();
int getIdArticulo();
int getIdVenta();
float getPrecioUnitario();
void setCantidad(int cantidad);
void setIdArticulo(int idArticulo);
void setIdVenta(int idVenta);
void setPrecioUnitario(float precioUnitario);
void mostrar();
};

#endif // DETALLEVENTA_H_INCLUDED
