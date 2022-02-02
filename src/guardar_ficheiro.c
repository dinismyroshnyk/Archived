#ifndef _GUARDAR_FICHEIRO_
    #define _GUARDAR_FICHEIRO_

    #include <stdio.h>
    #include <stdlib.h>

    #define MAX_TAREFAS 100

    void guardarFicheiro(int tarefas[MAX_TAREFAS][2], int data[MAX_TAREFAS][3], char descricaoTarefa[MAX_TAREFAS][52]){

        FILE * ffinal;

        char ficheiro[] = "tarefas";

        ffinal = fopen(ficheiro, "a");
        if (ffinal == NULL)
        {
            printf("Ocorreu um erro ao criar/aceder o ficheiro");
            exit(1);
        }

        for (int i = 0; i < MAX_TAREFAS; i++)
        {
            if (descricaoTarefa[i][0] != NULL)
            {
                fprintf(ffinal, "%d %d %02d/%02d/%04d %s\n",tarefas[i][0], tarefas[i][1], data[i][0], data[i][1], data[i][2], descricaoTarefa[i]);
            }
        }
        
        fclose(ffinal);

        printf("As tarefas foram guardadas com sucesso ...");

    }

#endif