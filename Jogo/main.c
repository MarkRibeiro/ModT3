#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "DADO.H"
#include "PECA.H"
#include "LISTA.H"
#include "TABULEIRO.H"
#include "DadoPontos.h"
#include "BAR.H"
#include "PecasFinalizadas.h"


//Calcula Permutacoes
void retorna_movimentos(int *dado, int *movimentos, int casa_atual, char cor)
{
	if(cor == 'p')
	{
		movimentos[0] = casa_atual - dado[0];
		if(dado[3] == NULL)
			movimentos[1] = casa_atual - dado[1];
	}

	if(cor == 'b')
	{
		movimentos[0] = casa_atual + dado[0];
		if(dado[3] == NULL)
			movimentos[1] = casa_atual + dado[1];
	}
}

//Limpa a tela
void clrscr()
{
    system("clear");
}

//Pause e espera uma tecla ser pressionada
void pausa ( char str[] ) 
{ 
  printf("%s\n", str);
  fflush ( stdout );
  getchar();
} 

void mostraDado(int val){

    switch(val){
        case 1:
            printf(
                "-----\n"
                "|   |\n"
                "| o |\n"
                "|   |\n"
                "-----\n");
        break;

        case 2:
            printf(
                "-----\n"
                "|o  |\n"
                "|   |\n"
                "|  o|\n"
                "-----\n");
        break;

        case 3:
            printf(
                "-----\n"
                "|o  |\n"
                "| o |\n"
                "|  o|\n"
                "-----\n");
        break;

        case 4:
            printf(
                "-----\n"
                "|o o|\n"
                "|   |\n"
                "|o o|\n"
                "-----\n");
        break;

        case 5:
            printf(
                "-----\n"
                "|o o|\n"
                "| o |\n"
                "|o o|\n"
                "-----\n");
        break;

        case 6:
            printf(
                "-----\n"
                "|o o|\n"
                "|o o|\n"
                "|o o|\n"
                "-----\n");
        break;
    }
    
}

void visInicial(void){
    printf(R"EOF(
    ____                        __  ___          __      __              ___________
   / __ \_________  ____ _     /  |/  ____  ____/ __  __/ ____ ______   /_  __|__  /
  / /_/ / ___/ __ \/ __ `/    / /|_/ / __ \/ __  / / / / / __ `/ ___/    / /   /_ < 
 / ____/ /  / /_/ / /_/ _    / /  / / /_/ / /_/ / /_/ / / /_/ / /       / /  ___/ / 
/_/   /_/   \____/\__, (_)  /_/  /_/\____/\__,_/\__,_/_/\__,_/_/       /_/  /____/  
                 /____/    ______                                                   
                          / ________ _____ ___  ____ _____                          
                         / / __/ __ `/ __ `__ \/ __ `/ __ \                         
                        / /_/ / /_/ / / / / / / /_/ / /_/ /                         
                        \____/\__,_/_/ /_/ /_/\__,_/\____/                          
                                                                                       

                Mark Ribeiro, Caio Graça Melo e Lucca Buffara de Almeida    

                Prof: Flavio B.               

    )EOF");
}

void printBanner(char *c){
    if(*c == 'b'){
    printf(R"EOF(
  ____                                       _                             
 |  _ \                                     | |                            
 | |_) |_ __ __ _ _ __   ___ __ _ ___       | | ___   __ _  __ _ _ __ ___  
 |  _ <| '__/ _` | '_ \ / __/ _` / __|  _   | |/ _ \ / _` |/ _` | '_ ` _ \ 
 | |_) | | | (_| | | | | (_| (_| \__ \ | |__| | (_) | (_| | (_| | | | | | |
 |____/|_|  \__,_|_| |_|\___\__,_|___/  \____/ \___/ \__, |\__,_|_| |_| |_|
                                                      __/ |                
                                                     |___/                                                                                                                                         
    )EOF");
    printf("\n");

    }else{
    printf(R"EOF(
  _____          _                   _                             
 |  __ \        | |                 | |                            
 | |__) | __ ___| |_ __ _ ___       | | ___   __ _  __ _ _ __ ___  
 |  ___/ '__/ _ \ __/ _` / __|  _   | |/ _ \ / _` |/ _` | '_ ` _ \ 
 | |   | | |  __/ || (_| \__ \ | |__| | (_) | (_| | (_| | | | | | |
 |_|   |_|  \___|\__\__,_|___/  \____/ \___/ \__, |\__,_|_| |_| |_|
                                              __/ |                
                                             |___/                                                                                                                                 
    )EOF");
        printf("\n");
    }
}

//Funcao que incializa/reinicializa todas as estruturas de dados dependentes de cada partida
void initPartida(void){
    TAB_CriarTabuleiro();
    TAB_ArrumarTabuleiro();
    DP_criaDadosPontos();
}

char lanceInicial(int *dados){

    char c;
    
    while(1){

        DAD_JogaDados(dados);

        printf("Decidindo qual jogador começa a partida:\n");
        printf("Lançe dos dados iniciais das pretas: \n");
        mostraDado(dados[0]);
        printf("Lançe dos dados iniciais das brancas: \n");
        mostraDado(dados[1]);

        if(dados[0] > dados[1]){
            printf("\nPretas começam a partida!\n\n");
            c = 'p';
            break;
        }else if(dados[1] > dados[0]){
            printf("\nBrancas começam a partida!\n\n");
            c = 'b';
            break;
        }else{
            printf("Mesmo valor! Lançando novamente...\n\n");
        }
    }

    return c;

}

void mostraLanceDados(int *dados, char *c){

    if(*c=='b'){
        printf("Brancas lancam os dados: \n");
    }else{
        printf("Pretas lancam os dados: \n");
    }

    mostraDado(dados[0]);
    mostraDado(dados[1]);

    if(dados[0]==dados[1]){
        switch(dados[0]){
            case 1:
                mostraDado(1);
                mostraDado(1);
            break;

            case 2:
                mostraDado(2);
                mostraDado(2);
            break;

            case 3:
                mostraDado(3);
                mostraDado(3);
            break;

            case 4:
                mostraDado(4);
                mostraDado(4);
            break;

            case 5:
                mostraDado(5);
                mostraDado(5);
            break;

            case 6:
                mostraDado(6);
                mostraDado(6);
            break;
        }
    }

    printf("\n");

}

//Por em quanto apenas uma partida...
int main(void){

    TAB_tpCondRet tp_CondRet;
    int casaIni, casaDest, movimentosTotais, dadosPontos;
    char cor;
    int aux;

    // int movimento[4] = {NULL, NULL, NULL, NULL};

    int dados[4] = {0,0,0,0};
    
    DP_criaDadosPontos(); // Inicializa DadosPontos para todas as partidas
    DP_lerPontos('p', &aux);
    printf("pontos p: %d\n", aux);

    visInicial();
    pausa("\t\t\t [Pressione qualquer tecla para iniciar]");
    clrscr();

    //Decidir qual cor joga primeiro:
    cor = lanceInicial(&dados);
    pausa("Inicializando a partida! [Pressione qualquer tecla]");
    clrscr();

    //Init estruturas
    initPartida();

    //Main game loop
    while(1){       
    
        //Lancamento dos dados
        DAD_JogaDados(&dados);

        mostraLanceDados(&dados, &cor);

        movimentosTotais = dados[0] + dados[1];

        //Dobra dos dados
        if(dados[0]==dados[1]){
            movimentosTotais *= 2;
        }

        clrscr();

        //Movimentacao das pecas
        while(movimentosTotais != 0){  

            printBanner(&cor);
            mostraLanceDados(&dados, &cor);
            TAB_PrintTabuleiro();
            printf("Escolha qual casa deseja mover: ");
            scanf("%d", &casaIni);
            
            // retorna_movimentos(int *dado, int *movimentos, int casa_atual, cor);
            
            printf("Escolha a casa destino: ");
            scanf("%d", &casaDest);
            getchar(); //Dummy getchar

            //Verifica se movimento foi validado pelo modulo tabuleiro
            //E nao permite que movimentos totais seja negativo
            if(cor=='p' && (casaIni - casaDest) <= movimentosTotais){
                if(TAB_MoverPeca(casaIni, casaDest, cor) == 0){
                    movimentosTotais = movimentosTotais - (casaIni - casaDest);
                }else{  
                    pausa("Movimento invalido!\n");
                }
            
            }else if(cor=='b' && (casaDest - casaIni) <= movimentosTotais ){

                if(TAB_MoverPeca(casaIni, casaDest, cor) == 0){
                    movimentosTotais = movimentosTotais - (casaDest - casaIni);
                }else{
                    pausa("Movimento invalido!\n");
                }
        
            }else{
                pausa("Movimento invalido!\n");
            }
            clrscr();

            }

        //Troca vez do jogador 
        if(cor=='p'){
            cor = 'b';
        }else{
            cor = 'p';
        }

    }
}