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
				switch (pEntidade->getID())
				{
					case Ids::Ids::plataforma:
					{
						colisaoPlataforma(intersecao, pEntidade);
						pular = true;
						noChao = true;
						caindo = false;
						break;
					}
					case Ids::Ids::goblin_bate:
					{
						Personagem* pGoblin = static_cast<Personagem*>(pEntidade);
						pGoblin->ativarAtacar();
						if (pGoblin->podeAtacar()) {
							pGoblin->desligarAtacar();
							podeTomarDano(pGoblin->valorDano());
						}
					}
					case Ids::Ids::esqueleto_bate: {
						Personagem* pEsqueleto = static_cast<Personagem*>(pEntidade);
						pEsqueleto->ativarAtacar();
						if (pEsqueleto->podeAtacar()) {
							pEsqueleto->desligarAndar();
							podeTomarDano(pEsqueleto->valorDano());
						}
						break;
					}
					default:
					{
						break;
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