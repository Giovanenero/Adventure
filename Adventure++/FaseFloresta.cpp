#include "FaseFloresta.h"

namespace Fase {

    FaseFloresta::FaseFloresta():
        FaseGenerica()
    {
        pEvento = Gerenciador::GerenciadorEvento::getGerenciadorEvento();
        pGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
        ListaEntidadeEstatica = new Lista::ListaEntidade();
        ListaEntidadeMovimento = new Lista::ListaEntidade();
        pOriana = new Entidade::Personagem::Jogador::Oriana(Matematica::CoordenadaF(200.0f, 200.0f));
        pPascal = new Entidade::Personagem::Inimigo::Pascal(Matematica::CoordenadaF(600.0f, 200.0f), pOriana);
        pColisao = new Gerenciador::GerenciadorColisao(ListaEntidadeEstatica, ListaEntidadeMovimento);

    }

    FaseFloresta::~FaseFloresta() {
        if (ListaEntidadeEstatica) {
            delete(ListaEntidadeEstatica);
            ListaEntidadeEstatica = nullptr;
        }
        if (ListaEntidadeMovimento) {
            delete(ListaEntidadeMovimento);
            ListaEntidadeMovimento = nullptr;
        }
        if (pColisao) {
            delete(pColisao);
            pColisao = nullptr;
        }
        if (pOriana) {
            delete(pOriana);
            pOriana = nullptr;
        }
        if (pPascal) {
            delete(pPascal);
            pPascal = nullptr;
        }
    }

    void FaseFloresta::init() {
        //teste...
        pEvento->setOriana(pOriana);

        ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pOriana));
        ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pPascal));

        Entidade::Obstaculo::Fundo* fundo = new Entidade::Obstaculo::Fundo(Matematica::CoordenadaF(600.f, 300.f), Matematica::CoordenadaF(1200.0f, 600.0f), Ids::Ids::fundo_floresta);
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(fundo));

        //arrumar ineficiente...
        Matematica::CoordenadaF tam(100.0f, 30.0f);
        for (int i = 0; i < 12; i++) {
            if (i != 8 && i != 7) {
                Matematica::CoordenadaF pos(i * 100.f, 450.f);
                Entidade::Obstaculo::Plataforma* plataforma = new Entidade::Obstaculo::Plataforma(pos, tam, Ids::Ids::plataforma);
                ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma));
            }
            else {
                Matematica::CoordenadaF pos(i * 100.f, 550.f);
                Entidade::Obstaculo::Plataforma* plataforma = new Entidade::Obstaculo::Plataforma(pos, tam, Ids::Ids::plataforma);
                ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma));
            }
        }
        Entidade::Obstaculo::Plataforma* plataforma1 = new Entidade::Obstaculo::Plataforma(Matematica::CoordenadaF(200.0f, 340.0f), tam, Ids::Ids::plataforma);
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma1));

        Entidade::Obstaculo::Plataforma* plataforma2 = new Entidade::Obstaculo::Plataforma(Matematica::CoordenadaF(500.0f, 340.0f), tam, Ids::Ids::plataforma);
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma2));

        Entidade::Obstaculo::Plataforma* plataforma3 = new Entidade::Obstaculo::Plataforma(Matematica::CoordenadaF(750.0f, 340.0f), tam, Ids::Ids::plataforma);
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma3));

        Entidade::Obstaculo::Plataforma* plataforma4 = new Entidade::Obstaculo::Plataforma(Matematica::CoordenadaF(350.0f, 210.0f), tam, Ids::Ids::plataforma);
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma4));
    }
    void FaseFloresta::executar() {
        while (pGrafico->isWindowOpen()) {
            float tempo = pGrafico->atualizartempo();
            pEvento->pollEvents();
            pGrafico->limpar();

            //arrumar... ineficiente
            for (int i = 0; i < (int)ListaEntidadeEstatica->getTamanho(); i++) {
                Entidade::Obstaculo::Obstaculo* aux = static_cast<Entidade::Obstaculo::Obstaculo*>(ListaEntidadeEstatica->operator[](i));
                aux->atualizar();
            }

            for (int i = 0; i < (int)ListaEntidadeMovimento->getTamanho(); i++) {
                Entidade::Personagem::Personagem* pMov = static_cast<Entidade::Personagem::Personagem*>(ListaEntidadeMovimento->operator[](i));
                pMov->atualizar(tempo);
                if (pMov->podeMorrer()) {
                    pMov = static_cast<Entidade::Personagem::Personagem*>(ListaEntidadeMovimento->removerEntidade((unsigned int)i));
                    Entidade::Personagem::Inimigo::Pascal* novoInimigo = new Entidade::Personagem::Inimigo::Pascal(Matematica::CoordenadaF((float)(rand() % 1050), (float)(300 + rand() % 300)), pOriana);
                    ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(novoInimigo));
                }

                //arrumar...
                /*
                if (pMov->podeMorrer()) {
                    ListaEntidadeMovimento->removerEntidade((unsigned int)i);
                }
                */
            }

            pColisao->Colisao();
            pGrafico->mostrar();
        }
    }
} //namespace Fase
