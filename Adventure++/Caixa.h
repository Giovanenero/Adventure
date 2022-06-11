#pragma once
#include "Obstaculo.h"

namespace Entidade {
    namespace Obstaculo {
        class Caixa: public Obstaculo
        {
        private:
            bool empurrar = true;
        public:
            Caixa(Matematica::CoordenadaF posInicio);
            ~Caixa();
            void inicializacao();
            void atualizar();
            void setEmpurrar(bool empurrar) {
                this->empurrar = empurrar;
            }
            const bool getEmpurrar() const {
                return empurrar;
            }
        };
    }
}

