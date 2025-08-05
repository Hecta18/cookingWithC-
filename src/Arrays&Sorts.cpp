#include <iostream>
#include <algorithm>// para usar sort
using namespace std;

int main() {
    int numeros[3];

    cout << "Ingrese tres números: ";
    for (int i = 0; i < 3; i++) {
        cin >> numeros[i];
        //ingresar numeros en array
    }

    // Ordenar los números
    sort(numeros, numeros + 3);
    // De mayor a menor

    cout << "Números en orden ascendente: ";
    for (int i = 0; i < 3; i++) {
        cout << numeros[i] << " ";
    }
    // imprimir elementos del array 
    cout << endl;

    return 0;
}