/***************************************************************************
*  $MCD Módulo de definição: Módulo dado
*
*  Arquivo gerado:              TESTADADO.C
*  Letras identificadoras:      DAD
*
*  Projeto: Disciplina INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: mr - Mark Ribeiro
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data    Observações
*       3.00   mr   11/05/2019 Documentação
*       2.00   mr   05/05/2019 Final do desenvolvimento
*       1.00   mr   27/04/2019 Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Este módulo implementa um lançamento de dado
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo árvore:
*
*     =jogardados - DAD_JogaDados( <Int> )
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include    "DADO.H"

int dados[4] = {NULL, NULL, NULL, NULL};

/* Tabela dos nomes dos comandos de teste específicos */

#define     JOGAR_DAD_CMD          "=jogardados"

/*****  Código das funções exportadas pelo módulo  *****/

/***********************************************************************
*
*  $FC Função: TDAD Efetuar operações de teste específicas para dado
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     dado sendo testado.
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
      DAD_tpCondRet CondRetObtido   = DAD_CondRetOK;
      DAD_tpCondRet CondRetEsperada = DAD_CondRetFaltouMemoria;               

      char ValorEsperado = '?'  ;
      char ValorObtido   = '!'  ;
      char ValorRecebido = '\0' ;

      int  NumLidos = -1 ;
      int ind;
      int i;

      TST_tpCondRet Ret ;


      /*Testar PEC_CriaPeça*/

         if ( strcmp( ComandoTeste , JOGAR_DAD_CMD ) == 0 )
         {
            NumLidos = LER_LerParametros( "i", &CondRetEsperada ) ;

            if ( NumLidos != 1 )
            {
                 return TST_CondRetParm ;
            } //if

            CondRetObtido = DAD_JogaDados( dados );

            return TST_CompararInt( CondRetEsperada , CondRetObtido , "Retorno errado ao jogar." );

         } /*fim ativa: Testar PEC_CriaPeca*/

      return TST_CondRetNaoConhec ;

   } /* Fim função: TARV Efetuar operações de teste específicas para árvore */

/********** Fim do módulo de implementação: Módulo de teste específico **********/