public class Frase {
    // Atributos
    private String frase;
    private int numeroDePalavras;
    private int numeroDeCaracteres;

    // Métodos
    private int contarPalavras() {
        return frase.split(" ").length;
    }

    private int contarCaracteres() {
        return frase.replace(" ", "").length();
    }

    // Construtores
    public Frase(String aFrase) {
        setFrase(aFrase);
    }
    // Getters e Setters
    public String getFrase() {
        return frase;
    }

    public int getNumeroDePalavras() {
        return numeroDePalavras;
    }

    public int getNumeroDeCaracteres() {
        return numeroDeCaracteres;
    }

    public void setFrase(String aNovaFrase) {
        frase = aNovaFrase;
        numeroDePalavras = contarPalavras();
        numeroDeCaracteres = contarCaracteres();
    }
}