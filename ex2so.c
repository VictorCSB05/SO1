#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();  // Cria um processo filho

    if (pid == 0) {  // Processo filho
        printf("Sou o processo filho. Meu PID é %d.\n", getpid());
        for (int i = 0; i < 5; i++) {
            printf("Filho: Imprimindo mensagem %d\n", i + 1);
            sleep(1);  // Aguarda 1 segundo entre cada mensagem
        }
    } else if (pid > 0) {  // Processo pai
        wait(NULL);  // Aguarda o término do processo filho
        printf("Filho terminou. Sou o processo pai, PID %d.\n", getpid());
    } else {
        printf("Falha ao criar o processo filho.\n");
    }

    return 0;
}
