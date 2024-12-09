#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void MenuPrincipal();
void MenuVendedores();
void RegistrarVendedor();
void ListarVendedores();
void BuscarVendedor();
void EliminarVendedor();
void DescargarArchivoVendedores();
void ModificarVendedores();
void MenuClientes();
void RegistrarCliente();
void BuscarCliente();
void ListarClientes();
void EliminarCliente();
void DescargarArchivoClientes();
void ModificarClientes();
bool validarEmail(const char* email);
void MenuArticulos();
void RegistrarArticulo();
void BuscarArticulo();
void ListarArticulos();
void EliminarArticulo();
void DescargarArchivoArticulos();
void ModificarArticulo();
void MenuVentas();
void RegistrarVenta();
void ListarVentas();
void buscarVentaPorID();
void clearLines (int numLines);
void verDetalleDeVenta();
void exportarCsvVentas();


#endif // MENU_H_INCLUDED
