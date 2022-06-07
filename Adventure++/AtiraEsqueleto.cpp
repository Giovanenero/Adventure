#include "AtiraEsqueleto.h"

#define PONTUACAO_ATIRAESQUELETO 200

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            AtiraEsqueleto::AtiraEsqueleto(Matematica::CoordenadaF posInicio, Jogador::Oriana* pOriana, Jogador::Hideo* pHideo, Lista::ListaEntidade* ListaEntidadeMovimento) :
                Esqueleto(posInicio, pOriana, pHideo, Ids::Ids::esqueleto_atira),
				Atirador(ListaEntidadeMovimento)
            {
                this->inicializacao();
				carregarTomarDano = 0.5f;
				carregarMorrer = 0.35f;
				carregarAtaque = 1.5f;
				tempoAtaque = 1.0f;
            }
            AtiraEsqueleto::~AtiraEsqueleto() { }

            void AtiraEsqueleto::inicializacao() {
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Esqueleto/esqueletoAtacando3.png", 6, Ids::Ids::esqueleto_ataca3, tamanho, Matematica::CoordenadaF(2.5f, 1.2f));
            }
            void AtiraEsqueleto::atualizar(const float tempo) {
				if (posicao.y > 600.f) {
					morrer = true;
				}
				atualizarTempoAtaque(tempo);
				Matematica::CoordenadaF distancia = jogadorMaisProximo(pOriana, pHideo, posicao)->getPosicao();
				if (!morrer && !tomarDano && !atacando) {
					if (fabs(distancia.y - posicao.y) > DISTANCIA_ESQUELETO_RECONHECER_Y || fabs(distancia.x - posicao.x) > DISTANCIA_ESQUELETO_RECONHECER_X) {
						movimentoAleatorio(tempo);
					}
					else {
						desligarAndar();
						if (!jaAtirou) {
							ativarAtacar();
							carregarTempoExplosao = 0.0f;
						}
						else {
							if (carregarTempoExplosao > TEMPO_PROJETIL_EXPLOSAO) {
								jaAtirou = false;
							}
						}
						olharEsquerda = ((distancia.x - posicao.x) > 0.0f) ? false : true;
					}
				}
				velocidade.y += GRAVIDADE * tempo;
				posicao.y += velocidade.y * tempo;

				//teste...
				carregarTempoExplosao += tempo;
				atualizarImagem(tempo);
				renderizar();
            }
            void AtiraEsqueleto::atualizarImagem(const float tempo) {
				if (morrer) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::esqueleto_morre);
					carregandoMorrendo += tempo;
				}
				else if (tomarDano) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo * 0.5f, Ids::Ids::esqueleto_tomaDano);
					carregaTomarDano(tempo);
				}
				else if (atacando) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo * 0.3f, Ids::Ids::esqueleto_ataca3);
					if (podeAtacar()) {
						tempoAtacando = 0.f;
						criarProjetil(posicao, olharEsquerda, DANO_ESQUELETO_PROJETIL);
						desligarAtacar();
					}
				}
				else if (andando) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::esqueleto_anda);
				}
				else {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::esqueleto_para);
				}
            }
			const short AtiraEsqueleto::getPontuacao() const {
				return PONTUACAO_ATIRAESQUELETO;
			}
        }
    }
}