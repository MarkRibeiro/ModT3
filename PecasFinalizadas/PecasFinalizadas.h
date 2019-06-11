/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo PFN
*
*  Arquivo gerado:              PecasFinalizadas.H
*  Letras identificadoras:      PFN
*
*  Projeto: Trabalho 2 Modular
*  Autores: cgm - Caio Gra�a Melo
*			mr - Mark Ribeiro
*			lb - Lucca Buffara
*
*  $HA Hist�rico de evolu��o:
*     Vers�o   Autores	  Data					Observa��es
*	  	 1		cgm			30/05				Criado o m�dulo
*
*  $ED Descri��o do m�dulo
*		M�dulo que cont�m as fun��es que o BAR disponibiliza para 
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

         PFN_CondRetOK,
               /* Executou correto */

         PFN_CondRetFaltouMemoria,
               /* Faltou mem�ria ao alocar dados */

		 PFN_CondRetVazio
				/* PFN vazio*/

   } PFN_tpCondRet ;


/***********************************************************************
*
*	$FC Fun��o: BAR Criar BAR
*
*  $ED Descri��o da fun��o
*     Cria uma estrutura que guarda as pecas capturadas de cada jogador.
*
*	Assertivas de entrada e saida:
*	Fun��o n�o recebe par�metros.
*
*	$FV Valores de retorno:
*		- PFN_CondRetOK
*		- PFN_CondRetFaltouMemoria
*
*************************************************************************/

   PFN_tpCondRet PFN_CriarPFN( void ) ;


   /***********************************************************************
*
*	$FC Fun��o: BAR Inserir BAR
*
*  $ED Descri��o da fun��o
*     Insere uma peca na lista de pecas capturadas de um jogador.
*
*	Assertivas de entrada e saida:
*	Fun��o n�o recebe par�metros.
*
*	$FV Valores de retorno:
*		- PFN_CondRetOK
*		- PFN_CondRetFaltouMemoria
*
*************************************************************************/

   PFN_tpCondRet PFN_Inserir( char c ) ;

   /***********************************************************************
*
*	$FC Fun��o: BAR NPecas BAR
*
*  $ED Descri��o da fun��o
*     Pega o numero de pecas existentes na lista que guarda o numero de pecas
*	  capturadas de um jogador.
*
*	Assertivas de entrada e saida:
*	Fun��o n�o recebe par�metros.
*
*	$FV Valores de retorno:
*		- PFN_CondRetOK
*		- PFN_CondRetVazio
*
*************************************************************************/

   PFN_tpCondRet PFN_NPecas( char c, int *n ) ;

/*************************************************************************
*
*	$FC Fun��o: BAR Destruir BAR
*
*  $ED Descri��o da fun��o
*     Remove o BAR existente. Nada ocorre se n�o houver um BAR
*	  j� criado	
*	Assertivas de entrada e saida:
*	Fun�ao que n�o recebe parametros e tem valor de retorno void.
*
*************************************************************************/

   void PFN_DestruirPFN( void ) ;
 