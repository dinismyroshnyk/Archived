#ifndef _MENU_TAREFAS_
    #define _MENU_TAREFAS_
        #include <stdio.h>
        #include <stdlib.h>
#endif

void menuTarefas(int opcao_sub){
    do
    {
        system("cls");

        printf("=======================================\n");
        printf("               TAREFAS\n");
        printf("=======================================\n\n");
        printf("1 - Consultar as tarefas\n");
        printf("2 - Consultar as tarefas nao concluidas\n");
        printf("3 - Consultar tarefas em atraso\n");
        printf("4 - Resumo do estado das tarefas\n");
        printf("0 - Voltar\n\n");

        printf("Opcao: ");
        scanf("%d", &opcao_sub);

        switch (opcao_sub)
        {
        case 1:
            /* code */
            break;

        case 2:
            /* code */
            break;					
        
        case 3:
            /* code */
            break;

        case 4:
            /* code */
            break;

        case 0:
            break;

        default: printf("\nOpcao invalida\n");
            break;
        }

        if (opcao_sub != 0)
        {
            printf("\nPressione Enter para voltar ...");
            fflush(stdin);
            getchar();
        }

    } while (opcao_sub != 0);
}