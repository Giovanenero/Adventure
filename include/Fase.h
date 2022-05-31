#pragma once

#include "Ente.h"

#include "GerenciadorGrafico.h"
#include "GerenciadorEvento.h"
#include "GerenciadorColisao.h"
#include "Oriana.h"
#include "Pascal.h"
#include "Plataforma.h"
#include "Fundo.h"

namespace Fase {
    class FaseGenerica: public Ente
    {
    protected:
        Gerenciador::GerenciadorGrafico* pGrafico;
        Gerenciador::GerenciadorEvento* pEvento;
        Entidade::Personagem::Jogador::Oriana *pOriana;
        Entidade::Personagem::Inimigo::Pascal *pPascal;
        Lista::ListaEntidade *ListaEntidadeEstatica;
        Lista::ListaEntidade *ListaEntidadeMovimento;
        Gerenciador::GerenciadorColisao* pColisao;
        Fundo* fundo;
    public:
        FaseGenerica();
        virtual ~FaseGenerica();
        virtual void init() = 0;
        virtual void executar() = 0;
        virtual void atualizar(const float tempo) = 0;
    };
}