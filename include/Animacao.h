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
		sf::Vector2f escala;
		Ids::Ids ID;

		static Gerenciador::GerenciadorGrafico* pGrafico;
	public:
		Animacao();
		~Animacao();
		static Gerenciador::GerenciadorGrafico* getGerenciadorGrafico();
		virtual void novaAnimacao();
		virtual void atualizar();
		void renderizar();
	};
}

