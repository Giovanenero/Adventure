#include "FaseFloresta.h"
#include "Principal.h"

namespace Fase {

    FaseFloresta::FaseFloresta(Principal *principal):
            Fase(), Estados::Estado(static_cast<Estados::MaquinaEstados*>(principal), Estados::IDestado::jogandoFloresta)
    {
        pEvento = Gerenciador::GerenciadorEvento::getGerenciadorEvento();
        pGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
        ListaEntidadeEstatica = new Lista::ListaEntidade();
        ListaEntidadeMovimento = new Lista::ListaEntidade();
        pOriana = new Entidade::Personagem::Jogador::Oriana(Matematica::CoordenadaF(200.0f, 200.0f));
        pColisao = new Gerenciador::GerenciadorColisao(ListaEntidadeEstatica, ListaEntidadeMovimento);
        fundo = new Fundo(Ids::Ids::fase_floresta);
    }

    FaseFloresta::~FaseFloresta() { }

    void FaseFloresta::init() {

        if (iniciou) {
            return;
        }
        iniciou = true;
        //teste...
        pEvento->setJogadores(pOriana, pHideo);

        ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pOriana));
        ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pHideo));

        //arrumar ineficiente...
        Matematica::CoordenadaF tam(100.0f, 30.0f);

        /*
        srand(time(NULL));
        for (int i = 0; i < 10; i++) {
            if (i != 6 && i != 7) {
                Matematica::CoordenadaF pos(i * 100.0f, 350.0f);
                Entidade::Obstaculo::Plataforma* plataforma = new Entidade::Obstaculo::Plataforma(pos, tam);
                ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma));
            }
        }

        for (int i = 0; i < 2; i++) {
            Matematica::CoordenadaF pos2(200.f * (i + 1), 220.f);
            Entidade::Obstaculo::Plataforma* plataforma2 = new Entidade::Obstaculo::Plataforma(pos2, tam);
            ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma2));
        }

        Matematica::CoordenadaF pos3(500.f, 100.f);
        Entidade::Obstaculo::Plataforma* plataforma3 = new Entidade::Obstaculo::Plataforma(pos3, tam);
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma3));

        Matematica::CoordenadaF pos4(700.f, 100.f);
        Entidade::Obstaculo::Plataforma* plataforma5 = new Entidade::Obstaculo::Plataforma(pos4, tam);
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma5));


        for (int i = 0; i < 10; i++) {
            Matematica::CoordenadaF pos5(100.0f * i, 600.f);
            Entidade::Obstaculo::Plataforma* plataforma6 = new Entidade::Obstaculo::Plataforma(pos5, tam);
            ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma6));
        }

        Matematica::CoordenadaF pos5(-150.f, 480.f);
        Entidade::Obstaculo::Plataforma* plataforma7 = new Entidade::Obstaculo::Plataforma(pos5, tam);
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma7));

        Entidade::Obstaculo::Espinhos* pAux = new Entidade::Obstaculo::Espinhos(Matematica::CoordenadaF(200.0f, 330.0f));
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(pAux));

        Entidade::Obstaculo::Pedra* pPedra = new Entidade::Obstaculo::Pedra(Matematica::CoordenadaF(100.0f, 600.0f - 50.0f));
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(pPedra));

        for (int i = 10; i < 20; i++) {
            Entidade::Obstaculo::Plataforma* plat = new Entidade::Obstaculo::Plataforma(Matematica::CoordenadaF((8 * 100.f) + 500.0f + ((i - 10) * 100.0f), 350.0f), tam);
            ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plat));
        }

        Entidade::Obstaculo::Pedra* pP = new Entidade::Obstaculo::Pedra(Matematica::CoordenadaF((8 * 100.f) + 500.0f + 8 * 105.0f + 50.0f, 350.0f - 50.0f));
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(pP));

        Entidade::Obstaculo::Pedra* pP2 = new Entidade::Obstaculo::Pedra(Matematica::CoordenadaF((8 * 100.f) + 500.0f, 350.0f - 50.0f));
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(pP2));

        Entidade::Obstaculo::Caixa* pCaixa = new Entidade::Obstaculo::Caixa(Matematica::CoordenadaF(200.0f - 100.0f, 350.0f - 50.0f));
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(pCaixa));
        Entidade::Obstaculo::Caixa* pCaixa2 = new Entidade::Obstaculo::Caixa(Matematica::CoordenadaF(200.0f - 150.0f, 350.0f - 50.0f));
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(pCaixa2));
        Entidade::Obstaculo::Caixa* pCaixa3 = new Entidade::Obstaculo::Caixa(Matematica::CoordenadaF(200.0f - 150.0f, 350.0f - 100.0f));
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(pCaixa3));

        Entidade::Obstaculo::Plataforma* platafor = new Entidade::Obstaculo::Plataforma(Matematica::CoordenadaF((6 * 100.f) + 500.0f, 250.0f), tam);
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(platafor));

        for (int i = 0; i < 1; i++) {
            Entidade::Personagem::Inimigo::AtiraGoblin* pAtiraGoblin = new Entidade::Personagem::Inimigo::AtiraGoblin(Matematica::CoordenadaF((float)(rand()%1000), 100.f), pOriana, pHideo, ListaEntidadeMovimento);
            ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pAtiraGoblin));
        }


        for (int i = 0; i < 1; i++) {
            Entidade::Personagem::Inimigo::AtiraEsqueleto* pAtiraEsqueleto = new Entidade::Personagem::Inimigo::AtiraEsqueleto(Matematica::CoordenadaF((float)(rand() % 1000), 100.f), pOriana, pHideo, ListaEntidadeMovimento);
            ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pAtiraEsqueleto));
        }

        for (int i = 0; i < 2; i++) {
            Entidade::Personagem::Inimigo::BateGoblin* pBateGoblin = new Entidade::Personagem::Inimigo::BateGoblin(Matematica::CoordenadaF((float)(rand()%1000), 100.0f), pOriana, pHideo);
            ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pBateGoblin));
        }

        for (int i = 0; i < 2; i++) {
            Entidade::Personagem::Inimigo::BateEsqueleto* pBateEsqueleto = new Entidade::Personagem::Inimigo::BateEsqueleto(Matematica::CoordenadaF((float)(rand()%1000), 100.f), pOriana, pHideo);
            ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pBateEsqueleto));
        }

        for (int i = 0; i < 1; i++) {
            Entidade::Personagem::Inimigo::Animagus* pAnimagus = new Entidade::Personagem::Inimigo::Animagus(Matematica::CoordenadaF((float)(rand() % 1000) + 10 * 100.0f, 100.f), pOriana, pHideo);
            ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pAnimagus));
        }

        Entidade::Personagem::Inimigo::Noturno* noturno = new Entidade::Personagem::Inimigo::Noturno(Matematica::CoordenadaF((float)(rand() % 1000) + 10 * 100.0f, 100.f), pOriana, pHideo);
        ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(noturno));
        */

        for (int i = 0; i < 15; i++) {
            Entidade::Obstaculo::Plataforma* plat = new Entidade::Obstaculo::Plataforma(Matematica::CoordenadaF(100.0f * i, 600.0f));
            ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plat));
        }

        for (int i = 0; i < 4; i++) {
            Entidade::Obstaculo::Andaime* a = new Entidade::Obstaculo::Andaime(Matematica::CoordenadaF(500.0f - 300.0f, 600.0f - 50.f*(i + 1)));
            ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(a));
        
            Entidade::Obstaculo::Andaime* b = new Entidade::Obstaculo::Andaime(Matematica::CoordenadaF(500.0f + 300.0f, 600.0f - 50.0f* (i + 1)));
            ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(b));
        }

        Entidade::Obstaculo::Ponte* ponte = new Entidade::Obstaculo::Ponte(Matematica::CoordenadaF(500.0f, 600.0f - 50.0f * 4 - 20.0f), 2);
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(ponte));
        
        for (int i = 0; i < 3; i++) {
            Entidade::Obstaculo::Caixa* a = new Entidade::Obstaculo::Caixa(Matematica::CoordenadaF(500.0f, 0.0f));
            ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(a));
        }

        /*
        Entidade::Personagem::Inimigo::BateGoblin* a = new Entidade::Personagem::Inimigo::BateGoblin(Matematica::CoordenadaF(500.0f, 500.0f), pOriana, pHideo);
        ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(a));

        Entidade::Personagem::Inimigo::BateGoblin* b = new Entidade::Personagem::Inimigo::BateGoblin(Matematica::CoordenadaF(600.0f, 000.0f), pOriana, pHideo);
        ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(b));
        */

        /*
        Entidade::Obstaculo::Ponte* ponte2 = new Entidade::Obstaculo::Ponte(Matematica::CoordenadaF(900.0f, 600.0f - 50.0f * 6));
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(ponte2));

        Entidade::Obstaculo::Espinhos* esp = new Entidade::Obstaculo::Espinhos(Matematica::CoordenadaF(650.0f, 600.0f - 50 * 5 - 30.0f - 20.0f));
        ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(esp));
        */
        iniciou = true;
    }
    void FaseFloresta::executar() { }

    void FaseFloresta::atualizar(const float tempo) {
        Matematica::CoordenadaF pos;
        if (pOriana->getPosicao().y < 315.f) {
            pos.operator=(Matematica::CoordenadaF(pOriana->getPosicao().x, pOriana->getPosicao().y));
        }
        else {
            pos.operator=(Matematica::CoordenadaF(pOriana->getPosicao().x, 315.0f));
        }
        fundo->atualizar(pos);
        pGrafico->centralizarCamera(pos);
        
        for (int i = 0; i < (int)ListaEntidadeEstatica->getTamanho(); i++) {
            Entidade::Obstaculo::Obstaculo* aux = static_cast<Entidade::Obstaculo::Obstaculo*>(ListaEntidadeEstatica->operator[](i));
            aux->atualizar(tempo);
        }
        //float tempo = pGrafico->atualizartempo();
        int i = 0;
        int tam = (int)ListaEntidadeMovimento->getTamanho();
        while (i < tam) {
            Entidade::Entidade* pEnt = ListaEntidadeMovimento->operator[](i);
            if (pEnt != nullptr) {
                pEnt->atualizar(tempo);
                if (pEnt->podeRemover()) {
                    ListaEntidadeMovimento->removerEntidade(pEnt);
                    //delete(pEnt);
                    //pEnt = nullptr;
                    tam = (int)ListaEntidadeMovimento->getTamanho();
                }
            }
            i++;
        }
        pColisao->Colisao();
    }

    void FaseFloresta::renderizar() {

    }

    void FaseFloresta::resetEstado() {
        //TODO: remover todas as entidades e resetar tudo antes de possivelmente reinicar a fase.
        init();
    }
} //namespace Fase
