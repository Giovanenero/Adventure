#pragma once
#include "Obstaculo.h"

namespace Entidade {
    namespace Obstaculo {
        class Espinhos: public Obstaculo
        {
        private:
            short contDano;
        public:
            Espinhos(Matematica::CoordenadaF pos);
            ~Espinhos();
            void inicializacao();
            void atualizar();
            const int getDano() const;
            const bool podeTomarDano();
        };
    }
}

