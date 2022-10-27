class Estagio {
    private int duracao;
    private Local local;
    private int classificacao;

    Estagio(){
        duracao = -1;
        local = new Local();
        classificacao = -1;
    }

    public void setClassificacao(int aClassificacao){
        classificacao = aClassificacao;
    }

    public  Local getLocal(){
        return local;
    }

    public String toString(){
        return "Estágio realizado em " + local + "com duração" + duracao;
    }
}
