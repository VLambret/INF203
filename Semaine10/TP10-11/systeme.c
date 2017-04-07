#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

#include "systeme.h"
#include "common.h"
#include "gestion_path.h"

int executer_ligne_decoupee(char *ligne_decoupee[]) {
    pid_t pid;
    int stat_loc;
    char *commande;
    int i;
    commande = trouver_commande(ligne_decoupee[0]);

    switch (pid = fork()) {
    case -1:
        fprintf(stderr,"Erreur dans execute : erreur de fork\n");
        return -1;
    case 0:
        debug(printf("Execution de :"));
        i = 0;
        while(ligne_decoupee[i] != NULL) {
            debug(printf(" %s", ligne_decoupee[i]));
            i++;
        }
        debug(printf("\n"));
        execv(commande, ligne_decoupee);
        perror("Erreur d'exec");
        exit(-1);
    default:
        wait(&stat_loc);
        debug(printf("Code de retour de la commande : %d\n", stat_loc));
        if (WIFEXITED(stat_loc)) {
            return WEXITSTATUS(stat_loc);
        } else {
            fprintf(stderr,"Commande terminee par un signal : anormal\n");
            return WTERMSIG(stat_loc);
        }
    }
}
