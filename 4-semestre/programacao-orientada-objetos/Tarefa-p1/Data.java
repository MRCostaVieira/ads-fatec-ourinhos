
public class Data {

    private int dia;
    private int mes;
    private int ano;

    private String[] meses = { "janeiro", "fevereiro", "março", "abril", "maio", "junho", "julho", "agosto", "setembro",
            "outubro", "novembro", "dezembro" };

    public Data(int dia, int mes, int ano) {
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
    }

    public boolean validarData() {
        if (ano < 1900)
            return false;

        return switch (mes) {
            case 4, 6, 9, 11 -> dia > 0 && dia < 31;
            case 1, 3, 5, 7, 8, 10, 12 -> dia > 0 && dia <= 31;
            case 2 -> dia > 0 && dia <= (validaAnoBissexto() ? 29 : 28);
            default -> false;
        };
    }

    public boolean validaAnoBissexto() {
        if (ano % 4 == 0 && ano % 100 != 0) {
            return true;
        } else if (ano % 400 == 0) {
            return true;
        }
        return false;
    }

    public int quantidadeDiaMes() {
        return switch (mes) {
            case 4, 6, 9, 11 -> 30;
            case 1, 3, 5, 7, 8, 10, 12 -> 31;
            case 2 -> (validaAnoBissexto() ? 29 : 28);
            default -> 0;
        };
    }

    public String formatoPorExtenso() {
        if (!validarData())
            return "data inválida";

        return dia + " de " + meses[mes - 1] + " de " + ano + ".";
    }

}
