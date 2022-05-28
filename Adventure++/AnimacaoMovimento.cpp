#include "AnimacaoMovimento.h"
#include "LinhaAnimacaoMovimento.h"

namespace ElementoGrafico {
	AnimacaoMovimento::AnimacaoMovimento():
		Animacao(), mapAnimacaoMovimento() { }

	AnimacaoMovimento::~AnimacaoMovimento() { 
		std::map<Ids::Ids, LinhaAnimacaoMovimento*>::iterator it = mapAnimacaoMovimento.begin();
		while (it != mapAnimacaoMovimento.end()) {
			delete(it->second);
			it->second = nullptr;
			it++;
		}
		mapAnimacaoMovimento.clear();
	}
	void AnimacaoMovimento::novaAnimacao(const char* caminhoTextura, unsigned int contaImagem, Ids::Ids id) {
		LinhaAnimacaoMovimento* temp = new LinhaAnimacaoMovimento(caminhoTextura, contaImagem);
		if (temp == nullptr) {
			std::cout << "Nao foi possivel criar LinhaAnimacaoMovimento" << std::endl;
			exit(1);
		}
		mapAnimacaoMovimento.insert(std::pair<Ids::Ids, LinhaAnimacaoMovimento*>(id, temp));
		this->escala = sf::Vector2f(escala.x, escala.y);
		sf::IntRect tamanho = temp->getTamanho();
		//teste
		corpo.setSize(sf::Vector2f(tamanho.width, tamanho.height));
		corpo.setOrigin(sf::Vector2f(tamanho.width, tamanho.height) / 2.0f);
		corpo.setScale(this->escala);
		std::cout << corpo.getScale().x << " ";
	}
	void AnimacaoMovimento::atualizar(Matematica::CoordenadaF pos, bool Esquerda, float tempo, Ids::Ids id, Matematica::CoordenadaF tam, Matematica::CoordenadaF escala) {
		if (ID != id) {
			ID = id;
			//mapAnimacaoMovimento[ID]->resetar();
		}
		mapAnimacaoMovimento[ID]->atualizar(Esquerda, tempo);

		corpo.setScale(sf::Vector2f(escala.x, escala.y));
		corpo.setSize(sf::Vector2f(tam.x, tam.y));
		corpo.setOrigin(sf::Vector2f(tam.x, tam.y) / 2.0f);
		corpo.setPosition(sf::Vector2f(pos.x, pos.y));
		corpo.setTextureRect(mapAnimacaoMovimento[ID]->getTamanho());
		corpo.setTexture(mapAnimacaoMovimento[ID]->getTextura());

	}
}