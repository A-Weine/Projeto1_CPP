#include <iostream>
#include "bib_cores.h" // Inclui biblioteca de cores.
#include "bib_rede.h" // Inclui biblioteca da rede.
using namespace std;

void Desenhar(unsigned int, unsigned int);

void Espacos(unsigned char);

int main() {
	srand(unsigned(time(NULL)));

	// --------------------
	// Inicializa dados:
	// - Posi��o
	unsigned char posicao_atual_a = 0; // Inicializa vari�vel de posi��o do caminh�o do jogador A.
	unsigned char posicao_atual_b = 0; // Inicializa vari�vel de posi��o do caminh�o do jogador B.
	// - Velocidade
	unsigned char velocidade_a = 0; // Inicializa vari�vel de velocidade do caminh�o do jogador A.
	unsigned char velocidade_b = 0; // Inicializa vari�vel de velocidade do caminh�o do jogador B.
	// - Cores
	unsigned char cor_caminhao_a = verde; // Inicializa vari�vel de cor do caminh�o do jogador A.
	unsigned char cor_caminhao_b = vermelho; // Inicializa vari�vel de cor do caminh�o do jogador B.
	// - Estado da pista
	unsigned char estado_pista_a = 0; // Inicializa vari�vel de estado da pista do jogador A.
	unsigned char estado_pista_b = 0; // Inicializa vari�vel de estado da pista do jogador B.
	// --------------------
	int passo = 0; // Inicializa vari�vel de Frames.

	do
	{
		// ------------------
		// Limpa tela
		system("cls");
		// Desenha caminh�es
		Desenhar(posicao_atual_a, cor_caminhao_a);
		Desenhar(posicao_atual_b, cor_caminhao_b);
		// ------------------
		
		// ------------------------
		// Atualiza velocidade
		velocidade_a = rand() % 10 + 1;
		velocidade_b = rand() % 10 + 1;

		// Atualiza estado da pista
		estado_pista_a = rand() % 2;
		estado_pista_b = rand() % 2;
		// ------------------------
			
		// ----------------------------------
		// Transmite, recebe e processa dados do caminh�o do jogador A.
		Transmitir(passo, cor_caminhao_a, posicao_atual_a, velocidade_a, estado_pista_a); // Empacota os dados adquiridos do caminh�o A para vari�vel global.
		posicao_atual_a = Processar(Receber()); // Recebe e imprime os dados adquiridos do caminh�o A, tamb�m calcula pr�xima posi��o.
		// Calcula Pr�xima posi��o
		AjustarCor(cor_caminhao_a, preto);
		cout << "Proxima posicao: " << int(posicao_atual_a) << endl << endl; // Imprime a pr�xima posi��o do caminh�o A.
		ResetarCor();
		// ----------------------------------
	
		// ----------------------------------
		// Transmite, recebe e processa dados do caminh�o do jogador B.
		Transmitir(passo, cor_caminhao_b, posicao_atual_b, velocidade_b, estado_pista_b); // Empacota os dados adquiridos do caminh�o B para vari�vel global.
		posicao_atual_b = Processar(Receber()); // Recebe e imprime os dados adquiridos do caminh�o B, tamb�m calcula pr�xima posi��o.
		// Calcula Pr�xima posi��o
		AjustarCor(cor_caminhao_b, preto);
		cout << "Proxima posicao: " << int(posicao_atual_b); // Imprime a pr�xima posi��o do caminh�o B.
		ResetarCor();
		// ----------------------------------

		// -------------------------------
		// Aguarda pressionamento de tecla
		cout << "\n\n";
		AjustarCor(preto, branco);
		cout << right; cout.width(122); // Define o alinhamento do pr�ximo cout
		cout << "[Enter] Executar passo >\n\n";
		ResetarCor();
		system("pause > nul") ; // Pausa o programa para que seja poss�vel controlar a quantidade de passos.
		passo = passo + 1;
		// -------------------------------
	} while (posicao_atual_a <= 100 && posicao_atual_b <= 100);
	// --------------------
	// Limpa tela
	system("cls");
	// Desenha caminh�es
	Desenhar(posicao_atual_a, cor_caminhao_a);
	Desenhar(posicao_atual_b, cor_caminhao_b);

	cout << right; cout.width(70);
	cout << "Corrida Concluida" << endl;

	// Exibe resultados
	AjustarCor(preto, branco);
	cout << " Passos ";
	ResetarCor();
	cout << " ";

	cout << passo << "\n\n"; // Imprime o n�mero de passos.

	// Caminh�o A:
	AjustarCor(branco, cor_caminhao_a);
	cout << " Posicao A ";
	ResetarCor();
	cout << " ";

	AjustarCor(cor_caminhao_a, preto);
	cout << int(posicao_atual_a); // Imprime a posi��o final do caminh�o A.
	ResetarCor();
	cout << " ";

	AjustarCor(branco, cor_caminhao_a);
	cout << " Velocidade Media ";
	ResetarCor();
	cout << " ";

	cout << fixed;
	cout.precision(2); // Define n�mero de digitos ap�s a virgula para 2 em pontos flutuantes.

	AjustarCor(cor_caminhao_a, preto);
	cout << float(posicao_atual_a) / passo << "\n\n"; // Imprime a velocidade m�dia do caminh�o A.

	// Caminh�o B:
	AjustarCor(branco, cor_caminhao_b);
	cout << " Posicao B ";
	ResetarCor();
	cout << " ";

	AjustarCor(cor_caminhao_b, preto);
	cout << int(posicao_atual_b); // Imprime a posi��o final do caminh�o A.
	ResetarCor();
	cout << " ";

	AjustarCor(branco, cor_caminhao_b);
	cout << " Velocidade Media ";
	ResetarCor();
	cout << " ";

	AjustarCor(cor_caminhao_b, preto);
	cout << float(posicao_atual_b) / passo << endl; // Imprime a velocidade m�dia do caminh�o A.

	ResetarCor();
	// --------------------

	return 0;
}

void Desenhar(unsigned int posicao_atual, unsigned int cor_caminhao) { 
	// Desenha os caminh�es, ajusta suas cores e utiliza Espacos() para colocar espa�os brancos antes deles.
	cout << right; cout.width(posicao_atual);
	AjustarCor(cor_caminhao, preto); // Define os pr�ximos caracteres com a cor do caminh�o do jogador.
	cout << "\n\n";
	Espacos(posicao_atual);
	cout << "\xDB\xDB\xDB\xDB\xDB\xDB \xDB\xDC\xDC\n";
	Espacos(posicao_atual);
	cout << "\xDFOO\xDF\xDF\xDF\xDF\xDFO\xDF\n";

	cout << "--------------------";
	cout << "--------------------";
	cout << "--------------------";
	cout << "--------------------";
	cout << "--------------------";
	cout << "|-------------------";
	
	cout << right; cout.width(102); 
	cout << "100" << endl;
	ResetarCor();
}

void Espacos(unsigned char qtd) { while (qtd-- > 0) cout << ' '; } // Coloca espa�os em branco antes dos caminh�es.