#pragma once

#include "Ente.h"
#include "Botao.h"
#include <vector>

class Menu : public Ente {

protected:
    std::vector<ElementoGrafico::Botao*> vectorBotoes;
    std::vector<ElementoGrafico::Botao*>::iterator it;
    int selecionado;
    int min;
    int max;
    bool ativo;

public:
    Menu();
    virtual ~Menu();
    virtual void executar() = 0;
    void atualizarVisao();
    void selecionarBaixo();
    void selecionarCima();
};
