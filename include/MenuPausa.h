#pragma once

#include "Menu.h"
#include "Estado.h"
#include "MaquinaEstados.h"

namespace Estados {

    class MenuPausa : public Menu, public Estados::Estado {
    private:
        IDestado idFase;
        int pontos;
    public:
        MenuPausa(Estados::MaquinaEstados* pSM = nullptr, IDestado idFase = IDestado::desconhecido);

        ~MenuPausa();

        void atualizar(float dt);

        void renderizar();

        void executar();

        void resetEstado();

        void setIDFase(IDestado id);

        IDestado getIDFase();

        void setPontos(int pontos);

        int getPontos();

    };

}