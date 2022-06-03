#include "Personagem.h"

namespace Entidade {
	namespace Personagem {
		Personagem::Personagem(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id, const int vida, const int dano) :
			Entidade(pos, tam, id), 
			morrer(false),
			olharEsquerda(false), 
			velocidade(Matematica::CoordenadaF(0.f, 0.f)),
			atacando(false),  
			andando(false), 
			noChao(false),
			pAnimacaoMovimento(nullptr),
			vida(vida),
			tomarDano(false),
			dano(dano),
			carregandoAtaque(0.0f),
			tempoAtacando(0.0f),
			carregandoMorrendo(0.0f),
			carregandoTomarDano(0.0f),
			carregarAtaque(0.0f),
			tempoAtaque(0.0f),
			carregarMorrer(0.0f),
			carregarTomarDano(0.0f)
		{
			//srand(time(NULL));
			pAnimacaoMovimento = new ElementoGrafico::AnimacaoMovimento();
			//arrumar velocidade...
		}
		Personagem::~Personagem() { 
			/*
			if (pAnimacaoMovimento) {
				delete(pAnimacaoMovimento);
				pAnimacaoMovimento = nullptr;
			}
			*/
		}

		void Personagem::setVida(int vida) { this->vida = vida; }

		int Personagem::getVida() const { return this->vida; }

		void Personagem::setMorrer(bool morrer) { this->morrer = morrer; }

		bool Personagem::getMorrer() const { return morrer; }
		
		void Personagem::setVelocidade(Matematica::CoordenadaF velocidade) { this->velocidade = velocidade; }
		
		Matematica::CoordenadaF Personagem::getVelocidade() { return velocidade; }

		void Personagem::renderizar() {
			pAnimacaoMovimento->renderizar();
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
				velocidade.x = 0.f;
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
		void Personagem::atualizarTempoAtaque(const float tempo) {
			if (atacando) {
				carregandoAtaque = 0.f;
				tempoAtacando += tempo;
				if (tempoAtacando > tempoAtaque) {
					atacando = false;
				}
			}
			else {
				carregandoAtaque += tempo;
				tempoAtacando = 0.f;
			}
		}
		void Personagem::ativarAndar(bool paraEsquerda) {
			andando = true;
			olharEsquerda = paraEsquerda;
		}
		void Personagem::ativarAtacar() {
			atacando = true;
		}
		void Personagem::desligarAtacar() {
			atacando = false;
		}
		void Personagem::desligarAndar() {
			andando = false;
		}
		void Personagem::podeTomarDano(int dano) {
			vida = vida - dano;
			if (vida <= 0) {
				morrer = true;
			}
			else {
				tomarDano = true;
			}
		}
		const int Personagem::valorDano() const {
			return dano;
		}
		const bool Personagem::podeMorrer() const {
			return (carregandoMorrendo > carregarMorrer) ? true : false;
		}
		const bool Personagem::podeAtacar() const {
			return (tempoAtacando > carregarAtaque) ? true : false;
		}
		void Personagem::carregaTomarDano(const float tempo) {
			carregandoTomarDano += tempo;
			if (carregandoTomarDano > carregarTomarDano) {
				tomarDano = false;
				carregandoTomarDano = 0.0f;
			}
		}
	}
}