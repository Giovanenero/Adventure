#include "Oriana.h"

namespace Entidade {
	namespace Personagem {
		Oriana::Oriana(Matematica::CoordenadaF pos) :
			Jogador(pos, Matematica::CoordenadaF(TAMX, TAMY), Ids::Ids::jogador1),
			EhJogador1(true)
		{
			velocidade = Matematica::CoordenadaF(0.05f, 0.1f);
			inicializacao();
		}

		Oriana::~Oriana() { }

		//inicializa as animacoes
		void Oriana::inicializacao() {
			//parametro(caminhoTexto, contaImagem, id, escala)
			pAnimacaoMovimento->novaAnimacao("textura/orianaParada.png", 15, Ids::Ids::parar);
			pAnimacaoMovimento->novaAnimacao("textura/orianaMorrendo.png", 15, Ids::Ids::morrer);
			pAnimacaoMovimento->novaAnimacao("textura/orianaPulando.png", 15, Ids::Ids::pular);
			pAnimacaoMovimento->novaAnimacao("textura/orianaAtacando.png", 22, Ids::Ids::atacar);
			pAnimacaoMovimento->novaAnimacao("textura/orianaAndando.png", 8, Ids::Ids::andar);
		}
	}
}