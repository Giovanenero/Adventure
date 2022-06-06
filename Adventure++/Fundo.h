#pragma once

#include "AnimacaoEstatica.h"
#include "Entidade.h"

class Fundo : public Ente
{
private:
    Entidade::Entidade* pJogador;
    ElementoGrafico::AnimacaoEstatica* pAnimacaoEstatica;
    //static Gerenciador::GerenciadorGrafico* pGrafico;
public:
    Fundo(Ids::Ids id, Entidade::Entidade* pJogador1);
    ~Fundo();
    void inicializacao();
    void atualizar();
    void executar();
};