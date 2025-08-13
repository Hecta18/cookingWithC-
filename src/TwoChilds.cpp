#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main() {
    pid_t pid1 = fork(); // Primer hijo

    if (pid1 < 0) {
        cerr << "Error en creacion." << endl;
        return 1;
    } else if (pid1 == 0) {
        // Hijo 1: contar del 1 al 5
        for (int i = 1; i <= 5; ++i) {
            cout << "Hijo 1: " << i << endl;
            sleep(1);
        }
        return 0;
    } else {
        pid_t pid2 = fork(); // Crear segundo hijo

        if (pid2 < 0) {
            cerr << "Error en creacion." << endl;
            return 1;
        } else if (pid2 == 0) {
            // Hijo 2: imprimir letras de A a E
            for (char c = 'A'; c <= 'E'; ++c) {
                // Uso ASCII
                cout << "Hijo 2: " << c << endl;
                sleep(1);
            }
            return 0;
        } else {
            // Proceso padre
            wait(NULL); // Esperar al hijo 1 
            wait(NULL); // Esperar al hijo 2 
            cout << "Ambos hijos han terminado." << endl;
        }
    }
    return 0;
}
