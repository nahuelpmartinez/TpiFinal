#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include <string>
#include "Fecha.h"

using namespace std;

class Persona{
//modificacion pedida por Kloster Persona:tiene DNI, DOMICILIO, telefono, mail, estado
private:

    char _dni [15], _apellidos[50], _nombres[50], _mail[100], _telefono[50], _domicilio[100];
    Fecha _nacimiento;
    bool _estado; //propiedad que vamos a utilizar para definir si el registro est� o no activo (borrado)

public:
 Persona();
 Persona(char *dni, char *apellidos, char *nombres, Fecha nacimiento, char*mail, char* telefono, char* domicilio, bool estado);
 char* getDni ();
 char* getApellidos ();
 char* getNombres ();
 char* getMail ();//modificacion pedida por Kloster
 char* getTelefono ();//modificacion pedida por Kloster
 char* getDomicilio (); //modificacion pedida por Kloster
 bool getEstado();
 string getNacimiento ();
 void  setDni(char *dni);
 void setApellidos (char *Apellidos);
 void setNacimiento (Fecha Nacimiento);
 void setNombres(char *Nombres);
 void setMail(char *mail);//modificacion pedida por Kloster
 void setTelefono( char *telefono); //modificacion pedida por Kloster
 void setDomicilio(char *domicilio); //modificacion pedida por Kloster
 void setEstado(bool estado);
 };
#endif // PERSONA_H_INCLUDED
