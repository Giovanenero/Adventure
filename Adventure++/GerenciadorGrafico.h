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
        sf::Font *fonte;

		static Gerenciador::GerenciadorGrafico* pGrafico;
		static float tempo;
		GerenciadorGrafico();
	public:
		~GerenciadorGrafico();

		static GerenciadorGrafico* getGerenciadorGrafico();
		void renderizacao(sf::RectangleShape* corpo);
        void renderizacao(sf::Text *texto);
		void mostrar();
		void limpar();
		bool isWindowOpen() const;
		void fecharJanela();
		void centralizarCamera(Matematica::CoordenadaF pos);
		sf::Texture* loadTexture (const char* caminhoTextura, sf::IntRect tamanho = {0, 0, 0, 0});
        sf::Font *carregarFonte(); //apenas uma fonte usada pelo jogo no momento.
		float atualizartempo();
		sf::RenderWindow* getWindow();
	};
}

