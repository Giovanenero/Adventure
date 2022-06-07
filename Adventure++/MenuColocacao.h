#pragma once

#include "Menu.h"
#include "Estado.h"
#include "Texto.h"
#include <vector>

namespace Estados {

    class MenuColocacao : public Menu, public Estados::Estado {
    private:
        std::vector<ElementoGrafico::Texto *> allPoints;
        std::vector<ElementoGrafico::Texto *>::iterator itr;

    public:
        MenuColocacao(Estados::MaquinaEstados *pSM = nullptr);

        ~MenuColocacao();

        void atualizar(const float dt);

        void renderizar();

        void resetEstado();

        void executar();

        void criarColocacao();

    };
}