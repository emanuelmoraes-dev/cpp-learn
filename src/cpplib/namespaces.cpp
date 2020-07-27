#include <stdio.h>

namespace emdev_gaming {

	void attack() {
		printf("Você errou o tiro porque isso é um jogo!\n");
	}

}

namespace emdev_killer {
	
	void attack() {
		printf("Você acertou o tiro porque seu alvo é uma pessoa real!\n");
	}

}
