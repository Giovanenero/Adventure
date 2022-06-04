#include "AtiraGoblin.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
			AtiraGoblin::AtiraGoblin(Matematica::CoordenadaF posInicio, Jogador::Oriana* pOriana, Lista::ListaEntidade* ListaEntidadeMovimento) :
				Goblin(posInicio, pOriana, Ids::Ids::goblin_atira),
				Atirador(ListaEntidadeMovimento)
            {
                this->inicializacao();
				carregarAtaque = 0.5f;
				tempoAtaque = 0.5f;
            }
            AtiraGoblin::~AtiraGoblin() {
            }
            void AtiraGoblin::inicializacao() {
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Goblin/goblinAtacando3.png", 12, Ids::Ids::goblin_ataca3, tamanho, Matematica::CoordenadaF(2.5f, 1.5f));
            }

			void AtiraGoblin::atualizar(const float tempo) {
				if (posicao.y > 2000.f) {
					//teste...
					morrer = true;
				}
				atualizarTempoAtaque(tempo);
				Matematica::CoordenadaF distancia = pOriana->getPosicao() - getPosicao();
				if (!morrer && !tomarDano && !atacando) {
					if (fabs(distancia.y) < DISTANCIA_GOBLIN_RECONHECER_X && fabs(distancia.x) > DISTANCIA_GOBLIN_RECONHECER_Y) {
						movimentoAleatorio(tempo);
					}
					else {
						desligarAndar();
						if (!jaAtirou) {
							ativarAtacar();
							carregarTempoExplosao = 0.0f;
						}
						else {
							if (carregarTempoExplosao > tempoExplosao) {
								jaAtirou = false;
							}
							desligarAtacar();

						}
						olharEsquerda = distancia.x >= 0.0f ? false : true;
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
						tempoAtacando = 0.f;
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
        }
    }
}