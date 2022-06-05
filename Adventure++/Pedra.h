#pragma once
#include "Obstaculo.h"

namespace Entidade {
    namespace Obstaculo {
        class Pedra: public Obstaculo
        {
        public:
            Pedra(Matematica::CoordenadaF pos);
            ~Pedra();
            void inicializacao();
            void atualizar();
        };
    }
}

