import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Frase aMinhaFrase = new Frase(lerFrase());
        escreverFrase(aMinhaFrase);
    }

    private static String lerFrase() {
        System.out.println("Introduza uma frase: ");
        return new Scanner(System.in).nextLine();
    }

    private static void escreverFrase(Frase aFrase) {
        System.out.println("A frase é: " + aFrase.getFrase());
        System.out.println("A frase tem " + aFrase.getNumeroDePalavras() + " palavras.");
        System.out.println("A frase tem " + aFrase.getNumeroDeCaracteres() + " caracteres.");
    }
}