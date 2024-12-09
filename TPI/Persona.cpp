#include "Persona.h"
#include <cstring>

using namespace std;

Persona::Persona(){}
Persona::Persona(char *dni, char *apellidos, char *nombres, Fecha nacimiento, char *domicilio, char *telefono, char *mail, bool estado){ // constructor
    strcpy(_dni,dni);
    strcpy(_apellidos,apellidos);
    strcpy(_nombres,nombres);
    strcpy(_domicilio,domicilio);
    strcpy(_telefono,telefono);
    strcpy(_mail,mail);
    _estado = estado;
    _nacimiento = nacimiento;
}

char* Persona::getDni ()
 {
    return _dni;
 }

char* Persona::getApellidos ()
 {
     return _apellidos;
 }

char* Persona::getNombres ()
 {
     return _nombres;
 }

string Persona::getNacimiento()
 {
     return _nacimiento.toString();
 }

char* Persona ::getDomicilio ()
{
    return _domicilio;
}

char* Persona ::getMail ()
{
    return _mail ;
}

char* Persona :: getTelefono ()
{
    return _telefono;
}

bool Persona:: getEstado()
{
    return _estado;
}

void Persona::setDni(char *dni)
 {
     strcpy(_dni,dni);
 }

void Persona::setApellidos (char *apellidos)
 {
     strcpy(_apellidos,apellidos);
 }

void Persona::setNacimiento (Fecha Nacimiento)
 {
     _nacimiento = Nacimiento;

 }

void Persona::setNombres(char *Nombres)
 {
     strcpy(_nombres,Nombres);
 }

 void Persona :: setDomicilio (char *domicilio)
 {
     strcpy(_domicilio,domicilio);
 }

 void Persona :: setTelefono ( char *telefono)
 {
     strcpy (_telefono, telefono);
 }

 void Persona :: setMail (char *mail)
 {
     strcpy (_mail, mail);
 }

 void Persona :: setEstado(bool estado){
    _estado = estado;
}

//std::string Persona::toCSV(){ le veo m�s sentido usar este toCSV a las subclases como Vendedor, Cliente
//
//    std::string str = std::to_string(_IDServicioMesa) + "," + std::to_string(_IDMozo) + "," + std::to_string(_IDPlato) + "," + std::to_string(_tiempoPreparacion) + "," + std::to_string(_puntajeObtenido) + "," + std::to_string((int) _propina) + "," + std::to_string((int) _importe) + "," + _fecha.toString();
//    return str;
//}
