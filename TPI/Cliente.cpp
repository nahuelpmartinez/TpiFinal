#include "Fecha.h"
#include "Cliente.h"
#include "ArchivoClientes.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;
Cliente::Cliente(){

}

Cliente::Cliente(int id, char *dni, char *apellidos, char *nombres, Fecha nacimiento, char *mail, char *telefono, char *domicilio, bool estado)
    : Persona (dni, apellidos, nombres, nacimiento, mail, telefono, domicilio, estado){

    _id = id;

}

int Cliente::getID(){

    return _id;
}

void Cliente::setID(int id){

    _id = id;
}

void Cliente::mostrar(){
    cout<< "--------------------------------------------------------"<< endl;
    cout<< "Cod: "<< getID()<< endl;
    cout<< "Nombre y Apellido: " << getNombres()<< " " <<getApellidos()<< endl;
    cout<< "DNI: "<< getDni()<< endl;
    cout<< "Fecha de Nacimiento: " << getNacimiento()<< endl;
    cout<< "Domicilio: " << getDomicilio()<< endl;
    cout<< "Mail: " << getMail()<< endl;
    cout<< "Telefono: " << getTelefono()<< endl;
    //cout<< "Estado: " << getEstado()<< endl;
    cout<< "--------------------------------------------------------" <<endl <<endl;
}


std::string Cliente::toCSV() {
    std::string str = std::string(getDni()) +
                      "," + std::string(getNombres()) +
                      "," + std::string(getApellidos()) +
                      "," + getNacimiento() + // Asumo que ya devuelve un `std::string`
                      "," + std::string(getDomicilio()) +
                      "," + std::string(getMail()) +
                      "," + std::string(getTelefono());
    return str;
}







