#include <stdio.h>

int main() {
  while (1) {
    int numero;

    printf("Digite um numero: ");

    if (scanf("%d", &numero) == 1) {
        printf("Entrada valida! Numero = %d\n", numero);
    } else {
        printf("Entrada invalida!\n");
    }
  }
  

  return 0;
}