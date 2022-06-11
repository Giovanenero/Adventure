#pragma once

#include "Menu.h"
#include "Estado.h"
#include "MaquinaEstados.h"

namespace Fase {
    class Fase;
}

class Principal;

namespace Estados {

    class MenuJogadores : public Menu, public Estados::Estado {

    private:
        Fase::Fase *fase;

    public:
        MenuJogadores(Principal* principal, Fase::Fase *f, IDestado id);
        ~MenuJogadores();
        void atualizar(const float dt);
        void renderizar();
        void resetEstado();
        virtual void executar();
    };

} // Estados
