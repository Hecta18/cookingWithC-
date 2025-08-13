#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main() {
    pid_t pid_hijo = fork();

    if (pid_hijo < 0) {
        cerr << "Error al crear hijo." << endl;
        return 1;
    } else if (pid_hijo == 0) {
        // Proceso hijo
        cout << "Soy hijo. Mi PID es: " << getpid() << ", PID de mi padre: " << getppid() << endl;
        
        pid_t pid_nieto = fork(); // Crear nieto

        if (pid_nieto < 0) {
            cerr << "Error al crear nieto." << endl;
            return 1;
        } else if (pid_nieto == 0) {
            // Proceso nieto
            cout << "Soy nieto. Mi PID es: " << getpid() << ", PID de mi padre: " << getppid() << endl;
            sleep(2); // Dormir 2 segundos
            return 0;
        } else {
            // Hijo espera al nieto
            wait(NULL);
            return 0;
        }
    } else {
        // Proceso padre
        wait(NULL); // Esperar al hijo
        cout << "Descendencia ha terminado." << endl;
    }
    return 0;
}