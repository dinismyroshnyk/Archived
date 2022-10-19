import java.util.Scanner;

public class FormulaResolvente {
    public static void main(String[] args) {
        do {
            //pedir coeficientes
            int coefA = pedirCoeficiente("a");
            int coefB = pedirCoeficiente("b");
            int coefC = pedirCoeficiente("c");
            //calcular fatores
            double fator1 = calcularFator(coefA, coefB, coefC, true);
            double fator2 = calcularFator(coefA, coefB, coefC, false);
            //mostrar resultados
            mostrarResultados(fator1, fator2);
        }while (continuar());
        System.out.println("Adeus !");
    }

    static int pedirCoeficiente(String aCoef) {
        System.out.print("Introduza o coeficiente " + aCoef + ": ");
        return (new Scanner(System.in)).nextInt();
    }
    static double calcularFator(int aCoef, int bCoef, int cCoef, boolean aSinal) {
        double delta = Math.sqrt(Math.pow(bCoef, 2) - 4 * aCoef * cCoef);
        double fator = 0;
        if (!aSinal) delta = -delta;
        else fator = (-bCoef + delta / 2 / aCoef);
        return fator;
    }
    static void mostrarResultados(double factor1, double factor2) {
        System.out.println("x1 = " + factor1 + " x2 = " + factor2);
    }
    static boolean continuar(){
        System.out.println("Deseja continuar ? (S/N)");
        Scanner teclado = new Scanner(System.in);
        String resposta = teclado.nextLine();
        return resposta.equalsIgnoreCase("S");
    }
}