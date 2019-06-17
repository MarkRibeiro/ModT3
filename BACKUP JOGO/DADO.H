/***************************************************************************
*  $MCD Módulo de definição: Módulo dado
*
*  Arquivo gerado:              DADO.H
*  Letras identificadoras:      DAD
*
*  Projeto: Disciplina INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: mr - Mark Ribeiro
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data    Observações
*       3.00   mr   11/05/2019 Documentação
*		2.00   mr   05/05/2019 Final do desenvolvimento
*       1.00   mr   27/04/2019 Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Este módulo implementa um lançamento de dados
*
***************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

/***********************************************************************
*
*  $TC Tipo de dados: DAD Condicoes de retorno
*
*
***********************************************************************/

	typedef enum {

	         DAD_CondRetOK = 0 ,
	               /* Executou correto */

	         DAD_CondRetFaltouMemoria = 1 ,
	               /* Faltou memória ao alocar dados */

	     } DAD_tpCondRet ;

/***********************************************************************
*
*  $FC Função: DAD Joga dados
*
*  $ED Descrição da função
*     Gera dois valores aleatorios e os retorna.
*     Caso os dois numeros sejam iguais retorna 4 numeros, todos igais.
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetFaltouMemoria
*
***********************************************************************/

	DAD_tpCondRet DAD_JogaDados(int *d);