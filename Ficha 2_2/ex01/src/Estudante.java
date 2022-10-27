public class Estudante {
    // Atributos
    // Atributos de instância
    private String nome;
    private int numero;
    private int nota1;
    private int nota2;
    private int nota3;
    private float media;
    private Estagio estagio;

    // Atributos de Class
    private static int contador = 0;

    //Construtores
    public Estudante(String aNome, int aNumero) {
        nome = aNome;
        numero = aNumero;
    }

    public Estudante(String aNome){
        this(aNome, contador++);
    }

    public Estudante(){
        this("Sem nome");
    }

    // Ações / métodos
    // Métodos de instância
    public String getNome(){
        return nome;
    }

    public void setNumero(int aNumero) {
        numero = aNumero;
    }

    public void setNotas(int aNota1, int aNota2, int aNota3) {
        nota1 = aNota1;
        nota2 = aNota2;
        nota3 = aNota3;
    }

    public void calculaMedia(int aPeso) {
        try {
            media = (nota1 + nota2 + nota3) / aPeso;
        } catch (ArithmeticException ae) {
            ae.printStackTrace();
            calculaMedia(1);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public String toString() {
        String output= "Estudante com nome '"+nome+"' e numero: "+numero+" com estágio em"+estagio;
        if(media != 0) output += " com media "+media;
        else output += " sem media";
        return output;
    }

    //Método de Class
    public static int lerContador() {
        return contador;
    }
}