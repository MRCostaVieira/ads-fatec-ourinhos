#include <stdio.h>

// Variáveis globais 
int execLacoPrincipal = 1;
int escolhaUser; // Opção do menu
int numeroInserido; // Número que o user está inseriu no prompt
char buffer[100]; // Buffer usado na filtragem de input

// Declaração das funções
void printOpcaoErrada();
void inserirNumValidarNum();
void media();
void variancia();
void encerrarPrograma();

int main() {

  printf("\nBem vindo ao meu programa que efetua calculos com base nos números que você me fornecer!\
    \nO que você deseja fazer? 😃\n\n");

  while(execLacoPrincipal) {
    printf("[1] Informar números\n");
    printf("[2] Calcular média dos números\n");
    printf("[3] Calcular variância dos números\n");
    printf("[0] Finalizar programa\n");

    printf("\n\nExecultar: ");

    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
      if (sscanf(buffer, "%d", &escolhaUser) == 1) {

        if(escolhaUser > 3 || escolhaUser < 0) { // Se não for um número
          printOpcaoErrada();
        }

        switch (escolhaUser) {
          case 1:
            inserirNumValidarNum();
            break;
          case 2:
            media();
            break;
          case 3:
            variancia();
            break;
          case 0:
            encerrarPrograma();
            break;
        }
      } 
    }
  }

  return 0;
}

// Codificação das funções
void printOpcaoErrada() {
  printf("\nOpção errada. Tente novamente.\n\n");
}

void inserirNumValidarNum() {

  int quantidadeNumeros;

  printf("Digite a quantidade de numeros que você irá inserir: ");
  scanf("%d", &quantidadeNumeros);

  float *numeros = (float*) malloc(quantidadeNumeros * sizeof(float));

  if (numeros == NULL) {
    printf("Erro ao alocar memoria.\n");
    return 1;
  }

  for (int i = 0; i < quantidadeNumeros; i++) {
    printf("Digite o numero %d: ", i + 1);
    scanf("%f", &numeros[i]);
  }

}

void media() {
  printf("\nFunção-2\n\n");
}

void variancia() {
  printf("\nFunção-3\n\n");
}

void encerrarPrograma() {
  printf("\nFunção-4\n\n");
}
