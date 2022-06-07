#include "Botao.h"

#define BUTTON_PATH_DEFAULT "./textura/Botao/naoselecionado.png"
#define BUTTON_PATH_SELECTED "./textura/Botao/selecionado.png"
#define BUTTON_HEIGHT 80.f
#define BUTTON_WIDTH 300.f
#define BUTTON_TEXT_COLOR 77.6, 68.2, 44.3 // R, G, B
#define FONT_SIZE 30.f

namespace ElementoGrafico {

    Botao::Botao(Matematica::CoordenadaF posicao, std::string info) :
        textInfo(posicao, info),
        defaultTexture(nullptr),
        selectedTexture(nullptr) 
    {
        defaultTexture = pGrafico->loadTexture(BUTTON_PATH_DEFAULT);
        selectedTexture = pGrafico->loadTexture(BUTTON_PATH_SELECTED);

        corpo.setSize(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT));

        corpo.setOrigin(sf::Vector2f(BUTTON_WIDTH / 2, BUTTON_HEIGHT / 2));

        corpo.setPosition(sf::Vector2f(posicao.x, posicao.y));

        corpo.setTexture(defaultTexture);

        textInfo.setTamanhoFonte(FONT_SIZE);

        textInfo.setAlinhamento(AlinhamentoTexto::centro);

        textInfo.setCor(BUTTON_TEXT_COLOR);

        textInfo.setPosicao(Matematica::CoordenadaF(posicao.x, posicao.y));
    }

    Botao::~Botao() { }

    void Botao::selecionar(const bool isSelected) {
        if (isSelected)
            corpo.setTexture(selectedTexture);
        else
            corpo.setTexture(defaultTexture);
    }

    void Botao::renderizar() {
        pGrafico->renderizacao(&corpo);
        textInfo.renderizar();
    }

}