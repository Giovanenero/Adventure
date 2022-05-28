#include "Principal.h"

using namespace Gerenciador;

Principal::Principal(): 
	pGrafico(GerenciadorGrafico::getGerenciadorGrafico()),
	pEvento(GerenciadorEvento::getGerenciadorEvento()),
	pOriana(new Entidade::Personagem::Oriana(Matematica::CoordenadaF(200.0f, 200.0f))),
	pPascal(new Entidade::Personagem::Pascal(Matematica::CoordenadaF(600.0f, 200.0f), pOriana))
{
	Executar();
}
Principal::~Principal() {
	pGrafico = nullptr;
	pEvento = nullptr;
}

void Principal::Executar() {
	float tempo = 0.f;

	//teste...
	pEvento->setOriana(pOriana);
	Lista::ListaEntidade* objLista = new Lista::ListaEntidade();
	//Lista::ListaEntidade* objListaAux = new Lista::ListaEntidade();
	objLista->adicionarEntidade(static_cast<Entidade::Entidade*>(pOriana));
	objLista->adicionarEntidade(static_cast<Entidade::Entidade*>(pPascal));
	

	//arrumar ineficiente...
	Lista::ListaEntidade* objLista2 = new Lista::ListaEntidade();
	Matematica::CoordenadaF tam(100.0f, 40.0f);
	for (int i = 0; i < 12; i++) {
		if (i != 8 && i != 7) {
			Matematica::CoordenadaF pos(i * 100.f, 350.f);
			Entidade::EntidadeEstatica* plataforma = new Entidade::EntidadeEstatica(pos, tam, Ids::Ids::plataforma);
			plataforma->inicializacao();
			objLista2->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma));
		}
	}
	Entidade::EntidadeEstatica* plataforma1 = new Entidade::EntidadeEstatica(Matematica::CoordenadaF(200.0f, 300.0f), tam, Ids::Ids::plataforma);
	plataforma1->inicializacao();
	objLista2->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma1));

	/*Entidade::EntidadeEstatica* plataforma2 = new Entidade::EntidadeEstatica(Matematica::CoordenadaF(400.0f, 250.0f), tam, Ids::Ids::plataforma);
	plataforma2->inicializacao();
	objLista2->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma2));*/

	Gerenciador::GerenciadorColisao* pColisao = new Gerenciador::GerenciadorColisao(objLista2, objLista);
	
	while (pGrafico->isWindowOpen()) {
		tempo = pGrafico->atualizartempo();
		pEvento->pollEvents();
		pGrafico->limpar();

		//arrumar... ineficiente
		for (int i = 0; i < (int)objLista2->getTamanho(); i++) {
			Entidade::EntidadeEstatica* aux = static_cast<Entidade::EntidadeEstatica*>(objLista2->operator[](i));
			aux->atualizar();
		}

		for (int i = 0; i < (int)objLista->getTamanho(); i++) {
			objLista->operator[](i)->atualizar(tempo);
		}
		pColisao->Colisao();

		pGrafico->mostrar();
	}
}