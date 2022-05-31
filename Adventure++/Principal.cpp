#include "Principal.h"
#include "FaseFloresta.h"

using namespace Gerenciador;

Principal::Principal(): 
    fase(new Fase::FaseFloresta()) 
{
	Executar();
}
Principal::~Principal() {
    //ver o motivo do erro...
    /*
    if (fase != nullptr) {
        delete(fase);
        fase = nullptr;
    }
    */
}

void Principal::Executar() {
    fase->init();
    fase->executar();
}