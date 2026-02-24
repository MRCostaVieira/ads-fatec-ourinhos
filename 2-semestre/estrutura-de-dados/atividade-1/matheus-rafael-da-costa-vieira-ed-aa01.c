// === INTRUÇÕES PARA COMPILAR E EXECULTAR O PROGRAMA ===

// Requisitos: compilador C instalado na sua máquina.
// - Windows: https://www.alura.com.br/artigos/compilando-executando-programas-c-c-windows?srsltid=AfmBOorblquofsV8X8lsoDCpSQfRsEOemIJVagGtjMcSW2uS8fKCTY80
// - Linux
//   - Ubuntu / Debian / Mint: sudo apt update -y && sudo apt install build-essential -y
//   - Fedora / RHEL / CentOS: sudo dnf groupinstall "Development Tools" -y
//   - Arch linux: sudo pacman -S base-devel
// - Mac OS: https://viniciuspaes.com/mac-osx/tutorial-instalar-compilador-c-mac-osx/

// Compilar programa
// 1. Abra seu terminal
//   - No Visual Studio Code, podemos usar o atalho "ctrl + j"
// 2. Certifique-se de estar no repositório (pasta) correta do programa.
// 3. Comando para compilar o programa: 
//   gcc matheus-rafael-da-costa-vieira-ed-aa01.c -o programa
// 4. Execultar programa: ./programa


#include <stdio.h>

int execLacoPrincipal = 1; // Mantém o laço execultando
int escolhaUser; // Escolha (input) do usuário
char buffer[100]; // Buffer usado na filtragem de input

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

int contadorDefeitosCarros = 0;
const char *defeitosCarros[] = {
  "O Fiat Marea adora festas, ele gosta tanto de fogos de artifício que, às vezes, decide transformar o próprio motor em um.",
  "A Land Rover Discovery não quebra, ela apenas gosta de andar no elevador hidráulico.",
  "O grande problema da Chevrolet é o seu espírito natalino. Eles amam tanto o Natal que todos os seus carros acendem as luzes de advertência do painel.",
  "Acabaram os defeitos 😞"
  };
      
void escolha_1(); // Piadas
void escolha_2(); // Curiosidades
void escolha_3(); // Defeito de um carro
    
void escolhaInvalida(); // Input incorreto
void encerrarLaco(); // Encerrar programa

int main () {
  
  printf("Bem vindo ao menu de opções 🥳\n");

  while(execLacoPrincipal) {

    printf("\nO que você deseja? 😁\n\n");
    // Opções do menu
    printf("[Digite 1] Ouvir uma piada\n");
    printf("[Digite 2] Saber uma curiosidade\n");
    printf("[Digite 3] Alguma coisa\n");
    printf("[Digite 0] Quero sair desse programa!\n");
    printf("Qual é a sua escolha? -> ");

    // Filtragem de input
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
      if (sscanf(buffer, "%d", &escolhaUser) == 1) {

        if(escolhaUser > 3 || escolhaUser < 0) { // Se não for um número
          escolhaInvalida();
        }

        switch (escolhaUser) { // Número que o usuário escolheu
        case 1:
          escolha_1();
          break;
        case 2:
          escolha_2();
          break;
        case 3:
          escolha_3();
          break;
        case 0:
          encerrarLaco();
          break;
        }

      } else {
        escolhaInvalida();
      }
    }
  }

  return 0;
}

void escolha_1() {
  printf("\nVocê escolheu ouvir uma piada [opção 1] 🤡\n\n");

  printf("%s\n", piadas[contadorPiadas]);
  // Evitar estouro da variável e erro no array
  if(contadorPiadas != 3) {
    contadorPiadas++;
  } 
}
      
void escolha_2() {
  printf("\nVocê escolheu saber uma curiosidade [opção 2] 🔎\n\n");

  printf("%s\n", curiosidades[contadorCuriosidades]);
  // Evitar estouro da variável e erro no array
  if(contadorCuriosidades != 3) {
    contadorCuriosidades++;
  } 
}
    
void escolha_3() {
  printf("\nVocê escolheu conhecer um defeito de um carro [opção 3] 🚗\n\n");

  printf("%s\n", defeitosCarros[contadorDefeitosCarros]);
  // Evitar estouro da variável e erro no array
  if(contadorDefeitosCarros != 3) {
    contadorDefeitosCarros++;
  } 
}

void escolhaInvalida() {
  printf("\nOpção inválida meu chapa, tenta de novo 🔄️\n\n");
}
      
void encerrarLaco() {
  printf("\nVocê escolheu sair do programa 😭\n\n");
  execLacoPrincipal = 0;
}