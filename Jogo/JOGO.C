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
#include <unistd.h>

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

//-------------------------------------------------------
//GUIs e utilitarios

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

void retorna_movimentos(int *dado, int *movimentos, int casaAtual, char cor, int inseri_peca_capturada)
{
    int i;

    if(inseri_peca_capturada){
        if(cor = 'b'){
            casaAtual = 12; 
        }else{
            casaAtual = 13;
        }
    }
    
	if(cor == 'p')
	{
		movimentos[0] = casaAtual - dado[0];
		if(dado[3] == 0)
			movimentos[1] = casaAtual - dado[1];
            movimentos[2] = -100;
            movimentos[3] = -100;
	}

	if(cor == 'b')
	{
		movimentos[0] = casaAtual + dado[0];
		if(dado[3] == 0)
			movimentos[1] = casaAtual + dado[1];
            movimentos[2] = -100;
            movimentos[3] = -100;
	}
}

void tiraDado(int *dado, int dadoUsado)
{
	switch (dadoUsado)
	{
		case 0:
			dado[0] = dado[1]; 
			dado[1] = dado[2];
			dado[2] = dado[3];
			dado[3] = 0;
			return ;

		case 1:
			dado[1] = dado[2];
			dado[2] = dado[3];
			dado[3] = 0;
			return ;

		case 2:
			dado[2] = dado[3];
			dado[3] = 0;
			return ;

		case 3:
			dado[3] = 0;
			return ; 

	}
	
}

//Funcao que incializa/reinicializa todas as estruturas de dados dependentes de cada partida
void initPartida(void){
    TAB_CriarTabuleiro();
    TAB_ArrumarTabuleiro();
    BAR_CriarBAR();
    PFN_CriarPFN();
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

//Calcula e acrescenta pontos
void calculaPontos(){
    return;
}

//Por em quanto apenas uma partida...
int main(void){

    TAB_tpCondRet tp_CondRet;
    FILE* fptr;
    int casaIni, casaDest, movimentosTotais, dadosPontos;
    char cor, char_aux;
    char ultimo_a_dobrar = 'f'; //Init qualquer coisa diferente de p ou b
    int aux, i, inseri_peca_capturada, pode_finalizar, decisao;

    // int movimento[4] = {NULL, NULL, NULL, NULL};

    int dados[4] = {0,0,0,0};
    int movimentos[4] = {0, 0, 0, 0};
    
    DP_criaDadosPontos(); // Inicializa DadosPontos para todas as partidas

    visInicial();
    pausa("\t\t\t [Pressione qualquer tecla para iniciar]");
    clrscr();

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

    getchar();
    //Decidir qual cor joga primeiro:
    cor = lanceInicial(&dados);
    pausa("Inicializando a partida! [Pressione qualquer tecla]");
    clrscr();

    //Main game loop
    while(1){

        printf("s - Salvar o jogo\nqualquer outra tecla - Fazer sua jogada\nEscolha sua acao: ");
        scanf("%c", &decisao);
        if(decisao=='s')
        {
            Salva_Jogo(cor);
        }

        PFN_NPecas(cor, &aux);

        if(aux == 15){
            if(cor == 'p'){
                clrscr();
                printf("Pretas venceram essa partida!\n");
            }else{
                clrscr();
                printf("Pretas venceram essa partida!\n");
            }
            calculaPontos();
            break;
        }

        printBanner(&cor);
        
        DP_lerUltimoJogador(&ultimo_a_dobrar);

        if(ultimo_a_dobrar != cor){
            DP_lerValorDadosPontos(&aux);
            printf("Valor do dados pontos: %d\n", aux);

            printf("Deseja dobrar os pontos? [S/n]: ");
            scanf("%c", &char_aux);
            getchar(); //Dummy
        }

        if(char_aux == 'S'){
            DP_dobraValor(cor);
            DP_lerValorDadosPontos(&aux);
            printf("Pontuação dobrada! Agora a partida esta valendo: %d\n", aux);
        } 

        printf("Pontuação atual do jogo: \n");
        DP_lerPontos('p', &aux);
        printf("Pretas: %d\n", aux);
        DP_lerPontos('b', &aux);
        printf("Brancas: %d\n", aux);

        pausa("[Pressione qualquer tecla]");
    
        //Lancamento dos dados
        DAD_JogaDados(&dados);

        clrscr();

        //Movimentacao das pecas
        while(1){
            printBanner(&cor);
        
            inseri_peca_capturada = 0;
            pode_finalizar = 0;

            if(TAB_ChecaQuadrante(cor)){
                printf("***Voce ja pode finalizar suas pecas!***\n");
                pode_finalizar = 1;
            }

            mostraLanceDados(&dados, &cor);
            TAB_PrintTabuleiro();

            BAR_NPecas('p', &aux);
            printf("Peças pretas capturadas: %d\n", aux);

            BAR_NPecas('b', &aux);
            printf("Peças brancas capturadas: %d\n\n", aux);

            PFN_NPecas('p', &aux);
            printf("Peças pretas finalizadas: %d\n", aux);

            PFN_NPecas('b', &aux);
            printf("Peças brancas finalizadas: %d\n\n", aux);

            BAR_NPecas(cor, &aux);
            if(aux > 0){
                inseri_peca_capturada = 1;
            }

            while(1){

                if(inseri_peca_capturada){
                    printf("Voce deve inserir a peca capturada!\n");
                    casaIni = 0; //Qualquer valor
                    break;
                }

                printf("Escolha qual casa deseja mover: ");
                scanf("%d", &casaIni);

                if(casaIni > 24 || casaIni < 1){
                    printf("Casa invalida!\n");
                    continue;
                }

                if(TAB_ChecaCasa(casaIni, cor) == 0){
                    break;
                }
                printf("Voce nao pode mexer a peca nessa casa!\n");
            }

            retorna_movimentos(dados, movimentos, casaIni, cor , inseri_peca_capturada);

            for(i = 0; i < 4; i++){
                
                if((movimentos[i] > 24 || movimentos[i] < 1) && movimentos[i] > -100 && pode_finalizar){
                    printf("Finalizar peca usando dado [%d]\n",i);
                    printf("%d\n", movimentos[i]);
                    continue;
                }else if((movimentos[i] > 24 || movimentos[i] < 1 ) && movimentos[i] > -100){
                    continue;
                }

                if(movimentos[i] == -100){movimentos[i] = 0;}

                if(movimentos[i] != 0 && movimentos[i] != casaIni && (TAB_ChecaCasa(movimentos[i], cor) == 0 || TAB_ChecaCasa(movimentos[i], cor) == 1)){
                    printf("Usando dado [%d] :%d -> %d\n",i, casaIni, movimentos[i]);
                }
            }
            
            while(1){
                printf("Escolha qual dado deseja usar [-1 para cancelar]: ");
                scanf("%d", &aux);
                if((aux>=0 && aux<=3) || aux == -1){ //Dumb check
                    break;
                }
                printf("Escolha o numero do dado!\n");
            }

            if(aux != -1){
                casaDest = movimentos[aux];
                getchar(); //Dummy getchar

                if(TAB_ChecaCasa(casaDest, cor) == 1){
                    TAB_RemoverPeca(casaDest); // "Come a Peca e bota na BAR"
                    if(cor == 'p'){
                        BAR_Inserir('b', 1);
                    }else{
                        BAR_Inserir('p', 1);
                    }
                }

                if(inseri_peca_capturada){
                    TAB_InserirPecasCasa(1, cor, casaDest);
                    BAR_Excluir(cor);
                }else{
                    TAB_MoverPeca(casaIni, casaDest, cor);
                }

                tiraDado(&dados, aux);
                }

            if(dados[0] == 0 && dados[1] == 0 && dados[2] == 0 && dados[3] == 0){
                TAB_PrintTabuleiro();
                pausa("[Pressione qualquer tecla]");
                clrscr();
                break;
            }
        }

        //Troca vez do jogador 
        if(cor=='p'){
            cor = 'b';
        }else{
            cor = 'p';
        }

    }
}


