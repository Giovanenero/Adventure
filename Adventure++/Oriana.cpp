#include "Oriana.h"

namespace Entidade {
	namespace Personagem {
		Oriana::Oriana(Matematica::CoordenadaF pos): 
			Personagem(pos, Matematica::CoordenadaF(TAMX, TAMY), Ids::Ids::jogador1), 
			EhJogador1(true)
		{
			velocidade = Matematica::CoordenadaF(0.05f, 0.1f);
			inicializacao();
		}
		
		Oriana::~Oriana() {

		}	

		void Oriana::atualizar(float tempo) {
			this->tempo += tempo;
			if (this->tempo < 5) {
				//parametro(pos, EhEsquerda, tempo, id)
				pAnimacaoMovimento->atualizar(posicao, olharEsquerda, tempo, Ids::Ids::atacar);
			}
			else {
				tempo = 0;
			}
		}
		void Oriana::inicializacao() {
			//parametro(caminhoTexto, contaImagem, id)
			pAnimacaoMovimento->novaAnimacao("atacando.png", 22, Ids::Ids::atacar);
		}
		void Oriana::colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade) {
			switch (pEntidade->getID())
			{
			case Ids::Ids::plataforma:
			{
				colisaoPlataforma(intersecao, pEntidade);
				break;
			}
			//colisao com todas as entidades...
			//terminar...
			default:
				break;
			}
		}
	}
}