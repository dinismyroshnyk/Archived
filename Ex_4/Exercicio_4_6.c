#include <stdio.h>
//@cikey 67361819476f1ac99dde38b453a6db17
//@sid 2021157297
//@aid 4.6
int main(){

	//begin_inputs

  int dia_semana,idade;
  printf("Introduza o dia da semana: \n");
  printf("1-Domingo\n2-Segunda\n3-Terca\n4-Quarta\n5-Quinta\n6-Sexta\n7-Sabado\n\n");
  scanf("%d",&dia_semana);
  printf("\nIntroduza a sua idade em anos: \n\n");
  scanf("%d",&idade);

	//end_inputs

  float ingresso = 10;

  switch (dia_semana) {
    case 1:
    if (idade>120 || idade<0) {
      printf("\nIdade invalida");
    } else {
      if (idade>=65 || idade<=12) {
        ingresso = (ingresso*0.5)-((ingresso*0.5)*0.4);
        printf("\ndia da semana: domingo - idade: %d - preco do ingresso: %.2f euros",idade,ingresso);
      } else {
        if (idade>=13 && idade<=20) {
          ingresso = (ingresso*0.5)-((ingresso*0.5)*0.25);
          printf("\ndia da semana: domingo - idade: %d - preco do ingresso: %.2f euros",idade,ingresso);
        } else {
          ingresso = ingresso*0.5;
          printf("\ndia da semana: domingo - idade: %d - preco do ingresso: %.2f euros",idade,ingresso);
        }
      }
    }
    break;
    case 5:
    if (idade>120 || idade<0) {
      printf("\nIdade invalida");
    } else {
      if (idade>=65 || idade<=12) {
        ingresso = (ingresso*0.5)-((ingresso*0.5)*0.4);
        printf("\ndia da semana: quinta-feira - idade: %d - preco do ingresso: %.2f euros",idade,ingresso);
      } else {
        if (idade>=13 && idade<=20) {
          ingresso = (ingresso*0.5)-((ingresso*0.5)*0.25);
          printf("\ndia da semana: quinta-feira - idade: %d - preco do ingresso: %.2f euros",idade,ingresso);
        } else {
          ingresso = ingresso*0.5;
          printf("\ndia da semana: quinta-feira - idade: %d - preco do ingresso: %.2f euros",idade,ingresso);
        }
      }
    }
    break;
    case 2:
    if (idade>120 || idade<0) {
      printf("\nIdade invalida");
    } else {
      if (idade>=65 || idade<=12) {
        ingresso = ingresso-(ingresso*0.4);
        printf("\ndia da semana: segunda-feira - idade: %d - preco do ingresso: %.2f euros",idade,ingresso);
      } else {
        if (idade>=13 && idade<=20) {
          ingresso = ingresso-(ingresso*0.25);
          printf("\ndia da semana: segunda-feira - idade: %d - preco do ingresso: %.2f euros",idade,ingresso);
        } else {
          printf("\ndia da semana: segunda-feira - idade: %d - preco do ingresso: %.2f euros",idade,ingresso);
        }
      }
    }
    break;
    case 3:
    if (idade>120 || idade<0) {
      printf("\nIdade invalida");
    } else {
      if (idade>=65 || idade<=12) {
        ingresso = ingresso-(ingresso*0.4);
        printf("\ndia da semana: terca-feira - idade: %d - preco do ingresso: %.2f euros",idade,ingresso);
      } else {
        if (idade>=13 && idade<=20) {
          ingresso = ingresso-(ingresso*0.25);
          printf("\ndia da semana: terca-feira - idade: %d - preco do ingresso: %.2f euros",idade,ingresso);
        } else {
          printf("\ndia da semana: terca-feira - idade: %d - preco do ingresso: %.2f euros",idade,ingresso);
        }
      }
    }
    break;
    case 4:
    if (idade>120 || idade<0) {
      printf("\nIdade invalida");
    } else {
      if (idade>=65 || idade<=12) {
        ingresso = ingresso-(ingresso*0.4);
        printf("\ndia da semana: quarta-feira - idade: %d - preco do ingresso: %.2f euros",idade,ingresso);
      } else {
        if (idade>=13 && idade<=20) {
          ingresso = ingresso-(ingresso*0.25);
          printf("\ndia da semana: quarta-feira - idade: %d - preco do ingresso: %.2f euros",idade,ingresso);
        } else {
          printf("\ndia da semana: quarta-feira - idade: %d - preco do ingresso: %.2f euros",idade,ingresso);
        }
      }
    }
    break;
    case 6:
    if (idade>120 || idade<0) {
      printf("\nIdade invalida");
    } else {
      if (idade>=65 || idade<=12) {
        ingresso = ingresso-(ingresso*0.4);
        printf("\ndia da semana: sexta-feira - idade: %d - preco do ingresso: %.2f euros",idade,ingresso);
      } else {
        if (idade>=13 && idade<=20) {
          ingresso = ingresso-(ingresso*0.25);
          printf("\ndia da semana: sexta-feira - idade: %d - preco do ingresso: %.2f euros",idade,ingresso);
        } else {
          printf("\ndia da semana: sexta-feira - idade: %d - preco do ingresso: %.2f euros",idade,ingresso);
        }
      }
    }
    break;
    case 7:
    if (idade>120 || idade<0) {
      printf("\nIdade invalida");
    } else {
      if (idade>=65 || idade<=12) {
        ingresso = ingresso-(ingresso*0.4);
        printf("\ndia da semana: sabado - idade: %d - preco do ingresso: %.2f euros",idade,ingresso);
      } else {
        if (idade>=13 && idade<=20) {
          ingresso = ingresso-(ingresso*0.25);
          printf("\ndia da semana: sabado - idade: %d - preco do ingresso: %.2f euros",idade,ingresso);
        } else {
          printf("\ndia da semana: sabado - idade: %d - preco do ingresso: %.2f euros",idade,ingresso);
        }
      }
    }
    break;
    default:
      printf("\nDia da semana invalido");
  }

	return 0;
}

//otimizar
