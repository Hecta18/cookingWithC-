#include <iostream>
#include <iomanip>
using namespace std;

struct Persona {
    char sexo; // 'M' o 'F'
    double peso; // kg
    double altura; // m
};

double calcularGrasa(Persona p) {
    double grasa;
    if (p.sexo == 'M') {
        grasa = (1.20 * (p.peso / (p.altura * p.altura))) + (0.23 * 25) - 16.2; // 25 es la edad
    } else if (p.sexo == 'F') {
        grasa = (1.20 * (p.peso / (p.altura * p.altura))) + (0.23 * 25) - 5.4; // 25 es la edad
    }
    return grasa;
}

int main() {
    Persona p;
    cout << "Ingrese el sexo (M/F): ";
    cin >> p.sexo;
    p.sexo = toupper(p.sexo); 
    // toupper para convertir a mayúscula, para facilitar validación

    // Validar sexo
    if (p.sexo != 'M' && p.sexo != 'F') {
        cout << "Error: Sexo inválido. Debe ser 'M' o 'F'." << endl;
        return 1;
    }

    cout << "Ingrese el peso (kg): ";
    cin >> p.peso;
    cout << "Ingrese la altura (m): ";
    cin >> p.altura;

    // Calcular y mostrar el porcentaje de grasa corporal
    double grasa = calcularGrasa(p);
    cout << "Porcentaje de grasa corporal: " << fixed << setprecision(2) << grasa << "%" << endl;
    // fixed y setprecision(2) para mostrar dos decimales

    return 0;
}