#pragma once

#include <iostream>

namespace Matematica {
	template<typename TIPO>
	class Coordenada
	{
	public:
		TIPO x;
		TIPO y;
	public:
		Coordenada(TIPO x = 0, TIPO y = 0);
		~Coordenada();

		void operator=(Coordenada<TIPO> outro);
		void operator+=(Coordenada<TIPO> outro);
		void operator-=(Coordenada<TIPO> outro);
		void operator/=(Coordenada<TIPO> outro);
		void operator*=(Coordenada<TIPO> outro);
		void operator*=(double mult);
		void operator/=(double div);

		Coordenada<TIPO> operator+(Coordenada<TIPO> outro);
		Coordenada<TIPO> operator-(Coordenada<TIPO> outro);
		Coordenada<TIPO> operator*(Coordenada<TIPO> outro);
		Coordenada<TIPO> operator*(double mult);
		Coordenada<TIPO> operator/(Coordenada<TIPO> outro);
		Coordenada<TIPO> operator/(double div);

	};
	typedef Coordenada<double> CoordenadaD;
	typedef Coordenada<float> CoordenadaF;
	typedef Coordenada<int> CoordenadaI;
	typedef Coordenada <unsigned int> CoordenadaU;

	template<typename TIPO>
	Coordenada<TIPO>::Coordenada(TIPO x, TIPO y) :
		x(x), y(y)
	{}

	template<typename TIPO>
	Coordenada<TIPO>::~Coordenada() {}

	template<typename TIPO>
	void Coordenada<TIPO>::operator=(Coordenada<TIPO> outro) {
		this->x = outro.x;
		this->y = outro.y;
	}

	template<typename TIPO>
	void Coordenada<TIPO>::operator+=(Coordenada<TIPO> outro) {
		this->x += outro.x;
		this->y += outro.y;
	}

	template<typename TIPO>
	void Coordenada<TIPO>::operator-=(Coordenada<TIPO> outro) {
		this->x -= outro.x;
		this->y -= outro.y;
	}

	template<typename TIPO>
	void Coordenada<TIPO>::operator/=(Coordenada<TIPO> outro) {
		this->x /= outro.x;
		this->y /= outro.y;
	}

	template<typename TIPO>
	void Coordenada<TIPO>::operator*=(Coordenada<TIPO> outro) {
		this->x *= outro.x;
		this->y *= outro.y;
	}

	template<typename TIPO>
	void Coordenada<TIPO>::operator*=(double mult) {
		this->x *= mult;
		this->y += mult;
	}

	template<typename TIPO>
	void Coordenada<TIPO>::operator/=(double div) {
		if (div == 0.0f) {
			std::cout << "ERRO: div = 0" << std::endl;
			exit(1);
		}
		this->x /= div;
		this->y /= div;
	}

	template<typename TIPO>
	Coordenada<TIPO> Coordenada<TIPO>::operator+(Coordenada<TIPO> outro) {
		Coordenada aux(this->x, this->y);
		aux.x += outro.x;
		aux.y += outro.y;
		return aux;
	}

	template<typename TIPO>
	Coordenada<TIPO> Coordenada<TIPO>::operator-(Coordenada<TIPO> outro) {
		Coordenada aux(this->x, this->y);
		aux.x -= outro.x;
		aux.y -= outro.y;
		return aux;
	}

	template<typename TIPO>
	Coordenada<TIPO> Coordenada<TIPO>::operator*(Coordenada<TIPO> outro) {
		Coordenada aux(this->x, this->y);
		aux.x *= outro.x;
		aux.y *= outro.y;
		return aux;
	}

	template<typename TIPO>
	Coordenada<TIPO> Coordenada<TIPO>::operator*(double mult) {
		Coordenada aux(this->x, this->y);
		aux.x *= mult;
		aux.y *= mult;
		return aux;
	}

	template<typename TIPO>
	Coordenada<TIPO> Coordenada<TIPO>::operator/(Coordenada<TIPO> outro) {
		Coordenada aux(this->x, this->y);
		aux.x /= outro.x;
		aux.y /= outro.y;
		return aux;
	}

	template<typename TIPO>
	Coordenada<TIPO> Coordenada<TIPO>::operator/(double div) {
		if (div == 0.0f) {
			std::cout << "ERRO: div = 0" << std::endl;
			exit(1);
		}
		Coordenada aux(this->x, this->y);
		aux.x /= div;
		aux.y /= div;
		return aux;
	}
}

