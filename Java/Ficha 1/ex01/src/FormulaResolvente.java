import java.util.InputMismatchException;
import java.util.Scanner;

public class FormulaResolvente {
    public static void main(String[] args) {
        do {
            // Pedir os coeficientes ao usuário
            double coefA = lerCoeficientes("a");
            double coefB = lerCoeficientes("b");
            double coefC = lerCoeficientes("c");
            // Calcular e mostrar raízes (ax^2 + bx + c = 0)
            calcularRaizes(coefA, coefB, coefC);
        }while (continuar());
    }

    private static double lerCoeficientes(String aCoef){
        System.out.println("Introduza o coeficiente " +aCoef+ ": ");
        try {
            return new Scanner(System.in).nextInt();
        } catch (InputMismatchException e) {
            System.out.println("Introduza um número válido!");
            return lerCoeficientes(aCoef);
        }
    }

    private static void calcularRaizes(double aCoefA, double aCoefB, double aCoefC){
        double delta = Math.pow(aCoefB, 2) - 4 * aCoefA * aCoefC;
        if (delta < 0){
            System.out.println("A equação não tem raízes reais");
        } else if (delta == 0){
            double raiz = -aCoefB / (2 * aCoefA);
            System.out.println("A equação tem uma raiz real: " + raiz);
        } else {
            double raiz1 = (-aCoefB + Math.sqrt(delta)) / (2 * aCoefA);
            double raiz2 = (-aCoefB - Math.sqrt(delta)) / (2 * aCoefA);
            System.out.println("A equação tem duas raízes reais: " + raiz1 + " e " + raiz2);
        }
    }

    private static boolean continuar(){
        return switch (mensagemContinuar()) {
            case "s", "sim" -> true;
            case "n", "nao", "não" -> false;
            default -> continuar();
        };
    }

    private static String mensagemContinuar(){
        System.out.println("Deseja continuar?");
        return new Scanner(System.in).nextLine().toLowerCase();
    }
}