/***************************************************************************
*  $MCI Módulo de implementação: Módulo Jogo
*
*  Arquivo gerado:              JOGO.C
*  Letras identificadoras:      JOG
*
*  Projeto: Trabaolho 3 Modular
*  Autores: cgm - Caio Graça Melo
*			mr - Mark Ribeiro
*			lb - Lucca Buffara
*
*  $HA Histórico de evolução:
*     Versão   Autores	  Data					Observações
*		 4		cgm			16/05				Ajustes no modulo e add opcao salvar jogo
*		 3		mr			12/06				Adicionada a func permutacoes movimentos
*		 2		lb			12/06				Revisão de algumas funções criadas
*	  	 1		lb			08/06				Criado o módulo
*
***************************************************************************/

#include <stdlib.h>
#include <stdio.h>
//#include <unistd.h>

#include "DADO.H"
#include "PECA.H"
#include "LISTA.H"
#include "TABULEIRO.H"
#include "DadoPontos.h"
#include "BAR.H"
#include "PFN.h"

#define bufSize 22


void Salva_Jogo(char jogadorVez)
{
	int i, nB, nP;
	FILE *fptr;
	fptr = fopen("JogoSalvo.txt", "w");
	for(i=1;i<25;i++)
	{
		nB=TAB_ChecaCasa(i,'p'); //Checa o numero de pecas brancas na casa i
		nP=TAB_ChecaCasa(i,'b'); //Checa o numero de pecas pretas na casa i

		if(nP>0)
		{
			fprintf(fptr,"%d%c\n",nP,'p');
		}
		else if(nB>0)
		{
			fprintf(fptr,"%d%c\n",nB,'b');
		}
		else
		{
			fprintf(fptr,"%d%c\n",0,'n');
		}
	}
	BAR_NPecas('b',&nB); //Checa o numero de pecas brancas capturadas 
	fprintf(fptr,"%d\n",nB);

	BAR_NPecas('p',&nP); //Checa o numero de pecas pretas capturadas
	fprintf(fptr,"%d\n",nP);

	PFN_NPecas('b',&nB); //Checa o numero de pecas brancas finalizadas
	fprintf(fptr,"%d\n",nB);

	PFN_NPecas('p',&nP); //Checa o numero de pecas pretas finalizadas
	fprintf(fptr,"%d",nP);

	fclose(fptr);
}

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
    system("cls");
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
    /*printf(R"EOF(
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

    )EOF");*/
	printf("PROG MODULAR T3\nGAMAO\n\nMark Ribeiro, Caio Graça Melo e Lucca Buffara de Almeida\nProf: Flavio B.");
}

void printBanner(char *c){
    if(*c == 'b'){
    /*printf(R"EOF(
  ____                                       _                             
 |  _ \                                     | |                            
 | |_) |_ __ __ _ _ __   ___ __ _ ___       | | ___   __ _  __ _ _ __ ___  
 |  _ <| '__/ _` | '_ \ / __/ _` / __|  _   | |/ _ \ / _` |/ _` | '_ ` _ \ 
 | |_) | | | (_| | | | | (_| (_| \__ \ | |__| | (_) | (_| | (_| | | | | | |
 |____/|_|  \__,_|_| |_|\___\__,_|___/  \____/ \___/ \__, |\__,_|_| |_| |_|
                                                      __/ |                
                                                     |___/                                                                                                                                         
    )EOF");*/
		printf("BRANCAS JOGAM");
		printf("\n");

    }else{
    /*printf(R"EOF(
  _____          _                   _                             
 |  __ \        | |                 | |                            
 | |__) | __ ___| |_ __ _ ___       | | ___   __ _  __ _ _ __ ___  
 |  ___/ '__/ _ \ __/ _` / __|  _   | |/ _ \ / _` |/ _` | '_ ` _ \ 
 | |   | | |  __/ || (_| \__ \ | |__| | (_) | (_| | (_| | | | | | |
 |_|   |_|  \___|\__\__,_|___/  \____/ \___/ \__, |\__,_|_| |_| |_|
                                              __/ |                
                                             |___/                                                                                                                                 
    )EOF");*/
		printf("PRETAS JOGAM");
        printf("\n");
    }
}

//Funcao que incializa/reinicializa todas as estruturas de dados dependentes de cada partida
void initPartida(void){
    TAB_CriarTabuleiro();
    TAB_ArrumarTabuleiro();
	BAR_CriarBAR();
	PFN_CriarPFN();
    DP_criaDadosPontos();
}

void RecarregaJogo(FILE * fptr){
	int i,n;
	BAR_tpCondRet auxBAR;
	char cor;
	char buf[bufSize];
    TAB_CriarTabuleiro();
	BAR_CriarBAR();
	PFN_CriarPFN();
    DP_criaDadosPontos();

	for(i=1;i<25;i++)
	{
		fgets(buf, sizeof(buf), fptr);
		n = atoi(&buf[0]);
		cor = buf[1];
		if(n!=0)
		{
			TAB_InserirPecasCasa(n,cor,i);
		}
	}
	fgets(buf, sizeof(buf), fptr);
	n = atoi(&buf[0]);
	auxBAR=BAR_Inserir('b',n);

	fgets(buf, sizeof(buf), fptr);
	n = atoi(&buf[0]);
	BAR_Inserir('p',n);

	fgets(buf, sizeof(buf), fptr);
	n = atoi(&buf[0]);
	PFN_Inserir('b',n);

	fgets(buf, sizeof(buf), fptr);
	n = atoi(&buf[0]);
	PFN_Inserir('p',n);


	TAB_PrintTabuleiro();
	BAR_NPecas('b',&n);
	BAR_NPecas('p',&n);
	PFN_NPecas('b',&n);
	PFN_NPecas('P',&n);
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
	FILE* fptr;
    TAB_tpCondRet tp_CondRet;
    int casaIni, casaDest, movimentosTotais, dadosPontos;
    char cor, decisao;
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
	while(1)
	{
		printf("i - Iniciar uma nova partida\nc - Carregar partida em andamento\nEscolha sua acao: ");
		scanf("%c",&decisao);

		if(decisao=='i')
		{
			initPartida();
			break;
		}
		else if(decisao=='c')
		{
			if ((fptr = fopen("JogoSalvo.txt","r")) == NULL)
			{
				printf("Erro ao abrir o arquivo\n");
			}
			else
			{
				RecarregaJogo(fptr);
				break;
			}
		}
		else
		{
			printf("Comando invalido\n");
		}
		clrscr();
	}
	clrscr();
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

		printf("s - Salvar o jogo\nqualquer outra tecla - Fazer sua jogada\nEscolha sua acao: ");
		scanf("%c", &decisao);
		if(decisao=='s')
		{
			Salva_Jogo(cor);
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