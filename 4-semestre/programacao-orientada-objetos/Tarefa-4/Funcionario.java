public class Funcionario {

    static int ID = 1;

    private int id;
    private String nome;
    private String cpf;
    private String nomeCargo;
    private String departamento;
    private double salarioBase;

    public Funcionario(String nome, String cpf) {
        this.id = ID;
        this.nome = nome;
        this.cpf = cpf;
        this.nomeCargo = "cargo";
        this.departamento = "empresa";
        this.salarioBase = 1500.00;

        ID++;
    }

    public Funcionario(String nome, String cpf, String nomeCargo, String departamento, double salarioBase) {
        this.nome = nome;
        this.cpf = cpf;
        this.nomeCargo = nomeCargo;
        this.departamento = departamento;
        this.salarioBase = salarioBase;

        ID++;
    }

    public double calculaGanhoAnual() {
        return this.salarioBase * 12;
    }

    public double calculaINSS() {
        return this.salarioBase * 0.08;
    }

    public double calculaFérias() {
        return this.salarioBase * 0.33;
    }

    public double calcularIR() {
        double baseCalculo = this.salarioBase - this.calculaINSS();

        if (baseCalculo <= 2259.20) {
            return 0.0;
        } else if (baseCalculo <= 2826.65) {
            return baseCalculo * 0.075 - 169.44;
        } else if (baseCalculo <= 3751.05) {
            return baseCalculo * 0.15 - 381.44;
        } else if (baseCalculo <= 4664.68) {
            return baseCalculo * 0.225 - 662.77;
        } else {
            return baseCalculo * 0.275 - 896.00;
        }
    }

    public void bonifica(double bonificacao) {
        this.salarioBase += this.salarioBase * bonificacao;
    }

    public void alteraDepartamento(String novoDepartamento) {
        this.departamento = novoDepartamento;
    }

}