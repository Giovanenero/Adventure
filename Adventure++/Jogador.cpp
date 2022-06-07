#include "Jogador.h"

#define VIDA_JOGADOR 100
#define DANO_JOGADOR 20
#define TAM_X_JOGADOR 80.f
#define TAM_Y_JOGADOR 80.f
#define VELOCIDADE_X_JOGADOR 160.0f
#define VELOCIDADE_Y_JOGADOR 0.0f
#define TAMANHO_PULO_JOGADOR 140.0f
//teste...
/*
#define TEMPO_ATAQUE_JOGADOR 0.4f
#define TEMPO_DANO_JOGADOR 0.6f
#define TEMPO_MORRE_JOGADOR 0.6f
*/


namespace Entidade {
	namespace Personagem {
		namespace Jogador {
			Jogador::Jogador(Matematica::CoordenadaF pos, Ids::Ids id) :
				Personagem(pos, 
				Matematica::CoordenadaF(TAM_X_JOGADOR, TAM_Y_JOGADOR),
				id,
				VIDA_JOGADOR,
				DANO_JOGADOR), 
				pular(true), 
				caindo(true) ,
				mudarAtaque(0),
				pontuacao(0)
			{ 
				velocidade = Matematica::CoordenadaF(VELOCIDADE_X_JOGADOR, VELOCIDADE_Y_JOGADOR);
			}

			Jogador::~Jogador() { }

			void Jogador::colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade) {
				if (pEntidade->getID() == Ids::Ids::plataforma || pEntidade->getID() == Ids::Ids::pedra) {
					colisaoPlataforma(intersecao, pEntidade);
					if (velocidade.y == 0.0f) {
						pular = true;
						noChao = true;
						caindo = false;
					}
				}
				else if (pEntidade->getID() == Ids::Ids::goblin_bate ||
					pEntidade->getID() == Ids::Ids::esqueleto_bate ||
					pEntidade->getID() == Ids::Ids::animagus) {
					Personagem* pPerson = dynamic_cast<Personagem*>(pEntidade);
					pPerson->ativarAtacar();
					if (pPerson->podeAtacar()) {
						pPerson->desligarAtacar();
						podeTomarDano(pPerson->valorDano());
						mudarAtaque = rand() % 5;
					}
				}
				else if (pEntidade->getID() == Ids::Ids::espinhos) {
					Obstaculo::Espinhos* pEsp = dynamic_cast<Obstaculo::Espinhos*>(pEntidade);
					if (pEsp->podeTomarDano()) {
						podeTomarDano(pEsp->getDano());
					}
				}
			}
			void Jogador::podePular() {
				if (pular) {
					velocidade.y = -sqrt(2.0f * GRAVIDADE * TAMANHO_PULO_JOGADOR);
					pular = false;
					noChao = false;
				}
			}
			void Jogador::atualizar(const float tempo) {
				atualizarTempoAtaque(tempo);
				if (andando) {
					velocidade.x = VELOCIDADE_X_JOGADOR;
					if (olharEsquerda) {
						velocidade.x = -velocidade.x;
					}
				}
				else {
					velocidade.x *= 0.5;
				}
				velocidade.y += GRAVIDADE * tempo;

				posicao.x += velocidade.x * tempo;
				posicao.y += velocidade.y * tempo;

				if (velocidade.y > 0) {
					caindo = true;
				}
				atualizarImagem(tempo);
				//carregandoDano += tempo;

				/*if (posicao.y >= 600.0f) {
					morrer = true;
					exit(1);
				}
				*/
				renderizar();
			}
			void Jogador::setPontuacao(int pontuacao) {
				this->pontuacao += pontuacao;
			}
			const int Jogador::getPontuacao() const {
				return (int)pontuacao;
			}
		}
	}
}