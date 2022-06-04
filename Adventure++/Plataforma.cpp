#include "Plataforma.h"

namespace Entidade {
	namespace Obstaculo {
		Plataforma::Plataforma(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam) :
			Obstaculo(pos, tam, Ids::Ids::plataforma)
		{
			inicializacao();
		}
		Plataforma::~Plataforma() {

		}
		void Plataforma::inicializacao() {
			pAnimacaoEstatica->novaAnimacao("textura/Fundo/gramaFloresta.png", Ids::Ids::plataforma, posicao, tamanho, Matematica::CoordenadaF(2.3f, 1.0f));
		}
		void Plataforma::atualizar() {
			pAnimacaoEstatica->atualizar(Ids::Ids::plataforma);
			pAnimacaoEstatica->renderizar();
		}
	} //namespace Obstaculo
} //namespace Entidade