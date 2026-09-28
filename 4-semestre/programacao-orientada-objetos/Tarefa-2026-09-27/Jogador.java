/**
 * Representa um jogador de futebol, com seus dados pessoais e contratuais.
 */
public class Jogador {

    private String nome;
    private int idade;
    private String posicao;
    private float salario;
    private boolean contratado;

    public Jogador(String nome, int idade, String posicao, float salario, boolean contratado) {
        setNome(nome);
        setIdade(idade);
        setPosicao(posicao);
        setSalario(salario);
        setContratado(contratado);
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        if (idade <= 0) {
            throw new IllegalArgumentException("A idade do jogador deve ser maior que zero.");
        }
        this.idade = idade;
    }

    public String getPosicao() {
        return posicao;
    }

    public void setPosicao(String posicao) {
        this.posicao = posicao;
    }

    public float getSalario() {
        return salario;
    }

    public void setSalario(float salario) {
        if (salario < 0) {
            throw new IllegalArgumentException("O salário do jogador não pode ser negativo.");
        }
        this.salario = salario;
    }

    public boolean isContratado() {
        return contratado;
    }

    public void setContratado(boolean contratado) {
        this.contratado = contratado;
    }

    @Override
    public String toString() {
        return "Jogador{" +
                "nome='" + nome + '\'' +
                ", idade=" + idade +
                ", posicao='" + posicao + '\'' +
                ", salario=" + salario +
                ", contratado=" + contratado +
                '}';
    }
}
