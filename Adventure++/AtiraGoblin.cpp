#include "AtiraGoblin.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
			AtiraGoblin::AtiraGoblin(Matematica::CoordenadaF posInicio, Jogador::Oriana* pOriana, Lista::ListaEntidade* ListaEntidadeMovimento) :
				Goblin(posInicio, pOriana, Ids::Ids::goblin_atira),
				pProjetil(nullptr),
				ListaEntidadeMovimento(ListaEntidadeMovimento)
            {
                inicializacao();
				carregarAtaque = 0.5f;
				tempoAtaque = 0.5f;
            }
            AtiraGoblin::~AtiraGoblin() {

            }
            void AtiraGoblin::inicializacao() {
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Goblin/goblinAtacando3.png", 12, Ids::Ids::goblin_ataca3, tamanho, Matematica::CoordenadaF(2.5f, 1.5f));
            }

			void AtiraGoblin::verificaProjetil() {
				//...
			}

			void AtiraGoblin::atualizar(const float tempo) {
				if (posicao.y > 600.f) {
					//teste...
					morrer = true;
				}
				atualizarTempoAtaque(tempo);
				Matematica::CoordenadaF distancia = pOriana->getPosicao() - getPosicao();
				if (!morrer && !tomarDano && !atacando) {
					velocidade.x = VELOCIDADE_GOBLIN_X;
					if (fabs(distancia.x) > DISTANCIA_GOBLIN_RECONHECER_X || fabs(distancia.y) > DISTANCIA_GOBLIN_RECONHECER_Y) {
						if (aleatorio == 0) {
							posicao.x += velocidade.x * tempo;
							ativarAndar(false);
						}
						else if (aleatorio == 1) {
							posicao.x -= velocidade.x * tempo;
							ativarAndar(true);
						}
						else {
							desligarAndar();
						}
						contAleatorio++;
						if (contAleatorio == 1000) {
							contAleatorio = 0;
							aleatorio = rand() % 3;
						}
					}
					else {
						desligarAndar();
						if (!jaAtirou) {
							ativarAtacar();
						}
						else {
							desligarAtacar();
							const float posProjetil = pProjetil->getPosicao().x;
							if (fabs(posProjetil - getPosicao().x) > DISTANCIA_PROJETIL_GOBLIN) {
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
            void AtiraGoblin::atualizarImagem(const float tempo) {
				if (morrer) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::goblin_morre);
					carregandoMorrendo += tempo;
				}
				else if (tomarDano) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo * 0.5f, Ids::Ids::goblin_tomaDano);
					carregandoTomarDano += tempo;
					if (carregandoTomarDano > carregarTomarDano) {
						tomarDano = false;
						carregandoTomarDano = 0.0f;
					}
				}
				else if (atacando) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo * 0.8f, Ids::Ids::goblin_ataca3);
					if (podeAtacar()) {
						//atacando = false;
						jaAtirou = true;
						tempoAtacando = 0.f;
						pProjetil = new Projetil(posicao, olharEsquerda, DANO_GOBLIN_PROJETIL);
						ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade*>(pProjetil));
					}
				}
				else if (andando) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::goblin_anda);
				}
				else {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::goblin_para);
				}
            }
			void AtiraGoblin::colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade) {
				//colisaoPlataforma(intersecao, pEntidade);
				if (pEntidade->getID() == Ids::Ids::plataforma) {
					noChao = true;
					colisaoPlataforma(intersecao, pEntidade);
				}
				else if (pEntidade->getID() == Ids::Ids::oriana) {
					if (pOriana->podeAtacar()) {
						podeTomarDano(pOriana->valorDano());
					}
				}
			}
        }
    }
}