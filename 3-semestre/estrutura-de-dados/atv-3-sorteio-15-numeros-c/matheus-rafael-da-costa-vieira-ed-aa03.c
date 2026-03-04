/* --------------------------------------------------------
 * Disciplina : Estruturas de Dados
 * Atividade  : AA03 - Sorteio de 15 números
 * Linguagem  : C
 * Aluno      : Matheus Rafael da Costa Vieira
 * Descrição  : Programa que preenche um vetor com 15
 *              números aleátorios [1..25] e o imprime.
 * --------------------------------------------------------
 */

/*
 * 1. Programa inicia.
 * 2. Vetor criado.
 * 3. Função gera número aleatório entre 1 e 25 e o valor é
 *    armazenado em uma variável.
 * 4. Função analise se número já foi inserido no vetor.
 * 4.1. Retorna verdadeiro caso não tenha sido inserido.
 * 4.2. Retorna falso caso já tenha sido inserido.
 * 5. Insere o número no vetor.
 * 5.1. Se 4.2 acontecer, não atribui o valor e loop continua
 *      sem alterar nenhuma variável.
 * 6. Repete o processo até todos as 15 bolas serem sorteadas.
 * 7. Exibe as 15 bolas (números).
 * 8. Programa encerra.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // time()

// Constantes ---------------------------------------------
#define NUMEROMIN 1
#define NUMEROMAX 25
#define TOTALNUMEROS 15
// --------------------------------------------------------

// Declaração das funções ---------------------------------
int gerarNum();
int verificarNumeroNoVetor(int n, int totalSorteados, int vetor[]);
void inserirNumeroVetor(int n, int totalSorteados, int vetor[]);
void printVetor(int vetor[]);
// --------------------------------------------------------

int main() {

  srand(time(NULL));
  int vetor[TOTALNUMEROS], i;
  int totalSorteados = 0;

  printf("\n================================================\n");
  printf("==== BEM VINDO AO SORTEIO DA FATEC OURINHOS ====\n\n");

  printf("Bola rolando...\n");

  do {
    int n = gerarNum();

    if (verificarNumeroNoVetor(n, totalSorteados, vetor) == 1) {
      inserirNumeroVetor(n, totalSorteados, vetor);
      totalSorteados++;
    }

  } while (totalSorteados < TOTALNUMEROS);

  printf("\nSorteio concluido!\n");

  printVetor(vetor);
}

// Codificação das funções ---------------------------------

/* --------------------------------------------------------
 * gerarNum
 * Gera e retorna um numero aleatório entre as contantes
 * NUMEROMIN e NUMEROMAX
 ------------------------------------------------------- */
int gerarNum() {
  return (rand() % (NUMEROMAX - NUMEROMIN + 1)) + NUMEROMIN;
}

/* --------------------------------------------------------
 * verificarNumeroNoVetor
 * Verifica se o número gerado já não está no vetor.
 ------------------------------------------------------- */
int verificarNumeroNoVetor(int n, int totalSorteados, int vetor[]) {

  if(totalSorteados == 0) return 1;

  for(int i = 0; i < totalSorteados; i++) {
    if (n ==  vetor[i]) {
      return 0;
    }
  }

  return 1;
}

/* --------------------------------------------------------
 * inserirNumeroVetor
 * Inseri o número no vetor caso a função
 * verificarNumeroNoVetor retorne 1 (verdadeiro).
 ------------------------------------------------------- */
void inserirNumeroVetor(int n, int totalSorteados, int vetor[]) {
  vetor[totalSorteados] = n;
}

/* --------------------------------------------------------
 * printVetor
 * Imprime os números que foram armazenados no vetor.
 ------------------------------------------------------- */
void printVetor(int vetor[]) {
  printf("\n==== RESULTADOS ====\n\n");

  for(int i = 0; i < TOTALNUMEROS; i++) {
    printf("Bola %d: %d\n", i + 1, vetor[i]);
  }

  printf("\n");
}
// --------------------------------------------------------
