#include "core\EsaCore.h"


int main(int argc, char* argv[], char* env[]){
	Kashashi::EsaCore* core = new Kashashi::EsaCore();
	(*core).run();
	delete core;
	return 0;
}