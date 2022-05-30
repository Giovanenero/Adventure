#include "Principal.h"
#include "FaseFloresta.h"

using namespace Gerenciador;

Principal::Principal(): fase(new Fase::FaseFloresta()) {
	Executar();
}
Principal::~Principal() {
    delete fase;
}

void Principal::Executar() {

    fase->init();
    fase->executar();

}