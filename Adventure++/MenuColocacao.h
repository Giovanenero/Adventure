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
        std::string nome;
        ElementoGrafico::Texto texNome;
        int pontos;
        IDestado fase;

        void criarColocacao();

        void escreverColocacao();

    public:
        MenuColocacao(Estados::MaquinaEstados *pSM = nullptr);

        ~MenuColocacao();

        void atualizar(const float dt);

        void renderizar();

        void resetEstado();

        void executar();

        void aceitarLetra(char letra);

    };
}