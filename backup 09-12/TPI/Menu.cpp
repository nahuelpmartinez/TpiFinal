#include <iostream>
#include <cstring>
#include <cctype>
#include <vector>
#include "Vendedor.h"
#include "Menu.h"
#include "Fecha.h"
#include "Cliente.H"
#include "Articulo.h"
#include "Venta.h"
#include "ArchivoClientes.h"
#include "ArchivoVendedores.h"
#include "ArchivoArticulos.h"
#include "ValidarIngresoDatos.h"
#include "ArchivoVentas.h"
#include "DetalleVenta.h"
#include "ArchivoDetalleVenta.h"


using namespace std;


void MenuPrincipal(){
    int Opcion = -1;

    while (Opcion != 5) {

        while (Opcion > 5 || Opcion < 0) {

            cout<< " 1 - Ventas " << endl;
            cout<< " ------------- "<< endl;
            cout<< " 2 - Clientes " << endl;
            cout<< " ------------- "<< endl;
            cout<< " 3 - Vendedores" << endl;
            cout<< " ------------- "<< endl;
            cout<< " 4 - Articulos" << endl;
            cout<< " ------------- "<< endl;
            cout<< " 0 - Salir " << endl<< endl;

            cout<< " Ingrese la opcion deseada: ";
            cin>> Opcion;

            system ("cls");
        }

        switch (Opcion){
            case 1: MenuVentas();
                break;
            case 2: MenuClientes();
                break;
            case 3: MenuVendedores();
                break;
            case 4: MenuArticulos();
                break;
            case 0: exit(0);
                break;

        }

    }
}

void MenuVendedores(){
    int Opcion = -1;

    while (Opcion != 6) {

        while (Opcion > 6 || Opcion < 0) {

            cout<< " 1 - Registrar Vendedor" << endl;
            cout<< " -------------------------- "<< endl;
            cout<< " 2 - Modificar Vendedor" << endl;
            cout<< " --------------------------  "<< endl;
            cout<< " 3 - Buscar Vendedor" << endl;
            cout<< " --------------------------  "<< endl;
            cout<< " 4 - Eliminar Vendedor" << endl;
            cout<< " --------------------------  "<< endl;
            cout<< " 5 - Listar Vendedor" << endl;
            cout<< " --------------------------  "<< endl;
            cout<< " 6 - Descargar Archivo de Vendedores" << endl;
            cout<< " --------------------------  "<< endl;
            cout<< " 0 - Volver al menu principal " << endl<< endl;

            cout<< " Ingrese la opcion deseada: ";
            cin>> Opcion;

            system ("cls");
        }

        switch (Opcion){
            case 1: RegistrarVendedor(); return;
                break;
            case 2: ModificarVendedores();return;
                break;
            case 3: BuscarVendedor(); return;
                break;
            case 4: EliminarVendedor(); return;
                break;
            case 5: ListarVendedores(); return;
                break;
            case 6: DescargarArchivoVendedores(); return;
                break;
            case 0: MenuPrincipal();
                break;

        }

    }

}
void RegistrarVendedor(){
    char dni [15], apellidos[50], nombres[50], mail[50], telefono[50], domicilio[50];
    int diaNacimiento, mesNacimiento, anioNacimiento,diaIngreso, mesIngreso, anioIngreso, id = 0;
    float sueldo;
    //NOMBRES

    validarNombres(nombres);  // Llama a la función y automáticamente solicita y valida el dato

    //APELLIDOS
    while (true){
        cout << "Ingrese el Apellido/s: ";
        cin.getline(apellidos, 50);

        bool validar = true;
        int espacioCount = 0;

        for (int i = 0; i < (int)strlen(apellidos); i++){
            if (isalpha(apellidos[i])){
                continue;// Es letra, es válido
            }
            else if (apellidos[i] == ' '){
                espacioCount++;  // Cuenta los espacios
                if (espacioCount > 1){// Solo se permite un espacio
                    validar = false;
                    break;
                }
            }
            else{
                validar = false;  // Si no es letra ni espacio, no es válido
                break;
            }
        }

    if (validar && strlen(apellidos) > 0) break;  // Salimos si es válido
    cout << "Dato ingresado no válido. Solo debe contener letras y un solo espacio (opcional). Intente de nuevo." << endl;
}
    cout << "Ingrese el DNI: ";
    cin >> dni;
    cout<< "Ingrese el Dia de nacimiento: ";
    cin>> diaNacimiento;
    cout<< "Ingrese el Mes de nacimiento: ";
    cin>> mesNacimiento;
    cout<< "Ingrese el Anio de nacimiento: ";
    cin>> anioNacimiento;
        //DOMICILIO
    while (true){
        cout << "Ingrese su domicilio: ";
        cin.ignore();  // Ignora cualquier entrada previa
        cin.getline(domicilio, 50);

        bool validar = true;

        // Validar que el primer carácter sea una letra
        if (!isalpha(domicilio[0])){
            validar = false;
        }
        else{
            // Comprobar que todos los caracteres sean letras, números o espacios
            for (int i = 1; i < (int)strlen(domicilio); i++){
                if (!(isalpha(domicilio[i]) || isdigit(domicilio[i]) || domicilio[i] == ' ')){
                    validar = false;
                    break;
                }
            }
        }

        if (validar && strlen(domicilio) > 0) break;
        cout << "Domicilio no válido. Debe empezar con letras y puede contener números y espacios." << endl;
    }
while (true)
    {
        cout << "Ingrese el teléfono de contacto: ";
        cin >> telefono;

        bool validar = true;

        // Verificar que el número contenga exactamente 10 dígitos
        if (strlen(telefono) == 10){
            for (int i = 0; i < 10; ++i){
                if (!isdigit(telefono[i])){
                    validar = false;  // Si no es un dígito, no es válido
                    break;
                }
            }
        }
        else{
            validar = false;  // Longitud incorrecta
        }

        if (validar) break;  // Si es válido, salimos del bucle
        cout << "Teléfono no válido. Debe contener exactamente 10 dígitos sin espacios. Intente de nuevo." << endl;
    }
    while (true) {
        cout << "Ingrese el mail: ";
        cin >> mail;

        if (validarEmail(mail)) {
            break; // Email válido
        } else {
            cout << "Email no válido. Debe tener el formato: ejemplo@mail.com. Intente de nuevo." << endl;
        }
    }
    cout<< "Ingrese el sueldo: $";
    cin>> sueldo;
    cout<< "Ingrese el Dia de ingreso: ";
    cin>> diaIngreso;
    cout<< "Ingrese el Mes de ingreso: ";
    cin>> mesIngreso;
    cout<< "Ingrese el Anio de ingreso: ";
    cin>> anioIngreso;

    Fecha nacimiento(diaNacimiento, mesNacimiento, anioNacimiento);
    Fecha ingreso(diaIngreso, mesIngreso, anioIngreso);

    ArchivoVendedores Registro;

    id = Registro.crearId();

    cout << "Domicilio:" << domicilio << endl;
    cout << "Mail: " << mail << endl;

    Vendedor NuevoRegistro(id, dni, apellidos, nombres, nacimiento, domicilio, telefono, mail, true, sueldo, ingreso);

    bool escribio = Registro.registrarVendedor(NuevoRegistro);

    if(escribio)
    {
        cout<< endl << endl;
        cout<< "El vendedor se registro correctamente." <<endl;
    }else
    {
        cout<< endl << endl;
        cout<< "Ocurrio un error al registrar el vendedor." <<endl;
    }
    system("pause");
    system("cls");


    return;
}
void ListarVendedores(){
    ArchivoVendedores aux;
    aux.listarVendedores();
    system("pause");
    system("cls");
}
void BuscarVendedor(){

    char dni[8];

    cout << "Ingresar el DNI del cliente: ";
    cin >> dni;

    ArchivoVendedores buscar;

    buscar.buscarVendedorPorDNI(dni);

    system("pause");
    system("cls");
}
void EliminarVendedor(){

    //TipoBusqueda();
    int opcion = TipoBusqueda();

    ArchivoVendedores vendedor;

    switch(opcion){
    case 1:

        char dni[8];

        cout << "Ingresar el DNI del vendedor: ";
        cin >> dni;

        vendedor.eliminarVendedorPorDNI(dni);

        system("pause");
        system("cls");

        MenuVendedores();
        break;
    case 2:
        int id;

        cout << "Ingresar el ID del vendedor: ";
        cin >> id;

        //vendedor.EliminarVendedorPorID(id);

        system("pause");
        system("cls");

        MenuVendedores();
        break;
    case 3:
        break;
    }
}
void DescargarArchivoVendedores(){
    ArchivoVendedores aux;
    aux.exportarVendedoresACSV();
    system("pause");
    system("cls");
}
void ModificarVendedores(){
    ArchivoVendedores archivoVendedores;
    char dni[10], apellidos[50], nombres[50], mail[100], telefono[50], domicilio[100];
    int diaNacimiento, mesNacimiento, anioNacimiento,diaIngreso, mesIngreso, anioIngreso, id = 0;
    float sueldo = 0;

    Vendedor nuevosDatos;

    // Solicitar el DNI
    cout << "Ingrese el DNI del vendedor a modificar: ";
    cin.ignore();
    cin.getline(dni, 10);

    // Verificar si el cliente existe
    Vendedor vendedorActual;

    if (!archivoVendedores.buscarVendedorPorDNI(dni, vendedorActual)) {
        cout << "El vendedor con DNI " << dni << " no se encuentra en los registros." << endl;
        return;
    }

    // Mostrar datos actuales
    cout << "Datos actuales del vendedor:" << endl;
    vendedorActual.mostrar();

    // Solicitar los nuevos datos
    cout << "Ingrese el Nombre/s: ";
    cin.getline(nombres, 50);
    nuevosDatos.setNombres(nombres);

    cout << "Ingrese el Apellido/s: ";
    cin.getline(apellidos, 50);
    nuevosDatos.setApellidos(apellidos);

    cout << "Ingrese el día de nacimiento: ";
    cin >> diaNacimiento;

    cout << "Ingrese el mes de nacimiento: ";
    cin >> mesNacimiento;

    cout << "Ingrese el día de nacimiento: ";
    cin >> anioNacimiento;

    cout << "Ingrese el Domicilio: ";
    cin.ignore();
    cin.getline(domicilio, 50);
    nuevosDatos.setDomicilio(domicilio);

    cout << "Ingrese el Teléfono: ";
    cin.getline(telefono, 50);
    nuevosDatos.setTelefono(telefono);

    cout << "Ingrese el Mail: ";
    cin.getline(mail, 50);
    nuevosDatos.setMail(mail);

    cout << "Ingrese el día de Ingreso: ";
    cin >> diaIngreso;

    cout << "Ingrese el mes de Ingreso: ";
    cin >> mesIngreso;

    cout << "Ingrese el año de Ingreso: ";
    cin >> anioIngreso;

    cout << "Ingrese el Sueldo: ";
    cin >> sueldo;
    nuevosDatos.setSueldo(sueldo);

    cout << endl;
    cout << endl;

    Fecha nacimiento(diaNacimiento, mesNacimiento, anioNacimiento);
    nuevosDatos.setNacimiento(nacimiento);
    Fecha ingreso(diaIngreso, mesIngreso, anioIngreso);
    nuevosDatos.setIngreso(ingreso);
    nuevosDatos.setDni(dni);  // El DNI permanece igual
    id = vendedorActual.getID(); //pido el id
    nuevosDatos.setID(id); //guardo nuevamente el id
    nuevosDatos.setEstado(true);
    nuevosDatos.mostrar();

    // Llamar al método para modificar en el archivo
    if (archivoVendedores.modificarVendedorPorDNI(dni, nuevosDatos)) {
        cout << "Modificación completada con éxito." << endl << endl;
    }else{
        cout << "Hubo un problema al modificar el cliente." << endl << endl;
    }
    system("pause");
    system("cls");

}

void MenuClientes(){
    int Opcion = -1;

    while (Opcion != 6) {

        while (Opcion > 6 || Opcion < 0) {

            cout<< " 1 - Registrar Cliente" << endl;
            cout<< " -------------------------- "<< endl;
            cout<< " 2 - Modificar Cliente" << endl;
            cout<< " --------------------------  "<< endl;
            cout<< " 3 - Buscar Cliente" << endl;
            cout<< " --------------------------  "<< endl;
            cout<< " 4 - Eliminar Cliente" << endl;
            cout<< " --------------------------  "<< endl;
            cout<< " 5 - Listar Clientes" << endl;
            cout<< " --------------------------  "<< endl;
            cout<< " 6 - Descargar Archivo de Clientes" << endl;
            cout<< " --------------------------  "<< endl;
            cout<< " 0 - Volver al menu principal " << endl<< endl;

            cout<< " Ingrese la opcion deseada: ";
            cin>> Opcion;

            system ("cls");
        }

        switch (Opcion){
            case 1: RegistrarCliente(); return;
                break;
            case 2: ModificarClientes(); return;
                break;
            case 3: BuscarCliente(); return;
                break;
            case 4: EliminarCliente(); return;
                break;
            case 5: ListarClientes(); return;
                break;
            case 6: DescargarArchivoClientes(); return;
                break;
            case 0: MenuPrincipal();
                break;

        }

    }

}
void RegistrarCliente(){

    char dni[15], apellidos[50], nombres[50], mail[100], telefono[50], domicilio[100];
    int diaNacimiento, mesNacimiento, anioNacimiento, id = 0;

    //NOMBRES
    validarNombres(nombres);  // Llama a la función y automáticamente solicita y valida el dato

    //APELLIDOS
    while (true){
        cout << "Ingrese el Apellido/s: ";
        cin.getline(apellidos, 50);

        bool validar = true;
        int espacioCount = 0;

        for (int i = 0; i < (int)strlen(apellidos); i++){
            if (isalpha(apellidos[i])){
                continue;// Es letra, es válido
            }
            else if (apellidos[i] == ' '){
                espacioCount++;  // Cuenta los espacios
                if (espacioCount > 1){// Solo se permite un espacio
                    validar = false;
                    break;
                }
            }
            else{
                validar = false;  // Si no es letra ni espacio, no es válido
                break;
            }
        }

    if (validar && strlen(apellidos) > 0) break;  // Salimos si es válido
    cout << "Dato ingresado no válido. Solo debe contener letras y un solo espacio (opcional). Intente de nuevo." << endl;
}
    //DNI
    while (true) {
        cout << "Ingrese el DNI: ";
        cin >> dni;
        bool validar = true;

    // Verificar que tenga exactamente 8 caracteres y sean todos dígitos
        if (strlen(dni) == 8){
            for (int i = 0; i < 8; ++i) {
                if (!isdigit(dni[i])) {
                validar = false;
                break;
                }
            }
        }else{
        validar = false;
        }

        if (validar) break; // Si es válido, salimos del bucle
        cout << "DNI no válido. Debe contener exactamente 8 dígitos. Intente de nuevo." << endl;
    }
    //DÍA DE NACIMIENTO
    while (true){
        cout << "Ingrese el día de nacimiento: ";
        cin >> diaNacimiento;
        // Comprobar que el día esté en el rango válido
        if (diaNacimiento >= 1 && diaNacimiento <= 31){
            break;  // Día válido
        }
        else{
            cout << "Día no válido. Debe ser un número entre 1 y 31. Intente de nuevo." << endl;
        }
    }
    //MES DE NACIMIENTO
    while (true){
        cout << "Ingrese el mes de nacimiento: ";
        cin >> mesNacimiento;
        // Comprobar que el mes esté en el rango válido
        if (mesNacimiento >= 1 && mesNacimiento <= 12){
            break;  // mes válido
        }
        else{
            cout << "Mes no válido. Debe ser un número entre 1 y 12. Intente de nuevo." << endl;
        }
    }
    //AÑO DE NACIMIENTO
    while (true){
        cout << "Ingrese el Año de nacimiento: ";
        cin >> anioNacimiento;

        // Comprobar que el año tenga 4 dígitos y esté en el rango válido
        if (anioNacimiento >= 1900 && anioNacimiento <= 2008){
            break;  // Año válido
        }
        else{
            cout << "Año no válido. Debe ser un número de 4 dígitos entre 1900 y 2008. Intente de nuevo." << endl;
        }
    }
    //DOMICILIO
    while (true){
        cout << "Ingrese su domicilio: ";
        cin.ignore();  // Ignora cualquier entrada previa
        cin.getline(domicilio, 100);

        bool validar = true;

        // Validar que el primer carácter sea una letra
        if (!isalpha(domicilio[0])){
            validar = false;
        }
        else{
            // Comprobar que todos los caracteres sean letras, números o espacios
            for (int i = 1; i < (int)strlen(domicilio); i++){
                if (!(isalpha(domicilio[i]) || isdigit(domicilio[i]) || domicilio[i] == ' ')){
                    validar = false;
                    break;
                }
            }
        }

        if (validar && strlen(domicilio) > 0) break;
        cout << "Domicilio no válido. Debe empezar con letras y puede contener números y espacios." << endl;
    }
    //TELEFONO
    while (true){
        cout << "Ingrese el teléfono de contacto: ";
        cin >> telefono;

        bool validar = true;

        // Verificar que el número contenga exactamente 10 dígitos
        if (strlen(telefono) == 10){
            for (int i = 0; i < 10; ++i){
                if (!isdigit(telefono[i])){
                    validar = false;  // Si no es un dígito, no es válido
                    break;
                }
            }
        }
        else{
            validar = false;  // Longitud incorrecta
        }

        if (validar) break;  // Si es válido, salimos del bucle
        cout << "Teléfono no válido. Debe contener exactamente 10 dígitos sin espacios. Intente de nuevo." << endl;
    }
    //MAIL
    while (true){
        cout << "Ingrese el mail: ";
        cin >> mail;

        if (validarEmail(mail)) {
            break; // Email válido
        } else {
            cout << "Email no válido. Debe tener el formato: ejemplo@mail.com. Intente de nuevo." << endl;
        }
    }

    Fecha nacimiento(diaNacimiento,mesNacimiento,anioNacimiento);

    ArchivoClientes Registro;

    id = Registro.crearId();

    Cliente NuevoRegistro(id, dni, apellidos, nombres, nacimiento, mail, telefono, domicilio, true);

    //ArchivoClientes Registro;

    bool escribio = Registro.registrarCliente(NuevoRegistro);

    if(escribio){
        cout<< endl << endl;
        cout<< "El cliente se registro correctamente." <<endl;
    }else{
        cout<< endl << endl;
        cout<< "Ocurrio un error al registrar el cliente." <<endl;
    }
    system("pause");
    system("cls");


    return MenuClientes();
}
void BuscarCliente(){

    char dni[8];

    cout << "Ingresar el DNI del cliente: ";
    cin >> dni;

    ArchivoClientes buscar;

    buscar.buscarClientePorDNI(dni);

    system("pause");
    system("cls");
}
void ListarClientes(){
    ArchivoClientes aux;
    aux.listarClientes();
    system("pause");
    system("cls");
}
void EliminarCliente(){

    int opcion = TipoBusqueda();

    ArchivoClientes eliminar;

    switch(opcion){
    case 1:

        char dni[8];

        cout << "Ingresar el DNI del cliente: ";
        cin >> dni;

        eliminar.eliminarClientePorDNI(dni);

        system("pause");
        system("cls");

        MenuClientes();
        break;
    case 2:
        int id;

        cout << "Ingresar el ID del cliente: ";
        cin >> id;

        //cliente.EliminarClientePorID(id);

        system("pause");
        system("cls");

        MenuClientes();
        break;
    case 3:
        break;
    }
}
void DescargarArchivoClientes(){
    ArchivoClientes aux;
    aux.exportarClientesACSV();
    system("pause");
    system("cls");
}
void ModificarClientes(){
    ArchivoClientes archivoClientes;
    char dni[10], apellidos[50], nombres[50], mail[100], telefono[50], domicilio[100];
    int diaNacimiento, mesNacimiento, anioNacimiento, id = 0;
    Cliente nuevosDatos;

    // Solicitar el DNI
    cout << "Ingrese el DNI del cliente a modificar: ";
    cin.ignore();
    cin.getline(dni, 10);

    // Verificar si el cliente existe
    Cliente clienteActual;
    if (!archivoClientes.buscarClientePorDNI(dni, clienteActual)) {
        cout << "El cliente con DNI " << dni << " no se encuentra en los registros." << endl;
        return;
    }

    // Mostrar datos actuales
    cout << "Datos actuales del cliente:" << endl;
    clienteActual.mostrar();

    // Solicitar los nuevos datos
    cout << "Ingrese el nuevo Nombre/s: ";
    cin.getline(nombres, 50);
    nuevosDatos.setNombres(nombres);

    cout << "Ingrese el nuevo Apellido/s: ";
    cin.getline(apellidos, 50);
    nuevosDatos.setApellidos(apellidos);

    cout << "Ingrese el día de nacimiento: ";
    cin >> diaNacimiento;

    cout << "Ingrese el mes de nacimiento: ";
    cin >> mesNacimiento;

    cout << "Ingrese el día de nacimiento: ";
    cin >> anioNacimiento;

    cout << "Ingrese el nuevo Domicilio: ";
    cin.ignore();
    cin.getline(domicilio, 50);
    nuevosDatos.setDomicilio(domicilio);

    cout << "Ingrese el nuevo Teléfono: ";
    cin.getline(telefono, 50);
    nuevosDatos.setTelefono(telefono);

    cout << "Ingrese el nuevo Mail: ";
    cin.getline(mail, 50);
    nuevosDatos.setMail(mail);


    cout << endl;
    cout << endl;

    Fecha nacimiento(diaNacimiento, mesNacimiento, anioNacimiento);
    nuevosDatos.setNacimiento(nacimiento);
    nuevosDatos.setDni(dni);  // El DNI permanece igual
    id = clienteActual.getID(); //pido el id
    nuevosDatos.setID(id); //guardo nuevamente el id
    nuevosDatos.setEstado(true);
    nuevosDatos.mostrar();

    // Llamar al método para modificar en el archivo
    if (archivoClientes.modificarClientePorDNI(dni, nuevosDatos)) {
        cout << "Modificación completada con éxito." << endl << endl;
    } else {
        cout << "Hubo un problema al modificar el cliente." << endl << endl;
    }
    system("pause");
    system("cls");
}

void MenuArticulos(){
    int Opcion = -1;

    while (Opcion != 6) {

        while (Opcion > 6 || Opcion < 0) {

            cout<< " 1 - Registrar Articulo" << endl;
            cout<< " -------------------------- "<< endl;
            cout<< " 2 - Modificar Articulo" << endl;
            cout<< " --------------------------  "<< endl;
            cout<< " 3 - Buscar Articulo" << endl;
            cout<< " --------------------------  "<< endl;
            cout<< " 4 - Eliminar Articulo" << endl;
            cout<< " --------------------------  "<< endl;
            cout<< " 5 - Listar Articulos" << endl;
            cout<< " --------------------------  "<< endl;
            cout<< " 6 - Descargar Archivo de Articulos" << endl;
            cout<< " --------------------------  "<< endl;
            cout<< " 0 - Volver al menu principal " << endl<< endl;

            cout<< " Ingrese la opcion deseada: ";
            cin>> Opcion;

            system ("cls");
        }

        switch (Opcion){
            case 1: RegistrarArticulo(); return;
                break;
            case 2: ModificarArticulo(); return;
                break;
            case 3: BuscarArticulo(); return;
                break;
            case 4: EliminarArticulo(); return;
                break;
            case 5: ListarArticulos(); return;
                break;
            case 6: DescargarArchivoArticulos(); return;
                break;
            case 0: MenuPrincipal();
                break;
        }
    }
}
void RegistrarArticulo(){
    char nombreArticulo[50], codArticulo[8];
    int stock = 0, id = 0;
    float precioUnitario;

    cout<< "Ingrese el Codigo del articulo: ";
    cin>> codArticulo;
//nombre art
    while (true){
        cout << "Ingrese el Nombre del articulo: ";
        cin.ignore();  // Ignora cualquier entrada previa
        cin.getline(nombreArticulo, 50);

        bool validar = true;
        int espacioCount = 0;

        for (int i = 0; i < (int)strlen(nombreArticulo); i++){
            if (isalpha(nombreArticulo[i])){
                continue;// Es letra, es válido
            }
            else if (nombreArticulo[i] == ' '){
                espacioCount++;  // Cuenta los espacios
                if (espacioCount > 1){// Solo se permite un espacio
                    validar = false;
                    break;
                }
            }
            else{
                validar = false;  // Si no es letra ni espacio, no es válido
                break;
            }
        }

    if (validar && strlen(nombreArticulo) > 0) break;  // Salimos si es válido
    cout << "Dato ingresado no válido. Solo debe contener letras y un solo espacio (opcional). Intente de nuevo." << endl;
}
    cout<< "Ingrese el Stock del articulo: ";
    cin>> stock;
    cout<< "Ingrese el precio unitario del articulo: ";
    cin>> precioUnitario;

    ArchivoArticulos Registro;

    id = Registro.crearId();

    Articulo nuevoRegistro(id, codArticulo, nombreArticulo, stock, precioUnitario, true);

    bool escribio = Registro.registrarArticulo(nuevoRegistro);

    if(escribio)
    {
        cout<< endl << endl;
        cout<< "El Articulo se registro correctamente." <<endl;
    }else
    {
        cout<< endl << endl;
        cout<< "Ocurrio un error al registrar el Articulo." <<endl;
    }
    void CrearId ();

    system("pause");
    system("cls");


    return;
}
void ListarArticulos(){
    ArchivoArticulos aux;
    aux.listarArticulos();
    system("pause");
    system("cls");
}
void DescargarArchivoArticulos(){
    ArchivoArticulos aux;
    aux.exportarArticulosACSV();
    system("pause");
    system("cls");
}
void BuscarArticulo(){

    char cod[10];

    cout << "Ingresar el Código del Articulo: ";
    cin >> cod;

    ArchivoArticulos buscar;

    buscar.buscarArticuloPorCod(cod);

    system("pause");
    system("cls");
}
void EliminarArticulo(){

    char cod[10];

    ArchivoArticulos articulo;

        cout << "Ingresar el Código del Articulo: ";
        cin >> cod;

        articulo.eliminarArticuloPorCod(cod);

        system("pause");
        system("cls");

        MenuArticulos();

}
void ModificarArticulo(){
    ArchivoArticulos archivoArticulos;
    char codArticulo[10], nombreArticulo[50];
    int stock = 0, id = 0;
    float precioUnitario;

    Articulo nuevosDatos;

    // Solicitar el DNI
    cout << "Ingrese el Código del Articulo a modificar: ";
    cin.ignore();
    cin.getline(codArticulo, 10);

    // Verificar si el articulo existe
    Articulo articuloActual;
    if (!archivoArticulos.buscarArticuloPorCod(codArticulo, articuloActual)) {
        cout << "El Articulo con Código " << codArticulo << " no se encuentra en los registros." << endl;
        return;
    }

    // Mostrar datos actuales
    cout << "Datos actuales del Articulo:" << endl;
    articuloActual.mostrar();

    // Solicitar los nuevos datos
    cout << "Ingrese el Nombre: ";
    cin.getline(nombreArticulo, 50);
    nuevosDatos.setNombreArticulo(nombreArticulo);

    cout << "Ingrese Precio Unitario: ";
    cin >> precioUnitario;
    nuevosDatos.setPrecioUnitario(precioUnitario);

    cout << "Ingrese el Stock: ";
    cin >> stock;
    nuevosDatos.setStock(stock);

    cout << endl;
    cout << endl;

    nuevosDatos.setCodArticulo(codArticulo);  // El DNI permanece igual
    id = articuloActual.getID(); //pido el id
    nuevosDatos.setID(id); //guardo nuevamente el id
    nuevosDatos.setEstado(true);
    nuevosDatos.mostrar();

    // Llamar al método para modificar en el archivo
    if (archivoArticulos.modificarArticuloPorCod(codArticulo, nuevosDatos)) {
        cout << "Modificación completada con éxito." << endl << endl;
    } else {
        cout << "Hubo un problema al modificar el Articulo." << endl << endl;
    }

    system("pause");
    system("cls");
}

void MenuVentas(){

    int Opcion = -1;

    while (Opcion != 6){

        while (Opcion > 6 || Opcion < 0){

            cout<< " 1 - Registrar Venta " << endl;
            cout<< " --------------------------  "<< endl;
            cout<< " 2 - Listar ventas realizadas " << endl;
            cout<< " --------------------------  "<< endl;
            cout<< " 3 - Buscar una Venta" << endl;
            cout<< " --------------------------  "<< endl;
            cout<< " 4 - Ver detalle de una Venta" << endl;
            cout<< " --------------------------  "<< endl;
            cout<< " 5 - Descargar Archivo de Clientes" << endl;
            cout<< " --------------------------  "<< endl;
            cout<< " 0 - Volver al menu principal " << endl<< endl;

            cout<< " Ingrese la opcion deseada: ";
            cin>> Opcion;

            system ("cls");
        }

        switch (Opcion){// Sub menu Venta (realizar venta, listar ventas, buscar venta
            case 1: RegistrarVenta(); return;
                break;
            case 2: ListarVentas(); return;
                break;
            case 3: buscarVentaPorID(); return;
                break;
            case 4: verDetalleDeVenta(); return;
                break;
            case 5: exportarCsvVentas(); return;
                break;
            case 0: MenuPrincipal();
                break;

        }
    }
}
void verDetalleDeVenta() {
    int id;
    cout << "Ingrese el ID de la venta que desea buscar: ";
    cin >> id;

    ArchivoVentas archivoVentas;
    ArchivoDetalleVentas archivoDetalleVentas;

    // Buscar la venta
    Venta venta = archivoVentas.buscarVentaID(id);
    if (venta.getIdCliente() == -1 || venta.getIdVendedor() == -1) {
        cout << "La venta con ID " << id << " no existe." << endl;
        system("pause");
        return;
    }

    // Mostrar los detalles de la venta
    vector<DetalleVenta> detalles = archivoDetalleVentas.buscarDetalle(id);

    cout << "------------------VENTA------------------" << endl << endl;
    venta.Mostrar();

    // Verificar si existen detalles asociados a la venta
    if (detalles.empty()) {
        cout << endl << "No se encontraron detalles asociados a esta venta." << endl;
    } else {
        cout << endl << "-------------DETALLE DE VENTA------------" << endl << endl;
        for (DetalleVenta& detalle : detalles) {
            detalle.mostrar();
        }
    }

    cout << endl;
    system("pause");
    system("cls");
}
void RegistrarVenta() {
    int codVendedor, cantidadArticulos, formaDePago;
    char dniCliente[15], codArticulo[10];
    float importeTotal = 0;
    Vendedor vendedor;
    Cliente cliente;
    ArchivoClientes archivoCliente;
    ArchivoVendedores archivoVendedor;
    ArchivoVentas archivoVentas;
    ArchivoDetalleVentas archivoDetalleVenta;
    ArchivoArticulos archivoArticulos;
    Articulo articuloActual;

    // Solicitar y validar vendedor
    cout << "Ingrese el Código del Vendedor: ";
    cin >> codVendedor;

    vendedor = archivoVendedor.buscarVendedorID(codVendedor);
    while (vendedor.getID() == -1) {
        cout << "No existe un vendedor con código: " << codVendedor << ". Vuelva a ingresarlo: ";
        cin >> codVendedor;
        vendedor = archivoVendedor.buscarVendedorID(codVendedor);
    }

    cout << "Vendedor: " << vendedor.getNombres() << " " << vendedor.getApellidos() << endl << endl;

    // Solicitar y validar cliente
    cout << "Ingrese el DNI del cliente: ";
    cin >> dniCliente;

    bool clienteExiste = archivoCliente.buscarClientePorDNI(dniCliente, cliente);
    while (!clienteExiste) {
        cout << "El cliente con DNI: " << dniCliente << " no existe. Vuelva a ingresarlo: ";
        cin >> dniCliente;
        clienteExiste = archivoCliente.buscarClientePorDNI(dniCliente, cliente);
    }

    cout << "Cliente: " << cliente.getNombres() << " " << cliente.getApellidos() << endl;

    // Solicitar forma de pago
    cout << "Ingrese la forma de pago: 1-Efectivo, 2-Tarjeta de crédito, 3-Transferencia: ";
    cin >> formaDePago;
    while (formaDePago < 1 || formaDePago > 3) {
        cout << "Forma de pago inválida. Intente nuevamente: ";
        cin >> formaDePago;
    }

    // Crear la venta
    Venta venta(cliente.getID(), vendedor.getID(), formaDePago);

    // Solicitar artículos y cantidades
    cout << "Ingrese la cantidad de artículos diferentes que cargará en la factura: ";
    cin >> cantidadArticulos;

    vector<Articulo> articulos;
    vector<int> cantidades;
    vector<DetalleVenta> detalles;

    for (int i = 0; i < cantidadArticulos; i++) {
        cout << "Ingrese el código del artículo: ";
        cin >> codArticulo;

        while (!archivoArticulos.buscarArticuloPorCod(codArticulo, articuloActual)) {
            cout << "El artículo con código " << codArticulo << " no existe. Vuelva a ingresarlo: ";
            cin >> codArticulo;
        }

        cout << "Artículo: " << articuloActual.getNombreArticulo() << endl;

        int cantidad;
        cout << "Ingrese la cantidad vendida: ";
        cin >> cantidad;

        while (cantidad > articuloActual.getStock()) {
            cout << "La cantidad ingresada excede el stock disponible (" << articuloActual.getStock() << "). Intente nuevamente: ";
            cin >> cantidad;
        }

        // Actualizar stock y reflejar el cambio en el archivo
        articuloActual.setStock(articuloActual.getStock() - cantidad);
        if (!archivoArticulos.modificarArticuloPorCod(codArticulo, articuloActual)) {
            cout << "Error al actualizar el stock del artículo " << codArticulo << "." << endl;
            continue; // Pasar al siguiente artículo
        }

        // Registrar los datos en las colecciones
        articulos.push_back(articuloActual);
        cantidades.push_back(cantidad);
        detalles.emplace_back(cantidad, articuloActual.getID(), venta.getId(), articuloActual.getPrecioUnitario());

        // Calcular importe total
        importeTotal += articuloActual.getPrecioUnitario() * cantidad;
    }

    // Guardar la venta
    venta.setImporteTotal(importeTotal);
    bool registroVenta = archivoVentas.registrarVenta(venta);

    // Guardar detalles de la venta
    int registroDetalles = archivoDetalleVenta.registrarDetalleVenta(detalles.data(), detalles.size());

    if (registroVenta && registroDetalles > 0) {
        cout << "La venta se registró con éxito y el stock fue actualizado." << endl;
    } else {
        cout << "Ocurrió un error al registrar la venta o actualizar los detalles." << endl;
    }

    system("pause");
    system("cls");
}
void ListarVentas(){
    ArchivoVentas archivoVentas;
    archivoVentas.listarVenta(true);
    system("pause");
    system("cls");
}
void exportarCsvVentas(){
    ArchivoVentas aux;
    aux.exportarCSV();
    system("pause");
    system("cls");
}
void buscarVentaPorID(){
    int id;
    cout << "Ingrese el ID de la venta que desea buscar: ";
    cin >> id;

    system("cls");
    ArchivoVentas archivoVentas;
    Venta venta = archivoVentas.buscarVentaID(id);
    if(venta.getIdCliente() > -1 && venta.getIdVendedor() > -1)
    {
        venta.Mostrar(true);
    }
    system("pause");
    system("cls");
}





//void ModificarArticulo(){
//
//int idBuscar;
//
//cout << "Ingrese el ID del articulo a modificar: " ;
//cin>> idBuscar;
//
//Articulo modificar;
//
//modificar = modificar.buscarArticuloID(idBuscar);
//if(idBuscar == modificar.getId()){
//    modificar.Mostrar();
//
//    system("pause");
//    cout << endl <<endl;
//    char confirma;
//    cout << endl <<endl << "Para confirmar que desea modificar este articulo ingrese 's': ";
//    cin >> confirma;
//    if (confirma == 's' ||  confirma == 'S'){
//
//     int stock;
//     float precioUnitario;
//
//    cout<< "Ingrese el Nuevo Stock total del articulo: " ;
//    cin>> stock;
//    cout<< "Ingrese el Nuevo precio unitario del articulo: ";
//    cin>> precioUnitario;
//
//    modificar.setStock(stock);
//    modificar.setPrecioUnitario( precioUnitario);
//    bool escribio = modificar.modificarArticulo(modificar);
//    if (escribio)
//    {
//        cout<< endl<< "El articulo se modifico con exito."<< endl;
//        system("pause");
//        system ("cls");
//    }
//     else
//    {
//        cout<< endl<< "Ocurrio un error al guardar." << endl;
//        system("pause");
//        system ("cls");
//    }
//}
// else {
//        system ("cls");
//    }
//}
//else{
//    cout << "El ID ingresado es invalido" << endl;
//
//    system("pause");
//    system ("cls");
//}
//
//
//}


//void MenuVentas(){
//
//    int Opcion = 0;
//
//    while (Opcion != 4){
//
//        while (Opcion > 4 || Opcion < 1){
//
//            cout<< " 1 - Registrar Venta " << endl;
//            cout<< " --------------------------  "<< endl;
//            cout<< " 2 - Listar ventas realizadas " << endl;
//            cout<< " --------------------------  "<< endl;
//            cout<< " 3 - Buscar una Venta" << endl;
//            cout<< " --------------------------  "<< endl;
//            cout<< " 4 - Volver al menu principal " << endl<< endl;
//
//            cout<< " Ingrese la opcion deseada: ";
//            cin>> Opcion;
//
//            system ("cls");
//        }
//
//        switch (Opcion){// Sub menu Venta (realizar venta, listar ventas, buscar venta
//            case 1: RegistrarVenta(); return;
//                break;
//            case 2: ListarVentas(); return;
//                break;
//            case 3: buscarVentaPorID(); return;
//                break;
//            case 4:MenuPrincipal();
//                break;
//
//        }
//    }
//}
//void RegistrarVenta(){
//
//    char formaPago[50];
//    int dia, mes, anio;
//    float importeTotal;
//   // string idCliente, id;
//    int idCliente, idVendedor;
//
//    //DÍA DE NACIMIENTO
//    while (true){
//        cout << "Ingrese el día: ";
//        cin >> dia;
//        // Comprobar que el día esté en el rango válido
//        if (dia >= 1 && dia <= 31){
//            break;  // Día válido
//        }
//        else{
//            cout << "Día no válido. Debe ser un número entre 1 y 31. Intente de nuevo." << endl;
//        }
//    }
//    //MES DE NACIMIENTO
//    while (true){
//        cout << "Ingrese el mes: ";
//        cin >> mes;
//        // Comprobar que el mes esté en el rango válido
//        if (mes >= 1 && mes <= 12){
//            break;  // mes válido
//        }
//        else{
//            cout << "Mes no válido. Debe ser un número entre 1 y 12. Intente de nuevo." << endl;
//        }
//    }
//    //AÑO DE NACIMIENTO
//    while (true){
//        cout << "Ingrese el Año: ";
//        cin >> anio;
//
//        // Comprobar que el año tenga 4 dígitos y esté en el rango válido
//        if (anio == 2024){
//            break;  // Año válido
//        }
//        else{
//            cout << "Año no válido. Debe corresponder al año en curso (2024). Intente de nuevo." << endl;
//        }
//    }
//
//    //IDCLIENTE
//    cout << "Ingrese el ID del cliente (solo números, sin espacios ni letras): ";
//    cin >> idCliente;
//
//    //IDVENDEDOR
//    cout << "Ingrese el ID del vendedor (solo números, sin espacios ni letras): ";
//    cin >> idVendedor;
//
//
//    //FORMA DE PAGO
//        cout << "Seleccione la forma de pago:";
//        cin >> formaPago;
//
//    //IMPORTE TOTAL
//
//        cout << "Ingrese importe total de la factura: ";
//        cin >> importeTotal;
//
//    Fecha fecha(dia, mes, anio);
//
//    Venta NuevoRegistro(fecha, idCliente, idVendedor, formaPago, importeTotal);
//
//    bool escribio = NuevoRegistro.registrarVenta(NuevoRegistro);
//
//    if(escribio){
//        cout<< endl;
//        cout<< "La factura se registro correctamente." <<endl;
//    }else{
//        cout<< endl;
//        cout<< "Ocurrio un error al registrar la factura." <<endl;
//    }
//    cout << endl;
//    system("pause");
//    system("cls");
//
//
//    return MenuVentas();
//}
//void ListarVentas(){
//    Venta aux;
//    aux.listarVenta();
//    system("pause");
//    system("cls");
//
//}
//void buscarVentaPorID(){
//    int id;
//    cout << "Ingrese el ID de la venta que desea buscar: ";
//    cin >> id;
//
//    Venta venta;
//    venta.buscarVentaID(id); // Llama al método de la clase Venta
//    system("pause");
//    system("cls");
//}

int TipoBusqueda(){
    int opcion;

    do{
        cout << "Seleccione el tipo de búsqueda:" << endl;
        cout << "1. Buscar por DNI" << endl;
        cout << "2. Buscar por ID" << endl;
        cout << "3. Volver al menú anterior" << endl;
        cin >> opcion;

        switch (opcion){
        case 1:
            cout << "Has seleccionado buscar por DNI." << endl;
            break;
        case 2:
            cout << "Has seleccionado buscar por ID." << endl;
            break;
        case 3:
            cout << "Volviendo al menú anterior." << endl;
            break;
        default:
            cout << "Opción inválida. Por favor, ingrese una opción válida (1, 2 o 3)." << endl;
            opcion = 0; // Reseteamos `opcion` para continuar en el bucle
            break;
        }
    }
    while (opcion != 1 && opcion != 2 && opcion != 3);

    return opcion;
}

void clearLines(int numLines) {
for (int i = 0; i < numLines; ++i) {
        // Mueve el cursor hacia arriba
        cout << "\033[A";
        // Borra la l�nea actual
        cout << "\033[2K";
    }
    cout.flush();
}
