#pragma once


#include "Coordenada.h"
#include "SFML/Graphics.hpp"

namespace ElementoGrafico {
	class LinhaAnimacao
	{
	protected:
		sf::Texture* textura;
		sf::IntRect tamanho;
		sf::Vector2f escala;
	public:
		LinhaAnimacao(Matematica::CoordenadaF escala);
		~LinhaAnimacao();
		sf::IntRect getTamanho() const;
		sf::Texture* getTextura() const;
		sf::Vector2f getEscala() const;
	};
}

