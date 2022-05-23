#pragma once

#include "SFML/Graphics.hpp"
#include "Coordenada.h"

#include <iostream>
#include <string>
#include <map>

namespace Gerenciador {
	class GerenciadorGrafico
	{
	private:
		sf::RenderWindow* window;
		sf::View camera;
		sf::Clock relogio;
		std::map<const char*, sf::Texture*> Maptexturas;

		static Gerenciador::GerenciadorGrafico* pGrafico;
		static float tempo;
		GerenciadorGrafico();
	public:
		~GerenciadorGrafico();

		static GerenciadorGrafico* getGerenciadorGrafico();
		void renderizacao(sf::RectangleShape* corpo);
		void mostrar();
		void limpar();
		bool isWindowOpen() const;
		void fecharJanela();
		void centralizarCamera(Matematica::CoordenadaF pos);
		sf::Texture* loadTexture (const char* caminhoTextura, sf::IntRect tamanho = {0, 0, 0, 0});
		float atualizartempo();
		sf::RenderWindow* getWindow();
	};
}

