#pragma once
#include "Obstaculo.h"

namespace Entidade {
    namespace Obstaculo {
        class Ponte : public Obstaculo
        {
        public:
            Ponte(Matematica::CoordenadaF pos);
            ~Ponte();
            void inicializacao();
            void atualizar();
        };
    }
}

