#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();  // Cria um processo filho

    if (pid == 0) {  // Processo filho
        printf("Sou o processo filho. Meu PID é %d.\n", getpid());
        for (int i = 0; i < 5; i++) {
            printf("Filho: Imprimindo mensagem %d\n", i + 1);
            sleep(1);  // Aguarda 1 segundo entre cada mensagem
        }
    } else if (pid > 0) {  // Processo pai
        printf("Sou o processo pai. Meu PID é %d e o PID do meu filho é %d.\n", getpid(), pid);
    } else {
        printf("Falha ao criar o processo filho.\n");
    }

    return 0;
}
