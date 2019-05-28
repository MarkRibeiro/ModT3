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
*     Este módulo implementa o modulo DadoPontos
*
***************************************************************************/

#include "DadosPontos.h"

struct dadosPontos {

	//ID do ultimo jogador (1 ou 2) que requisitou a dobra dos pontos
	int ultimo_jogador;

	//Valor atual do DadosPontos
	int mult;

	//Pontuacao dos jogadores
	int pontuacaoJogador1;
	int pontuacaoJogador2;

};

//Dado encapsulado
static DadosPontos * dp = NULL;

DP_tpCondRet DP_criaDadosPontos(void)
{
	if (dp != NULL) {
		DP_destroiDadosPontos();
	}

	dp = (DadosPontos *)malloc(sizeof(DadosPontos));

	if (dp == NULL)
	{
		return DP_CondRetFaltouMemoria;
	}

	//Primeira 'dobrada' pode ser feita por qualquer jogador entao ultimo_jogador inicializa com 0
	dp->ultimo_jogador = 0;

	//Multiplicador incializa com 1
	dp->mult = 1;

	//Pontuacao de ambos jogadores incializa com 0
	dp->pontuacaoJogador1 = 0;
	dp->pontuacaoJogador2 = 0;

	return DP_CondRetOk;
}

DP_tpCondRet DP_dobraValor(int jogador)
{
	if (dp == NULL)
	{
		return DP_CondRetNaoExiste;
	}

	//Verifica se ID do jogador � valido
	if (jogador != 1 && jogador != 2) {
		printf("ID do jogador invalido! Deve ser 1 ou 2\n");
		return DP_CondRetJogadorInvalido;
	}

	//Primeira 'dobrada'
	if (dp->ultimo_jogador == 0) {

		dp->mult = 2;
		dp->ultimo_jogador = jogador;

		return DP_CondRetOk;
	}

	//Verifica se jogador pode dobrar os pontos
	if (dp->ultimo_jogador == jogador) {
		printf("Este jogador n�o pode dobrar a pontuacao!\n");
		return DP_CondRetJogadorNaoPodeDobrar;
	}

	//Verifica se valor do multiplicador � maximo
	if (dp->mult == 64) {
		printf("Valor maximo do dado atingido!\n");
		return DP_CondRetValorMaximoDado;
	}

	dp->ultimo_jogador = jogador;
	dp->mult = dp->mult * 2;

	return DP_CondRetOk;
}

DP_tpCondRet DP_lerPontos(int jogador, int *val)
{
	if (dp == NULL)
	{
		return DP_CondRetNaoExiste;
	}

	//Verifica se ID do jogador � valido
	if (jogador != 1 && jogador != 2) {
		printf("ID do jogador invalido! Deve ser 1 ou 2\n");
		return DP_CondRetJogadorInvalido;
	}

	if (jogador == 1) {
		*val = dp->pontuacaoJogador1;
	}
	else
	{
		*val = dp->pontuacaoJogador2;
	}

	return DP_CondRetOk;

}

DP_tpCondRet DP_lerValorDadosPontos(int *val)
{
	if (dp == NULL) {
		return DP_CondRetNaoExiste;
	}
	*val = dp->mult;
	return DP_CondRetOk;
}

DP_tpCondRet DP_lerUltimoJogador(int *val)
{
	if (dp == NULL) {
		return DP_CondRetNaoExiste;
	}
	*val = dp->ultimo_jogador;
	return DP_CondRetOk;
}

DP_tpCondRet DP_modificaPontos(int valor, int jogador)
{
	if (dp == NULL) {
		return DP_CondRetNaoExiste;
	}

	//Verifica se ID do jogador � valido
	if (jogador != 1 && jogador != 2) {
		printf("ID do jogador invalido! Deve ser 1 ou 2\n");
		return DP_CondRetJogadorInvalido;
	}

	if (jogador == 1) {
		dp->pontuacaoJogador1 = dp->pontuacaoJogador1 + valor;
	}
	else
	{
		dp->pontuacaoJogador2 = dp->pontuacaoJogador2 + valor;
	}

	return DP_CondRetOk;

}

DP_tpCondRet DP_destroiDadosPontos()
{
	if (dp == NULL) {
		return DP_CondRetNaoExiste;
	}
	free(dp);
	return DP_CondRetOk;
}
