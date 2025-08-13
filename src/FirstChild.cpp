#include <iostream>
#include <unistd.h> //solo para unix
#include <sys/wait.h>
using namespace std;

int main() {
    pid_t pid = fork(); // Crear un hijo

    if (pid < 0) {
        cerr << "Error al crear hijo." << endl;
        return 1;
    } else if (pid == 0) {
        // Proceso hijo
        cout << "PID del hijo: " << getpid() << ", PID del padre: " << getppid() << endl;
        sleep(3); // Pausa de 3 segundos
        return 0;
    } else {
        // Proceso padre
        wait(NULL); // Esperar que el hijo termine
        // Padre se bloquea hasta que todos los hijos terminen
        cout << "El proceso hijo ha terminado." << endl;
    }
    return 0;
}
