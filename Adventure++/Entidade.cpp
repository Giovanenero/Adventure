#include "Entidade.h"

namespace Entidade {
	Entidade::Entidade(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id):
		Ente(id), posicao(pos), tamanho(tam), velocidade(Matematica::CoordenadaF(0.0f, 0.0f)) { }

	Entidade::~Entidade() { }
	void Entidade::setPosicao(Matematica::CoordenadaF pos) { posicao = pos; }
	Matematica::CoordenadaF Entidade::getPosicao() const { return posicao; }
	void Entidade::setTamanho(Matematica::CoordenadaF tam) { tamanho = tam; }
	Matematica::CoordenadaF Entidade::getTamanho() const { return tamanho; }
	void Entidade::setVelocidade(Matematica::CoordenadaF velocidade) { this->velocidade = velocidade; }
	Matematica::CoordenadaF Entidade::getVelocidade() const { return velocidade; }
	Ids::Ids Entidade::getID() const { return ID; }

	void Entidade::colisaoPlataforma(Matematica::CoordenadaF intersecao, Entidade* pEntidade) {
		/*
			baseado no tutorial: https://www.youtube.com/watch?v=mxZMK7ZqFtE
		*/
		Matematica::CoordenadaF posEntidade = pEntidade->getPosicao();
		Matematica::CoordenadaF tamEntidade = pEntidade->getTamanho();
		if (intersecao.x > intersecao.y) { //colisao na direcao de x
			if (posicao.x < posEntidade.x) {
				posicao.x += intersecao.x;
			}
			else {
				posicao.x -= intersecao.x;
			}
			velocidade.x = 0.f;
		}
		else {
			if (posicao.y < posEntidade.y) { // colisao na direcao de y
				posicao.y += intersecao.y;
			}
			else {
				posicao.y -= intersecao.y;
			}
			velocidade.y = 0.f;
		}
	}
}