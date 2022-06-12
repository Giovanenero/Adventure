#include "BateEsqueleto.h"

#define PONTUACAO_BATEESQUELETO 500
#define CARREGAR_TOMAR_DANO_BATEESQUELETO 0.5f
#define CARREGAR_MORRER_BATEESQUELETO 0.35f
#define CARREGAR_ATAQUE_BATEESQUELETO 1.6f
#define TEMPO_ATAQUE_BATEESQUELETO 1.6f

namespace Entidade {
	namespace Personagem {
		namespace Inimigo {
			BateEsqueleto::BateEsqueleto(Matematica::CoordenadaF posInicio, Jogador::Oriana* pOriana, Jogador::Hideo* pHideo):
				Esqueleto(posInicio, pOriana, pHideo, Ids::Ids::esqueleto_bate),
				mudarAtaque(rand()%2)
			{
				this->inicializacao();
			}
			BateEsqueleto::~BateEsqueleto() { }

			void BateEsqueleto::inicializacao() {
				pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Esqueleto/esqueletoAtacando1.png", 8, Ids::Ids::esqueleto_ataca1, tamanho, Matematica::CoordenadaF(2.5f, 1.2f));
				pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Esqueleto/esqueletoAtacando2.png", 8, Ids::Ids::esqueleto_ataca2, tamanho, Matematica::CoordenadaF(2.5f, 1.2f));
				carregarTomarDano = CARREGAR_TOMAR_DANO_BATEESQUELETO;
				carregarMorrer = CARREGAR_MORRER_BATEESQUELETO;
				carregarAtaque = CARREGAR_ATAQUE_BATEESQUELETO;
				tempoAtaque = TEMPO_ATAQUE_BATEESQUELETO;
			}

			void BateEsqueleto::atualizarImagem(const float tempo) {
				if (morrer) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo * 0.8f, Ids::Ids::esqueleto_morre);
					carregandoMorrendo += tempo;
				}
				else if (tomarDano) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo * 0.8f, Ids::Ids::esqueleto_tomaDano);
					carregaTomarDano(tempo);
				}
				else if (atacando) {
					if (mudarAtaque == 0) {
						pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::esqueleto_ataca1);
					}
					else {
						pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::esqueleto_ataca2);
					}
					desligarAtacar();
				}
				else if (andando) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::esqueleto_anda);
				}
				else {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::esqueleto_para);
					mudarAtaque = rand() % 2;
				}
			}

			const short BateEsqueleto::getPontuacao() const {
				return PONTUACAO_BATEESQUELETO;
			}
		}
	}
}