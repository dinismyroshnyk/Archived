#include <stdio.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 6.7

int diaDoAno(int dia, int mes, int ano);
int numDiasMes(int mes, int ano);
int bissexto(int ano);
int dataValida(int dia, int mes, int ano);
int main(){

	//begin_inputs

  int dia,mes,ano;
  printf("Introduza a data: \n");
  scanf("%d%d%d",&dia,&mes,&ano);

	//end_inputs

  bissexto(ano);
  numDiasMes(mes,bissexto(ano));
  dataValida(dia,numDiasMes(mes,bissexto(ano)),ano);
  diaDoAno(dia,mes,ano);

  if (dataValida(dia,numDiasMes(mes,bissexto(ano)),ano) == 1) {
    printf("data: %02d-%02d-%04d - numero do dia: %d",dia,mes,ano,diaDoAno(dia,mes,ano));
  } else{
    printf("data: %02d-%02d-%04d - invalida",dia,mes,ano);
  }

	return 0;
}

int bissexto(int ano){
  if ((ano%4 == 0  && ano%100 != 0) || ano%400==0) {
    return 1;
  } else {
    return 0;
  }
}

int numDiasMes(int mes,int ano){
  switch (mes) {
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
      if (ano == 1) {
          return 29;
      }else{
        return 28;
      }
    break;
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;
    default:
      return 0;
  }
}

int dataValida(int dia,int mes,int ano){
  if (dia > 0 && dia <= mes && ano > 1582) {
    return 1;
  } else{
    return 0;
  }
}

int diaDoAno(int dia,int mes,int ano){
  int contador = 0;
  for (; mes > 0; mes--) {
    contador += numDiasMes(mes-1,bissexto(ano));
  }
  contador += dia;
  return contador;
}
