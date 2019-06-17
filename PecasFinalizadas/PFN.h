/***************************************************************************
*  $MCD M�dulo de defini��o: M�dulo PFN
*
*  Arquivo gerado:              PecasFinalizadas.C
*  Letras identificadoras:      PFN
*
*  Projeto: Trabaolho 2 Modular
*  Autores: cgm - Caio Gra�a Melo
*           mr - Mark Ribeiro
*           lb - Lucca Buffara
*
*  $HA Hist�rico de evolu��o:
*     Vers�o   Autores    Data      Observa��es
*		 4		cgm		  16/06		Ajustes nos parametros da funcao de inserir
*        3      cgm       11/06     Cria��o de scripts de teste do modulo
*        2      cgm       09/06     Finaliza��o do modulo
*        1      mr        07/06     Criado o m�dulo
*
*  $ED Descri��o do m�dulo
*		M�dulo que cont�m as fun��es, que o PFN disponibiliza, para 
*		serem usadas pelo jogo. Al�m disso tamb�m s�o disponibilizadas
*		as condi�oes de retorno das fun��es em quest�o.
*
***************************************************************************/

/***********************************************************************
*
*  $TC Tipo de dados: PFN Condi��es de retorno
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
*	$FC Fun��o: PFN CriarPFN
*
*  $ED Descri��o da fun��o
*     Cria uma estrutura que guarda as pecas finalizadas de cada jogador.
*
*	Assertivas de entrada e saida:
*	Saida: f!=null
*
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
*	$FC Fun��o: PFN Inserir
*
*  $ED Descri��o da fun��o
*     Insere uma peca na lista de pecas finalizadas de um jogador.
*
*	Assertivas de entrada e saida:
*	Entrada: cor=='b' || cor=='p'
*			 f!=null
*	Saida: PFN da cor c com uma peca a mais
*
*	Fun��o n�o recebe par�metros.
*
*	$FV Valores de retorno:
*		- PFN_CondRetOK
*		- PFN_CondRetFaltouMemoria
*
*************************************************************************/

   PFN_tpCondRet PFN_Inserir( char c, int n ) ;

   /***********************************************************************
*
*	$FC Fun��o: PFN NPecas
*
*  $ED Descri��o da fun��o
*     Pega o numero de pecas existentes na lista que guarda o numero de pecas
*	  finalizadas de um jogador.
*
*	Assertivas de entrada e saida:
*	Entrada: cor=='b' || cor=='p'
*			 f!=null
*	Saida: n>=0 && n<=12
*
*	$FV Valores de retorno:
*		- PFN_CondRetOK
*		- PFN_CondRetVazio
*
*************************************************************************/

   PFN_tpCondRet PFN_NPecas( char c, int *n ) ;

/*************************************************************************
*
*	$FC Fun��o: PFN DestruirPFN
*
*  $ED Descri��o da fun��o
*     Remove o PFN existente. Nada ocorre se n�o houver um PFN
*	  j� criado	
*	Assertivas de entrada e saida:
*	N�o h� assertivas de entrada e saida
*	Fun�ao que n�o recebe parametros e tem valor de retorno void.
*
*************************************************************************/

   void PFN_DestruirPFN( void ) ;
 