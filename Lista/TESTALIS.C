/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste do tabuleiro
*
*  Arquivo gerado:              TESTALIS.C
*  Letras identificadoras:      TESTALIS
*
*  Projeto: Trabaolho 2 Modular
*  Autores: cgm - Caio Graça Melo
*			mr - Mark Ribeiro
*			lb - Lucca Buffara
*
*  $HA Histórico de evolução:
*    Versão	  Autores		 	 Data			Observações
*      1		cgm			  	13/05/2019     Modulo de teste criado
*
*  $ED Descrição do módulo
*     Este módulo contém as funções específicas para o teste da 
*	  funçao de pegar o numero de elementos da lista. 
*	  Ilustra como redigir um interpretador de comandos
*     de teste específicos utilizando o arcabouço de teste para C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo tabuleiro:
*
*     "=criar"        
*		- chama função LIS_CriarLista( void   ( * ExcluirValor ) ( void * pDado ))
*
*     "=destruir"   
*		- chama função LIS_DestruirLista( )
*
*     "=insere <Int>"
*       - chama função LIS_InserirElementoApos( LIS_tppLista, <Int> )
*    "=num <Int>"
*       - chama função pegaNumElementos( LIS_tppLista, <Int*> )
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

#define     CRIAR_LIS_CMD       "=criar"
#define     INSERE_CMD         	"=inserir"
#define     PEGA_NUM_CMD         "=num"
#define     DESTROI_CMD         "=destruir"

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TESTALIS Efetuar operações de teste específicas para tabuleiro
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     lista ser testado.
*
*  $EP Parâmetros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/
		/*Lista auxiliar para os testes de lista*/
		LIS_tppLista lista=NULL;

		/*Função auxiliar do criar lista*/

		void ExcluirLista(void*ponteiro)
		{
			ponteiro=NULL;
		}

		/*Fim Função auxiliar do criar lista*/

	TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
	{

		LIS_tpCondRet CondRetObtido   = LIS_CondRetOK ;
		LIS_tpCondRet CondRetEsperada = LIS_CondRetListaVazia ;
												  /* inicializa para qualquer coisa */

		int ValorDadoInt= 0 ;
		int ValorRecebidoInt= 0 ;
		int ValorEsperadoInt= 0 ;

		int  NumLidos = -1 ;

		TST_tpCondRet Ret ;

		/* Testar LIS Criar lista */

			if ( strcmp( ComandoTeste , CRIAR_LIS_CMD ) == 0 )
			{
				NumLidos = LER_LerParametros( "i" ,
										 &CondRetEsperada ) ;
				if ( NumLidos != 1 )
				{
					return TST_CondRetParm ;
				} /* if */

				lista = LIS_CriarLista( ExcluirLista) ;

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao criar a lista." ) ;

			} /* fim ativa: Testar LIS Criar lista */

		/* Testar LIS Inserir valor na lista */

			else if ( strcmp( ComandoTeste , INSERE_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "ii" ,
										 &ValorDadoInt , &CondRetEsperada ) ;
				if ( NumLidos != 2 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = LIS_InserirElementoApos(lista,(int*) ValorDadoInt) ;

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao inserir valor na lista dada." ) ;

			} /* fim ativa: Testar  LIS Inserir valor na lista */

		/* Testar LIS Pega num de valores na lista */

			else if ( strcmp( ComandoTeste , PEGA_NUM_CMD ) == 0 )
			{
				int num;
				NumLidos = LER_LerParametros( "i" ,
										 &CondRetEsperada ) ;
				if ( NumLidos != 1 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = pegaNumElementos(lista,&num) ;

				printf("Numero de elementos na lista: %d\n", num);

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao inserir valor na lista dada." ) ;

			} /* fim ativa: Testar  LIS Pega num de valores na lista */


		/* Testar LIS Destruir lista */

			else if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
			{

				LIS_DestruirLista(lista ) ;

				return TST_CondRetOK ;

			} /* fim ativa: Testar LIS Destruir lista */

		return TST_CondRetNaoConhec ;

	} /* Fim função: TTAB Efetuar operações de teste específicas para lista */

/********** Fim do módulo de implementação: Módulo de teste específico **********/