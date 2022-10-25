import java.util.InputMismatchException;
import java.util.Scanner;

public class NotaFinal {
    public static void main(String[] args) {
        // Pedir as notas dos 2 trabalhos e 2 projetos ao usuário
        int trab1 = pedirNotas("trabalho 1");
        int trab2 = pedirNotas("trabalho 2");
        int proj1 = pedirNotas("projeto 1");
        int proj2 = pedirNotas("projeto 2");

        // Calcular as notas
        float notaFinal = calcularNotas(trab1, trab2, proj1, proj2);

        // Apresentar as notas ao usuário
        apresentarNotas(notaFinal);
    }

    private static int pedirNotas(String aNota) {
        System.out.println("Introduza a nota do " + aNota + " (0-100): ");
        try {
            int teclado = new Scanner(System.in).nextInt();
            if (teclado < 0 || teclado > 100) {
                System.out.println("Nota inválida");
                return pedirNotas(aNota);
            } else {
                return teclado;
            }
        } catch (InputMismatchException ime) {
            System.out.println("Introduza um número inteiro!");
            return pedirNotas(aNota);
        }
    }

    private static float calcularNotas(int aTrab1, int aTrab2, int aProj1, int aProj2) {
        return (aTrab1 * 0.15f) + (aTrab2 * 0.15f) + (aProj1 * 0.35f) + (aProj2 * 0.35f);
    }

    private static void apresentarNotas(float aNotaFinal) {
        System.out.println("A nota final é: " + aNotaFinal);
    }
}