#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include <string>
#include "Persona.h"

class Cliente : public Persona
{

private:
    int _id;

public:
    Cliente();
    // Constructor de Cliente
    Cliente(int id, char *dni, char *apellidos, char *nombres, Fecha nacimiento, char*mail, char* telefono, char* domicilio, bool estado);
    int getID();
    std::string toCSV();
    void setID(int id);
    void mostrar();


 // M�todos heredados de Persona
    using Persona::getDni;
    using Persona::getApellidos;
    using Persona::getNombres;
    using Persona::getNacimiento;
    using Persona::getDomicilio;
    using Persona::getMail;
    using Persona::getTelefono;
    using Persona::setDni;
    using Persona::setApellidos;
    using Persona::setNombres;
    using Persona::setNacimiento;
    using Persona::setDomicilio;
    using Persona::setMail;
    using Persona::setTelefono;
 };



#endif // CLIENTE_H_INCLUDED


