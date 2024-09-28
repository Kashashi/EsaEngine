#include "core\EsaCore.h"

extern Kashashi::EsaCore* Kashashi::GirigaraFromHere(commandLine cmd);

int main(int argc, char* argv[]){
	Kashashi::EsaCore* core = Kashashi::GirigaraFromHere({argc, argv});
	(*core).run();
	return 0;
}