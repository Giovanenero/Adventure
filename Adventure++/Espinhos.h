#pragma once
#include "Obstaculo.h"

#define TOMA_DANO 800

namespace Entidade {
    namespace Obstaculo {
        class Espinhos: public Obstaculo
        {
        private:
            //teste...
            short contAux = 0;
        public:
            Espinhos(Matematica::CoordenadaF pos);
            ~Espinhos();
            void atualizar();
            void inicializacao();
            const int getDano() const;
            const bool podeTomarDano() {
                contAux++;
                if (contAux >= TOMA_DANO) {
                    contAux = 0;
                    return true;
                }
                return false;
            }
        };
    }
}

