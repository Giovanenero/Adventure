#include "Personagem.h"

namespace Entidade {
	namespace Personagem {
		Personagem::Personagem(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id, const int vida, Matematica::CoordenadaF vel) :
			EntidadeMovimento(pos, tam, id), vida(vida), morrer(false),
			olharEsquerda(false), velocidade(vel),
			tempoAtaque(TEMPOATAQUE), atacando(false), tempoAtacando(0.f),
			carregarAtaque(0.f) { }

		Personagem::~Personagem() { }

		void Personagem::setVida(int vida) { this->vida = vida; }

		int Personagem::getVida() const { return this->vida; }

		void Personagem::setMorrer(bool morrer) { this->morrer = morrer; }

		bool Personagem::getMorrer() const { return morrer; }
		
		void Personagem::setVelocidade(Matematica::CoordenadaF velocidade) { this->velocidade = velocidade; }
		
		Matematica::CoordenadaF Personagem::getVelocidade() { return velocidade; }


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
		const bool Personagem::podeAtacar() const {
			return ((carregarAtaque > tempoAtaque) ? true : false);
		}
		
		void Personagem::ativarAtacando() { atacando = true; }

		const bool Personagem::getAtacando() const { return atacando; }

		void Personagem::atualizaTempoAtacando(const float tempo) {
			if (atacando) {
				carregarAtaque = 0.f;
				tempoAtacando += tempo;
				if (tempoAtacando > tempoAtaque) {
					atacando = false;
				}
			}
			else {
				carregarAtaque += tempo;
				tempoAtacando = 0.f;
			}
		}
	}
}