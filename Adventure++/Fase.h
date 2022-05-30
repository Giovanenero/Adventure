#pragma once

#include "GerenciadorGrafico.h"
#include "GerenciadorEvento.h"
#include "GerenciadorColisao.h"
#include "Oriana.h"
#include "Pascal.h"

namespace Fase {
    class FaseGenerica
    {
    protected:
        Gerenciador::GerenciadorGrafico* pGrafico;
        Gerenciador::GerenciadorEvento* pEvento;
        Entidade::Personagem::Oriana *pOriana;
        Entidade::Personagem::Pascal *pPascal;
        Lista::ListaEntidade *ListaEntidadeEstatica;
        Lista::ListaEntidade *ListaEntidadeMovimento;
        Gerenciador::GerenciadorColisao* pColisao;
    public:
        FaseGenerica();
        virtual ~FaseGenerica();
        virtual void init() = 0;
        virtual void executar();
    };
}