/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo de teste do tabuleiro
*
*  Arquivo gerado:              TESTALIS.C
*  Letras identificadoras:      TESTALIS
*
*  Projeto: Trabaolho 2 Modular
*  Autores: cgm - Caio Gra�a Melo
*			mr - Mark Ribeiro
*			lb - Lucca Buffara
*
*  $HA Hist�rico de evolu��o:
*    Vers�o	  Autores		 	 Data			Observa��es
*      1		cgm			  	13/05/2019     Modulo de teste criado
*
*  $ED Descri��o do m�dulo
*     Este m�dulo cont�m as fun��es espec�ficas para o teste da 
*	  fun�ao de pegar o numero de elementos da lista. 
*	  Ilustra como redigir um interpretador de comandos
*     de teste espec�ficos utilizando o arcabou�o de teste para C.
*
*  $EIU Interface com o usu�rio pessoa
*     Comandos de teste espec�ficos para testar o m�dulo tabuleiro:
*
*     "=criar"        
*		- chama fun��o LIS_CriarLista( void   ( * ExcluirValor ) ( void * pDado ))
*
*     "=destruir"   
*		- chama fun��o LIS_DestruirLista( )
*
*     "=insere <Int>"
*       - chama fun��o LIS_InserirElementoApos( LIS_tppLista, <Int> )
*    "=num <Int>"
*       - chama fun��o pegaNumElementos( LIS_tppLista, <Int*> )
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    "generico.h"
#include    "lerparm.h"
#include "LISTA.H"
#include "TABULEIRO.H"
#include "PECA.H"

/* Tabela dos nomes dos comandos de teste espec�ficos */

#define     CRIAR_LIS_CMD       "=criar"
#define     INSERE_CMD         	"=inserir"
#define     PEGA_NUM_CMD         "=num"
#define     DESTROI_CMD         "=destruir"

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TESTALIS Efetuar opera��es de teste espec�ficas para tabuleiro
*
*  $ED Descri��o da fun��o
*     Efetua os diversos comandos de teste espec�ficos para o m�dulo
*     lista ser testado.
*
*  $EP Par�metros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/
		/*Lista auxiliar para os testes de lista*/
		LIS_tppLista lista=NULL;

		/*Fun��o auxiliar do criar lista*/

		void ExcluirLista(void*ponteiro)
		{
			ponteiro=NULL;
		}

		/*Fim Fun��o auxiliar do criar lista*/

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

	} /* Fim fun��o: TTAB Efetuar opera��es de teste espec�ficas para lista */

/********** Fim do m�dulo de implementa��o: M�dulo de teste espec�fico **********/