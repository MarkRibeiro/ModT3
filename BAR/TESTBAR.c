/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste do BAR
*
*  Arquivo gerado:              TESTBAR.C
*  Letras identificadoras:      TESTBAR
*
*  Projeto: Trabaolho 2 Modular
*  Autores: cgm - Caio Graça Melo
*			mr - Mark Ribeiro
*			lb - Lucca Buffara
*
*  $HA Histórico de evolução:
*    Versão	  Autores		 	 Data			Observações
*      1		cgm			  	30/05/2019     Modulo de teste criado
*
*  $ED Descrição do módulo
*     Este módulo contém as funções específicas para o teste do
*     módulo BAR. Ilustra como redigir um interpretador de comandos
*     de teste específicos utilizando o arcabouço de teste para C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo tabuleiro:
*
*     "=criar"        
*		- chama função BAR_CriarBAR( )
*
*     "=destruir"   
*		- chama função BAR_DestruirBAR( )
*
*	  "=inserir <Int> <Int>"
*       - chama função BAR_Inserir( <Peca> )
*
*     "=remover <int>"
*       - chama função BAR_Excluir( <char> )
*
*	  "=num"		
*		- chama função BAR_NPecas( <char>, <Int>)
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    "generico.h"
#include    "lerparm.h"
#include "LISTA.H"
#include "TABULEIRO.H"
#include "PECA.H"
#include "BAR.h"

/* Tabela dos nomes dos comandos de teste específicos */

#define     CRIAR_BAR_CMD       "=criar"
#define     INSERE_CMD         	"=inserir"
#define     REMOVE_CMD         	"=remover"
#define     NPECAS_CMD         	"=num"
#define     DESTROI_CMD         "=destruir"

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TESTBAR Efetuar operações de teste específicas para tabuleiro
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     BAR ser testado.
*
*  $EP Parâmetros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/

	TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
	{

		BAR_tpCondRet CondRetObtido   = BAR_CondRetOK ;
		BAR_tpCondRet CondRetEsperada = BAR_CondRetVazio ;
												  /* inicializa para qualquer coisa */

		char ValorDadoCor='b';
		int ValorDadoInt= 0 ;
		int ValorRecebidoInt= 0 ;
		int ValorEsperadoInt= 0 ;

		int  NumLidos = -1 ;

		TST_tpCondRet Ret ;

		/* Testar BAR Criar BAR */

			if ( strcmp( ComandoTeste , CRIAR_BAR_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "i" ,
										 &CondRetEsperada ) ;
				if ( NumLidos != 1 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = BAR_CriarBAR( ) ;

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao criar o BAR." ) ;

			} /* fim ativa: Testar BAR Criar BAR */

			/* Testar BAR Num BAR */

			if ( strcmp( ComandoTeste , NPECAS_CMD ) == 0 )
			{
				int num;
				NumLidos = LER_LerParametros( "ci" ,
										 &ValorDadoCor, &CondRetEsperada ) ;
				if ( NumLidos != 2 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = BAR_NPecas(ValorDadoCor, &num ) ;

				printf("Numero de pecas da cor %c no BAR: %d\n", ValorDadoCor, num);

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao pegar o numero de elementos no BAR." ) ;

			} /* fim ativa: Testar TAB Criar tabuleiro */

		/* Testar BAR Insere Peça no BAR */

			else if ( strcmp( ComandoTeste , INSERE_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "cii" ,
										 &ValorDadoCor, &ValorDadoInt , &CondRetEsperada ) ;
				if ( NumLidos != 3 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = BAR_Inserir( ValorDadoCor, ValorDadoInt) ;

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao inserir peça no BAR." ) ;

			} /* fim ativa: Testar BAR Insere Peça no BAR */

		/* Testar BAR Remover Peça do BAR */

			else if ( strcmp( ComandoTeste , REMOVE_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "ci" ,
										 &ValorDadoCor , &CondRetEsperada ) ;
				if ( NumLidos != 2 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = BAR_Excluir( ValorDadoCor ) ;

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao remover peça do BAR." ) ;

			} /* fim ativa: Testar BAR Remover Peça do BAR */


		/* Testar TAB Destruir BAR */

			else if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
			{

				BAR_DestruirBAR( ) ;

				return TST_CondRetOK ;

			} /* fim ativa: Testar TAB Destruir BAR */

		return TST_CondRetNaoConhec ;

	} /* Fim função: TBAR Efetuar operações de teste específicas para BAR */

/********** Fim do módulo de implementação: Módulo de teste específico **********/