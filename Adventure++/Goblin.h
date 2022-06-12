#pragma once

#include "Inimigo.h"

#define DISTANCIA_GOBLIN_RECONHECER_X 400.0f
#define DISTANCIA_GOBLIN_RECONHECER_Y 80.0f
#define DANO_GOBLIN_PROJETIL 10

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

