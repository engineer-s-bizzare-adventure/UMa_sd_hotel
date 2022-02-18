#include "Hospedes.h"
#include "Recepcao.h"
using namespace std;

int hospedesExistentes = 0;

void copiaHospedesRececao(hospede *vHospede, int &numHospedes,int &counterHosRecepcao) {
	for (int i = 0; i < numHospedes; i++) {
		string hospede = vHospede[i].nome + " " + vHospede[i].familia + " - " + vHospede[i].nacionalidade;
		cout << hospede << endl;
		counterHosRecepcao++;
	}

	//Chamar a função do André para os Quartos com vRececao + vagas + hospedes existentes(counter)

}

void apagaRececao(hospede*vHospede, int &numHospedes, int &counterHosRecepcao) {
	counterHosRecepcao = 0;

	/*while (numHospedes != 0) {
		vHospede->nome.clear;
		vHospede->familia.clear;
		vHospede->nacionalidade.clear;
		for (int i = 0; i < numHospedes; i++) {
			vHospede[i].id = NULL;
		numHospedes--;
	}*/
}