#ifndef _DATA_LIMITE_
    #define _DATA_LIMITE_

        #include <stdio.h>

        int dataValida(int dia, int mes, int ano);
        int numDiasMes(int mes, int ano);
        int bissexto(int ano);

        void data_limite(int *dia, int *mes, int *ano){

            printf("Introduza a data limite para a tarefa (dd-mm-aaaa):\n\n");
            scanf("%d%d%d",&*dia,&*mes,&*ano);

            bissexto(*ano);
            numDiasMes(*mes,bissexto(*ano));
            dataValida(*dia,*mes,*ano);

            if (dataValida(*dia,*mes,*ano) == 1)
            {
                printf("\nTarefa adicionada com sucesso ...");
                fflush(stdin);
                getchar();
                fflush(stdin);
            }
            else
            {
                system("cls");
                printf("Data invalida ...\n");
                fflush(stdin);
                getchar();
                fflush(stdin);
                system("cls");
            }
            
                        

        }

        int bissexto(int ano){

            if ((ano%4 == 0  && ano%100 != 0) || ano%400==0)
            {
                return 1;
            }
            else return 0;        
            
        }

        int numDiasMes(int mes,int ano){

            switch (mes)
            {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:

                    return 31;

                    break;
                
                case 2:

                    if (ano == 1)
                    {
                        return 29;
                    }
                    else return 28;
                    
                    break;

                case 4:
                case 6:
                case 9:
                case 11:

                    return 30;

                    break;

                default: return 0;
                    break;
            }
        }

        int dataValida(int dia,int mes,int ano){

            if (ano < 1583)
            {
                return 0;
            }
            else
            {
                if (mes < 1 || mes > 12)
                {
                    return 0;
                }
                else
                {
                    if (dia > numDiasMes(mes,bissexto(ano)) || dia <= 0)
                    {
                        return 0;
                    }
                    else
                    {
                        return 1;
                    }
                    
                }   
            }   
        }

#endif