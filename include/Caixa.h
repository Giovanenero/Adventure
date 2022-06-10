#pragma once
#include "Obstaculo.h"

namespace Entidade {
    namespace Obstaculo {
        class Caixa: public Obstaculo
        {
        public:
            Caixa(Matematica::CoordenadaF posInicio);
            ~Caixa();
            void inicializacao();
            void atualizar();
        };
    }
}

