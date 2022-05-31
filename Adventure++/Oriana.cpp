#include "Oriana.h"

namespace Entidade {
	namespace Personagem {
		namespace Jogador {
			Oriana::Oriana(Matematica::CoordenadaF posInicio) :
				Jogador(posInicio,
					Matematica::CoordenadaF(TAM_X_ORIANA, TAM_Y_ORIANA),
					Ids::Ids::oriana,
					TAMANHO_PULO_ORIANA),
				EhJogador1(true)
			{
				vida = VIDA_ORIANA;
				velocidade = Matematica::CoordenadaF(VELOCIDADE_X_ORIANA, VELOCIDADE_Y_ORIANA);
				inicializacao();
			}

			Oriana::~Oriana() { }

			//inicializa animacoes
			void Oriana::inicializacao() {
				pAnimacaoMovimento->novaAnimacao("textura/Jogador/orianaParada.png", 15, Ids::Ids::oriana_para, tamanho, Matematica::CoordenadaF(1.5f, 3.0f));
				pAnimacaoMovimento->novaAnimacao("textura/jogador/orianaMorrendo.png", 15, Ids::Ids::oriana_morre, tamanho, Matematica::CoordenadaF(1.5f, 3.0f));
				pAnimacaoMovimento->novaAnimacao("textura/Jogador/orianaPulando.png", 1, Ids::Ids::oriana_pula, tamanho, Matematica::CoordenadaF(1.2f, 1.8f));
				pAnimacaoMovimento->novaAnimacao("textura/Jogador/orianaCaindo.png", 1, Ids::Ids::oriana_cai, tamanho, Matematica::CoordenadaF(1.2f, 2.0f));
				pAnimacaoMovimento->novaAnimacao("textura/jogador/orianaAtacando.png", 22, Ids::Ids::oriana_ataca, tamanho, Matematica::CoordenadaF(3.0f, 3.2f));
				pAnimacaoMovimento->novaAnimacao("textura/jogador/orianaAndando.png", 8, Ids::Ids::oriana_anda, tamanho, Matematica::CoordenadaF(2.2f, 3.0f));
			}
			void Oriana::atualizar(const float tempo) {
				atualizarTempoAtaque(tempo);

				if (andando) {
					velocidade.x = VELOCIDADE_X_ORIANA;
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

			void Oriana::atualizarImagem(const float tempo) {
				if (!noChao) {
					if (!caindo) {
						pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::oriana_pula);
					}
					else {
						pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::oriana_cai);
					}
				}
				else if (atacando) {
					desligarAndar();
					//arrumar tempo...
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo + 0.5 * tempo, Ids::Ids::oriana_ataca);
				}
				else if (andando) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::oriana_anda);
				}
				else {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::oriana_para);
				}
			}
			void Oriana::executar() {
				//???
			}
		} //namespace Jogador
	} //namespace Personagem
} //namespace Entidade