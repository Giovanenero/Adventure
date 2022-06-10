#pragma once

#define VIDA_GOBLIN 200
#define DANO_GOBLIN 20
#define DANO_GOBLIN_PROJETIL 20
#define TAMANHO_GOBLIN_X 50
#define TAMANHO_GOBLIN_Y 70
#define VELOCIDADE_GOBLIN_X 80.0f
#define VELOCIDADE_GOBLIN_Y 80.0f
#define DISTANCIA_GOBLIN_RECONHECER_X 200.0f
#define DISTANCIA_GOBLIN_RECONHECER_Y 80.0f

#include "Inimigo.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            class Goblin: public Inimigo
            {
            public:
                Goblin(Matematica::CoordenadaF posInicio, Jogador::Oriana* pOriana, Jogador::Hideo* pHideo, Ids::Ids id);
                ~Goblin();

                void inicializacao();
                const float getVelocidadeEspecifica() const;

                virtual const short getPontuacao() const = 0;
                virtual void atualizarImagem(const float tempo) = 0;
            };
        }
    }
}

