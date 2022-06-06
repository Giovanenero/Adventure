#include "GerenciadorGrafico.h"

namespace Gerenciador {

	GerenciadorGrafico* GerenciadorGrafico::pGrafico = nullptr;
	float GerenciadorGrafico::tempo = 0.f;

	GerenciadorGrafico* GerenciadorGrafico::getGerenciadorGrafico() {
		if (pGrafico == nullptr) {
			pGrafico = new GerenciadorGrafico();
		}
		return pGrafico;
	}
	GerenciadorGrafico::GerenciadorGrafico():
		window(new sf::RenderWindow(sf::VideoMode(TELAX, TELAY), "Adventure++")),
		camera(sf::Vector2f(TELAX / 2, TELAY / 2), 
		sf::Vector2f(TELAX, TELAY)),
		Maptexturas(),
        fonte(),
		relogio() {}

	GerenciadorGrafico::~GerenciadorGrafico() {
		std::map<const char*, sf::Texture*>::iterator it = Maptexturas.begin();
		while (it != Maptexturas.end()) {
			delete(it->second);
			it++;
		}
		Maptexturas.clear();
		delete(window);
	}

	void GerenciadorGrafico::renderizacao(sf::RectangleShape* corpo) { 
		window->draw(*corpo);
	}

    void GerenciadorGrafico::renderizacao(sf::Text *texto) {
        window->draw(*texto);
    }
	
	void GerenciadorGrafico::mostrar() {
		if (window->isOpen()) {
			window->display();
		}
	}
	void GerenciadorGrafico::limpar() {
		if (window->isOpen()) {
			window->clear();
		}
	}
	bool GerenciadorGrafico::isWindowOpen() const {
		return window->isOpen();
	}
	void GerenciadorGrafico::fecharJanela() {
		window->close();
	}
	void GerenciadorGrafico::centralizarCamera(Matematica::CoordenadaF pos) {
		camera.setCenter(sf::Vector2f(pos.x, pos.y));
		window->setView(camera);
	}
	sf::Texture* GerenciadorGrafico::loadTexture(const char* caminhoTextura, sf::IntRect tamanho) {
		std::map<const char*, sf::Texture*>::iterator it = Maptexturas.begin();
		while (it != Maptexturas.end()) {
			if (!strcmp(it->first, caminhoTextura)) {
				return it->second;
			}
			it++;
		}
		//cria nova textura...
		sf::Texture* novaTextura = new sf::Texture();
		if (!novaTextura->loadFromFile(caminhoTextura, tamanho)) {
			std::cout << "ERRO: caminho " << caminhoTextura << " nao encontrado!" << std::endl;
			exit(1);
		}
		Maptexturas.insert(std::pair<const char*, sf::Texture*>(caminhoTextura, novaTextura));
		return novaTextura;

	}

    sf::Font *GerenciadorGrafico::carregarFonte() {
        if (!fonte) {
            fonte = new sf::Font();
            if (!fonte->loadFromFile(FONT_PATH)) {
                std::cout << "ERRO: fonte nao carregada!" << std::endl;
                exit(1);
            }
        }
        return fonte;
    }

	float GerenciadorGrafico::atualizartempo() {
		tempo = relogio.getElapsedTime().asSeconds();
		relogio.restart();
		return tempo;
	}

	sf::RenderWindow* GerenciadorGrafico::getWindow() {
		return window;
	}

}