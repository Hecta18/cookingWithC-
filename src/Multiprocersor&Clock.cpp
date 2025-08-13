#include <iostream>
#include <unistd.h>
using namespace std;

int main() {
    for (int i = 0; i < 3; ++i) {
        pid_t pid = fork(); // Crear hijo

        if (pid < 0) {
            cerr << "Error al crear hijo." << endl;
            return 1;
        } else if (pid == 0) {
            // Proceso hijo
            for (int j = 0; j < 3; ++j) {
                cout << "Hijo " << i + 1 << " está chambeando." << endl;
                sleep(1); // Dormir 1 segundo
            }
            return 0;
        }
    }
    // Proceso padre
    cout << "El padre termino." << endl;
    return 0;
}
