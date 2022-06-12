#include "AnimacaoMovimento.h"
#include "LinhaAnimacaoMovimento.h"

namespace ElementoGrafico {
	AnimacaoMovimento::AnimacaoMovimento():
		Animacao(), 
		mapAnimacaoMovimento() { }

	AnimacaoMovimento::~AnimacaoMovimento() { 
		std::map<Ids::Ids, LinhaAnimacaoMovimento*>::iterator it = mapAnimacaoMovimento.begin();
		while (it != mapAnimacaoMovimento.end()) {
			delete(it->second);
			it->second = nullptr;
			it++;
		}
		mapAnimacaoMovimento.clear();
	}

	void AnimacaoMovimento::novaAnimacao(const char* caminhoTextura, unsigned int contaImagem, Ids::Ids id, Matematica::CoordenadaF tam, Matematica::CoordenadaF escala) {
		LinhaAnimacaoMovimento* temp = new LinhaAnimacaoMovimento(caminhoTextura, contaImagem, escala);
		if (temp == nullptr) {
			std::cout << "Nao foi possivel criar LinhaAnimacaoMovimento" << std::endl;
			exit(1);
		}
		mapAnimacaoMovimento.insert(std::pair<Ids::Ids, LinhaAnimacaoMovimento*>(id, temp));
		sf::IntRect tamanho = temp->getTamanho();
		corpo.setSize(sf::Vector2f(tamanho.width, tamanho.height));
		corpo.setOrigin(sf::Vector2f(tamanho.width, tamanho.height) / 2.0f);
	}
	void AnimacaoMovimento::atualizar(Matematica::CoordenadaF pos, const bool Esquerda, const float tempo, Ids::Ids id) {
		if (ID != id) {
			ID = id;
		}
		mapAnimacaoMovimento[ID]->atualizar(Esquerda, tempo);
		corpo.setScale(mapAnimacaoMovimento[ID]->getEscala());
		corpo.setPosition(sf::Vector2f(pos.x, pos.y));
		corpo.setTextureRect(mapAnimacaoMovimento[ID]->getTamanho());
		corpo.setTexture(mapAnimacaoMovimento[ID]->getTextura());
	}
}