#include "LinhaAnimacaoMovimento.h"

namespace ElementoGrafico {

	const float LinhaAnimacaoMovimento::trocaImagem = 0.08f;

	LinhaAnimacaoMovimento::LinhaAnimacaoMovimento(const char* caminhoTextura, const unsigned int contaImagem) :
		LinhaAnimacao(), contaImagem(contaImagem), imagemAtual(0), tempoTotal(0.f)
	{
		textura = AnimacaoMovimento::getGerenciadorGrafico()->loadTexture(caminhoTextura);
		if (!textura) {
			std::cout << "caminho " << caminhoTextura << " nao encontrado!" << std::endl;
			exit(1);
		}
		tamanho.width = textura->getSize().x / (float)(contaImagem);
		tamanho.height = textura->getSize().y;

	}

	LinhaAnimacaoMovimento::~LinhaAnimacaoMovimento() { }

	void LinhaAnimacaoMovimento::atualizar(bool Esquerda, float tempo) {
		tempoTotal += tempo;
		if (tempoTotal >= trocaImagem) {
			tempoTotal -= trocaImagem;
			imagemAtual++;
			if (imagemAtual >= contaImagem) {
				imagemAtual = 0;
			}
		}
		if (Esquerda) {
			tamanho.left = (imagemAtual + 1) * abs(tamanho.width);
			tamanho.width = -abs(tamanho.width);
		}
		else {
			tamanho.left = imagemAtual * tamanho.width;
			tamanho.width = abs(tamanho.width);
		}
	}

	void LinhaAnimacaoMovimento::resetar() {
		tempoTotal = 0.f;
		imagemAtual = 0;
	}
}