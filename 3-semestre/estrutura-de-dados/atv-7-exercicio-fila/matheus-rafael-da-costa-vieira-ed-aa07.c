/* --------------------------------------------------------
 * Disciplina : Estruturas de Dados
 * Atividade  : AA07 - Fazer a função main funcionar.
 * Linguagem  : C
 * Aluno      : Matheus Rafael da Costa Vieira
 * Descrição  : A main() e o código foi entregue pelo professor
 *              em um PDF, devemos unir o código e fazer a
 *              funcção main() rodar, mas eu vou fazer
 *              minhas alterações para me divertir e deixar o
 *              código mais bonito.
 * --------------------------------------------------------
 */

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declaração das estruturas ------------------------------
// Não entendo como elas funcionam, tenho que estudar. ----
struct lista
{
  int info;
  struct lista *prox;
};
typedef struct lista Lista;

struct fila
{
  Lista *prim;
  Lista *ult;
};
typedef struct fila Fila;

// Declaração das funções ---------------------------------
Fila *fila_cria();

void fila_adiciona(Fila *f, int i);
int fila_vazia(Fila *f);
void fila_imprime(Fila *f);
int fila_visualiza(Fila *f);
int fila_remove(Fila *f);
void fila_libera(Fila *f);
int random_int(int min, int max);
// --------------------------------------------------------

int main(int argc, char const *argv[])
{
  const int MIN = 10, MAX = 99;
  srand(time(NULL)); /* Inicializa função randômica */

  printf("\n----------------- INICIALIZANDO O PROGRAMA -----------------\n\n");

  Fila *f = fila_cria();                                      // Inicializa a estrutura fila 
  fila_imprime(f);                                            // Imprimirá: A fila não possui nenhum elemento!

  printf("\nAdicionando elementos na fila...\n");               
  fila_adiciona(f, random_int(MIN, MAX));                     // Insere elemento aleatório A 
  fila_adiciona(f, random_int(MIN, MAX));                     // Insere elemento aleatório B 
  fila_adiciona(f, random_int(MIN, MAX));                     // Insere elemento aleatório C 
  fila_adiciona(f, random_int(MIN, MAX));                     // Insere elemento aleatório D 
  fila_adiciona(f, random_int(MIN, MAX));                     // Insere elemento aleatório E 
  fila_imprime(f);                                            // imprimirá: A B C D E 

  printf("\nO próximo da fila (o mais perto do início): %d", fila_visualiza(f));    // imprimirá: A 
  printf("\nChamando e removendo o próximo da fila: %d", fila_remove(f)); // Removerá A 
  printf("\nChamando e removendo o próximo da fila: %d", fila_remove(f)); // Removerá B 
  printf("\nChamando e removendo o próximo da fila: %d", fila_remove(f)); // Removerá C 
  printf("\nFila atualizada!\n");

  fila_imprime(f); /* Imprimirá: D E */
  fila_libera(f);  /* Destói a estrutura fila */
}

// Codificação das funções --------------------------------

/* --------------------------------------------------------
 * fila_cria
 * Função de criação: retorna uma fila vazia
 ------------------------------------------------------- */
Fila *fila_cria()
{
  Fila *PtDF = (Fila *)malloc(sizeof(Fila));
  PtDF->prim = NULL;
  PtDF->ult = NULL;
}

/* --------------------------------------------------------
 * fila_adiciona
 * Inserção no final: retorna a fila atualizada.
 ------------------------------------------------------- */
void fila_adiciona(Fila *f, int i)
{
  /* Construção do elemento */
  Lista *novo = (Lista *)malloc(sizeof(Lista));
  novo->info = i;
  novo->prox = NULL;

  /* Enfileiramento */
  if (f->ult == NULL)
  {
    f->ult = novo;
    f->prim = novo;
  }
  else
  {
    f->ult->prox = novo;
    f->ult = novo;
  }
}

/* --------------------------------------------------------
 * fila_vazia
 * Retorna 1 se vazia ou 0 se não vazia.
 ------------------------------------------------------- */
int fila_vazia(Fila *f)
{
  return (f->ult == NULL);
}

/* --------------------------------------------------------
 * fila_imprime
 * Imprime os elementos da fila.
 ------------------------------------------------------- */
void fila_imprime(Fila *f)
{
  if (fila_vazia(f))
  {
    printf("A fila não possui nenhum elemento!\n");
    return;
  }

  printf("\nElementos da fila: ");

  Lista *p;
  for (p = f->prim; p != NULL; p = p->prox)
  {
    printf("%d ", p->info);
  }

  printf("\n");
}

/* --------------------------------------------------------
 * fila_visualizar
 * Função peek - Obtem o elemento da fila, sem removê-lo.
 ------------------------------------------------------- */
int fila_visualiza(Fila *f)
{
  return f->prim->info;
}

/* --------------------------------------------------------
 * fila_remove
 * Remove elemento do início da fila.
 ------------------------------------------------------- */
int fila_remove(Fila *f)
{
  if (!fila_vazia(f))
  {
    Lista *prim = f->prim;
    /* retira elemento do inicio */
    if (prim->prox == NULL)
    {
      f->prim = NULL;
      f->ult = NULL;
    }
    else
    {
      f->prim = f->prim->prox;
    }
    int info = prim->info;
    free(prim);
    return info;
  }
  return (long)NULL;
}

/* --------------------------------------------------------
 * fila_libera
 * Desaloca memória ocupada pela fila.
 ------------------------------------------------------- */
void fila_libera(Fila *f)
{
  while (!fila_vazia(f))
    fila_remove(f);
  free(f);
}

/* --------------------------------------------------------
 * random_int
 * Gera valor Inteiro dentro do intervalo [min, max].
 * Necessita <time.h>.
 ------------------------------------------------------- */
int random_int(int min, int max)
{
  return min + (rand() % ((max - min) + 1));
}
// --------------------------------------------------------