#include "Texto.h"

#define TEXT_SIZE 24

namespace ElementoGrafico {

    Gerenciador::GerenciadorGrafico* Texto::pGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();

    Texto::Texto(Matematica::CoordenadaF posicao, std::string info) :
            info(info) {
        text.setString(info);

        text.setFont(*pGrafico->carregarFonte());

        text.setCharacterSize(TEXT_SIZE);

        setAlinhamento(AlinhamentoTexto::esquerda);

        text.setPosition(sf::Vector2f(posicao.x, posicao.y));

        text.setFillColor(sf::Color::White);
    }

    Texto::~Texto() { }

    void Texto::setInfo(std::string info) {
        this->info = info;
        text.setString(this->info);
    }

    void Texto::setPosicao(Matematica::CoordenadaF posicao) {
        text.setPosition(sf::Vector2f(posicao.x, posicao.y));
    }

    void Texto::setCor(const unsigned int R, const unsigned int G, const unsigned int B) {
        text.setFillColor(sf::Color(R, G, B));
    }

    void Texto::setTamanhoFonte(const unsigned int size) {
        text.setCharacterSize(size);
    }

    void Texto::setAlinhamento(AlinhamentoTexto option) {
        switch (option) {
            case AlinhamentoTexto::esquerda:
                text.setOrigin(0, 0);
                break;
            case AlinhamentoTexto::centro:
                text.setOrigin(getTamanho().x / 2, getTamanho().y);
                break;
            case AlinhamentoTexto::direita:
                text.setOrigin(getTamanho().x, 0);
                break;
            default:
                text.setOrigin(getTamanho().x / 2, getTamanho().y);
                break;
        }
    }

    Matematica::CoordenadaF Texto::getTamanho() const {
        sf::FloatRect textRect = text.getLocalBounds();
        return Matematica::CoordenadaF(textRect.width, textRect.height);
    }

    void Texto::renderizar() {
        pGrafico->renderizacao(&text);
    }

    std::string Texto::getInfo() const {
        return info;
    }

    Matematica::CoordenadaF Texto::getPosicao() const {
        return Matematica::CoordenadaF(text.getPosition().x, text.getPosition().y);
    }

}