#include <iostream>
#include "bib_pacote.h"
using namespace std;


unsigned int Empacotar(unsigned char passo, unsigned char cor_caminhao, unsigned char posicao_atual, unsigned char velocidade, unsigned char estado_pista) {
	unsigned int empacotar = 0;

	empacotar = empacotar | passo; // Empacota dados referente ao número de passos nos 8 primeiros bits da variável.

	empacotar = empacotar << 8;
	empacotar = empacotar | cor_caminhao; // Empacota dados referente à cor do caminhão nos 8 bits subsequentes da variável.

	empacotar = empacotar << 8;
	empacotar = empacotar | (posicao_atual << 1); // Empacota dados referente à posição atual do caminhão nos 7 bits subsequentes da variável.

	empacotar = empacotar << 7;
	empacotar = empacotar | (velocidade << 4); // Empacota dados referente à velocidade atual do caminhão nos 4 bits subsequentes da variável.

	empacotar = empacotar << 1;
	empacotar = empacotar | (estado_pista << 4); // Empacota dados referente ao estado da pista em 1 bit subsequente da variável.

	return empacotar;
}


unsigned char Passo(unsigned int empacotado) {
	unsigned char passo = (empacotado >> 24); // Posiciona corretamente as informações sobre o número de passos e transfere para variável.

	return passo;
}

unsigned char Cor(unsigned int empacotado) {
	unsigned char cor_caminhao = (empacotado >> 16); // Posiciona corretamente as informações sobre a cor do caminhão e transfere para variável.

	return cor_caminhao;
}

unsigned char Posicao(unsigned int empacotado) {
	unsigned char posicao_atual = (127 & (empacotado >> 9)); // Posiciona corretamente as informações sobre a posição atual e transfere para variável.

	return posicao_atual;
}

unsigned char Velocidade(unsigned int empacotado) {
	unsigned char velocidade = (15 & (empacotado >> 5)); // Posiciona corretamente as informações sobre a velocidade e transfere para variável.

	return velocidade;
}

unsigned char Pista(unsigned int empacotado) {
	unsigned char estado_pista = (1 & (empacotado >> 4)); // Posiciona corretamente as informações sobre o estado da pista e transfere para variável.

	return estado_pista;
}