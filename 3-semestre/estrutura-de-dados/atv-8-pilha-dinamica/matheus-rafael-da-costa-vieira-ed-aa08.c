#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Nó da lista encadeada armazenando string de 2 chars */
typedef struct lista
{
  char info[3]; /* 2 chars + '\0' */
  struct lista *prox;
} Lista;

/* Estrutura da pilha: aponta para o topo (= início da lista) */
typedef struct pilha
{
  Lista *topo;
} Pilha;

/* ins_ini: insere um nó no INÍCIO da lista — é o push da lista */
Lista *ins_ini(Lista *l, char *sigla)
{
  Lista *novo = (Lista *)malloc(sizeof(Lista));
  strcpy(novo->info, sigla);
  novo->prox = l;
  return novo;
}

/* Cria pilha vazia */
Pilha *pilha_cria(void)
{
  Pilha *p = (Pilha *)malloc(sizeof(Pilha));
  p->topo = NULL;
  return p;
}

/* Verifica se a pilha está vazia */
int pilha_vazia(Pilha *p)
{
  return (p->topo == NULL);
}

/* Push: empilha — insere no início da lista */
void Push(Pilha *p, char *uf)
{
  p->topo = ins_ini(p->topo, uf);
}

/* Pop: desempilha — remove do início da lista e retorna o valor */
char *Pop(Pilha *p)
{
  if (pilha_vazia(p))
  {
    printf("Pilha vazia.\n");
    exit(1);
  }
  Lista *t = p->topo;
  char *v = (char *)malloc(3 * sizeof(char));
  strcpy(v, t->info);
  p->topo = t->prox;
  free(t);
  return v;
}

/* Top: consulta o topo sem remover */
char *Top(Pilha *p)
{
  if (pilha_vazia(p))
  {
    printf("Pilha vazia.\n");
    exit(1);
  }
  return p->topo->info;
}

/* Libera a pilha */
void pilha_libera(Pilha *p)
{
  Lista *q = p->topo;
  while (q != NULL)
  {
    Lista *t = q->prox;
    free(q);
    q = t;
  }
  free(p);
}

int main(int argc, char const *argv[])
{
  Pilha *PILHA = pilha_cria();

  Push(PILHA, "MS");
  Push(PILHA, "DF");
  Push(PILHA, "RJ");
  Push(PILHA, "PR");
  Top(PILHA);
  Push(PILHA, Pop(PILHA));
  Push(PILHA, "SP");
  Push(PILHA, Top(PILHA));
  Pop(PILHA);
  Pop(PILHA);

  printf("\nO elemento no topo da pilha: %s\n\n", Top(PILHA));

  pilha_libera(PILHA);
  return 0;
}