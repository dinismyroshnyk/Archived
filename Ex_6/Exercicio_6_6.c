#include <stdio.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 6.6

int dataValida(int dia, int mes, int ano);
int numDiasMes(int mes, int ano);
int bissexto(int ano);
int dataValida1582(int dataValida,int ano,int mes,int dia);
int main(){

	//begin_inputs

  int dia,mes,ano;
  printf("Introduza a data (dd-mm-aaaa): \n");
  scanf("%d%d%d",&dia,&mes,&ano);

	//end_inputs

  bissexto(ano);
  numDiasMes(mes,bissexto(ano));
  dataValida(dia,mes,ano);

  if (dataValida(dia,mes,ano) == 1) {
    printf("data: %02d-%02d-%04d - valida",dia,mes,ano);
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
  if (ano < 1583) {
    return 0;
  }else{
    if (mes < 1 || mes > 12) {
      return 0;
    }else{
      if (dia > numDiasMes(mes,bissexto(ano)) || dia <= 0) {
        return 0;
      }else{
        return 1;
      }
    }
  }
}
