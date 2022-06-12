#include "AtiraGoblin.h"

#define PONTUACAO_ATIRAGOBLIN 200
#define DISTANCIA_PROJETIL_GOBLIN 500.f
#define CARREGAR_ATAQUE_ATIRAGOBLIN 0.5f
#define TEMPO_ATAQUE_ATIRAGOBLIN 0.5f

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
			AtiraGoblin::AtiraGoblin(Matematica::CoordenadaF posInicio, Jogador::Oriana* pOriana, Jogador::Hideo* pHideo, Lista::ListaEntidade* ListaEntidadeMovimento) :
				Goblin(posInicio, pOriana, pHideo, Ids::Ids::goblin_atira),
				Atirador(ListaEntidadeMovimento)
            {
                this->inicializacao();
            }
            AtiraGoblin::~AtiraGoblin() { }

            void AtiraGoblin::inicializacao() {
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Goblin/goblinAtacando3.png", 12, Ids::Ids::goblin_ataca3, tamanho, Matematica::CoordenadaF(2.5f, 1.5f));
				carregarAtaque = CARREGAR_ATAQUE_ATIRAGOBLIN;
				tempoAtaque = TEMPO_ATAQUE_ATIRAGOBLIN;
			}

			void AtiraGoblin::atualizar(const float tempo) {
				if (posicao.y > 600.f) {
					morrer = true;
				}
				atualizarTempoAtaque(tempo);
				Matematica::CoordenadaF distancia = jogadorMaisProximo(pOriana, pHideo, posicao)->getPosicao();
				if (!morrer && !tomarDano && !atacando) {
					if (fabs(distancia.y - posicao.y) > DISTANCIA_GOBLIN_RECONHECER_Y && fabs(distancia.x - posicao.x) > DISTANCIA_GOBLIN_RECONHECER_X) {
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
							desligarAtacar();
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

            void AtiraGoblin::atualizarImagem(const float tempo) {
				if (morrer) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::goblin_morre);
					carregandoMorrendo += tempo;
				}
				else if (tomarDano) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo * 0.5f, Ids::Ids::goblin_tomaDano);
					carregaTomarDano(tempo);
				}
				else if (atacando) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo * 0.8f, Ids::Ids::goblin_ataca3);
					if (podeAtacar()) {
						criarProjetil(posicao, olharEsquerda, DANO_GOBLIN_PROJETIL);
						desligarAtacar();
					}
				}
				else if (andando) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::goblin_anda);
				}
				else {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::goblin_para);
				}
            }

			const short AtiraGoblin::getPontuacao() const {
				return PONTUACAO_ATIRAGOBLIN;
			}
        }
    }
}