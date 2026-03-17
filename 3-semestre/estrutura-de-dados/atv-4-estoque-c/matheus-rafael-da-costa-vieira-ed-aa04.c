/* --------------------------------------------------------
 * Disciplina : Estruturas de Dados
 * Atividade  : AA04 - Estoque
 * Linguagem  : C
 * Aluno      : Matheus Rafael da Costa Vieira
 * Descrição  : Atividade guiada por PDF, bastando apenas
 *              copiar e colocar os códigos.
 * --------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // 

// Constantes ---------------------------------------------
#define CAPACIDADE 5
// --------------------------------------------------------

int ITEM_INDEX = 0;

// Funções e estruturas -----------------------------------
enum bool {FALSE, TRUE};

typedef enum bool Boolean;
typedef long long duploLong;

struct produto {
  duploLong codigo;
  double preco;
};

typedef struct produto Produto;

typedef struct estoque_item {
  Produto produto;
  int quantidade;
  int minimo;
} EstoqueItem;

Boolean estaAcabando(EstoqueItem item) {
  if (item.quantidade <= item.minimo) {
    return TRUE;
  }
  
  return FALSE;
}

Boolean estoqueEstaVazio() {
  return ITEM_INDEX == 0;
}

/* Gera valor Inteiro dentro do intervalo [min, max] */
int random_int(int min, int max) {
  return ( rand() % ( (max - min) + 1 ) ) + min;
}
// --------------------------------------------------------

int main(int argc, char const *argv[]) {
  srand(time(NULL)); /* Inicialização da Semente Rand^omica */

  EstoqueItem inventario[CAPACIDADE];

  Produto prod1;
  prod1.codigo = 1111111111;
  prod1.preco = 10.01;

  EstoqueItem item1;
  item1.produto = prod1;
  item1.quantidade = random_int(1, 10);
  item1.minimo = random_int(1, 5);
  inventario[ITEM_INDEX++] = item1;

  Produto prod2;
  prod2.codigo = 2222222222;
  prod2.preco = 22.22;
  EstoqueItem item2;
  item2.produto = prod2;
  item2.quantidade = 32;
  item2.minimo = 16;
  inventario[ITEM_INDEX++] = item2;

  Produto prod3 = {1234567890, 98.76};
  EstoqueItem item3 = {prod3, 333, 333};
  inventario[ITEM_INDEX++] = item3;

  if (estoqueEstaVazio() == FALSE) {

    for (int i=0; i<ITEM_INDEX; i++) {
      EstoqueItem item = inventario[i];
  
      printf("\nProduto: %lld (R$ %.2f) Estoque: %3d.",
        item.produto.codigo, item.produto.preco,
        item.quantidade);
  
      if (estaAcabando(item)) { 
        printf(" [ESTA ACABANDO] ");
      }
    }
    printf("\n\n");
  }

  return 0;
} 