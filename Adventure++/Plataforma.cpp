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
			pAnimacaoEstatica->novaAnimacao("textura/Obstaculos/grama.png", Ids::Ids::plataforma, posicao, tamanho, Matematica::CoordenadaF(3.15f, 1.0f));
		}
		void Plataforma::atualizar() {
			pAnimacaoEstatica->atualizar(Ids::Ids::plataforma);
			pAnimacaoEstatica->renderizar();
		}
	} //namespace Obstaculo
} //namespace Entidade