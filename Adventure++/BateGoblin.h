#pragma once
#include "Goblin.h"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            class BateGoblin: public Goblin
            {
            private:
            public:
                BateGoblin(Matematica::CoordenadaF posInicio, Jogador::Oriana* pOriana);
                ~BateGoblin();
                void inicializacao();
                void atualizarImagem(const float tempo);
            };
        }
    }
}

