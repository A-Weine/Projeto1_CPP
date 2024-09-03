Simulador de corrida de caminhões em C++

Este projeto implementa um jogo simples de corrida entre dois caminhões com uma simulação de rede.

**Características:**

* **Mecânica de jogo:** A corrida ocorre em turnos, avançando um frame a cada vez que a tecla ENTER é pressionada. A velocidade e a distância percorrida por cada caminhão são atualizadas aleatoriamente a cada turno.
* **Simulação de rede:** Os dados de cada caminhão (velocidade, posição, cor, etc.) são encapsulados em pacotes, simulando uma transmissão de dados em uma rede.
* **Eventos aleatórios:** A pista pode conter "manchas de óleo" que afetam a velocidade, desacelerando os caminhões em uma unidade de velocidade.
* **Condição de vitória:** O primeiro caminhão a ultrapassar a linha de chegada (representada por 100 caracteres '-') vence a corrida.

**Uso:**

Para jogar, basta pressionar a tecla Enter para avançar para o próximo frame.
