#include "Plataforma.h"

namespace Entidade {
	namespace Obstaculo {
		Plataforma::Plataforma(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id) :
			Obstaculo(pos, tam, id)
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
		void Plataforma::executar() {
			//????
		}
	} //namespace Obstaculo
} //namespace Entidade