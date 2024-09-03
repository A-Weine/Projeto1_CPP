#include <iostream>
#include "bib_cores.h"
using namespace std;

void AjustarCor(unsigned char letra, unsigned char fundo) {
	cout << "\033[38;5;" << int(letra) << "m"; // Ajusta cor das letras do terminal para a cor desejada.

	cout << "\033[48;5;" << int(fundo) << "m"; // Ajusta cor do fundo do terminal para a cor desejada.
}

void ResetarCor() {
	cout << "\033[m"; // Retorna para cor padrão do terminal.
}