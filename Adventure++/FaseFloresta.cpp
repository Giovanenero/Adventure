#include "FaseFloresta.h"
#include "EntidadeEstatica.h"

Fase::FaseFloresta::FaseFloresta()  {

    pEvento = Gerenciador::GerenciadorEvento::getGerenciadorEvento();
    pGrafico = Gerenciador::GerenciadorGrafico::getGerenciadorGrafico();
    ListaEntidadeEstatica = new Lista::ListaEntidade();
    ListaEntidadeMovimento = new Lista::ListaEntidade();
    pOriana = new Entidade::Personagem::Oriana(Matematica::CoordenadaF(200.0f, 200.0f));
    pPascal = new Entidade::Personagem::Pascal(Matematica::CoordenadaF(600.0f, 200.0f), pOriana);
    pColisao = new Gerenciador::GerenciadorColisao(ListaEntidadeEstatica, ListaEntidadeMovimento);

}

Fase::FaseFloresta::~FaseFloresta() {
    delete ListaEntidadeEstatica;
    delete ListaEntidadeMovimento;
    delete pColisao;
    ListaEntidadeEstatica = nullptr;
    ListaEntidadeMovimento = nullptr;
    pColisao = nullptr;
}

void Fase::FaseFloresta::init() {
    //teste...
    pEvento->setOriana(pOriana);

    ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pOriana));
    ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade::Entidade*>(pPascal));

    Entidade::Fundo* fundo = new Entidade::Fundo(Matematica::CoordenadaF(600.f, 300.f), Matematica::CoordenadaF(1200.0f, 600.0f), Ids::Ids::fundo_floresta);
    ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(fundo));

    //arrumar ineficiente...
    Matematica::CoordenadaF tam(100.0f, 30.0f);
    for (int i = 0; i < 12; i++) {
        if (i != 8 && i != 7) {
            Matematica::CoordenadaF pos(i * 100.f, 350.f);
            Entidade::Plataforma* plataforma = new Entidade::Plataforma(pos, tam, Ids::Ids::plataforma);
            ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma));
        }
        else {
            Matematica::CoordenadaF pos(i * 100.f, 450.f);
            Entidade::Plataforma* plataforma = new Entidade::Plataforma(pos, tam, Ids::Ids::plataforma);
            ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma));
        }
    }
    Entidade::Plataforma* plataforma1 = new Entidade::Plataforma(Matematica::CoordenadaF(200.0f, 300.0f), tam, Ids::Ids::plataforma);
    ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma1));

    Entidade::Plataforma* plataforma2 = new Entidade::Plataforma(Matematica::CoordenadaF(500.0f, 240.0f), tam, Ids::Ids::plataforma);
    ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma2));

    Entidade::Plataforma* plataforma3 = new Entidade::Plataforma(Matematica::CoordenadaF(750.0f, 240.0f), tam, Ids::Ids::plataforma);
    ListaEntidadeEstatica->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma3));
}

//void Fase::FaseFloresta::executar() {

//}
