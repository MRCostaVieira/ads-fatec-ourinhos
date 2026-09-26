import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = 0;

        while (n <= 5) {
            System.out.println("Quantas datas deseja informar? (Mínimo 6)");
            System.out.print("Número de dadas: ");
            n = scanner.nextInt();
        }

        Data[] datas = new Data[n];

        for (int i = 0; i < n;) {

            System.out.print("\nDia da " + (i + 1) + "ª data: ");
            int dia = scanner.nextInt();

            System.out.print("\nMes da " + (i + 1) + "ª data: ");
            int mes = scanner.nextInt();

            System.out.print("\nAno da " + (i + 1) + "ª data: ");
            int ano = scanner.nextInt();

            Data dataTemp = new Data(dia, mes, ano);

            if (dataTemp.validarData()) {
                datas[i] = dataTemp;
                i++;
            } else {
                System.out.println("data inválida");
            }
        }

        System.out.println("\n===== DATA INSERIDAS =====");

        for (int i = 0; i < n; i++) {
            System.out.println(datas[i].formatoPorExtenso());
        }

        scanner.close();
    }

}