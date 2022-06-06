#pragma once

#include "GerenciadorGrafico.h"
#include "Coordenada.h"

#include <SFML/Graphics.hpp>
#include <string>

namespace ElementoGrafico {

    enum AlinhamentoTexto {
        esquerda,
        centro,
        direita
    };
    //Baseado em tutorial de Matheus Burda, em: https://www.youtube.com/watch?v=e22ddfm1fBI&list=PLSPev71NbUEBIQlT2QCd-gN6l_mNVw1cJ&index=14
    class Texto {
    private:
        std::string info;

        sf::Text text;

        static Gerenciador::GerenciadorGrafico* pGrafico;

    public:
        Texto(Matematica::CoordenadaF posicao = Matematica::CoordenadaF(0, 0), std::string info = "");

        ~Texto();

        void setInfo(std::string info);

        void setPosicao(Matematica::CoordenadaF posicao);

        void setCor(const unsigned int R, const unsigned int G, const unsigned int B);

        void setTamanhoFonte(const unsigned int size);

        void setAlinhamento(AlinhamentoTexto option);

        Matematica::CoordenadaF getTamanho() const;

        void renderizar();

        std::string getInfo() const;

        Matematica::CoordenadaF getPosicao() const;
    };

} // namespace GraphicalElements