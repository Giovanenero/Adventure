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
	Lista::ListaEntidade* objListaAux = new Lista::ListaEntidade();
	objLista->adicionarEntidade(static_cast<Entidade::Entidade*>(pOriana));
	objLista->adicionarEntidade(static_cast<Entidade::Entidade*>(pPascal));
	Gerenciador::GerenciadorColisao* pColisao = new Gerenciador::GerenciadorColisao(objListaAux, objLista);


	while (pGrafico->isWindowOpen()) {
		tempo = pGrafico->atualizartempo();
		pEvento->pollEvents();
		pGrafico->limpar();
		
		//teste...
		for (unsigned int i = 0; i < objLista->getTamanho(); i++) {
			objLista->operator[]((int)i)->mover(tempo);
		}
		pColisao->Colisao();

		pGrafico->mostrar();
	}
}