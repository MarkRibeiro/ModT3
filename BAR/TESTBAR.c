/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo de teste do BAR
*
*  Arquivo gerado:              TESTBAR.C
*  Letras identificadoras:      TESTBAR
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
*     m�dulo BAR. Ilustra como redigir um interpretador de comandos
*     de teste espec�ficos utilizando o arcabou�o de teste para C.
*
*  $EIU Interface com o usu�rio pessoa
*     Comandos de teste espec�ficos para testar o m�dulo tabuleiro:
*
*     "=criar"        
*		- chama fun��o BAR_CriarBAR( )
*
*     "=destruir"   
*		- chama fun��o BAR_DestruirBAR( )
*
*	  "=inserir <Int> <Int>"
*       - chama fun��o BAR_Inserir( <Peca> )
*
*     "=remover <int>"
*       - chama fun��o BAR_Excluir( <char> )
*
*	  "=num"		
*		- chama fun��o BAR_NPecas( <char>, <Int>)
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

/* Tabela dos nomes dos comandos de teste espec�ficos */

#define     CRIAR_BAR_CMD       "=criar"
#define     INSERE_CMD         	"=inserir"
#define     REMOVE_CMD         	"=remover"
#define     NPECAS_CMD         	"=num"
#define     DESTROI_CMD         "=destruir"

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TESTBAR Efetuar opera��es de teste espec�ficas para tabuleiro
*
*  $ED Descri��o da fun��o
*     Efetua os diversos comandos de teste espec�ficos para o m�dulo
*     BAR ser testado.
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

		/* Testar BAR Insere Pe�a no BAR */

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
												"Retorno errado ao inserir pe�a no BAR." ) ;

			} /* fim ativa: Testar BAR Insere Pe�a no BAR */

		/* Testar BAR Remover Pe�a do BAR */

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
												"Retorno errado ao remover pe�a do BAR." ) ;

			} /* fim ativa: Testar BAR Remover Pe�a do BAR */


		/* Testar TAB Destruir BAR */

			else if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
			{

				BAR_DestruirBAR( ) ;

				return TST_CondRetOK ;

			} /* fim ativa: Testar TAB Destruir BAR */

		return TST_CondRetNaoConhec ;

	} /* Fim fun��o: TBAR Efetuar opera��es de teste espec�ficas para BAR */

/********** Fim do m�dulo de implementa��o: M�dulo de teste espec�fico **********/