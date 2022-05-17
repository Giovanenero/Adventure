#pragma once

#include "GerenciadorGrafico.h"

namespace Gerenciador {
	class GerenciadorEvento
	{
	private:
		GerenciadorGrafico* pGrafico;
		sf::RenderWindow* window;
		//terminar...

		static GerenciadorEvento* pEvento;
		GerenciadorEvento();
	public:
		~GerenciadorEvento();
		static GerenciadorEvento* getGerenciadorEvento();
		void pollEvents();
	};
}
