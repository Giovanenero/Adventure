#pragma once
#include "Obstaculo.h"

namespace Entidade {
    namespace Obstaculo {
        class Andaime :public Obstaculo
        {
        public:
            Andaime(Matematica::CoordenadaF pos);
            ~Andaime();
            void inicializacao();
            void atualizar();
        };
    }
}

