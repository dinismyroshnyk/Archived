class Local {
    private String designacao;
    private String morada;
    private int telefone;

    Local(){
        designacao = "sem valor definido";
        morada = "sem valor definido";
        telefone = -1;
    }

    public void setMorada(String aMorada){
        morada = aMorada;
    }

    public int getTelefone(){
        return telefone;
    }

    public String toString(){
        return "realizado em " + designacao + ", na morada " + morada;
    }
}
