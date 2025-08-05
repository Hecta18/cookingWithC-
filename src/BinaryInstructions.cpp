#include <iostream>
#include <sstream>// Para manejar cadenas de entrada
#include <vector>
#include <cmath>// Para operaciones matemáticas
#include <iomanip>// Para formateo de salida

using namespace std;

// Funciones para operaciones
int suma(int a, int b) {
    return a + b;
}

int resta(int a, int b) {
    return a - b;
}

int multiplicacion(int a, int b) {
    return a * b;
}

double division(int a, int b) {
    if (b == 0) {
        throw runtime_error("Error: División por cero");
        // Excepcion division por cero
    }
    return static_cast<double>(a) / b;
    // Convertir a double para evitar división entera
}

double potencia(int a, int b) {
    return pow(a, b);// de cmath
}

int modulo(int a, int b) {
    return a % b;
}

// Función para decodificar la instrucción
void decodificarInstruccion(const string& instruccion) {// Usar referencia para evitar copia innecesaria
    if (instruccion.length() != 8) {
        cout << "Error: Instrucción inválida " << instruccion << endl;
        return;
    }

    // Extraer bits
    int opcode = (instruccion[0] - '0') * 2 + (instruccion[1] - '0');
    // Convertir caracteres '0' y '1' a enteros 0 y 1
    // Multiplicar por 2 porque es el bit más significativo
    int mod = (instruccion[2] - '0') * 2 + (instruccion[3] - '0');
    int a = (instruccion[4] - '0') * 2 + (instruccion[5] - '0');
    int b = (instruccion[6] - '0') * 2 + (instruccion[7] - '0');

    // Intercambiar A y B si MOD es 11
    if (mod == 3) {
        swap(a, b);
    }

    // Realizar operación según OPCODE
    double resultado;
    switch (opcode) {
        case 0: // Suma
            resultado = suma(a, b);
            cout << "→ Resultado: " << a << " + " << b << " = " << resultado << endl;
            break;
        case 1: // Resta
            resultado = resta(a, b);
            cout << "→ Resultado: " << a << " - " << b << " = " << resultado << endl;
            break;
        case 2: // Multiplicación
            resultado = multiplicacion(a, b);
            cout << "→ Resultado: " << a << " * " << b << " = " << resultado << endl;
            break;
        case 3: // División
            try {
                resultado = division(a, b);
                cout << "→ Resultado: " << a << " / " << b << " = " << resultado << endl;
            } catch (const runtime_error& e) {// manejo de excepcion
                cout << e.what() << " en instrucción " << instruccion << endl;
            }
            break;
    }

    // Aplicar MOD
    if (mod == 1) { // Potencia
        resultado = potencia(a, b);
        cout << "→ Resultado: " << a << "^" << b << " = " << resultado << endl;
    } else if (mod == 2) { // Modulo
        resultado = modulo(a, b);
        cout << "→ Resultado: " << a << " mod " << b << " = " << resultado << endl;
    }
}

int main() {
    string input;
    cout << "Ingrese las instrucciones binarias (separadas por espacios): ";
    getline(cin, input);// Leer toda la línea de entrada
    istringstream is(input);// Crear un flujo de entrada a partir de la cadena
    string instruccion;

    while (is >> instruccion) {// Extraer cada instrucción del flujo separada por espacio
        cout << "→ Instrucción: " << instruccion << endl;
        decodificarInstruccion(instruccion);
    }

    return 0;
}