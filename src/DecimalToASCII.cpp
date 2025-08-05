#include <iostream>
#include <iomanip>
using namespace std;

void mostrarTablaASCII() {
    cout << "Tabla ASCII:\n";
    for (int i = 33; i < 127; i++) {
        cout << i << ": " << static_cast<char>(i) << endl;
        // static_cast<char>(i) convierte el número a su carácter ASCII
    }
}

int main() {
    int opcion;
    cout << "Menú:\n1. Ver tabla ASCII completa\n2. Convertir número\nSeleccione una opción: ";
    cin >> opcion;

    if (opcion == 1) {
        mostrarTablaASCII();
    } else if (opcion == 2) {
        int numero;
        cout << "Ingrese un número entre 33 y 126: ";
        cin >> numero;

        // Validación de entrada
        if (numero < 33 || numero > 126) {
            cout << "Error: Número fuera de rango." << endl;
        } else {
            cout << "El carácter ASCII correspondiente es: " << static_cast<char>(numero) << endl;
        }
    } else {
        cout << "Opción no válida." << endl;
    }

    return 0;
}