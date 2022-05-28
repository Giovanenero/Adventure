#include "Jogador.h"

namespace Entidade {
	namespace Personagem {
			Jogador::Jogador(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id, const float tamPulo) :
				Personagem(pos, tam, id), pulando(true), tamPulo(tamPulo)
			{ }
			Jogador::~Jogador() { }

			void Jogador::colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade) {
				switch (pEntidade->getID())
				{
				case Ids::Ids::plataforma:
				{
					colisaoPlataforma(intersecao, pEntidade);
					pulando = true;
					break;
				}
				default:
				{
					pulando = false;
					break;
				}
				}
			}
			void Jogador::pular() {
				if (pulando) {
					velocidade.y = -sqrt(2.0f * GRAVIDADE * tamPulo);
					//teste ...
					pulando = false;
				}
			}
			void Jogador::verificaPulo(const float tempo) {
				if (pulo < tamPulo) {
					pulo += tempo;
				}
			}
	}
}