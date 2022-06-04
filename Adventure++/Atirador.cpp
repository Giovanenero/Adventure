#include "Atirador.h"

namespace Entidade {
	namespace Personagem {
		namespace Inimigo {
			Atirador::Atirador(Lista::ListaEntidade* ListaEntidadeMovimento):
				jaAtirou(false),
				pProjetil(nullptr),
				ListaEntidadeMovimento(ListaEntidadeMovimento)
			{ }

			Atirador::~Atirador() {

			}
			void Atirador::criarProjetil(Matematica::CoordenadaF posicao, const bool esquerda, const int dano) {
				jaAtirou = true;
				pProjetil = new Projetil(posicao, esquerda, dano);
				if (pProjetil == nullptr) {
					std::cout << "pProjetil == nullptr" << std::endl;
					exit(1);
				}
				ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade*>(pProjetil));
			}
		}
	}
}