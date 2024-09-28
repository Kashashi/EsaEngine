#include "Esa.h"

class Girigara: public Kashashi::EsaCore{
public:
	Girigara(const Kashashi::軟體資料& 特化數據): Kashashi::EsaCore(特化數據){
		
	}
	~Girigara(){}
};

Kashashi::EsaCore* Kashashi::GirigaraFromHere(Kashashi::commandLine cmd){
	Kashashi::軟體資料 特化資料;
	特化資料.標題名稱 = "GiriGara";
	特化資料.cmd = cmd;
	return new Girigara(特化資料);
}