#include "Principal.h"

using namespace Gerenciador;

Principal::Principal(): 
	pGrafico(GerenciadorGrafico::getGerenciadorGrafico()),
	pEvento(GerenciadorEvento::getGerenciadorEvento()),
	pOriana(new Entidade::Personagem::Oriana(Matematica::CoordenadaF(200.0f, 500.0f))),
	pPascal(new Entidade::Personagem::Pascal(Matematica::CoordenadaF(600.0f, 500.0f), pOriana))
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
	//Gerenciador::GerenciadorColisao* pColisao = new Gerenciador::GerenciadorColisao(objListaAux, objLista);
	

	//arrumar ineficiente...
	Lista::ListaEntidade* objLista2 = new Lista::ListaEntidade();
	Matematica::CoordenadaF tam(50.f, 50.f);
	for (int i = 0; i < 28; i++) {
		Matematica::CoordenadaF pos(i * 50.f, 550.f);
		Entidade::EntidadeEstatica* plataforma = new Entidade::EntidadeEstatica(pos, tam, Ids::Ids::plataforma);
		plataforma->inicializacao();
		objLista2->adicionarEntidade(static_cast<Entidade::Entidade*>(plataforma));
	}


	while (pGrafico->isWindowOpen()) {
		tempo = pGrafico->atualizartempo();
		pEvento->pollEvents();
		pGrafico->limpar();

		//arrumar... ineficiente
		for (int i = 0; i < (int)objLista2->getTamanho(); i++) {
			Matematica::CoordenadaF pos(i * 50.f, 550.f);
			Entidade::EntidadeEstatica* aux = static_cast<Entidade::EntidadeEstatica*>(objLista2->operator[](i));
			aux->atualizar(pos, tam);
		}

		for (int i = 0; i < (int)objLista->getTamanho(); i++) {
			objLista->operator[](i)->atualizar(tempo);
		}
		//pColisao->Colisao();

		pGrafico->mostrar();
	}
}