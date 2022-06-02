#include "Projetil.h"

namespace Entidade {
	Projetil::Projetil(Matematica::CoordenadaF posInicio, const bool paraEsquerda, const int dano):
		Entidade(posInicio, Matematica::CoordenadaF(TAMANHO_PROJETIL_X, TAMANHO_PROJETIL_Y), Ids::Ids::projetil),
		pAnimacaoMovimento(new ElementoGrafico::AnimacaoMovimento()),
		dano(dano), explodir(false), 
		paraEsquerda(paraEsquerda)
	{
		inicializacao();
	}
	Projetil::~Projetil() {
		
	}
	void Projetil::inicializacao() {
		pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Goblin/goblinBomba.png", 19, Ids::Ids::goblin_bomba, tamanho, Matematica::CoordenadaF(2.5f, 2.5f));
		pAnimacaoMovimento->novaAnimacao("textura/Inimigo/Esqueleto/esqueletoBomba.png", 8, Ids::Ids::esqueleto_bomba, tamanho, Matematica::CoordenadaF(1.5f, 1.5f));
	}
	void Projetil::renderizar() {
		pAnimacaoMovimento->renderizar();
	}
	void Projetil::colisao(Matematica::CoordenadaF intersecao, Entidade* pEntidade) {
		if (pEntidade->getID() == Ids::Ids::oriana) {
			if (!explodir) {
				Personagem::Personagem* pOriana = static_cast<Personagem::Personagem*>(pEntidade);
				pOriana->podeTomarDano(dano);
				explodir = true;
			}
		}
		else if (pEntidade->getID() == Ids::Ids::plataforma) {
			explodir = true;
		}
	}
	void Projetil::atualizar(const float tempo) {
		if (paraEsquerda) {
			posicao.x += -VELOCIDADE_PROJETIL_X;
		}
		else {
			posicao.x += VELOCIDADE_PROJETIL_X; 
		}
		atualizarImagem(tempo);
		renderizar();
	}
	void Projetil::atualizarImagem(const float tempo) {
		if (!explodir) {
			pAnimacaoMovimento->atualizar(posicao, paraEsquerda, tempo * 0.6f, Ids::Ids::esqueleto_bomba);
		}
	}
	const bool Projetil::podeRemover() const {
		return explodir;
	}
}