import java.util.Scanner;

class Principal {
    public static void main(String[] args) {
        do {
            // Criação de um estudante
            Estudante est = criaEstudante();

            // Atualizar notas
            atualizarNotas(est);

            // Apresentar informação
            System.out.println(est);
        } while(continuar());
    }

    private static Estudante criaEstudante(){
        return new Estudante(
                leDadosString("Introduza o nome: "),
                leDadosInt("Introduza o numero: ")
        );
    }

    private static void atualizarNotas(Estudante aEstudante){
        aEstudante.setNotas(
                leDadosInt("Introduza nota1: "),
                leDadosInt("Introduza nota2: "),
                leDadosInt("Introduza nota3: ")
        );
        aEstudante.calculaMedia(
                leDadosInt("Introduza o peso: ")
        );
    }

    private static String leDadosString(String aMensagem){
        System.out.print(aMensagem);
        return new Scanner(System.in).nextLine();
    }

    private static int leDadosInt(String aMensagem){
        while (true){
            try {
                return Integer.parseInt(leDadosString(aMensagem));
            } catch (NumberFormatException nfe) {
                System.out.println("Apenas pode inserir dígitos");
            }
        }
    }

    private static boolean continuar(){
        return switch (leDadosString("Continuar? (s/n) ").toLowerCase()) {
            case "n", "não", "nao" -> false;
            case "s", "sim" -> true;
            default -> continuar();
        };
    }
}
