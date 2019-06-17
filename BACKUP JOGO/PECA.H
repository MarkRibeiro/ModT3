/***************************************************************************
*  $MCD Módulo de definição: Módulo peça
*
*  Arquivo gerado:              PECA.H
*  Letras identificadoras:      PEC
*
*  Projeto: Disciplina INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: mr - Mark RIbeiro
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data    Observações
*       3.00   mr   11/05/2019 Documentaçâo
*       2.00   mr   10/05/2019 Final do desenvolvimento
*       1.00   mr   01/05/2019 Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Este módulo implementa um conjunto simples de funções para criar, 
*     destruir ou obter a cor de uma peça.
*
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
typedef struct peca Peca; 

/***********************************************************************
*
*  $TC Tipo de dados: PEC Condicoes de retorno
*
*
***********************************************************************/

   typedef enum {

            PEC_CondRetOK = 0 ,
                  /* Executou correto */

            PEC_CondRetPecaNaoExiste = 1 ,
                  /* peça não existe */

            PEC_CondRetFaltouMemoria = 2 ,
                  /* Faltou memória ao alocar dados */

            PEC_CondRetInvalida = 3
   			         /*Cor da Peca é invalida*/

        } PEC_tpCondRet ;


/***********************************************************************
*
*  $FC Função: PEC Criar peça
*
*  $ED Descrição da função
*     Cria uma nova peça com a cor recebida.
*
*  $FV Valor retornado
*     PEC_CondRetOK
*     PEC_CondRetFaltouMemoria
*
***********************************************************************/

   PEC_tpCondRet PEC_CriaPeca( Peca **p, char cor );


/***********************************************************************
*
*  $FC Função: PEC Obtem peça
*
*  $ED Descrição da função
*     Recebe uma peça e uma cor e diz se ela existe

*  $FV Valor retornado
*     PEC_CondRetOK
*     PEC_CondRetPecaNaoExiste
*     PEC_CondRetInvalida
*
***********************************************************************/

   PEC_tpCondRet PEC_ObterCorPeca ( Peca *p, char *cor );


/***********************************************************************
*
*  $FC Função: PEC Destroi peça
*
*  $ED Descrição da função
*     Recebe uma peça e a apaga da memoria
*
*  $FV Valor retornado
*     PEC_CondRetOK
*     PEC_CondRetPecaNaoExiste
*
***********************************************************************/

   PEC_tpCondRet PEC_DestroiPeca( Peca *p );
