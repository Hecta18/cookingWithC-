#include <iostream>
using namespace std;

double calcularUtilidad(int cantidad, double costo, double precio) {
    return (precio - costo) * cantidad;
}

int main() {
    int cantidad;
    double costo, precio;

    cout << "Ingrese la cantidad vendida: ";
    cin >> cantidad;
    cout << "Ingrese el costo por unidad: ";
    cin >> costo;
    cout << "Ingrese el precio de venta por unidad: ";
    cin >> precio;

    // Validar que todos los valores sean positivos
    if (cantidad <= 0 || costo < 0 || precio < 0) {
        cout << "Error: Todos los valores deben ser positivos." << endl;
        return 1;
    }

    double utilidad = calcularUtilidad(cantidad, costo, precio);
    cout << "Utilidad total: Q" << utilidad << endl;

    return 0;
}