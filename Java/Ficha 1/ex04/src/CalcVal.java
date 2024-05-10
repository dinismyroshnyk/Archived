import java.util.Arrays;
import java.util.Scanner;

public class CalcVal {
    public static void main(String[] args) {
        // Pedir 3 valores inteiros ao usuário
        int val1 = pedirValor("Digite o primeiro valor: ");
        int val2 = pedirValor("Digite o segundo valor: ");
        int val3 = pedirValor("Digite o terceiro valor: ");

        // Calcular a soma
        int soma = calcularSoma(val1, val2, val3);

        // Calcular a média
        float media = calcularMedia(soma);

        // Calcular o maior o menor valor
        int maior = calcularMaior(val1, val2, val3);
        int menor = calcularMenor(val1, val2, val3);

        // Imprimir os resultados
        imprimirResultados(soma, media, maior, menor);
    }

    private static int pedirValor(String aVal) {
        System.out.print(aVal);
        return new Scanner(System.in).nextInt();
    }

    private static int calcularSoma(int aVal1, int aVal2, int aVal3) {
        return aVal1 + aVal2 + aVal3;
    }

    private static float calcularMedia(int soma) {
        return (float)soma / 3;
    }

    private static int calcularMaior(int aVal1, int aVal2, int aVal3) {
        int[] vetor = {aVal1, aVal2, aVal3};
        return Arrays.stream(vetor).max().getAsInt();
    }

    private static int calcularMenor(int aVal1, int aVal2, int aVal3) {
        int[] vetor = {aVal1, aVal2, aVal3};
        return Arrays.stream(vetor).min().getAsInt();
    }

    private static void imprimirResultados(int soma, float media, int maior, int menor) {
        System.out.println("Soma: " + soma);
        System.out.println("Média: " + media);
        System.out.println("Maior: " + maior);
        System.out.println("Menor: " + menor);
    }
}