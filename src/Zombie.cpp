#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main() {
    pid_t pid = fork(); // Crear un hijo

    if (pid < 0) {
        cerr << "Error al crear hijo." << endl;
        return 1;
    } else if (pid == 0) {
        // Proceso hijo
        cout << "Soy el hijo. Mi PID es: " << getpid() << endl;
        return 0; // Terminar rápidamente
    } else {
        // Proceso padre
        sleep(10); // Dormir 10 segundos sin llamar a wait()
        cout << "El padre ha terminado." << endl;
    }

    return 0;
}
// Al no llamar a wait(), el hijo termina 
// pero su entrada en la tabla de procesos permanece, 
// creando un proceso zombie.