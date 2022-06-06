#include "Entidade.h"

namespace Entidade {
	Entidade::Entidade(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id):
		Ente(id), posicao(pos), tamanho(tam) { }

	Entidade::~Entidade() { }
	void Entidade::setPosicao(Matematica::CoordenadaF pos) { posicao = pos; }
	Matematica::CoordenadaF Entidade::getPosicao() const { return posicao; }
	void Entidade::setTamanho(Matematica::CoordenadaF tam) { tamanho = tam; }
	Matematica::CoordenadaF Entidade::getTamanho() const { return tamanho; }
	Ids::Ids Entidade::getID() const { return ID; }
}