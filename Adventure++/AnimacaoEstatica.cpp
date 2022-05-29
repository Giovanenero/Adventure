#include "AnimacaoEstatica.h"
#include "LinhaAnimacaoEstatica.h"

namespace ElementoGrafico {
	AnimacaoEstatica::AnimacaoEstatica():
		Animacao(), mapAnimacaoEstatica() { }

	AnimacaoEstatica::~AnimacaoEstatica() { 
		std::map < Ids::Ids, LinhaAnimacaoEstatica*>::iterator it = mapAnimacaoEstatica.begin();
		while (it != mapAnimacaoEstatica.end()) {
			delete(it->second);
			it->second = nullptr;
			it++;
		}
		mapAnimacaoEstatica.clear();
	}

	void AnimacaoEstatica::novaAnimacao(const char* caminhoTextura, Ids::Ids id, Matematica::CoordenadaF escala) {
		LinhaAnimacaoEstatica* temp = new LinhaAnimacaoEstatica(caminhoTextura);
		if (temp == nullptr) {
			std::cout << "Nao foi possivel criar LinhaAnimacaoEstatica" << std::endl;
			exit(1);
		}
		mapAnimacaoEstatica.insert(std::pair<Ids::Ids, LinhaAnimacaoEstatica*>(id, temp));
		sf::IntRect tamanhoRect = temp->getTamanho();

		this->escala = sf::Vector2f(escala.x, escala.y);
		corpo.setScale(this->escala);
		corpo.setSize(sf::Vector2f(tamanhoRect.width, tamanhoRect.height));
		corpo.setOrigin(sf::Vector2f(tamanhoRect.width, tamanhoRect.height) / 2.0f);
	}

	void AnimacaoEstatica::atualizar(Ids::Ids id, Matematica::CoordenadaF pos, Matematica::CoordenadaF tam) {
		if (ID != id) { 
			ID = id; 
		}

		//teste...
		corpo.setSize(sf::Vector2f(tam.x, tam.y));
		corpo.setOrigin(sf::Vector2f(tam.x, tam.y) / 2.f);
		corpo.setPosition(sf::Vector2f(pos.x, pos.y));
		corpo.setTextureRect(mapAnimacaoEstatica[ID]->getTamanho());
		corpo.setTexture(mapAnimacaoEstatica[ID]->getTextura());
	}
}