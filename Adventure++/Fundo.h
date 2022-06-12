#pragma once

#include "AnimacaoEstatica.h"
#include "Entidade.h"

class Fundo : public Ente
{
private:
    ElementoGrafico::AnimacaoEstatica* pAnimacaoEstatica;
public:
    Fundo(Ids::Ids id);
    ~Fundo();
    void inicializacao();
    void atualizar(Matematica::CoordenadaF pos);
    void executar();
};