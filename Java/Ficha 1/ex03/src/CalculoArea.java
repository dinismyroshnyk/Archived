import java.util.InputMismatchException;
import java.util.Scanner;

public class CalculoArea {
    public static void main(String[] args) {
        // Pedir ao usuário as dimensões para as paredes, janelas e portas e a quantidade de tinta disponível
        float alturaParede = pedirDimensoes("altura da parede");
        float larguraParede = pedirDimensoes("largura da parede");
        float alturaJanela = pedirDimensoes("altura das janelas");
        float larguraJanela = pedirDimensoes("largura das janelas");
        float alturaPorta = pedirDimensoes("altura das portas");
        float larguraPorta = pedirDimensoes("largura das portas");
        float quantidadeTinta = pedirDimensoes("quantidade de tinta disponível");

        // Calcular a área da parede
        float areaParede = calcularAreaParede(alturaParede, larguraParede, alturaJanela, larguraJanela, alturaPorta, larguraPorta);

        // Apresentar a área ao usuário e dizer se é possível pintar ou não
        apresentarResultado(areaParede, quantidadeTinta);
    }

    private static float pedirDimensoes(String aDimensao) {
        if (aDimensao.equals("quantidade de tinta disponível")) {
            System.out.println("Introduza a " + aDimensao + " (L): ");
        } else {
            System.out.println("Introduza a " + aDimensao + " (m): ");
        }
        try {
            float teclado = new Scanner(System.in).nextFloat();
            if (teclado < 0) {
                System.out.println("Dimensão inválida");
                return pedirDimensoes(aDimensao);
            } else {
                return teclado;
            }
        } catch (InputMismatchException ime) {
            System.out.println("Introduza um número!");
            return pedirDimensoes(aDimensao);
        }
    }

    private static float calcularAreaParede(float alturaParede, float larguraParede, float alturaJanela, float larguraJanela, float alturaPorta, float larguraPorta) {
        if (alturaParede < alturaJanela || larguraParede < larguraJanela || alturaParede < alturaPorta || larguraParede < larguraPorta) {
            System.out.println("Dimensões inválidas");
            return 0;
        } else return (alturaParede * larguraParede) - (alturaJanela * larguraJanela * 8) - (alturaPorta * larguraPorta * 2);
    }

    private static void apresentarResultado(float areaParede, float quantidadeTinta) {
        if (areaParede == 0) {
            System.out.println("Não é possível pintar a parede");
        } else {
            System.out.println("A área das paredes é " + areaParede + " m2");
            if (areaParede > quantidadeTinta * 20) {
                System.out.println("Não é possível pintar as paredes");
            } else {
                System.out.println("É possível pintar a parede");
            }
        }
    }
}