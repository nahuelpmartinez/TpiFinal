#ifndef VENDEDOR_H_INCLUDED
#define VENDEDOR_H_INCLUDED
#include <string>
#include "Persona.h"

class Vendedor : public Persona
{

private:
    float _sueldo;
    Fecha _ingreso;
    int _id;

public:
 Vendedor();
 Vendedor(int id, char *dni, char *apellidos, char *nombres, Fecha nacimiento, char *domicilio, char *telefono, char *mail, bool estado, float sueldo, Fecha ingreso);

float getSueldo ();
string getIngreso ();
int getID();
void setSueldo (float Sueldo);
void setIngreso(Fecha Ingreso);
void setID(int id);
std::string toCSV();
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



#endif // VENDEDOR_H_INCLUDED

