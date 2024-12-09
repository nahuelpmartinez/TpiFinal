#include "Fecha.h"
#include "Vendedor.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;


Vendedor::Vendedor(){

}
Vendedor::Vendedor(int id, char *dni, char *apellidos, char *nombres, Fecha nacimiento, char *domicilio, char *telefono, char *mail, bool estado, float sueldo, Fecha ingreso)

    : Persona(dni, apellidos, nombres, nacimiento, domicilio, telefono, mail, estado){

    _id = id;
    _sueldo = sueldo;
    _ingreso = ingreso;

    }

float Vendedor::getSueldo(){
    return _sueldo;
}
string Vendedor::getIngreso(){
    return _ingreso.toString();
}
int Vendedor::getID(){
    return _id;
}
void Vendedor::setSueldo (float sueldo){
   _sueldo = sueldo;
}
void Vendedor::setIngreso(Fecha ingreso){
    _ingreso = ingreso;
}
void Vendedor::setID(int id){

    _id = id;
}
void Vendedor::mostrar(){
    cout << "--------------------------------------------------------"<< endl;
    cout << "ID: "<< getID()<< endl;
    cout << "Nombre y Apellido: " << getNombres()<< " " <<getApellidos()<< endl;
    cout << "DNI: "<< getDni()<< endl;
    cout << "Fecha de Nacimiento: " << getNacimiento()<< endl;
    cout << "Domicilio: " << getDomicilio()<< endl;
    cout << "Mail: " << getMail()<< endl;
    cout << "Telefono: " << getTelefono()<< endl;
    cout << "Fecha de Ingreso: " << getIngreso() << endl;
    cout << "Sueldo: $" << getSueldo() << endl;
    //cout<< "Estado: " << getEstado()<< endl;
    cout<< "--------------------------------------------------------" <<endl <<endl;
}
std::string Vendedor::toCSV() {
    std::string str = std::string(getDni()) +
                      "," + std::string(getNombres()) +
                      "," + std::string(getApellidos()) +
                      "," + getNacimiento() +
                      "," + std::string(getDomicilio()) +
                      "," + std::string(getMail()) +
                      "," + std::string(getTelefono()) +
                      "," + getIngreso() +
                      "," + std::to_string(getSueldo());

    return str;
}





