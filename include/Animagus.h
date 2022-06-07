#pragma once
#include "Chefao.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            class Animagus: public Chefao
            {
            public:
                Animagus(Matematica::CoordenadaF posInicio, Jogador::Oriana* pOriana, Jogador::Hideo* pHideo);
                ~Animagus();
                void inicializacao();
                void atualizarImagem(const float tempo);
                const float getVelocidadeEspecifica() const;
                const short getPontuacao() const;
            };
        }
    }
}

