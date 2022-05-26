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

	void AnimacaoEstatica::novaAnimacao(const char* caminhoTextura, Ids::Ids id) {
		LinhaAnimacaoEstatica* temp = new LinhaAnimacaoEstatica(caminhoTextura);
		if (temp == nullptr) {
			std::cout << "Nao foi possivel criar LinhaAnimacaoEstatica" << std::endl;
			exit(1);
		}
		mapAnimacaoEstatica.insert(std::pair<Ids::Ids, LinhaAnimacaoEstatica*>(id, temp));
		sf::IntRect tamanho = temp->getTamanho();

		corpo.setSize(sf::Vector2f(tamanho.width, tamanho.height));
		corpo.setOrigin(sf::Vector2f(tamanho.width, tamanho.height) / 2.0f);
	}

	void AnimacaoEstatica::atualizar(Ids::Ids id, Matematica::CoordenadaF pos, Matematica::CoordenadaF tam) {
		if (ID != id) { 
			ID = id; 
		}
		//teste... arrumar
		sf::RectangleShape shape(sf::Vector2f(tam.x, tam.y));
		corpo = shape;
		corpo.setPosition(sf::Vector2f(pos.x, pos.y));
		corpo.setTextureRect(mapAnimacaoEstatica[ID]->getTamanho());
		corpo.setTexture(mapAnimacaoEstatica[ID]->getTextura());
	}
}