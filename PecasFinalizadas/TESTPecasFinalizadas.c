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
*        3      cgm       11/06     Criação de scripts de teste do modulo
*        2      cgm       09/06     Finalização do modulo
*        1      mr        07/06     Criado o módulo
*
*  $ED Descrição do módulo
*     Este módulo contém as funções específicas para o teste do
*     módulo PFN. Ilustra como redigir um interpretador de comandos
*     de teste específicos utilizando o arcabouço de teste para C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo PFN:
*
*     "=criar"        
*		- chama função PFN_CriarPFN( )
*
*	  "=inserir <Int> <Int>"
*       - chama função PFN_Inserir( <Peca> )
*
*	  "=num"		
*		- chama função PFN_NPecas( <char>, <Int>)
*
*     "=destruir"   
*		- chama função PFN_DestruirPFN( )
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    "GENERICO.h"
#include    "LERPARM.h"
#include	"LISTA.H"
#include	"TABULEIRO.h"
#include	"PECA.H"
#include	"BAR.h"
#include	"PecasFinalizadas.h"

/* Tabela dos nomes dos comandos de teste específicos */

#define     CRIAR_PFN_CMD       "=criar"
#define     INSERE_CMD         	"=inserir"
#define     NPECAS_CMD         	"=num"
#define     DESTROI_CMD         "=destruir"

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TESTPFN Efetuar operações de teste específicas para PFN
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     PFN ser testado.
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

		PFN_tpCondRet CondRetObtido   = PFN_CondRetOK ;
		PFN_tpCondRet CondRetEsperada = PFN_CondRetVazio ;
												  /* inicializa para qualquer coisa */

		char ValorDadoCor='b';
		int ValorDadoInt= 0 ;
		int ValorRecebidoInt= 0 ;
		int ValorEsperadoInt= 0 ;

		int  NumLidos = -1 ;

		TST_tpCondRet Ret ;

		/* Testar PFN Criar PFN */

			if ( strcmp( ComandoTeste , CRIAR_PFN_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "i" ,
										 &CondRetEsperada ) ;
				if ( NumLidos != 1 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = PFN_CriarPFN( ) ;

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao criar o PFN." ) ;

			} /* fim ativa: Testar PFN Criar PFN */

			/* Testar PFN Num PFN */

			if ( strcmp( ComandoTeste , NPECAS_CMD ) == 0 )
			{
				int num;
				NumLidos = LER_LerParametros( "ci" ,
										 &ValorDadoCor, &CondRetEsperada ) ;
				if ( NumLidos != 2 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = PFN_NPecas(ValorDadoCor, &num ) ;

				printf("Numero de pecas da cor %c no PFN: %d\n", ValorDadoCor, num);

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao pegar o numero de elementos no PFN." ) ;

			} /* fim ativa: Testar PFN Num PFN */

		/* Testar PFN Insere Peça no PFN */

			else if ( strcmp( ComandoTeste , INSERE_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "cii" ,
										 &ValorDadoCor, &ValorDadoInt , &CondRetEsperada ) ;
				if ( NumLidos != 3 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = PFN_Inserir( ValorDadoCor, ValorDadoInt) ;

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao inserir peça no PFN." ) ;

			} /* fim ativa: Testar PFN Insere Peça no PFN */


		/* Testar PFN Destruir PFN */

			else if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
			{

				PFN_DestruirPFN( ) ;

				return TST_CondRetOK ;

			} /* fim ativa: Testar PFN Destruir PFN */

		return TST_CondRetNaoConhec ;

	} /* Fim função: TPFN Efetuar operações de teste específicas para PFN */

/********** Fim do módulo de implementação: Módulo de teste específico **********/