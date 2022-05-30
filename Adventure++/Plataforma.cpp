#include "Plataforma.h"

namespace Entidade {
	Plataforma::Plataforma(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id):
		EntidadeEstatica(pos, tam, id)
	{
		inicializacao();
	}
	Plataforma::~Plataforma() {

	}
	void Plataforma::inicializacao() {
		pAnimacaoEstatica->novaAnimacao("textura/Fundo/gramaFloresta.png", Ids::Ids::plataforma, Matematica::CoordenadaF(1.0f, 1.0f));
	}
	void Plataforma::atualizar() {
		pAnimacaoEstatica->atualizar(Ids::Ids::plataforma, posicao, tamanho);
		pAnimacaoEstatica->renderizar();
	}
}