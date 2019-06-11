/***************************************************************************
*
*  $MCD Módulo de definição: Módulo PFN
*
*  Arquivo gerado:              PecasFinalizadas.H
*  Letras identificadoras:      PFN
*
*  Projeto: Trabalho 2 Modular
*  Autores: cgm - Caio Graça Melo
*			mr - Mark Ribeiro
*			lb - Lucca Buffara
*
*  $HA Histórico de evolução:
*     Versão   Autores	  Data					Observações
*	  	 1		cgm			30/05				Criado o módulo
*
*  $ED Descrição do módulo
*		Módulo que contém as funções que o BAR disponibiliza para 
*		serem usadas pelo jogo. Além disso também são disponibilizadas
*		as condiçoes de retorno das funções em questão.
*
***************************************************************************/

/***********************************************************************
*
*  $TC Tipo de dados: TAB Condições de retorno
*
*
***********************************************************************/

   typedef enum {

         PFN_CondRetOK,
               /* Executou correto */

         PFN_CondRetFaltouMemoria,
               /* Faltou memória ao alocar dados */

		 PFN_CondRetVazio
				/* PFN vazio*/

   } PFN_tpCondRet ;


/***********************************************************************
*
*	$FC Função: BAR Criar BAR
*
*  $ED Descrição da função
*     Cria uma estrutura que guarda as pecas capturadas de cada jogador.
*
*	Assertivas de entrada e saida:
*	Função não recebe parâmetros.
*
*	$FV Valores de retorno:
*		- PFN_CondRetOK
*		- PFN_CondRetFaltouMemoria
*
*************************************************************************/

   PFN_tpCondRet PFN_CriarPFN( void ) ;


   /***********************************************************************
*
*	$FC Função: BAR Inserir BAR
*
*  $ED Descrição da função
*     Insere uma peca na lista de pecas capturadas de um jogador.
*
*	Assertivas de entrada e saida:
*	Função não recebe parâmetros.
*
*	$FV Valores de retorno:
*		- PFN_CondRetOK
*		- PFN_CondRetFaltouMemoria
*
*************************************************************************/

   PFN_tpCondRet PFN_Inserir( char c ) ;

   /***********************************************************************
*
*	$FC Função: BAR NPecas BAR
*
*  $ED Descrição da função
*     Pega o numero de pecas existentes na lista que guarda o numero de pecas
*	  capturadas de um jogador.
*
*	Assertivas de entrada e saida:
*	Função não recebe parâmetros.
*
*	$FV Valores de retorno:
*		- PFN_CondRetOK
*		- PFN_CondRetVazio
*
*************************************************************************/

   PFN_tpCondRet PFN_NPecas( char c, int *n ) ;

/*************************************************************************
*
*	$FC Função: BAR Destruir BAR
*
*  $ED Descrição da função
*     Remove o BAR existente. Nada ocorre se não houver um BAR
*	  já criado	
*	Assertivas de entrada e saida:
*	Funçao que não recebe parametros e tem valor de retorno void.
*
*************************************************************************/

   void PFN_DestruirPFN( void ) ;
 