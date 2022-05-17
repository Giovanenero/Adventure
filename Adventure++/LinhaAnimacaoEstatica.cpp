#include "LinhaAnimacaoEstatica.h"

namespace ElementoGrafico {

	LinhaAnimacaoEstatica::LinhaAnimacaoEstatica(const char* caminhoTextura):
		LinhaAnimacao()
	{
		textura = Animacao::getGerenciadorGrafico()->loadTexture(caminhoTextura);
		if (!textura) {
			std::cout << "caminho " << caminhoTextura << " nao encontrado!" << std::endl;
			exit(1);
		}
		tamanho.width = textura->getSize().x;
		tamanho.height = textura->getSize().y;
	}
	LinhaAnimacaoEstatica::~LinhaAnimacaoEstatica() { }
}