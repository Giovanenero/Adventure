#include "AtiraEsqueleto.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            AtiraEsqueleto::AtiraEsqueleto(Matematica::CoordenadaF posInicio, Jogador::Oriana* pOriana, Lista::ListaEntidade* ListaEntidadeMovimento) :
                Esqueleto(posInicio, pOriana, Ids::Ids::esqueleto_atira),
                Atirador(ListaEntidadeMovimento)
            {
                this->inicializacao();
				carregarTomarDano = 0.5f;
				carregarMorrer = 0.35f;
				carregarAtaque = 1.5f;
				tempoAtaque = 1.0f;
            }
            AtiraEsqueleto::~AtiraEsqueleto() {

            }
            void AtiraEsqueleto::inicializacao() {
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Esqueleto/esqueletoAtacando3.png", 6, Ids::Ids::esqueleto_ataca3, tamanho, Matematica::CoordenadaF(2.5f, 1.2f));
            }
            void AtiraEsqueleto::atualizar(const float tempo) {
				if (posicao.y > 600.f) {
					//teste...
					morrer = true;
				}
				atualizarTempoAtaque(tempo);
				Matematica::CoordenadaF distancia = pOriana->getPosicao() - getPosicao();
				if (!morrer && !tomarDano && !atacando) {
					if (fabs(distancia.y) < DISTANCIA_ESQUELETO_RECONHECER_Y && fabs(distancia.x) > DISTANCIA_ESQUELETO_RECONHECER_X) {
						movimentoAleatorio(tempo);
					}
					else {
						desligarAndar();
						if (!jaAtirou) {
							ativarAtacar();
						}
						else {
							desligarAtacar();
							const float posProjetil = pProjetil->getPosicao().x;
							if (fabs(posProjetil - getPosicao().x) > DISTANCIA_PROJETIL_ESQUELETO) {
								pProjetil->setExplodir(true);
								jaAtirou = false;
							}
							else if (pProjetil->getExplodir()) {
								jaAtirou = false;
							}
						}
						if (distancia.x >= 0.f) {
							olharEsquerda = false;
						}
						else {
							olharEsquerda = true;
						}
					}
				}
				velocidade.y += GRAVIDADE * tempo;
				posicao.y += velocidade.y * tempo;

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
					}
					//desligarAtacar();
				}
				else if (andando) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::esqueleto_anda);
				}
				else {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::esqueleto_para);
				}
            }
        }
    }
}