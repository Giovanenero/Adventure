#pragma once
#include "Inimigo.h"

#define DISTANCIA_ESQUELETO_RECONHECER_X 400.0f
#define DISTANCIA_ESQUELETO_RECONHECER_Y 80.0f
#define DANO_ESQUELETO_PROJETIL 20

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            class Esqueleto: public Inimigo
            {
            public:
                Esqueleto(Matematica::CoordenadaF posInicio, Jogador::Oriana* pOriana, Jogador::Hideo* pHideo, Ids::Ids id);
                ~Esqueleto();
                void inicializacao();
                virtual void atualizarImagem(const float tempo) = 0;

                const float getVelocidadeEspecifica() const;
                virtual const short getPontuacao() const = 0;
            };
        }
    }
}

