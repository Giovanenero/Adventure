#include "BateGoblin.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            BateGoblin::BateGoblin(Matematica::CoordenadaF posInicio, Jogador::Oriana* pOriana):
                Goblin(posInicio, pOriana, Ids::Ids::goblin_bate)
            {
                inicializacao();
				carregarAtaque = 2.0f;
				tempoAtaque = 0.6f;
            }
            BateGoblin::~BateGoblin() {

            }
            void BateGoblin::inicializacao() {
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Goblin/goblinAtacando1.png", 8, Ids::Ids::goblin_ataca1, tamanho, Matematica::CoordenadaF(2.5f, 1.5f));
                pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Goblin/goblinAtacando2.png", 8, Ids::Ids::goblin_ataca2, tamanho, Matematica::CoordenadaF(2.5f, 1.5f));
            }
            void BateGoblin::atualizarImagem(const float tempo) {
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
					if (mudarAtaque == 0) {
						pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::goblin_ataca1);
					}
					else {
						pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::goblin_ataca2);
					}
				}
				else if (andando) {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::goblin_anda);
				}
				else {
					pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::goblin_para);
					mudarAtaque = rand() % 2;
				}
            }
        }
    }
}