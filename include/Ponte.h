#pragma once
#include "Obstaculo.h"

namespace Entidade {
    namespace Obstaculo {
        class Ponte : public Obstaculo
        {
        private:
            short tipo_ponte;
        public:
            Ponte(Matematica::CoordenadaF pos, short tipo_ponte);
            ~Ponte();
            void inicializacao();
            void atualizar();
        };
    }
}

