/* --------------------------------------------------------
 * Disciplina : Estruturas de Dados
 * Atividade  : AA05 - Potencia de um número
 * Linguagem  : C
 * Aluno      : Matheus Rafael da Costa Vieira
 * Descrição  : Programa que precebe numero e exponencial
 *              do usuário e retorna o total da potência.
 * --------------------------------------------------------
 */

#include <stdio.h>

// Variáveis globais --------------------------------------
// --------------------------------------------------------

// Declaração das funções ---------------------------------
void menu();
double calcularPotencia(int base, int potencia);
// --------------------------------------------------------

int main(void) {

  int executarPrograma = 1;
  int escolha = 0;

  printf("\n======================================================\n");
  printf("==== BEM VINDO AO SISTEMA DE CÁLCULO DE POTÊNCIAS ====");

  do {

    int base = 0, potencia = 0;

    menu();

    if(scanf("%d", &escolha) != 1) {
      /* limpa buffer em caso de entrada inválida (letra, etc.) */
      while (getchar() != '\n');

      escolha = -1;
    }

    switch (escolha) {
      case 1:
        printf("\nDigite a base: ");
        scanf("%d", &base);
        printf("Digite a potencia: ");
        scanf("%d", &potencia);

        printf("Resultado: %.4f", calcularPotencia(base, potencia));
        break;
      
      case 0:
        printf("\nEncerrando programa.\n");
        executarPrograma = 0;
        break;

      default:
        printf("\nOpção inválida ou indisponível.\n");
        break;
    }
    

  } while(executarPrograma);

  return 0;
}

// Codificação das funções --------------------------------

/* --------------------------------------------------------
 * menu
 * Imprime o menu em cada repetição do laço.
 ------------------------------------------------------- */
void menu() {
  printf("\n\n[Aperte 1] Informar e calcular números.");
  printf("\n[Aperte 0] para encerrar o programa.\n");
  printf("Executar: ");
}

/* --------------------------------------------------------
 * calcularPotencia
 * Recebe a base e a potência, e retorna o resultado.
 ------------------------------------------------------- */
double calcularPotencia(int base, int potencia) {

  if (potencia == 0) {   // caso base
    return 1;
  } else {
    return base * calcularPotencia(base, potencia - 1); // chamada recursiva
  }
}

// --------------------------------------------------------