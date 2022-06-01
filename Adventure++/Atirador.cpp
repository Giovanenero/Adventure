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
					delete(pProjetil);
					pProjetil = nullptr;
				}
				if (ListaEntidadeMovimento) {
					delete(ListaEntidadeMovimento);
					ListaEntidadeMovimento = nullptr;
				}
			}
		}
	}
}