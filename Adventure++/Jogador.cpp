#include "Jogador.h"

namespace Entidade {
	namespace Personagem {
		namespace Jogador {
			Jogador::Jogador(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id, const float tamPulo, const int vida, const int dano) :
				Personagem(pos, tam, id, vida, dano), 
				pular(true), 
				tamPulo(tamPulo), 
				caindo(true) { }

			Jogador::~Jogador() { }

			void Jogador::colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade) {
				if (pEntidade->getID() == Ids::Ids::plataforma) {
					colisaoPlataforma(intersecao, pEntidade);
					pular = true;
					noChao = true;
					caindo = false;
				}
				else if (pEntidade->getID() == Ids::Ids::goblin_bate ||
					pEntidade->getID() == Ids::Ids::esqueleto_bate ||
					pEntidade->getID() == Ids::Ids::animagus) {
					Personagem* pPerson = static_cast<Personagem*>(pEntidade);
					pPerson->ativarAtacar();
					if (pPerson->podeAtacar()) {
						pPerson->desligarAtacar();
						podeTomarDano(pPerson->valorDano());
						std::cout << "a ";
					}
				}
			}
			void Jogador::podePular() {
				if (pular) {
					velocidade.y = -sqrt(2.0f * GRAVIDADE * tamPulo);
					pular = false;
					noChao = false;
				}
			}
		}
	}
}