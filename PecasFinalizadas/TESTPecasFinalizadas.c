/***************************************************************************
*  $MCD M�dulo de defini��o: M�dulo PFN
*
*  Arquivo gerado:              PecasFinalizadas.C
*  Letras identificadoras:      PFN
*
*  Projeto: Trabaolho 2 Modular
*  Autores: cgm - Caio Gra�a Melo
*           mr - Mark Ribeiro
*           lb - Lucca Buffara
*
*  $HA Hist�rico de evolu��o:
*     Vers�o   Autores    Data      Observa��es
*        3      cgm       11/06     Cria��o de scripts de teste do modulo
*        2      cgm       09/06     Finaliza��o do modulo
*        1      mr        07/06     Criado o m�dulo
*
*  $ED Descri��o do m�dulo
*     Este m�dulo cont�m as fun��es espec�ficas para o teste do
*     m�dulo PFN. Ilustra como redigir um interpretador de comandos
*     de teste espec�ficos utilizando o arcabou�o de teste para C.
*
*  $EIU Interface com o usu�rio pessoa
*     Comandos de teste espec�ficos para testar o m�dulo PFN:
*
*     "=criar"        
*		- chama fun��o PFN_CriarPFN( )
*
*	  "=inserir <Int> <Int>"
*       - chama fun��o PFN_Inserir( <Peca> )
*
*	  "=num"		
*		- chama fun��o PFN_NPecas( <char>, <Int>)
*
*     "=destruir"   
*		- chama fun��o PFN_DestruirPFN( )
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
#define     NPECAS_CMD         	"=num"
#define     DESTROI_CMD         "=destruir"

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TESTPFN Efetuar opera��es de teste espec�ficas para PFN
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

			} /* fim ativa: Testar PFN Num PFN */

		/* Testar PFN Insere Pe�a no PFN */

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
												"Retorno errado ao inserir pe�a no PFN." ) ;

			} /* fim ativa: Testar PFN Insere Pe�a no PFN */


		/* Testar PFN Destruir PFN */

			else if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
			{

				PFN_DestruirPFN( ) ;

				return TST_CondRetOK ;

			} /* fim ativa: Testar PFN Destruir PFN */

		return TST_CondRetNaoConhec ;

	} /* Fim fun��o: TPFN Efetuar opera��es de teste espec�ficas para PFN */

/********** Fim do m�dulo de implementa��o: M�dulo de teste espec�fico **********/