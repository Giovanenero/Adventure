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
        pColisao = new Gerenciador::GerenciadorColisao(ListaEntidadeEstatica, ListaEntidadeMovimento);
        fundo = new Fundo(Ids::Ids::fase_floresta, static_cast<Entidade::Entidade*>(pOriana));
    }

    FaseFloresta::~FaseFloresta() { }

    void FaseFloresta::init() {
        //teste...
        pEvento->setOriana(pOriana);

        ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pOriana));

        //arrumar ineficiente...
        Matematica::CoordenadaF tam(100.0f, 30.0f);
        /*
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
       
        */

        short aleatorio = rand() % 3;
        short contAleatorio = 0;
        short mudaPosicao = 0;
        bool flag = true;
        srand(time(NULL));
        for (int i = 0; i < 100; i++) {
            Matematica::CoordenadaF pos(i * 100.f, 500.f + mudaPosicao * 80.f );
            Entidade::Obstaculo::Plataforma* plataforma4 = new Entidade::Obstaculo::Plataforma(pos, tam, Ids::Ids::plataforma);
            ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma4));
            if (aleatorio == 0 && flag) {
                mudaPosicao++;
                flag = false;
            }
            else if (aleatorio == 1 && flag) {
                mudaPosicao--;
                flag = false;
            }
            contAleatorio++;
            if (contAleatorio == 5) {
                Entidade::Personagem::Inimigo::AtiraEsqueleto* pAtiraEsqueleto = new Entidade::Personagem::Inimigo::AtiraEsqueleto(Matematica::CoordenadaF((float)(i * 100.f), 100.f), pOriana, ListaEntidadeMovimento);
                if (pAtiraEsqueleto == nullptr) {
                    exit(1);
                }
                ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pAtiraEsqueleto));
                
                aleatorio = rand()%3;
                contAleatorio = 0;
                flag = true;
            }
        }

        Matematica::CoordenadaF pos2(200.f, 350.f);
        Entidade::Obstaculo::Plataforma* plataforma5 = new Entidade::Obstaculo::Plataforma(pos2, tam, Ids::Ids::plataforma);
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma5));

        /*
        Matematica::CoordenadaF pos3(1100.f, 250.f);
        Entidade::Obstaculo::Plataforma* plataforma5 = new Entidade::Obstaculo::Plataforma(pos3, tam, Ids::Ids::plataforma);
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma5));

        */


        for (int i = 0; i < 2; i++) {
            Entidade::Personagem::Inimigo::AtiraGoblin* pAtiraGoblin = new Entidade::Personagem::Inimigo::AtiraGoblin(Matematica::CoordenadaF((float)(rand()%1000), 100.f), pOriana, ListaEntidadeMovimento);
            ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pAtiraGoblin));
        }
        for (int i = 0; i < 2; i++) {
            Entidade::Personagem::Inimigo::AtiraEsqueleto* pAtiraEsqueleto = new Entidade::Personagem::Inimigo::AtiraEsqueleto(Matematica::CoordenadaF((float)(rand() % 1000), 100.f), pOriana, ListaEntidadeMovimento);
            ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pAtiraEsqueleto));
        }

        /*
        for (int i = 0; i < 2; i++) {
            Entidade::Personagem::Inimigo::BateGoblin* pBateGoblin = new Entidade::Personagem::Inimigo::BateGoblin(Matematica::CoordenadaF((float)(rand()%1000), 100.0f), pOriana);
            ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pBateGoblin));
        }
        for (int i = 0; i < 2; i++) {
            Entidade::Personagem::Inimigo::BateEsqueleto* pBateEsqueleto = new Entidade::Personagem::Inimigo::BateEsqueleto(Matematica::CoordenadaF((float)(rand()%1000), 100.f), pOriana);
            ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pBateEsqueleto));
        }
        for (int i = 0; i < 2; i++) {
            Entidade::Personagem::Inimigo::Animagus* pAnimagus = new Entidade::Personagem::Inimigo::Animagus(Matematica::CoordenadaF((float)(rand() % 1000), 100.f), pOriana);
            ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pAnimagus));
        }
        */
    }
    void FaseFloresta::executar() {
        while (pGrafico->isWindowOpen()) {
            float tempo = pGrafico->atualizartempo();
            pEvento->pollEvents();
            pGrafico->limpar();

            //arrumar... ineficiente
            fundo->atualizar();
            for (int i = 0; i < (int)ListaEntidadeEstatica->getTamanho(); i++) {
                Entidade::Obstaculo::Obstaculo* aux = static_cast<Entidade::Obstaculo::Obstaculo*>(ListaEntidadeEstatica->operator[](i));
                aux->atualizar();
            }

            int i = 0;
            int tam = (int)ListaEntidadeMovimento->getTamanho();
            while (i < tam) {
                Entidade::Entidade* pEnt = ListaEntidadeMovimento->operator[](i);
                if (pEnt != nullptr) {
                    pEnt->atualizar(tempo);
                    if (pEnt->podeRemover()) {
                        pEnt = ListaEntidadeMovimento->removerEntidade(pEnt);
                        //delete(pEnt);
                        //pEnt = nullptr;
                        tam = (int)ListaEntidadeMovimento->getTamanho();
                    }
                }
                i++;
            }
            
            pGrafico->centralizarCamera(pOriana->getPosicao());

            pColisao->Colisao();
            pGrafico->mostrar();
        }
    }
} //namespace Fase
