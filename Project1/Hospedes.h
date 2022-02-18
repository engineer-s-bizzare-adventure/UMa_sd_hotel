#ifndef H_Hospede
#define H_Hospede
#include <string>
#include <iostream>
#include <vector>
#include "Recepcao.h"

using namespace std;

/*struct hospedes {
vector <string> nomes;
vector <string> familias;
vector <string> nacionalidades;
};*/

struct hospede {
	string nome;
	string familia;
	string nacionalidade;
	int id;
};


/*struct idHospedados {
	string nome;
	int id;
};*/

//Prototipos  

void copiaHospedesRececao(hospede *vHospede, int &numHospedes,int &counterHosRecepcao);
void apagaRececao(hospede*vHospede, int &numHospedes,int &counterHosRecepcao);
void lerFicheiros(int &counter, int &contanome, int &contafam, int &contanac);
void criaRandomHospede(hospede * vHospede, int &numHospedes, int &contanome, int &contafam, int &contanac, int &counterHosRecepcao);
//void verificaID(hospede *vRececao, int hospedesExistentes);
void nacionalidadeHospedesPTSA(hospede *vRececao, int &counterHosRecepcao);
void nacionalidadeHospedesEstrangeiros(hospede *vRececao, int &counterHosRecepcao);




#endif