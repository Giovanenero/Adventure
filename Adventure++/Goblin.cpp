#include "Goblin.h"

#define VIDA_GOBLIN 100
#define DANO_GOBLIN 5
#define TAMANHO_GOBLIN_X 50
#define TAMANHO_GOBLIN_Y 70
#define VELOCIDADE_GOBLIN_X 80.0f
#define VELOCIDADE_GOBLIN_Y 80.0f

namespace Entidade {
	namespace Personagem {
		namespace Inimigo {
			Goblin::Goblin(Matematica::CoordenadaF posInicio, Jogador::Oriana* pOriana, Jogador::Hideo* pHideo, Ids::Ids id):
				Inimigo(posInicio,
				Matematica::CoordenadaF(TAMANHO_GOBLIN_X, TAMANHO_GOBLIN_Y),
				id,
				pOriana,
				pHideo,
				Matematica::CoordenadaF(DISTANCIA_GOBLIN_RECONHECER_X, DISTANCIA_GOBLIN_RECONHECER_Y),
				VIDA_GOBLIN,
				DANO_GOBLIN)
			{
				velocidade = Matematica::CoordenadaF(VELOCIDADE_GOBLIN_X, VELOCIDADE_GOBLIN_Y);
				this->inicializacao();
				carregarMorrer = 0.35f;
				carregarTomarDano = 0.6f;
			}
			Goblin::~Goblin() { }

			void Goblin::inicializacao() {
				pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Goblin/goblinAndando.png", 8, Ids::Ids::goblin_anda, tamanho, Matematica::CoordenadaF(2.5f, 1.5f));
				pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Goblin/goblinDano.png", 4, Ids::Ids::goblin_tomaDano, tamanho, Matematica::CoordenadaF(2.5f, 1.5f));
				pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Goblin/goblinMorrendo.png", 4, Ids::Ids::goblin_morre, tamanho, Matematica::CoordenadaF(2.5f, 1.5f));
				pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Goblin/goblinParado.png", 4, Ids::Ids::goblin_para, tamanho, Matematica::CoordenadaF(2.5f, 1.5f));
			}
			const float Goblin::getVelocidadeEspecifica() const {
				return VELOCIDADE_GOBLIN_X;
			}
		}
	}
}