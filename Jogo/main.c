#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "DADO.H"
#include "PECA.H"
#include "LISTA.H"
#include "TABULEIRO.H"

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

void visInicial(void){
    printf(R"EOF(
        ______                   ___  ___          _       _              _____ _____ 
        | ___ \                  |  \/  |         | |     | |            |_   _|____ |
        | |_/ / __ ___   __ _    | .  . | ___   __| |_   _| | __ _ _ __    | |     / /
        |  __/ '__/ _ \ / _` |   | |\/| |/ _ \ / _` | | | | |/ _` | '__|   | |     \ \
        | |  | | | (_) | (_| |_  | |  | | (_) | (_| | |_| | | (_| | |      | | .___/ /
        \_|  |_|  \___/ \__, (_) \_|  |_/\___/ \__,_|\__,_|_|\__,_|_|      \_/ \____/ 
                            __/ |                                                        
                        |___/                                                         
            ___                      _____                                             
            |_  |                    |  __ \                                            
            | | ___   __ _  ___    | |  \/ __ _ _ __ ___   __ _  ___                  
            | |/ _ \ / _` |/ _ \   | | __ / _` | '_ ` _ \ / _` |/ _ \                 
        /\__/ / (_) | (_| | (_) |  | |_\ \ (_| | | | | | | (_| | (_) |                
        \____/ \___/ \__, |\___/    \____/\__,_|_| |_| |_|\__,_|\___/                 
                        __/ |                                                           
                        |___/                                                  

            Mark Ribeiro, Caio Graça Melo e Lucca Buffara de Almeida                                                                 
    )EOF");
}

void printBanner(char *c){
    if(*c == 'b'){
    printf(R"EOF(
        ______                               
        | ___ \                              
        | |_/ /_ __ __ _ _ __   ___ __ _ ___ 
        | ___ \ '__/ _` | '_ \ / __/ _` / __|
        | |_/ / | | (_| | | | | (_| (_| \__ \
        \____/|_|  \__,_|_| |_|\___\__,_|___/
                                            
                                                                                                        
    )EOF");

    }else{
    printf(R"EOF(
        ______         _            
        | ___ \       | |           
        | |_/ / __ ___| |_ __ _ ___ 
        |  __/ '__/ _ \ __/ _` / __|
        | |  | | |  __/ || (_| \__ \
        \_|  |_|  \___|\__\__,_|___/
                                    
                                                                                                                
    )EOF");

    }
}

//Funcao que incializa/reinicializa todas as estruturas de dados dependentes de cada partida
void initPartida(void){
    TAB_CriarTabuleiro();
    TAB_ArrumarTabuleiro();
}

char lanceInicial(void){

    int dado1, dado2;
    char c;

    while(1){

        DAD_JogaDados(&dado1);
        DAD_JogaDados(&dado2);

        printf("Decidindo qual jogador começa a partida:\n");
        printf("Lançe dos dados iniciais das pretas: %d\n", dado1);
        printf("Lançe dos dados iniciais das brancas: %d\n", dado2);

        if(dado1 > dado2){
            printf("\nPretas começam a partida!\n\n");
            c = 'p';
            break;
        }else if(dado2 > dado1){
            printf("\nBrancas começam a partida!\n\n");
            c = 'b';
            break;
        }else{
            printf("Mesmo valor! Lançando novamente...\n\n");
        }
    }

    return c;

}

void mostraLanceDados(int d1, int d2, char *c){
    
    if(*c=='b'){
        printf("Brancas lancam os dados: \n");
    }else{
        printf("Pretas lancam os dados: \n");
    }

    if(d1==d2){
        printf("Dados iguais! Movimentação dobrada!\n");
    }

    printf("Valor dado 1: %d\n", d1);
    printf("Valor dado 2: %d\n", d2);

}

//Por em quanto apenas uma partida...
int main(void){

    TAB_tpCondRet tp_CondRet;
    int dado1, dado2, casaIni, casaDest, movimentosTotais;
    char cor; //A cor da vez

    visInicial();
    pausa("[Pressione qualquer tecla]");
    clrscr();

    //Decidir qual cor joga primeiro:
    cor = lanceInicial();
    pausa("Inicializando a partida! [Pressione qualquer tecla]");
    clrscr();

    //Init estruturas
    initPartida();

    //Main game loop
    while(1){
    
    //Lancamento dos dados
    DAD_JogaDados(&dado1);
    DAD_JogaDados(&dado2);
    mostraLanceDados(dado1,dado2, &cor);

    movimentosTotais = dado1 + dado2;

    //Dobra dos dados
    if(dado1==dado2){
        movimentosTotais *= 2;
    }

    clrscr();
    //Movimentacao das pecas
    while(movimentosTotais != 0){   
        printBanner(&cor);
        mostraLanceDados(dado1,dado2, &cor);
        TAB_PrintTabuleiro();
        printf("Movimentos disponiveis: %d\n", movimentosTotais);
        printf("Escolha qual casa deseja mover: ");
        scanf("%d", &casaIni);
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