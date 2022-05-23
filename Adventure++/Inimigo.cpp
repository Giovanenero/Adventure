#include "Inimigo.h"

namespace Entidade {
	namespace Personagem {
			Inimigo::Inimigo(Matematica::CoordenadaF pos, Matematica::CoordenadaF tam, Ids::Ids id) :
				Personagem(pos, tam, id), pOriana(nullptr), distanciaJogador(0.f)
			{
				inicializacao();
			}

			Inimigo::~Inimigo() { pOriana = nullptr; }

			void Inimigo::setOriana(Oriana* pOriana) { this->pOriana = pOriana; }

			Matematica::CoordenadaF Inimigo::getDistanciaJogador() { return distanciaJogador; }

			void Inimigo::colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade) {
				switch (pEntidade->getID())
				{
				case Ids::Ids::plataforma:
					colisaoPlataforma(intersecao, pEntidade);
					break;
				case Ids::Ids::jogador1:
					//apenas para texte;
					std::cout << "colisao com jogador!" << std::endl;
					exit(1);
					break;
				default:
					break;
				}
			}

			void Inimigo::atualizar(float tempo) {
				this->tempo += tempo;
				if (this->tempo < 2.0f) {
					Matematica::CoordenadaF escala(1.0f, 1.0f);
					pAnimacaoMovimento->atualizar(posicao, true, tempo, Ids::Ids::ataquedog, escala);
				}
				else {
					Matematica::CoordenadaF escala(1.0f, 1.0f);
					pAnimacaoMovimento->atualizar(posicao, true, tempo, Ids::Ids::corredog, escala);
				}
			}

			void Inimigo::inicializacao() {
				pAnimacaoMovimento->novaAnimacao("textura/teste/1 Dog/Walk.png", 6, Ids::Ids::corredog);
				pAnimacaoMovimento->novaAnimacao("textura/teste/1 Dog/Attack.png", 4, Ids::Ids::ataquedog);
			}
	}
}