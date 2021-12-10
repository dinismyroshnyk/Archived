#include <stdio.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 4.1
int main(){
  
    //begin_inputs

    float salario;
    printf("Introduza o seu salario: ");
    scanf("%f",&salario);

    //end_inputs

    if (salario <= 800) {
      printf("salario: %.2f - imposto: isento",salario);
    }
    else{
      if (salario <= 2000) {
        printf("salario: %.2f - imposto: %.2f",salario,(salario/100)*20);
      }
      else
        printf("salario: %.2f - imposto: %.2f",salario,(salario/100)*40);
    }

    return 0;
}
