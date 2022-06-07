#pragma once
#include "Goblin.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            class BateGoblin: public Goblin
            {
            private:
                short mudarAtaque;
            public:
                BateGoblin(Matematica::CoordenadaF posInicio, Jogador::Oriana* pOriana, Jogador::Hideo* pHideo);
                ~BateGoblin();
                void inicializacao();
                void atualizarImagem(const float tempo);
                const short getPontuacao() const;
            };
        }
    }
}

