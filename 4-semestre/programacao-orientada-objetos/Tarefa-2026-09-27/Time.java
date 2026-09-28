import java.time.Year;
import java.util.ArrayList;
import java.util.List;

/**
 * Representa um time de futebol, contendo seu técnico e a lista de jogadores.
 */
public class Time {

    private String nome;
    private String cidade;
    private int anoDeFundacao;
    private Tecnico tecnicoResponsavel;
    private final List<Jogador> listaDeJogadores;

    public Time(String nome, String cidade, int anoDeFundacao, Tecnico tecnicoResponsavel) {
        setNome(nome);
        setCidade(cidade);
        setAnoDeFundacao(anoDeFundacao);
        setTecnicoResponsavel(tecnicoResponsavel);
        this.listaDeJogadores = new ArrayList<>();
    }

    public final String getNome() {
        return nome;
    }

    public final void setNome(String nome) {
        this.nome = nome;
    }

    public String getCidade() {
        return cidade;
    }

    public final void setCidade(String cidade) {
        this.cidade = cidade;
    }

    public int getAnoDeFundacao() {
        return anoDeFundacao;
    }

    public final void setAnoDeFundacao(int anoDeFundacao) {
        int anoAtual = Year.now().getValue();
        if (anoDeFundacao > anoAtual) {
            throw new IllegalArgumentException("O ano de fundação do time não pode ser um ano futuro.");
        }
        this.anoDeFundacao = anoDeFundacao;
    }

    public Tecnico getTecnicoResponsavel() {
        return tecnicoResponsavel;
    }

    public final void setTecnicoResponsavel(Tecnico tecnicoResponsavel) {
        this.tecnicoResponsavel = tecnicoResponsavel;
    }

    public List<Jogador> getListaDeJogadores() {
        return listaDeJogadores;
    }

    /**
     * Adiciona um jogador à lista de jogadores do time.
     */
    public void adicionarJogador(Jogador jogadorParaAdicionar) {
        if (jogadorParaAdicionar == null) {
            throw new IllegalArgumentException("O jogador a ser adicionado não pode ser nulo.");
        }
        listaDeJogadores.add(jogadorParaAdicionar);
    }

    /**
     * Calcula a média de idade dos jogadores do time.
     */
    public float calcularMediaDeIdadeDosJogadores() {
        if (listaDeJogadores.isEmpty()) {
            return 0f;
        }
        int somaIdades = 0;
        for (Jogador jogador : listaDeJogadores) {
            somaIdades += jogador.getIdade();
        }
        return (float) somaIdades / listaDeJogadores.size();
    }

    /**
     * Exibe todas as informações do time: nome, cidade, ano de fundação,
     * informações do técnico e a lista de jogadores.
     */
    public void exibirTodasAsInformacoes() {
        System.out.println("===== Informações do Time =====");
        System.out.println("Nome: " + nome);
        System.out.println("Cidade: " + cidade);
        System.out.println("Ano de fundação: " + anoDeFundacao);

        System.out.println("--- Técnico responsável ---");
        if (tecnicoResponsavel != null) {
            System.out.println("Nome: " + tecnicoResponsavel.getNome());
            System.out.println("Idade: " + tecnicoResponsavel.getIdade());
            System.out.println("Salário: " + tecnicoResponsavel.getSalario());
            System.out.println("Anos de experiência: " + tecnicoResponsavel.getAnosDeExperiencia());
        } else {
            System.out.println("Nenhum técnico definido.");
        }

        System.out.println("--- Jogadores (" + listaDeJogadores.size() + ") ---");
        if (listaDeJogadores.isEmpty()) {
            System.out.println("Nenhum jogador cadastrado.");
        } else {
            for (Jogador jogador : listaDeJogadores) {
                System.out.println("Nome: " + jogador.getNome()
                        + " | Idade: " + jogador.getIdade()
                        + " | Posição: " + jogador.getPosicao()
                        + " | Salário: " + jogador.getSalario()
                        + " | Contratado: " + jogador.isContratado());
            }
        }
        System.out.println("================================");
    }
}
