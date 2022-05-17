#include "Personagem.h"

namespace Entidade {
	namespace Personagem {
		Personagem::Personagem(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id) :
			EntidadeMovimento(pos, tam, id), vida(100)
		{

		}
		Personagem::~Personagem() {

		}
		void Personagem::setVida(int vida) { this->vida = vida; }
		int Personagem::getVida() const { return this->vida; }
		void Personagem::tomarDano(const int dano) {
			vida -= dano;
			if (vida <= 0) {
				morrer = true;
			}
		}
		void Personagem::colisaoPlataforma(Matematica::CoordenadaF intersecao, Entidade* pEntidade) {
			Matematica::CoordenadaF posEntidade = pEntidade->getPosicao();
			Matematica::CoordenadaF tamEntidade = pEntidade->getTamanho();
			//colisao na direcao de x
			if (intersecao.x > intersecao.y) {
				if (posicao.x < posEntidade.x) {
					posicao.x += intersecao.x;
				}
				else {
					posicao.x -= intersecao.x;
				}
				velocidade.x *= 0.f;
			} 
			// colisao na direcao de y
			else {
				if (posicao.y < posEntidade.y) {
					posicao.y += intersecao.y;
				}
				else {
					posicao.y -= intersecao.y;
				}
				velocidade.y = 0.f;
			}
		}
	}
}