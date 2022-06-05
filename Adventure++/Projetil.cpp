#include "Projetil.h"

#define TAMANHO_PROJETIL_X 10.0f
#define TAMANHO_PROJETIL_Y 10.0f
#define VELOCIDADE_PROJETIL_X 1.0f
#define TEMPO_EXPLODIR_PROJETIL 10.0f
#define DISTANCIA_EXPLOSAO 400.f

namespace Entidade {
	Projetil::Projetil(Matematica::CoordenadaF posInicio, const bool paraEsquerda, const int dano):
		Entidade(posInicio, Matematica::CoordenadaF(TAMANHO_PROJETIL_X, TAMANHO_PROJETIL_Y), Ids::Ids::projetil),
		pAnimacaoMovimento(new ElementoGrafico::AnimacaoMovimento()),
		dano(dano), 
		explodir(false), 
		paraEsquerda(paraEsquerda),
		carregarTempoExplosao(0.0f)
	{
		this->inicializacao();
	}
	Projetil::~Projetil() {
		//pAnimacaoMovimento = nullptr;
	}
	void Projetil::inicializacao() {
		pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Goblin/goblinBomba.png", 19, Ids::Ids::goblin_bomba, tamanho, Matematica::CoordenadaF(2.5f, 2.5f));
		//pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Esqueleto/esqueletoBomba.png", 8, Ids::Ids::esqueleto_bomba, tamanho, Matematica::CoordenadaF(1.5f, 1.5f));
	}
	void Projetil::renderizar() {
		pAnimacaoMovimento->renderizar();
	}
	void Projetil::colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade) {
		if (pEntidade != nullptr) {
			if (pEntidade->getID() == Ids::Ids::oriana || pEntidade->getID() == Ids::Ids::hideo) {
				if (!explodir) {
					Personagem::Personagem* pPerson = static_cast<Personagem::Personagem*>(pEntidade);
					pPerson->podeTomarDano(dano);
					explodir = true;
				}
			}
			else if (pEntidade->getID() == Ids::Ids::plataforma || pEntidade->getID() == Ids::Ids::pedra) {
				explodir = true;
			}
		}
	}
	void Projetil::atualizar(const float tempo) {
		posicao.x += paraEsquerda ? -VELOCIDADE_PROJETIL_X : VELOCIDADE_PROJETIL_X;

		if (carregarTempoExplosao > TEMPO_EXPLODIR_PROJETIL) {
			explodir = true;
		}
		carregarTempoExplosao += tempo;
		atualizarImagem(tempo);
		renderizar();
	}
	void Projetil::atualizarImagem(const float tempo) {
		if (!explodir) {
			pAnimacaoMovimento->atualizar(posicao, paraEsquerda, tempo * 0.2f, Ids::Ids::goblin_bomba);
		}
		else {
			posicao = Matematica::CoordenadaF(-100.0f, -100.0f);
		}
	}
	const bool Projetil::podeRemover() const {
		return explodir;
	}
}