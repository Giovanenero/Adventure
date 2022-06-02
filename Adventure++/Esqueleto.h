#pragma once
#include "Inimigo.h"

#define TAMANHO_ESQUELETO_X 60.0f
#define TAMANHO_ESQUELETO_Y 60.0f
#define VIDA_ESQUELETO 100
#define DANO_ESQUELETO 20
#define DANO_ESQUELETO_PROJETIL 20
#define VELOCIDADE_ESQUELETO_X 80.0f
#define VELOCIDADE_ESQUELETO_Y 80.0f
#define DISTANCIA_ESQUELETO_RECONHECER_X 400.0f
#define DISTANCIA_ESQUELETO_RECONHECER_Y 100.0f

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            class Esqueleto: public Inimigo
            {
            public:
                Esqueleto(Matematica::CoordenadaF posInicio, Jogador::Oriana* pOriana, Ids::Ids id);
                ~Esqueleto();
                void inicializacao();
                virtual void atualizarImagem(const float tempo) = 0;

                const float getVelocidadeEspecifica() const;
            };
        }
    }
}

