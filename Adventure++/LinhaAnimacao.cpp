#include "LinhaAnimacao.h"

namespace ElementoGrafico {

	LinhaAnimacao::LinhaAnimacao(Matematica::CoordenadaF escala):
		textura(), 
		tamanho(),
		escala(sf::Vector2f(escala.x, escala.y)) { }

	LinhaAnimacao::~LinhaAnimacao() { if (textura) { textura = nullptr; } }

	sf::IntRect LinhaAnimacao::getTamanho() const { return tamanho; }
	
	sf::Texture* LinhaAnimacao::getTextura() const { return textura; }
	
	sf::Vector2f LinhaAnimacao::getEscala() const { return escala; }
}