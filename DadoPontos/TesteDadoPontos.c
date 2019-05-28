/***************************************************************************
*
*  $MCI Módulo de implementação: Módulo DadoPontos
*
*  Arquivo gerado:              TestaDadoPontos.C
*  Letras identificadoras:      DP
*
*  Projeto: Disciplina INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: cgm - Caio Graça Melo
*			mr - Mark Ribeiro
*			lb - Lucca Buffara
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data    Observações
*       1.00   lb   8/05/2019  Começo da implementacao
*       2.00   lb   10/05/2019 Final do desenvolvimento
*
*  $ED Descrição do módulo
*     Este módulo implementa um lançamento o DadoPontos
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo DadoPontos:
*
*    "=criar"                   DP_criaDadosPontos(void)
*    "=dobra"                   DP_dobraValor(int jogador)
*    "=modPontos"               DP_modificaPontos(int valor, int jogador)
*    "=lerPontos"               DP_lerPontos(int jogador, int *val)
*    "=lerDP"                   DP_lerValorDadosPontos(int *val)
*    "=lerUltimoJogador"        DP_lerUltimoJogador(int *val)
*    "=destruir"                DP_destroiDadosPontos(void)
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include    "DadosPontos.h"

/* Tabela dos nomes dos comandos de teste específicos */

#define     CRIAR_DP			"=criar"
#define     DOBRA				"=dobra"
#define     MOD_PONTOS			"=modPontos"
#define     LER_PONTOS          "=lerPontos"
#define     LER_VALOR_DP        "=lerDP"
#define     LER_ULTIMO_JOGADOR  "=lerUltimoJogador"
#define     DESTROI_DP			"=destruir"


   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

	   DP_tpCondRet CondRetObtido   = DP_CondRetOk;
	   DP_tpCondRet CondRetEsperada = DP_CondRetFaltouMemoria;

      int ValorEsperado = 0 ;
      int ValorObtido   = 0  ;
      int ValorDado     = 0 ;
	  int ValorDado_2 = 0;

      int  NumLidos = -1 ;

      TST_tpCondRet Ret ;

      /* Testar Criar DadosPontos */

         if ( strcmp( ComandoTeste , CRIAR_DP) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            }

            CondRetObtido = DP_criaDadosPontos( ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar DadosPontos." );

         }

      /* Testar DP dobrar valor dado */

         else if ( strcmp( ComandoTeste , DOBRA) == 0 )
         {

            NumLidos = LER_LerParametros( "ii" ,
                               &ValorDado , &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            }

            CondRetObtido = DP_dobraValor( ValorDado ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao dobrar dados pontos." );

         }

      /* Testar DP modificar pontos */

         else if ( strcmp( ComandoTeste , MOD_PONTOS) == 0 )
         {

            NumLidos = LER_LerParametros( "iii" ,
                               &ValorDado, &ValorDado_2 , &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            }

            CondRetObtido = DP_modificaPontos( ValorDado, ValorDado_2 ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao modificar pontos." );

         } 

      /* Testar ler pontuacao */

         else if ( strcmp( ComandoTeste , LER_PONTOS) == 0 )
         {
			 NumLidos = LER_LerParametros("iii",
				 &ValorDado, &ValorEsperado, &CondRetEsperada);
			 if (NumLidos != 3)
			 {
				 return TST_CondRetParm;
			 }

			 CondRetObtido = DP_lerPontos(ValorDado, &ValorObtido);

			 Ret = TST_CompararInt(CondRetEsperada, CondRetObtido,
				 "Retorno errado ao ler pontos.");

			 if (Ret != TST_CondRetOK)
			 {
				 return Ret;
			 }

			 return TST_CompararInt(ValorEsperado, ValorObtido,
				 "Valor retornado por ler pontos esta errado.");

         }

      /* Testar DP ler valor do dados pontos */

         else if ( strcmp( ComandoTeste , LER_VALOR_DP) == 0 )
         {

			 NumLidos = LER_LerParametros("ii",
				 &ValorEsperado, &CondRetEsperada);
			 if (NumLidos != 2)
			 {
				 return TST_CondRetParm;
			 }

			 CondRetObtido = DP_lerValorDadosPontos(&ValorObtido);

			 Ret = TST_CompararInt(CondRetEsperada, CondRetObtido,
				 "Retorno errado ao ler valor do dados pontos.");

			 if (Ret != TST_CondRetOK)
			 {
				 return Ret;
			 }

			 return TST_CompararInt(ValorEsperado, ValorObtido,
				 "Valor do dados pontos esta errado.");

         }

         else if ( strcmp( ComandoTeste , LER_ULTIMO_JOGADOR) == 0 )
         {

			 NumLidos = LER_LerParametros("ii",
				 &ValorEsperado, &CondRetEsperada);
			 if (NumLidos != 2)
			 {
				 return TST_CondRetParm;
			 }

			 CondRetObtido = DP_lerUltimoJogador(&ValorObtido);

			 Ret = TST_CompararInt(CondRetEsperada, CondRetObtido,
				 "Retorno errado ao ler ultimo jogador a dobrar.");

			 if (Ret != TST_CondRetOK)
			 {
				 return Ret;
			 }

			 return TST_CompararInt(ValorEsperado, ValorObtido,
				 "Ultimo jogador esta errado.");

         }

         else if ( strcmp( ComandoTeste , DESTROI_DP ) == 0 )
         {
            NumLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            }

            CondRetObtido = DP_destroiDadosPontos( ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar DadosPontos." );

         } 

      return TST_CondRetNaoConhec ;

   }

