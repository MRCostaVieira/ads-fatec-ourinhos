#include <stdio.h>

int execultar = 1; // Mantém o laço execultando
int escolha = 0; // Escolha do usuário
int contadorPiadas = 0;
const char *piadas[] = {
  "Como um computador fica bebado? Ele toma Screen Shots", 
  "O problema do computador é o USB: Usuário Super Burro.", 
  "O que uma impressora disse para a outra? Essa folha é sua ou é impressão minha?",
  "Acabaram as piadas 😞"
  };
int contadorCuriosidades = 0;
const char *curiosidades[] = {
  "As impressões digitais dos coalas são tão parecidas com as humanas que já confundiram peritos criminais na Austrália em cenas de crime (sim, sério, já aconteceu de verdade).", 
  "Um polvo tem três corações e pode mudar de cor pra se camuflar, mas também consegue mudar de textura pra parecer pedra, alga ou coral — tipo um cosplay nível hardcore da natureza.", 
  "A menor guerra da história durou 38 minutos. Foi a Guerra Anglo-Zanzibar em 1896: os britânicos bombardearam o palácio do sultão de Zanzibar e ele se rendeu antes de completar 40 minutos.",
  "Acabaram as curiosidades 😞"
  };
      
void escolha_1();
      
// void escolha_2();
// void escolha_3();
    
void encerrarLaco(int *execultar);

// void escolhaInvalida();

int main () {
  
  printf("Bem vindo ao menu de opções 🥳\n");

  while(execultar) {
    printf("\nO que você deseja? 😁\n\n");

    printf("[1] Ouvir uma piada\n");
    printf("[2] Saber uma curiosidade\n");
    printf("[3] Alguma coisa\n");
    printf("[0] Quero sair desse programa!\n");
    printf("Qual é a sua escolha? -> ");

    scanf("%d", &escolha);

    switch(escolha) {
      case 1:
        escolha_1();
        break;
      // case 2:
      //   escolha_2();
      //   break;
      // case 3:
      //   escolha_3();
      //   break;
      case 0:
        encerrarLaco(&execultar);
        break;
      // default:
      //   escolhaInvalida();
    }

  }

  return 0;
}

void escolha_1() {
  printf("\nVocê escolheu ouvir uma piada 🤡\n");

  printf("%s\n", piadas[contadorPiadas]);
  // Evitar estouro da variável e erro no array
  if(contadorPiadas != 3) {
    contadorPiadas++;
  } 
}
      
// void escolha_2();
    
// void escolha_3();
      
void encerrarLaco(int *execultar) {
  printf("\nVocê escolheu sair do programa 😭\n");
  *execultar = 0;
}

// void escolhaInvalida();