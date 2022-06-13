#include "AtiraEsqueleto.h"

#define PONTUACAO_ATIRAESQUELETO 200
#define DISTANCIA_PROJETIL_ESQUELETO 300.0f

#define CARREGAR_TOMAR_DANO_ATIRAESQUELETO 0.5f
#define CARREGAR_MORRER_ATIRAESQUELETO 0.35f
#define CARREGAR_ATAQUE_ATIRAESQUELETO 1.5f
#define TEMPO_ATAQUE_ATIRAESQUELETO 1.0f

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            AtiraEsqueleto::AtiraEsqueleto(Matematica::CoordenadaF posInicio, Jogador::Oriana* pOriana, Jogador::Hideo* pHideo, Lista::ListaEntidade* ListaEntidadeMovimento) :
                Esqueleto(posInicio, pOriana, pHideo, Ids::Ids::esqueleto_atira),
				Atirador(ListaEntidadeMovimento)
            {
                this->inicializacao();
            }

			AtiraEsqueleto::~AtiraEsqueleto() { }

            void AtiraEsqueleto::inicializacao() {
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Esqueleto/esqueletoAtacando3.png", 6, Ids::Ids::esqueleto_ataca3, tamanho, Matematica::CoordenadaF(2.5f, 1.2f));
				carregarTomarDano = CARREGAR_TOMAR_DANO_ATIRAESQUELETO;
				carregarMorrer = CARREGAR_MORRER_ATIRAESQUELETO;
				carregarAtaque = CARREGAR_ATAQUE_ATIRAESQUELETO;
				tempoAtaque = TEMPO_ATAQUE_ATIRAESQUELETO;
			}

            void AtiraEsqueleto::atualizar(const float tempo) {
				if (posicao.y > 600.f) {
					morrer = true;
				}
				atualizarTempoAtaque(tempo);
				Matematica::CoordenadaF distancia = jogadorMaisProximo(pOriana, pHideo, posicao)->getPosicao();
				if (!morrer && !tomarDano && !atacando) {
					if (fabs(distancia.y - posicao.y) > DISTANCIA_ESQUELETO_RECONHECER_Y && fabs(distancia.x - posicao.x) > DISTANCIA_ESQUELETO_RECONHECER_X) {
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