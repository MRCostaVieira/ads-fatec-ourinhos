/* --------------------------------------------------------
 *  Disciplina : Algoritmos e Estruturas de Dados
 *  Atividade  : AA02 - Média e Variância com Vetores
 *  Linguagem  : C
 *  Aluno      : Matheus Rafael da Costa Vieira
 *  Descrição  : Programa que lê N números reais (mínimo 8),
 *               armazena em vetor e calcula média e variância.
 * --------------------------------------------------------
 */

/* --------------------------------------------------------
 * 1. Exibir menu usuário
 * 2. Opções usuário
 * 3. Inserir números
 * 3.1. Perguntar quantos ele quer, minímo 8, máximo 100
 * 3.2. Verificar se está dentro do limite
 * 3.2.1. Avisar se estiver errado e interromper tudo,
 *        diga para inserir os números.
 * 3.3. Laço que insere os números
 * 4. Calcular média
 * 4.1. Retorne a média.
 * 5. Caclular variância
 * 5.1. Retorne a variância
 * 6. Sair do Programa.
 * --------------------------------------------------------
 */

#include <stdio.h>

// Constantes ---------------------------------------------
#define MINIMO 8    // Quantidade mínim de números
#define MAXIMO 100  // Quantidade máxima de números
// --------------------------------------------------------

// Declaração das funções ---------------------------------
void exibirMenu();
void verificarEntradaInteiro(int *escolha);
void inserirNumeros(double vetor[], int *quantidade);
void calcularEExibirMedia(double vetor[], int *quantidade);
// --------------------------------------------------------

int main(void) {

  double vetor[MAXIMO];
  int quantidade = 0;
  int escolha;

  do {

    exibirMenu();
    printf("Opção: ");

    verificarEntradaInteiro(&escolha);

    switch (escolha) {
      case 1:
        inserirNumeros(vetor, &quantidade);
        break;

      case 2:
        calcularEExibirMedia(vetor, &quantidade);
        break;

      case 0:
        printf("\nEncerrando programa\n");

      default:
        printf("\nOpção inválida ou indisponível.\n");
        break;
    }


  } while (escolha != 0);


}

// Codificação das funções --------------------------------

/* --------------------------------------------------------
 * ExibirMenu
 * Exibição do menu a cada laço
 * ----------------------------------------------------- */
void exibirMenu() {
  printf("\n======================================\n");
  printf("\nSISTEMA DE CÁLCULO - MÉDIA E VARIÂNCIA\n");
  printf("\n======================================\n");

  printf("[1] Inserir números\n");
  printf("[2] Calcular média\n");
  printf("[3] Calcular variância\n");
  printf("[0] Encerrar programa\n\n");
}

/* --------------------------------------------------------
 * verificarEntradaInteiro
 * Verifica a entrada e modifica a variável escolha
 * influenciando no corportamento do laço principal.
 * ----------------------------------------------------- */
void verificarEntradaInteiro(int *escolha) {
  if(scanf("%d", escolha) != 1) {
    /* limpa buffer em caso de entrada inválida (letra, etc.) */
    while (getchar() != '\n');

    *escolha = -1;
  }
}

/* --------------------------------------------------------
 * inserirNumeros
 * Inserir os números no vetor
 * ----------------------------------------------------- */
void inserirNumeros(double vetor[], int *quantidade) {

  int n;

  printf("\n\nQuantos números quer inserir? (minímo: %d, máximo: %d)\n",
    MINIMO, MAXIMO);
  printf("Digite: ");

  scanf("%d", &n);

  if(n < MINIMO) {
    printf("\n\nSão necessários mais de %d caracteres.\n", MINIMO );
    return;
  }

  if(n > MAXIMO) {
    printf("\n\nSó é possivel inserir até %d caracteres.\n", MAXIMO);
    return;
  }

  printf("\nDigite os %d números (separadamente)\n", n);

  for(int i=0; i < n; i++) {
    printf("Digite o %d° número: ", i + 1);
    scanf("%lf", &vetor[i]);
  }

  *quantidade = n;
  printf("\nNúmeros inseridos.\n");
}

/* --------------------------------------------------------
 * calcularEExibirMedia
 * Calcula média de X números em um vetor
 * ----------------------------------------------------- */
void calcularEExibirMedia(double vetor[], int *quantidade) {

  if(*quantidade < MINIMO) {
    printf("\nAlgarismos insuficientes. Insira mais de %d algarismos.\n", MINIMO);
    return;
  } else   if(*quantidade > MAXIMO) {
    printf("\nAlgarismos sobressalentes. Insira %d algarismos ou menos.\n", MAXIMO);
    return;
  }

  float media = 0;

  for(int i = 0; i < *quantidade; i++) {
    media += vetor[i];
  }

  media /= *quantidade;

  printf("\nMédia: %.2f", media);
}

// --------------------------------------------------------
