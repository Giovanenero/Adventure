#include "GerenciadorColisao.h"

namespace Gerenciador {
	GerenciadorColisao::GerenciadorColisao(Lista::ListaEntidade* LEstatica, Lista::ListaEntidade* LMovimento):
		ListaEntidadeEstatica(LEstatica), ListaEntidadeMovimento(LMovimento) { }

	GerenciadorColisao::~GerenciadorColisao() {
		if (ListaEntidadeEstatica) {
			ListaEntidadeEstatica = nullptr;
		}
		if (ListaEntidadeMovimento) {
			ListaEntidadeMovimento = nullptr;
		}
	}
	void GerenciadorColisao::Colisao() {
		Entidade::Entidade* Entidade1 = nullptr;
		Entidade::Entidade* Entidade2 = nullptr;
		Matematica::CoordenadaF intersecao = Matematica::CoordenadaF(0.f, 0.f);
		Matematica::CoordenadaF distanciaCentro = Matematica::CoordenadaF(0.f, 0.f);
		int tamLEstatica = (int)ListaEntidadeEstatica->getTamanho();
		int tamLMovimento = (int)ListaEntidadeMovimento->getTamanho();

		//colisao entre EntidadeEstatica e EntidadeMovimento
		for (int i = 0; i < tamLEstatica; i++) {
			for (int j = 0; j < tamLMovimento; j++) {

				Entidade1 = ListaEntidadeEstatica->operator[](i);
				Entidade2 = ListaEntidadeMovimento->operator[](j);

				distanciaCentro.x = Entidade2->getPosicao().x - Entidade1->getPosicao().x;
				distanciaCentro.y = Entidade2->getPosicao().y - Entidade1->getPosicao().y;

				intersecao.x = fabs(distanciaCentro.x) - (Entidade1->getTamanho().x / 2 + Entidade2->getTamanho().x / 2);
				intersecao.y = fabs(distanciaCentro.y) - (Entidade1->getTamanho().y / 2 + Entidade2->getTamanho().y / 2);

				//verifica a colisao
				if (intersecao.x < 0.f && intersecao.y < 0.f) {
					Entidade2->colisao(intersecao, Entidade1);
				}
				Entidade1 = nullptr;
				Entidade2 = nullptr;
			}
		}
		//colisao entre 2 EntidadeMovimento
		for (int i = 0; i < tamLMovimento; i++) {
			for (int j = 1; j < tamLMovimento; j++) {
				Entidade1 = ListaEntidadeMovimento->operator[](i);
				Entidade2 = ListaEntidadeMovimento->operator[](j);

				distanciaCentro.x = Entidade1->getPosicao().x - Entidade2->getPosicao().x;
				distanciaCentro.y = Entidade1->getPosicao().y - Entidade2->getPosicao().y;

				intersecao.x = fabs(distanciaCentro.x) - (Entidade1->getTamanho().x / 2 + Entidade2->getTamanho().x / 2);
				intersecao.y = fabs(distanciaCentro.y) - (Entidade1->getTamanho().y / 2 + Entidade2->getTamanho().y / 2);
				
				//verifica a colisao
				if (intersecao.x < 0.f && intersecao.y < 0.f) {
					Entidade2->colisao(intersecao, Entidade1);
				}
				Entidade1 = nullptr;
				Entidade2 = nullptr;
			}
		}
	}


}