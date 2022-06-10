#include "Plataforma.h"

#define TAMANHO_PLATAFORMA_X 100.0f
#define TAMANHO_PLATAFORMA_Y 50.0f

namespace Entidade {
	namespace Obstaculo {
		Plataforma::Plataforma(Matematica::CoordenadaF pos) :
			Obstaculo(pos, Matematica::CoordenadaF(TAMANHO_PLATAFORMA_X, TAMANHO_PLATAFORMA_Y), Ids::Ids::plataforma)
		{
			inicializacao();
		}
		Plataforma::~Plataforma() { }

		void Plataforma::inicializacao() {
			pAnimacaoEstatica->novaAnimacao("textura/Obstaculos/grama.png", Ids::Ids::plataforma, posicao, tamanho, Matematica::CoordenadaF(3.15f, 2.0f));
		}
		void Plataforma::atualizar() {
			pAnimacaoEstatica->atualizar(Ids::Ids::plataforma, posicao);
			pAnimacaoEstatica->renderizar();
		}
	} //namespace Obstaculo
} //namespace Entidade