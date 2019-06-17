/***************************************************************************
*  $MCD Módulo de definição: Módulo PFN
*
*  Arquivo gerado:              PecasFinalizadas.C
*  Letras identificadoras:      PFN
*
*  Projeto: Trabaolho 2 Modular
*  Autores: cgm - Caio Graça Melo
*           mr - Mark Ribeiro
*           lb - Lucca Buffara
*
*  $HA Histórico de evolução:
*     Versão   Autores    Data      Observações
*		 4		cgm		  16/06		Ajustes nos parametros da funcao de inserir
*        3      cgm       11/06     Criação de scripts de teste do modulo
*        2      cgm       09/06     Finalização do modulo
*        1      mr        07/06     Criado o módulo
*
*  $ED Descrição do módulo
*		Módulo que contém as funções, que o PFN disponibiliza, para 
*		serem usadas pelo jogo. Além disso também são disponibilizadas
*		as condiçoes de retorno das funções em questão.
*
***************************************************************************/

/***********************************************************************
*
*  $TC Tipo de dados: PFN Condições de retorno
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
*	$FC Função: PFN CriarPFN
*
*  $ED Descrição da função
*     Cria uma estrutura que guarda as pecas finalizadas de cada jogador.
*
*	Assertivas de entrada e saida:
*	Saida: f!=null
*
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
*	$FC Função: PFN Inserir
*
*  $ED Descrição da função
*     Insere uma peca na lista de pecas finalizadas de um jogador.
*
*	Assertivas de entrada e saida:
*	Entrada: cor=='b' || cor=='p'
*			 f!=null
*	Saida: PFN da cor c com uma peca a mais
*
*	Função não recebe parâmetros.
*
*	$FV Valores de retorno:
*		- PFN_CondRetOK
*		- PFN_CondRetFaltouMemoria
*
*************************************************************************/

   PFN_tpCondRet PFN_Inserir( char c, int n ) ;

   /***********************************************************************
*
*	$FC Função: PFN NPecas
*
*  $ED Descrição da função
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
*	$FC Função: PFN DestruirPFN
*
*  $ED Descrição da função
*     Remove o PFN existente. Nada ocorre se não houver um PFN
*	  já criado	
*	Assertivas de entrada e saida:
*	Não há assertivas de entrada e saida
*	Funçao que não recebe parametros e tem valor de retorno void.
*
*************************************************************************/

   void PFN_DestruirPFN( void ) ;
 