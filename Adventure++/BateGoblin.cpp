#include "BateGoblin.h"

#define PONTUACAO_BATEGOBLIN 500
#define CARREGAR_ATAQUE_BATEGOBLIN 5.5f
#define TEMPO_ATAQUE_BATEGOBLIN 0.6f

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            BateGoblin::BateGoblin(Matematica::CoordenadaF posInicio, Jogador::Oriana* pOriana, Jogador::Hideo* pHideo):
                Goblin(posInicio, pOriana, pHideo, Ids::Ids::goblin_bate),
				mudarAtaque(rand() % 2)
            {
                this->inicializacao();
            }
            BateGoblin::~BateGoblin() { }

            void BateGoblin::inicializacao() {
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Goblin/goblinAtacando1.png", 8, Ids::Ids::goblin_ataca1, tamanho, Matematica::CoordenadaF(2.5f, 1.5f));
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Goblin/goblinAtacando2.png", 8, Ids::Ids::goblin_ataca2, tamanho, Matematica::CoordenadaF(2.5f, 1.5f));
				carregarAtaque = CARREGAR_ATAQUE_BATEGOBLIN;
				tempoAtaque = TEMPO_ATAQUE_BATEGOBLIN;
			}

            void BateGoblin::atualizarImagem(const float tempo) {
				if (morrer) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::goblin_morre);
					carregandoMorrendo += tempo;
				}
				else if (tomarDano) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo * 0.5f, Ids::Ids::goblin_tomaDano);
					carregaTomarDano(tempo);
				}
				else if (atacando) {
					if (mudarAtaque == 0) {
						pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo * 0.8f, Ids::Ids::goblin_ataca1);
					}
					else {
						pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo * 0.8f, Ids::Ids::goblin_ataca2);
					}
					desligarAtacar();
				}
				else if (andando) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::goblin_anda);
				}
				else {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::goblin_para);
					mudarAtaque = rand() % 2;
				}
            }

			const short BateGoblin::getPontuacao() const {
				return PONTUACAO_BATEGOBLIN;
			}
        }
    }
}