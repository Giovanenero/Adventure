#include "Goblin.h"

namespace Entidade {
	namespace Personagem {
		namespace Inimigo {
			Goblin::Goblin(Matematica::CoordenadaF posInicio, Jogador::Oriana* pOriana, Ids::Ids id):
				Inimigo(posInicio,
				Matematica::CoordenadaF(TAMANHO_GOBLIN_X, TAMANHO_GOBLIN_Y),
				id,
				pOriana,
				Matematica::CoordenadaF(DISTANCIA_GOBLIN_RECONHECER_X, DISTANCIA_GOBLIN_RECONHECER_Y),
				VIDA_GOBLIN,
				DANO_GOBLIN)
			{
				velocidade = Matematica::CoordenadaF(VELOCIDADE_GOBLIN_X, VELOCIDADE_GOBLIN_Y);
				inicializacao();
				carregarMorrer = 0.35f;
				carregarTomarDano = 0.6f;
			}
			Goblin::~Goblin() {

			}
			void Goblin::inicializacao() {
				pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Goblin/goblinAndando.png", 8, Ids::Ids::goblin_anda, tamanho, Matematica::CoordenadaF(2.5f, 1.5f));
				pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Goblin/goblinDano.png", 4, Ids::Ids::goblin_tomaDano, tamanho, Matematica::CoordenadaF(2.5f, 1.5f));
				pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Goblin/goblinMorrendo.png", 4, Ids::Ids::goblin_morre, tamanho, Matematica::CoordenadaF(2.5f, 1.5f));
				pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Goblin/goblinParado.png", 4, Ids::Ids::goblin_para, tamanho, Matematica::CoordenadaF(2.5f, 1.5f));
			}
		}
	}
}