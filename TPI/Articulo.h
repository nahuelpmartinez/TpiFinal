#ifndef ARTICULO_H_INCLUDED
#define ARTICULO_H_INCLUDED
#include <string>

class Articulo{

private:
    char _nombreArticulo[50], _codArticulo[8];
    float _precioUnitario;
    bool _estado;
    int _id ,_stock;

public:
    Articulo();
    Articulo(int id, char* codArticulo, char* nombreArticulo, int stock, float precioUnitario, bool estado);

char* getCodArticulo();
char* getNombreArticulo();
int getStock();
bool getEstado();
float getPrecioUnitario();
int getID();
void setCodArticulo( char *codArticulo);
void setNombreArticulo( char *nombreArticulo);
void setStock( int stock);
void setPrecioUnitario( float precioUnitario);
void setEstado(bool estado);
void setID(int id);
void mostrar();
std::string toCSV();
};

#endif // ARTICULO_H_INCLUDED
