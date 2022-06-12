#pragma once

#include "SFML/Graphics.hpp"
#include "GerenciadorGrafico.h"
#include "Ids.h"

#include <map>

namespace ElementoGrafico {

	class Animacao
	{
	protected:
		sf::RectangleShape corpo;
		Ids::Ids ID;

		static Gerenciador::GerenciadorGrafico* pGrafico;
	public:
		Animacao();
		~Animacao();
		static Gerenciador::GerenciadorGrafico* getGerenciadorGrafico();
		void renderizar();
		void setPosicao(Matematica::CoordenadaF pos);
	};
}

