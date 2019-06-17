/***************************************************************************
*
*  $MCD Módulo de definição: Módulo BAR
*
*  Arquivo gerado:              BAR.H
*  Letras identificadoras:      BAR
*
*  Projeto: Trabalho 2 Modular
*  Autores: cgm - Caio Graça Melo
*			mr - Mark Ribeiro
*			lb - Lucca Buffara
*
*  $HA Histórico de evolução:
*     Versão   Autores	  Data					Observações
*		 2		cgm			16/06				Ajustes nos parametros da funcao de inserir
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

         BAR_CondRetOK,
               /* Executou correto */

         BAR_CondRetFaltouMemoria,
               /* Faltou memória ao alocar dados */

		 BAR_CondRetVazio
				/* BAR vazio*/

   } BAR_tpCondRet ;


/***********************************************************************
*
*	$FC Função: BAR Criar BAR
*
*  $ED Descrição da função
*     Cria uma estrutura que guarda as pecas capturadas de cada jogador.
*
*	Assertivas de entrada e saida:
*	Saida: b!=null
*
*	Função não recebe parâmetros.
*
*	$FV Valores de retorno:
*		- BAR_CondRetOK
*		- BAR_CondRetFaltouMemoria
*
*************************************************************************/

   BAR_tpCondRet BAR_CriarBAR( void ) ;


/*************************************************************************
*
*	$FC Função: BAR Destruir BAR
*
*  $ED Descrição da função
*     Remove o BAR existente. Nada ocorre se não houver um BAR
*	  já criado	
*	Assertivas de entrada e saida:
*	Não há assertivas de entrada e saida
*	Funçao que não recebe parametros e tem valor de retorno void.
*
*************************************************************************/

   void BAR_DestruirBAR( void ) ;

   /***********************************************************************
*
*	$FC Função: BAR Inserir BAR
*
*  $ED Descrição da função
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
*	$FC Função: BAR Excluir BAR
*
*  $ED Descrição da função
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
*	$FC Função: BAR NPecas BAR
*
*  $ED Descrição da função
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

 