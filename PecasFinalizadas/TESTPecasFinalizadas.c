/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo de teste do PFN
*
*  Arquivo gerado:              TESTPFN.C
*  Letras identificadoras:      TESTPFN
*
*  Projeto: Trabaolho 2 Modular
*  Autores: cgm - Caio Gra�a Melo
*			mr - Mark Ribeiro
*			lb - Lucca Buffara
*
*  $HA Hist�rico de evolu��o:
*    Vers�o	  Autores		 	 Data			Observa��es
*      1		cgm			  	30/05/2019     Modulo de teste criado
*
*  $ED Descri��o do m�dulo
*     Este m�dulo cont�m as fun��es espec�ficas para o teste do
*     m�dulo PFN. Ilustra como redigir um interpretador de comandos
*     de teste espec�ficos utilizando o arcabou�o de teste para C.
*
*  $EIU Interface com o usu�rio pessoa
*     Comandos de teste espec�ficos para testar o m�dulo tabuleiro:
*
*     "=criar"        
*		- chama fun��o PFN_CriarPFN( )
*
*     "=destruir"   
*		- chama fun��o PFN_DestruirPFN( )
*
*	  "=inserir <Int> <Int>"
*       - chama fun��o PFN_Inserir( <Peca> )
*
*     "=remover <int>"
*       - chama fun��o PFN_Excluir( <char> )
*
*	  "=num"		
*		- chama fun��o PFN_NPecas( <char>, <Int>)
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

/* Tabela dos nomes dos comandos de teste espec�ficos */

#define     CRIAR_PFN_CMD       "=criar"
#define     INSERE_CMD         	"=inserir"
#define     REMOVE_CMD         	"=remover"
#define     NPECAS_CMD         	"=num"
#define     DESTROI_CMD         "=destruir"

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TESTPFN Efetuar opera��es de teste espec�ficas para tabuleiro
*
*  $ED Descri��o da fun��o
*     Efetua os diversos comandos de teste espec�ficos para o m�dulo
*     PFN ser testado.
*
*  $EP Par�metros
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

			} /* fim ativa: Testar TAB Criar tabuleiro */

		/* Testar PFN Insere Pe�a no PFN */

			else if ( strcmp( ComandoTeste , INSERE_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "ci" ,
										 &ValorDadoCor , &CondRetEsperada ) ;
				if ( NumLidos != 2 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = PFN_Inserir( ValorDadoCor) ;

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao inserir pe�a no PFN." ) ;

			} /* fim ativa: Testar PFN Insere Pe�a no PFN */


		/* Testar TAB Destruir PFN */

			else if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
			{

				PFN_DestruirPFN( ) ;

				return TST_CondRetOK ;

			} /* fim ativa: Testar TAB Destruir PFN */

		return TST_CondRetNaoConhec ;

	} /* Fim fun��o: TPFN Efetuar opera��es de teste espec�ficas para PFN */

/********** Fim do m�dulo de implementa��o: M�dulo de teste espec�fico **********/