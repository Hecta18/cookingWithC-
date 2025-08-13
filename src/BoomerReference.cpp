#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int n;
    cout << "Ingrese la cantidad de hijos a crear (máximo 10): ";
    cin >> n;

    if (n < 1 || n > 10) {
        cerr << "Número no válido." << endl;
        return 1;
    }

    srand(time(0)); // Inicializar semilla para números aleatorios

    for (int i = 0; i < n; ++i) {
        pid_t pid = fork(); 

        if (pid < 0) {
            cerr << "Error al crear hijo." << endl;
            return 1;
        } else if (pid == 0) {
            // Proceso hijo
            int sleep_time = rand() % 5 + 1; // Dormir entre 1 y 5 segundos
            cout << "Soy el mijo " << (i + 1) << " mi PID " << getpid() << endl;
            sleep(sleep_time);
            return 0;
        }
    }

    // Proceso padre
    for (int i = 0; i < n; ++i) {
        wait(NULL); // Esperar a que todos los hijos terminen
    }
    cout << "Mis bendiciones terminaron." << endl;
    return 0;
}