public class Investimento {
    public static void main(String[] args) {
        double p = 1000.00; // quantia principal investida
        double r = 0.05; // taxa de juros anual (5%)
        int anos = 10;

        double a;

        for (int n = 1; n <= anos; n++) {
            a = p * Math.pow(1 + r, n);
            System.out.printf("Ano %d: R$ %.2f%n", n, a);
        }
    }
}