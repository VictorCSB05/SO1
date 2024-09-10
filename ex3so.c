#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();  // Cria um processo filho

    if (pid == 0) {  // Processo filho
        printf("Sou o processo filho. Meu PID é %d.\n", getpid());
        execlp("ls", "ls", "-l", NULL);  // Substitui o código do processo filho pelo comando ls
        printf("Erro ao executar o exec().\n");  // Caso exec() falhe
    } else if (pid > 0) {  // Processo pai
        wait(NULL);  // Aguarda o término do processo filho
        printf("Filho terminou. Sou o processo pai, PID %d.\n", getpid());
    } else {
        printf("Falha ao criar o processo filho.\n");
    }

    return 0;
}
