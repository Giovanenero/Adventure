#pragma once

#include "SFML/Graphics.hpp"

namespace ElementoGrafico {
	class LinhaAnimacao
	{
	protected:
		sf::Texture* textura;
		sf::IntRect tamanho;
	public:
		LinhaAnimacao();
		~LinhaAnimacao();
		sf::IntRect getTamanho() const;
		sf::Texture* getTextura() const;
	};
}

