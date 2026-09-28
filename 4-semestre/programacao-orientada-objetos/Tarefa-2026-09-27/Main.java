public class Main {
    public static void main(String[] args) {
        Jogador jogador1 = new Jogador("Neymar", 29, "Atacante", 500000.0F, true);
        Jogador jogador2 = new Jogador("Casemiro", 29, "Meio-campista", 300000.0F, true);

        Tecnico tecnico = new Tecnico("Tite", 60, 1000000.0F, 20);

        Time time = new Time("Seleção Brasileira", "Rio de Janeiro", 1914, tecnico);
        time.adicionarJogador(jogador1);
        time.adicionarJogador(jogador2);

        System.out.println("Média de idade dos jogadores: " + time.calcularMediaDeIdadeDosJogadores());
        time.exibirTodasAsInformacoes();
    }
}
