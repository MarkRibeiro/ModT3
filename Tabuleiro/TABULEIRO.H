/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo Tabuleiro
*
*  Arquivo gerado:              TABULEIRO.H
*  Letras identificadoras:      TAB
*
*  Projeto: Trabalho 3 Modular
*  Autores: cgm - Caio Gra�a Melo
*			mr - Mark Ribeiro
*			lb - Lucca Buffara
*
*  $HA Hist�rico de evolu��o:
*     Vers�o   Autores	  Data					Observa��es
*		 5		cgm			16/06				Add func quadrante
*		 4		cgm			13/06				Add func checa casa
*		 3		cgm			13/05				Ajustes finais
*		 2		cgm			11/05				Corre��o de bugs
*	  	 1		cgm			03/05				Criado o m�dulo
*
*  $ED Descri��o do m�dulo
*		M�dulo que cont�m as fun��es que o tabuleiro disponibiliza para 
*		serem usadas pelo jogo. Al�m disso tamb�m s�o disponibilizadas
*		as condi�oes de retorno das fun��es em quest�o.
*
***************************************************************************/

/***********************************************************************
*
*  $TC Tipo de dados: TAB Condi��es de retorno
*
*
***********************************************************************/

   typedef enum {

         TAB_CondRetOK,
               /* Executou correto */

         TAB_CondRetFaltouMemoria,
               /* Faltou mem�ria ao alocar dados */

         TAB_CondRetTabNaoExiste,
               /* Tabuleiro n�o existe */

         TAB_CondRetNumCasaNaoExiste,
               /* Numero da casa fornecida n�o existe */

         TAB_CondRetCasaVazia,
               /* A casa est� vazia*/

		 TAB_CondRetMovInvalido,
               /* Movimento da pe�a inv�lido*/

   } TAB_tpCondRet ;


/***********************************************************************
*
*	$FC Fun��o: TAB Criar tabuleiro
*
*  $ED Descri��o da fun��o
*     Cria um tabuleiro de gam�o.
*
*	Assertivas de entrada e saida:
*	Fun��o n�o recebe par�metros.
*
*	$FV Valores de retorno:
*		- TAB_CondRetOK
*		- TAB_CondRetFaltouMemoria
*
*************************************************************************/

   TAB_tpCondRet TAB_CriarTabuleiro( void ) ;

   /***********************************************************************
*
*	$FC Fun��o: TAB Arrumar tabuleiro
*
*  $ED Descri��o da fun��o
*     Organiza o tabuleiro de gam�o padr�o de forma que todas as pe�as estejam 
*	  em suas posi��es iniciais.
*
*	Assertivas de entrada e saida:
*	Entrada: t!=null
*
*	$FV Valores de retorno:
*		- TAB_CondRetOK
*		- TAB_CondRetTabNaoExiste
*		- TAB_CondRetFaltouMemoria
*
*************************************************************************/

   TAB_tpCondRet TAB_ArrumarTabuleiro( void );


/*************************************************************************
*
*	$FC Fun��o: TAB Destruir Tabuleiro
*
*  $ED Descri��o da fun��o
*     Remove o tabuleiro existente. Nada ocorre se n�o houver um tabuleiro
*	  j� criado	
*	Assertivas de entrada e saida:
*	N�o existe assertivas de entrada e saida.
*	Fun�ao que n�o recebe parametros e tem valor de retorno void.
*
*************************************************************************/

   void TAB_DestruirTabuleiro( void ) ;


   /*************************************************************************
*
*	$FC Fun��o: TAB Move Pe�a
*
*  $ED Descri��o da fun��o
*     Faz o movimento da pe�a.
*	
*	Assertivas de entrada e saida:
*	Entrada: casaIni entre 1 e 24
*			 casaFim entre 1 e 24 && � frente da casaIni
*			 corJogador=='b' || corJogador=='p'
*	Saida:   casaIni possuir -1 peca
*			 casaFim possui +1 peca
*
*	$EP Par�metros:
*     $P casaIni - Casa de sa�da da pe�a
*     $P casaFim - Casa de destino da pe�a. -1 tira a pe�a do tabuleiro.
*
*
*	$FV Valores de retorno:
*		- TAB_CondRetOK
*		- TAB_CondRetTabNaoExiste
*		- TAB_CondRetFaltouMemoria
*		- TAB_CondRetNumCasaNaoExiste
*		- TAB_CondRetMovInvalido
*
*************************************************************************/

   TAB_tpCondRet TAB_MoverPeca( int casaIni, int casaFim, char corJogador ) ;


/*************************************************************************
*
*	$FC Fun��o: TAB Insere Pe�a na Casa
*
*  $ED Descri��o da fun��o
*     Insere uma pe�a com a cor escolhida na casa de numero selecionado.
*	
*	Assertivas de entrada e saida:
*	Entrada: nCasa entre 1 e 24
*			 n<12
*			 cor=='b' || cor=='p'
*	Saida:   nCasa possuir +1 peca

*	$EP Par�metros:
*     $P nCasa - n�mero da casa desejada
*     $P cor - cor da pe�a desejada. 'p' para preta e 'b' para branca
*
*	$FV Valores de retorno:
*		- TAB_CondRetOK
*		- TAB_CondRetTabNaoExiste
*		- TAB_CondRetFaltouMemoria
*		- TAB_CondRetNumCasaNaoExiste
*
*************************************************************************/

   TAB_tpCondRet TAB_InserirPecasCasa(int n, char cor, int nCasa ) ;


/*************************************************************************
*
*	$FC Fun��o: TAB Remove Pe�a
*
*  $ED Descri��o da fun��o
*     Remove pe�a da casa desejada. Se a casa estiver vazia, n�o ocorre nada.
*	
*	Assertivas de entrada e saida:
*	Entrada: nCasa entre 1 e 24
*			 n<12
*			 cor=='b' || cor=='p'
*	Saida:   nCasa possuir -1 peca
*
*	$EP Par�metros:
*     $P nCasa - n�mero da casa que se deseja remover.
*
*	$FV Valores de retorno:
*		- TAB_CondRetOK
*		- TAB_CondRetTabNaoExiste
*		- TAB_CondRetCasaVazia
*		- TAB_CondRetCasaNaoExiste
*
*************************************************************************/

   TAB_tpCondRet TAB_RemoverPeca( int nCasa ) ;

/*************************************************************************
*
*	$FC Fun��o: TAB Printa Tabuleiro
*
*  $ED Descri��o da fun��o
*     Printa na tela o tabuleiro ativo.
*
*	Assertivas de entrada e saida:
*	Entrada: t!=null
*
*	$FV Valores de retorno:
*		- TAB_CondRetOK
*		- TAB_CondRetTabNaoExiste
*
*************************************************************************/

   TAB_tpCondRet TAB_PrintTabuleiro( void ) ;

   /*************************************************************************
*
*	$FC Fun��o: TAB Checa Casa
*
*  $ED Descri��o da fun��o
*     Checa a presenca de pecas adversarias na casa em questao.
*
*	Assertivas de entrada e saida:
*	Entrada: nCasa entre 1 e 24
*			 cor=='b' || cor=='p'
*	Saida: ret==0 || ret==1
*
*	$FV Valores de retorno:
*		- 0 se nao houverem pecas adversarias na casa
*		- 1 se houve uma peca adversaria na casa
*		- 2 se houver mais de uma peca adversaria na casa
*
*************************************************************************/
   int TAB_ChecaCasa (int nCasa, char c);

      /*************************************************************************
*
*	$FC Fun��o: TAB Checa Quadrante
*
*  $ED Descri��o da fun��o
*     Checa a a possibilidade de finalizacao de pecas para uma certa cor.
*
*	Assertivas de entrada e saida:
*	Entrada: cor=='b' || cor=='p'
*	Saida: ret==0 || ret==1
*
*	$FV Valores de retorno:
*		- 0 se a cor em questao ainda nao pode finalizar alguma peca
*		- 1 se a cor em questao ja pode finalizar alguma peca
*
*************************************************************************/
   int TAB_ChecaQuadrante (char c);

/********** Fim do m�dulo de defini��o: M�dulo Tabuleiro **********/