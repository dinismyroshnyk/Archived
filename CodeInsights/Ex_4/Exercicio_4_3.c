#include <stdio.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 4.3
int main(){

	//begin_inputs

  int horas,minutos,segundos;
  printf("Introduza uma hora  valida: \n");
  scanf("%d%d%d",&horas,&minutos,&segundos);

	//end_inputs

  if (horas > 23 || horas < 0) {
    printf("%02d:%02d:%02d : hora invalida",horas,minutos,segundos);
  }
  else {
    if (minutos > 59 || minutos < 0) {
      printf("%02d:%02d:%02d : hora invalida",horas,minutos,segundos);
    }
    else {
      if (segundos > 59 || segundos < 0) {
        printf("%02d:%02d:%02d : hora invalida",horas,minutos,segundos);
      }
      else {
        printf("%02d:%02d:%02d : hora valida",horas,minutos,segundos);
      }
    }
  }

	return 0;
}
