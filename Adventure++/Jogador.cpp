#include "Jogador.h"

#define VIDA_JOGADOR 100
#define DANO_JOGADOR 20
#define TAM_X_JOGADOR 50.f
#define TAM_Y_JOGADOR 80.f
#define VELOCIDADE_X_JOGADOR 160.0f
#define VELOCIDADE_Y_JOGADOR 0.0f
#define TAMANHO_PULO_JOGADOR 140.0f

#include "Caixa.h"

namespace Entidade {
	namespace Personagem {
		namespace Jogador {
			Jogador::Jogador(Matematica::CoordenadaF pos, Ids::Ids id) :
				Personagem(pos, 
				Matematica::CoordenadaF(TAM_X_JOGADOR, TAM_Y_JOGADOR),
				id,
				VIDA_JOGADOR,
				DANO_JOGADOR), 
				caindo(true) ,
				mudarAtaque(0),
				pontuacao(0)
			{ 
				velocidade = Matematica::CoordenadaF(VELOCIDADE_X_JOGADOR, VELOCIDADE_Y_JOGADOR);
			}

			Jogador::~Jogador() { }

			void Jogador::colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade) {
				if (pEntidade->getID() == Ids::Ids::caixa) {
					colisaoPlataforma(intersecao, pEntidade);
					Obstaculo::Caixa* pCaixa = static_cast<Obstaculo::Caixa*>(pEntidade);
					if (velocidade.x == 0.0f && !caindo && pCaixa->getEmpurrar() == true) {
						if (olharEsquerda) {
							pCaixa->setPosicao(Matematica::CoordenadaF(pCaixa->getPosicao().x - VELOCIDADE_X_JOGADOR * 0.004f, pCaixa->getPosicao().y));
						}
						else {
							pCaixa->setPosicao(Matematica::CoordenadaF(pCaixa->getPosicao().x + VELOCIDADE_X_JOGADOR * 0.004f, pCaixa->getPosicao().y));
						}
					}
					else {
						noChao = true;
						caindo = false;
					}
				}
				else if (pEntidade->getID() == Ids::Ids::plataforma || pEntidade->getID() == Ids::Ids::pedra || pEntidade->getID() == Ids::Ids::ponte || pEntidade->getID() == Ids::Ids::andaime) {
					colisaoPlataforma(intersecao, pEntidade);
					if (velocidade.y == 0.0f) {
						noChao = true;
						caindo = false;
					}
				}
				else if (pEntidade->getID() == Ids::Ids::goblin_bate ||
					pEntidade->getID() == Ids::Ids::esqueleto_bate ||
					pEntidade->getID() == Ids::Ids::animagus ||
					pEntidade->getID() == Ids::Ids::noturno) {
					Personagem* pPerson = static_cast<Personagem*>(pEntidade);
					pPerson->ativarAtacar();
					if (pPerson->podeAtacar()) {
						pPerson->desligarAtacar();
						podeTomarDano(pPerson->valorDano());
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
				/*
					Cinemática: Movimento Retilínio Uniformemente Variado(MRUV)
					Equação de Torricelli sendo aplicado na velocidade eixo y por
					sofrer o efeito da gravidade
				*/
				if (noChao) { 
					velocidade.y = -sqrt(2.0f * GRAVIDADE * TAMANHO_PULO_JOGADOR);
					noChao = false;
					caindo = false;
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
					velocidade.x *= 0.5f;
				}
				velocidade.y += GRAVIDADE * tempo;

				posicao.x += velocidade.x * tempo;
				posicao.y += velocidade.y * tempo;

				if (velocidade.y > 0.0f) {
					caindo = true;
				}

				atualizarImagem(tempo);
				renderizar();
			}
			void Jogador::setPontuacao(const int pontuacao) {
				this->pontuacao += pontuacao;
			}
			const int Jogador::getPontuacao() const {
				return (int)pontuacao;
			}
		}
	}
}