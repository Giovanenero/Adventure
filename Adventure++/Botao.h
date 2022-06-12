#pragma once

#include "Texto.h"
#include "Animacao.h"

namespace ElementoGrafico {

    class Botao : public Animacao {
    private:
        Texto textInfo;
        sf::Texture* defaultTexture;
        sf::Texture* selectedTexture;
    public:
        Botao(Matematica::CoordenadaF posicao = Matematica::CoordenadaF(0, 0), std::string info = "");
        ~Botao();
        void selecionar(const bool isSelected);
        void renderizar();
    };

}