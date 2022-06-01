#include "Goblin.h"

namespace Entidade {
	namespace Personagem {
		namespace Inimigo {
			Goblin::Goblin(Matematica::CoordenadaF posInicio, Jogador::Oriana* pOriana):
				Inimigo(posInicio,
				Matematica::CoordenadaF(TAMANHO_GOBLIN_X, TAMANHO_GOBLIN_Y),
				Ids::Ids::goblin,
				pOriana,
				Matematica::CoordenadaF(DISTANCIA_GOBLIN_RECONHECER_X, DISTANCIA_GOBLIN_RECONHECER_Y),
				VIDA_GOBLIN,
				DANO_GOBLIN)
			{
				velocidade = Matematica::CoordenadaF(VELOCIDADE_GOBLIN_X, VELOCIDADE_GOBLIN_Y);
				inicializacao();
				//arrumar...
				carregarAtaque = 2.0f;
				tempoAtaque = 0.6f;
				carregarMorrer = 0.35f;
				carregarTomarDano = 0.6f;
			}
			Goblin::~Goblin() {

			}
			void Goblin::inicializacao() {
				pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Goblin/goblinAndando.png", 8, Ids::Ids::goblin_anda, tamanho, Matematica::CoordenadaF(2.5f, 1.5f));
				pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Goblin/goblinAtacando1.png", 8, Ids::Ids::goblin_ataca1, tamanho, Matematica::CoordenadaF(2.5f, 1.5f));
				pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Goblin/goblinAtacando2.png", 8, Ids::Ids::goblin_ataca2, tamanho, Matematica::CoordenadaF(2.5f, 1.5f));
				pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Goblin/goblinAtacando3.png", 12, Ids::Ids::goblin_ataca3, tamanho, Matematica::CoordenadaF(2.5f, 1.5f));
				pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Goblin/goblinDano.png", 4, Ids::Ids::goblin_tomaDano, tamanho, Matematica::CoordenadaF(2.5f, 1.5f));
				pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Goblin/goblinMorrendo.png", 4, Ids::Ids::goblin_morre, tamanho, Matematica::CoordenadaF(2.5f, 1.5f));
				pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Goblin/goblinParado.png", 4, Ids::Ids::goblin_para, tamanho, Matematica::CoordenadaF(2.5f, 1.5f));
				//pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Goblin/goblinBomba.png", 19, Ids::Ids::goblin_anda, tamanho, Matematica::CoordenadaF(1.0f, 1.0f));
			}
			void Goblin::atualizarImagem(const float tempo) {
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
					else if (mudarAtaque == 1) {
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
			void Goblin::executar() {
				//nada ainda
			}
		}
	}
}