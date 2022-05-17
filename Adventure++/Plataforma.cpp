#include "Plataforma.h"

namespace ElementoGrafico {

	Gerenciador::GerenciadorGrafico* Plataforma::pGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();

	Plataforma::Plataforma(const char* caminhoTextura, Matematica::CoordenadaF tam) :
		textura(pGrafico->loadTexture(caminhoTextura)), tamanho()
	{
		if (!textura) {
			std::cout << "ERRO: caminho " << caminhoTextura << " nao encontrado!" << std::endl;
			exit(1);
		}
		//arrumar...pq ta pegando a imagem toda
		tamanho.width = textura->getSize().x;
		tamanho.height = textura->getSize().y;
	}
	Plataforma::~Plataforma() { }

	sf::IntRect Plataforma::getTamanho() {
		return tamanho;
	}
	sf::Texture* Plataforma::getTextura() {
		return textura;
	}
}