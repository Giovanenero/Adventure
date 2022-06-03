#include "Atirador.h"

namespace Entidade {
	namespace Personagem {
		namespace Inimigo {
			Atirador::Atirador(Lista::ListaEntidade* ListaEntidadeMovimento):
				ListaEntidadeMovimento(ListaEntidadeMovimento),
				jaAtirou(false),
				pProjetil(nullptr) { }

			Atirador::~Atirador() {
				if(pProjetil) {
					pProjetil = nullptr;
				}
				if (ListaEntidadeMovimento) {
					ListaEntidadeMovimento = nullptr;
				}
			}
			void Atirador::criarProjetil(Matematica::CoordenadaF posicao, const bool esquerda, const int dano) {
				jaAtirou = true;
				pProjetil = new Projetil(posicao, esquerda, dano);
				ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade*>(pProjetil));
				pProjetil->setExplodir(false);
			}
		}
	}
}