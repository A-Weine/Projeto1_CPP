#include <iostream>
#include "bib_pacote.h"
using namespace std;


unsigned int Empacotar(unsigned char passo, unsigned char cor_caminhao, unsigned char posicao_atual, unsigned char velocidade, unsigned char estado_pista) {
	unsigned int empacotar = 0;

	empacotar = empacotar | passo; // Empacota dados referente ao n�mero de passos nos 8 primeiros bits da vari�vel.

	empacotar = empacotar << 8;
	empacotar = empacotar | cor_caminhao; // Empacota dados referente � cor do caminh�o nos 8 bits subsequentes da vari�vel.

	empacotar = empacotar << 8;
	empacotar = empacotar | (posicao_atual << 1); // Empacota dados referente � posi��o atual do caminh�o nos 7 bits subsequentes da vari�vel.

	empacotar = empacotar << 7;
	empacotar = empacotar | (velocidade << 4); // Empacota dados referente � velocidade atual do caminh�o nos 4 bits subsequentes da vari�vel.

	empacotar = empacotar << 1;
	empacotar = empacotar | (estado_pista << 4); // Empacota dados referente ao estado da pista em 1 bit subsequente da vari�vel.

	return empacotar;
}


unsigned char Passo(unsigned int empacotado) {
	unsigned char passo = (empacotado >> 24); // Posiciona corretamente as informa��es sobre o n�mero de passos e transfere para vari�vel.

	return passo;
}

unsigned char Cor(unsigned int empacotado) {
	unsigned char cor_caminhao = (empacotado >> 16); // Posiciona corretamente as informa��es sobre a cor do caminh�o e transfere para vari�vel.

	return cor_caminhao;
}

unsigned char Posicao(unsigned int empacotado) {
	unsigned char posicao_atual = (127 & (empacotado >> 9)); // Posiciona corretamente as informa��es sobre a posi��o atual e transfere para vari�vel.

	return posicao_atual;
}

unsigned char Velocidade(unsigned int empacotado) {
	unsigned char velocidade = (15 & (empacotado >> 5)); // Posiciona corretamente as informa��es sobre a velocidade e transfere para vari�vel.

	return velocidade;
}

unsigned char Pista(unsigned int empacotado) {
	unsigned char estado_pista = (1 & (empacotado >> 4)); // Posiciona corretamente as informa��es sobre o estado da pista e transfere para vari�vel.

	return estado_pista;
}