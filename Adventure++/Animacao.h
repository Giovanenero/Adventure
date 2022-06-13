#pragma once

#include "SFML/Graphics.hpp"
#include "GerenciadorGrafico.h"
#include "Ids.h"

#include <map>

/*
	Basicamente 70% da namespace ElementoGrafico foi baseado no tutorial:
	https://www.youtube.com/watch?v=KJJo9QPY8kI&list=PLSPev71NbUEBIQlT2QCd-gN6l_mNVw1cJ&index=7
*/

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

