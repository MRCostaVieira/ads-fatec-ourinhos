/**
 * Representa o técnico responsável por um time de futebol.
 */
public class Tecnico {

    private String nome;
    private int idade;
    private float salario;
    private int anosDeExperiencia;

    public Tecnico(String nome, int idade, float salario, int anosDeExperiencia) {
        setNome(nome);
        setIdade(idade);
        setSalario(salario);
        setAnosDeExperiencia(anosDeExperiencia);
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
        if (idade <= 18) {
            throw new IllegalArgumentException("A idade do técnico deve ser maior que dezoito.");
        }
        this.idade = idade;
    }

    public float getSalario() {
        return salario;
    }

    public void setSalario(float salario) {
        if (salario < 0) {
            throw new IllegalArgumentException("O salário do técnico não pode ser negativo.");
        }
        this.salario = salario;
    }

    public int getAnosDeExperiencia() {
        return anosDeExperiencia;
    }

    public void setAnosDeExperiencia(int anosDeExperiencia) {
        this.anosDeExperiencia = anosDeExperiencia;
    }

    @Override
    public String toString() {
        return "Tecnico{" +
                "nome='" + nome + '\'' +
                ", idade=" + idade +
                ", salario=" + salario +
                ", anosDeExperiencia=" + anosDeExperiencia +
                '}';
    }
}
