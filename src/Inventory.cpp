#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Producto {
    string nombre;
    int stockInicial;
    int vendidos;
};

int main() {
    vector<Producto> inventario(10);
    
    // Ingresar datos de 10 productos
    for (int i = 0; i < 10; i++) {
        cout << "Ingrese el nombre del producto " << (i + 1) << ": ";
        // comenzar con 1
        cin >> inventario[i].nombre;
        cout << "Ingrese el stock inicial: ";
        cin >> inventario[i].stockInicial;
        cout << "Ingrese la cantidad vendidos: ";
        cin >> inventario[i].vendidos;
    }

    // Mostrar reporte tabular
    cout << left << setw(12) << "Producto"
    // Alineación a la izquierda
    // setw para definir el ancho de la columna
         << setw(10) << "Inicial" 
         << setw(10) << "Vendidos" 
         << setw(10) << "Restante" 
         << "Agotado" << endl;

    for (const auto& producto : inventario) {
        int restante = producto.stockInicial - producto.vendidos;
        cout << left << setw(12) << producto.nombre
             << setw(10) << producto.stockInicial 
             << setw(10) << producto.vendidos 
             << setw(10) << restante 
             << (restante <= 0 ? "Sí" : "No") << endl;
             // si o no agotado
    }

    return 0;
}