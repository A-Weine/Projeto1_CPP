#include <iostream>
#include "bib_rede.h"
#include "bib_pacote.h"
#include "bib_cores.h"
using namespace std;

unsigned int empacotado_rede = 0; // Vari�vel global com "informa��es da rede".

void Transmitir(unsigned char passo, unsigned char cor_caminhao, unsigned char posicao_atual, unsigned char velocidade, unsigned char estado_pista) {
	empacotado_rede = Empacotar(passo, cor_caminhao, posicao_atual, velocidade, estado_pista); // Empacota informa��es recebidas das vari�veis na vari�vel global da rede.
}

unsigned int Receber() {
	unsigned char passo_recebido = Passo(empacotado_rede); // Recebe n�mero de passos pela rede;
	unsigned char cor_caminhao_recebido = Cor(empacotado_rede); // Recebe a cor do caminh�o pela rede;
	unsigned char posicao_atual_recebido = Posicao(empacotado_rede); // Recebe a posi��o atual do caminh�o pela rede;
	unsigned char velocidade_recebido = Velocidade(empacotado_rede); // Recebe a velocidade do caminh�o pela rede;
	unsigned char estado_pista = Pista(empacotado_rede); // Recebe o estado da pista pela rede;

	cout << "Transmitindo dados..." << endl;

	AjustarCor(branco, cor_caminhao_recebido);
	cout << empacotado_rede << endl; // Informa o n�mero codificado recebido pela rede;
	ResetarCor();

	cout << "Recebendo dados..." << endl;
	
	AjustarCor(cor_caminhao_recebido, preto);
	cout << "Frame " << unsigned int(passo_recebido); // Imprime o n�mero de passos.
	cout << " Pos " << unsigned int(posicao_atual_recebido); // Imprime a posi��o atual.
	cout << " Vel " << unsigned int(velocidade_recebido); // Imprime a velocidade atual.
	cout << " Oil ";
	if (estado_pista == 0) { // Utilizado if e else que foram apresentados nos laborat�rios.
		cout << "false" << endl; // Imprime o estado da pista como falso(false) caso vari�vel seja igual a zero.
	}
	else {
		cout << "true" << endl; // Imprime o estado da pista como verdadeiro(true) caso vari�vel seja igual a um.
	}
	ResetarCor();

	cout << "Processando dados..." << endl;

	return empacotado_rede;
}

unsigned int Processar(unsigned int dado_rede) {
	unsigned int proxima_posicao = 0; // Inicializa vari�vel referente a pr�xima posi��o do caminh�o.

	unsigned int posicao_atual_recebido = Posicao(dado_rede); // Recebe posi��o atual do caminh�o pela rede.
	
	unsigned int velocidade_recebido = Velocidade(dado_rede); // Recebe velocidade do caminh�o pela rede.
	
	unsigned int estado_pista_recebido = Pista(dado_rede); // Recebe estado da pista pela rede.

	proxima_posicao = posicao_atual_recebido + velocidade_recebido - estado_pista_recebido; // C�lcula pr�xima posi��o do caminh�o.

	return proxima_posicao;
}