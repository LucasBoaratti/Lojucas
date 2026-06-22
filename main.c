// Projeto final de Linguagem de programação 1

// Nome do sistema: Lojucas
// Tema do sistema: Jogos de computador e de videogames

// As três funções principais do programa:

// 1 - Buscar um jogo
// 2 - Alugar um jogo
// 3 - Realizar aluguel

#include <stdio.h>
#include <string.h>

// Cores de texto e de fundo
#define reset "\033[0m"
#define corFundoAzul "\033[1;44m"
#define corFundoVermelho "\033[1;41m"
#define corVerde "\033[32m"
#define corAmarela "\033[33m"
#define corCiano "\033[36m"
#define corAzul "\033[34m"
#define corVermelha "\033[31m"

// Lista de todos os jogos disponiveis na loja
char* jogosDisponiveis[] = {
    "Minecraft", 
    "Lego", 
    "Portal"
};

void menu() {
    printf(corFundoAzul "Seja bem-vindo(a) à Lojucas!" reset "\n\n");
    printf(corFundoVermelho "Veja o menu a seguir e escolha uma opcao, por favor." reset "\n");
    
    printf(corVerde "1 - Buscar um jogo" reset);
    printf(corVerde "\n2 - Comprar um jogo" reset);
    printf(corVerde "\n3 - Realizar pagamento" reset);
    printf(corVerde "\n4 - Sair" reset);
}

int main()
{
    int opcao, diasAlugados, contadorCompras = 0;
    char carrinho[3][30], escolhaJogo[30];
    
    do {
        // Chamando a função do menu
        menu();
    
        printf(corAmarela "\nAgora, selecione uma opcao: " reset);
        scanf("%i", &opcao);
        
        switch (opcao) {
            case 1:
                printf(corCiano "\nVeja os jogos disponiveis aqui:\n" reset);
                
                for (int i = 0; i < 3; i++) {
                    printf("- %s\n", jogosDisponiveis[i]);
                }
                
                printf(corAmarela "\nFique a vontade para alugar um jogo que voce curtiu.\n" reset);
                
                break;
            case 2:
                int jogoEncontrado = 0;
                
                printf(corAzul "\nEscolha um jogo no qual te deixou interessado em alugar: ");
                scanf("%s", &escolhaJogo);
                
                for (int i = 0; i < 3; i++) {
                    if (strcmp(escolhaJogo, jogosDisponiveis[i]) == 0) {
                        jogoEncontrado = 1;
                        
                        break;
                    }
                }
                
                if (jogoEncontrado) {
                    if (contadorCompras < 3) {
                        strcpy(carrinho[contadorCompras], escolhaJogo);
                        contadorCompras++;
                        
                        printf(corVerde "\nJogo adicionado ao carrinho.\n" reset);
                    }
                }
                else {
                    printf(corVermelha "\nJogo não encontrado. Tente novamente.\n" reset);
                }
                
                break;
            case 3:
                printf(corAmarela "\nJogos alugados:" reset);
                
                for (int i = 0; i < contadorCompras; i++) {
                    printf("\n%i - %s", i + 1, carrinho[i]);
                }
                
                printf(corAzul "\nIndique quantos dias voce prentende alugar esse jogo: " reset);
                scanf("%i", &diasAlugados);
                
                printf(corVerde "\nJogo alugado com sucesso! Nao esqueca de devolve-lo em %i dias!\n", diasAlugados, reset);
                printf(corCiano "\nMuito obrigado por comprar na Lojucas! Ate a proxima.\n", reset);
                
                break;
            case 4:
                printf(corCiano "\nTudo bem, se tiver interesse de alugar um jogo, volte aqui na Lojucas! :D\n" reset);
                
                break;
            default:
                printf(corVermelha "\nEscolha uma opcao valida, por favor.\n" reset);
                
                break;
        }
    }
    while (opcao != 0);
    
    return 0;
}