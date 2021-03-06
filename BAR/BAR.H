/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo BAR
*
*  Arquivo gerado:              BAR.H
*  Letras identificadoras:      BAR
*
*  Projeto: Trabalho 2 Modular
*  Autores: cgm - Caio Gra�a Melo
*			mr - Mark Ribeiro
*			lb - Lucca Buffara
*
*  $HA Hist�rico de evolu��o:
*     Vers�o   Autores	  Data					Observa��es
*		 2		cgm			16/06				Ajustes nos parametros da funcao de inserir
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

         BAR_CondRetOK,
               /* Executou correto */

         BAR_CondRetFaltouMemoria,
               /* Faltou mem�ria ao alocar dados */

		 BAR_CondRetVazio
				/* BAR vazio*/

   } BAR_tpCondRet ;


/***********************************************************************
*
*	$FC Fun��o: BAR Criar BAR
*
*  $ED Descri��o da fun��o
*     Cria uma estrutura que guarda as pecas capturadas de cada jogador.
*
*	Assertivas de entrada e saida:
*	Saida: b!=null
*
*	Fun��o n�o recebe par�metros.
*
*	$FV Valores de retorno:
*		- BAR_CondRetOK
*		- BAR_CondRetFaltouMemoria
*
*************************************************************************/

   BAR_tpCondRet BAR_CriarBAR( void ) ;


/*************************************************************************
*
*	$FC Fun��o: BAR Destruir BAR
*
*  $ED Descri��o da fun��o
*     Remove o BAR existente. Nada ocorre se n�o houver um BAR
*	  j� criado	
*	Assertivas de entrada e saida:
*	N�o h� assertivas de entrada e saida
*	Fun�ao que n�o recebe parametros e tem valor de retorno void.
*
*************************************************************************/

   void BAR_DestruirBAR( void ) ;

   /***********************************************************************
*
*	$FC Fun��o: BAR Inserir BAR
*
*  $ED Descri��o da fun��o
*     Insere uma peca na lista de pecas capturadas de um jogador.
*
*	Assertivas de entrada e saida:
*	Entrada: cor=='b' || cor=='p'
*			 b!=null
*	Saida: BAR da cor c com uma peca a mais
*
*	$FV Valores de retorno:
*		- BAR_CondRetOK
*		- BAR_CondRetFaltouMemoria
*
*************************************************************************/

   BAR_tpCondRet BAR_Inserir( char c, int n ) ;

   /***********************************************************************
*
*	$FC Fun��o: BAR Excluir BAR
*
*  $ED Descri��o da fun��o
*     Exclui uma peca da lista que guarda as pecas capturadas de um jogador.
*
*	Assertivas de entrada e saida:
*	Entrada: cor=='b' || cor=='p'
*			 b!=null
*	Saida: BAR da cor c com uma peca a menos
*
*	$FV Valores de retorno:
*		- BAR_CondRetOK
*		- BAR_CondRetVazio
*
*************************************************************************/

   BAR_tpCondRet BAR_Excluir( char c ) ;

   /***********************************************************************
*
*	$FC Fun��o: BAR NPecas BAR
*
*  $ED Descri��o da fun��o
*     Pega o numero de pecas existentes na lista que guarda o numero de pecas
*	  capturadas de um jogador.
*
*	Assertivas de entrada e saida:
*	Entrada: cor=='b' || cor=='p'
*			 b!=null
*	Saida: n>=0 && n<=12
*
*	$FV Valores de retorno:
*		- BAR_CondRetOK
*		- BAR_CondRetVazio
*
*************************************************************************/

   BAR_tpCondRet BAR_NPecas( char c, int *n ) ;

 