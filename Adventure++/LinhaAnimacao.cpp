#include "LinhaAnimacao.h"

namespace ElementoGrafico {

	LinhaAnimacao::LinhaAnimacao():
		textura(nullptr), tamanho() { }

	LinhaAnimacao::~LinhaAnimacao() { if (textura) { textura = nullptr; } }

	sf::IntRect LinhaAnimacao::getTamanho() const { return tamanho; }
	sf::Texture* LinhaAnimacao::getTextura() const { return textura; }
}