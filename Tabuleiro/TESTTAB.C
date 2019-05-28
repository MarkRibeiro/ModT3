/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste do tabuleiro
*
*  Arquivo gerado:              TESTTAB.C
*  Letras identificadoras:      TESTAB
*
*  Projeto: Trabaolho 2 Modular
*  Autores: cgm - Caio Graça Melo
*			mr - Mark Ribeiro
*			lb - Lucca Buffara
*
*  $HA Histórico de evolução:
*    Versão	  Autores		 	 Data			Observações
*      1		cgm			  	03/05/2019     Modulo de teste criado
*
*  $ED Descrição do módulo
*     Este módulo contém as funções específicas para o teste do
*     módulo tabuleiro. Ilustra como redigir um interpretador de comandos
*     de teste específicos utilizando o arcabouço de teste para C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo tabuleiro:
*
*     "=criar"        
*		- chama função TAB_CriarTabuleiro( )
*
*     "=destruir"   
*		- chama função TAB_DestruirTabuleiro( )
*
*	  "=move" <int> <int>
*		- chama função TAB_MoverPeca( <int>, <int> )
*
*     "=remove <int>"
*       - chama função TAB_RemoverPecaCasa( <int> )
*
*     "=insere <Int> <Int>"
*       - chama função TAB_InserirPecaCasa( <Int> , <Int> )
*
*     "=imprimir"		
*		- chama função TAB_PrintTabuleiro()
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    "generico.h"
#include    "lerparm.h"
#include "LISTA.H"
#include "TABULEIRO.H"
#include "PECA.H"

/* Tabela dos nomes dos comandos de teste específicos */

#define     CRIAR_TAB_CMD       "=criar"
#define     ARRUMAR_TAB_CMD     "=arrumar"
#define     INSERE_CMD         	"=inserir"
#define     REMOVE_CMD         	"=remover"
#define     MOVE_CMD         	"=mover"
#define     IMPRIMI_CMD         "=imprimir"
#define     DESTROI_CMD         "=destruir"

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TESTAB Efetuar operações de teste específicas para tabuleiro
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     tabuleiro ser testado.
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

		TAB_tpCondRet CondRetObtido   = TAB_CondRetOK ;
		TAB_tpCondRet CondRetEsperada = TAB_CondRetCasaVazia ;
												  /* inicializa para qualquer coisa */

		char ValorDadoCor='b';
		int ValorDadoInt= 0 ;
		int ValorDadoInt2=0;
		int ValorRecebidoInt= 0 ;
		int ValorEsperadoInt= 0 ;

		int  NumLidos = -1 ;

		TST_tpCondRet Ret ;

		/* Testar TAB Criar tabuleiro */

			if ( strcmp( ComandoTeste , CRIAR_TAB_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "i" ,
										 &CondRetEsperada ) ;
				if ( NumLidos != 1 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = TAB_CriarTabuleiro( ) ;

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao criar o tabuleiro." ) ;

			} /* fim ativa: Testar TAB Criar tabuleiro */

			/* Testar TAB Criar tabuleiro */

			if ( strcmp( ComandoTeste , ARRUMAR_TAB_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "i" ,
										 &CondRetEsperada ) ;
				if ( NumLidos != 1 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = TAB_ArrumarTabuleiro( ) ;

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao criar o tabuleiro." ) ;

			} /* fim ativa: Testar TAB Criar tabuleiro */

		/* Testar TAB Arrumar Peça na Casa */

			else if ( strcmp( ComandoTeste , INSERE_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "iici" ,
										 &ValorDadoInt , &ValorDadoInt2, &ValorDadoCor , &CondRetEsperada ) ;
				if ( NumLidos != 4 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = TAB_InserirPecasCasa( ValorDadoInt , ValorDadoCor, ValorDadoInt2 ) ;

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao inserir peça na casa dada." ) ;

			} /* fim ativa: Testar TAB Arrumar Peça na Casa */

			/* Testar TAB Move Peça */

			else if ( strcmp( ComandoTeste , MOVE_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "iici" ,
										 &ValorDadoInt , &ValorDadoInt2, &ValorDadoCor , &CondRetEsperada ) ;
				if ( NumLidos != 4 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = TAB_MoverPeca( ValorDadoInt , ValorDadoInt2, ValorDadoCor ) ;

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao inserir peça na casa dada." ) ;

			} /* fim ativa: Testar TAB Move Peça */

		/* Testar TAB Remover Peça na Casa */

			else if ( strcmp( ComandoTeste , REMOVE_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "ii" ,
										 &ValorDadoInt , &CondRetEsperada ) ;
				if ( NumLidos != 2 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = TAB_RemoverPeca( ValorDadoInt ) ;

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao remover peça na casa dada." ) ;

			} /* fim ativa: Testar TAB Remover Peça na Casa */

		 /* Testar TAB Imprime Tabuleiro */

			else if ( strcmp( ComandoTeste , IMPRIMI_CMD ) == 0 )
			{
				NumLidos = LER_LerParametros( "i" ,
										 &CondRetEsperada ) ;
				if ( NumLidos != 1 )
				{
					return TST_CondRetParm ;
				} /* if */
				
				CondRetObtido = TAB_PrintTabuleiro() ;

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao imprimir costura." ) ;

			} /* fim ativa: Testar TAB Imprime Tabuleiro */


		/* Testar TAB Destruir Tabuleiro */

			else if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
			{

				TAB_DestruirTabuleiro( ) ;

				return TST_CondRetOK ;

			} /* fim ativa: Testar TAB Destruir Tabuleiro */

		return TST_CondRetNaoConhec ;

	} /* Fim função: TTAB Efetuar operações de teste específicas para tabuleiro */

/********** Fim do módulo de implementação: Módulo de teste específico **********/