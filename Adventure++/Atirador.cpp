#include "Atirador.h"

namespace Entidade {
	namespace Personagem {
		namespace Inimigo {
			Atirador::Atirador(Lista::ListaEntidade* ListaEntidadeMovimento):
				jaAtirou(false),
				ListaEntidadeMovimento(ListaEntidadeMovimento)
			{ }

			Atirador::~Atirador() { }

			void Atirador::criarProjetil(Matematica::CoordenadaF posicao, const bool esquerda, const int dano) {
				jaAtirou = true;
				Projetil* pProjetil = new Projetil(posicao, esquerda, dano);
				if (pProjetil == nullptr) {
					std::cout << "pProjetil == nullptr - class Atirador" << std::endl;
					exit(1);
				}
				ListaEntidadeMovimento->adicionarEntidade(static_cast<Entidade*>(pProjetil));
			}
			Jogador::Jogador* Atirador::jogadorMaisProximo(Jogador::Oriana* pOriana, Jogador::Hideo* pHideo, Matematica::CoordenadaF posInimigo) {
				if (pOriana == nullptr) {
					return static_cast<Jogador::Jogador*>(pHideo);
				}
				else if (pHideo == nullptr) {
					return static_cast<Jogador::Jogador*>(pOriana);
				}
				else {
					Matematica::CoordenadaF posOriana = pOriana->getPosicao() - posInimigo;
					Matematica::CoordenadaF posHideo = pHideo->getPosicao() - posInimigo;
					return ((fabs(posOriana.x) < fabs(posHideo.x)) ? static_cast<Jogador::Jogador*>(pOriana) : static_cast<Jogador::Jogador*>(pHideo));
				}
			}
		}
	}
}