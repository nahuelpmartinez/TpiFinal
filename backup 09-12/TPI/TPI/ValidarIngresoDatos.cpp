#include <iostream>
#include <cstring>
#include <cctype>
#include "Menu.h"

using namespace std;

bool validarEmail(const char* email){// No lo pondria en MENU

    // Buscar el primer '@'
    const char* at = strchr(email, '@');

    // Buscar el primer '.' después del '@'
    const char* dot = at ? strchr(at, '.') : nullptr;

    // Comprobar que '@' y '.' existan y estén en las posiciones correctas
    if (at && dot && (dot > at + 1) && (at > email) && (dot < email + strlen(email) - 1)){
        return true;
    }
    return false;
}

void validarNombres(char* nombres) {
    bool validar;

    do {
        cout << "Ingrese el Nombre/s: ";
        cin.ignore();
        cin.getline(nombres, 50);  // Solicita ingreso de nombres con límite de 50 caracteres

        validar = true;
        int espacioCount = 0;

        for (int i = 0; i < (int)strlen(nombres); i++) {
            if (isalpha(nombres[i])) {
                continue;  // Es letra, es válido
            }
            else if (nombres[i] == ' ') {
                espacioCount++;  // Cuenta los espacios
                if (espacioCount > 1) {  // Solo se permite un espacio
                    validar = false;
                    break;
                }
            }
            else {
                validar = false;  // Si no es letra ni espacio, no es válido
                break;
            }
        }

        if (!validar || strlen(nombres) == 0) {
            cout << "Dato ingresado no válido. Solo debe contener letras. Intente de nuevo." << endl;
            system("pause");
            system("cls");
        }
    } while (!validar || strlen(nombres) == 0);  // Repite hasta que sea válido
}




