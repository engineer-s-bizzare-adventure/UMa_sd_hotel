#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Quartos.h"
#include <ctime>
#include "Hospedes.h"

using namespace std;


/*void CriaQuantidadeQuartos() {
srand(time(NULL));
int QuantidadeQuartos = rand() % 10 + 21;
}


void criaCapacidadeQuartos(quarto *Vquarto) {
srand(time(NULL));
int min = 2;
int max = 5;
int RandomCapacidade = (min - (rand()%(int)(max-min+1)));
int RandomCapacidade = rand() % 5 + 3;
for (int i = 0; i < RandomCapacidade; i++){
Vquarto[i].numeroQuarto = i;
}
}
*/
int NumQuartos = rand() % 10 + 21;

//Valor guardado para usar na funçao de impressao dos quartos

void CriaRandomQuarto(quarto * Vquarto) {
	int CriaCapacidadeQuarto;

	for (int i = 0; i < NumQuartos; i++) {
		CriaCapacidadeQuarto = rand() % 5 + 3;
		//Cria capacidade random entre 3 e 5
		Vquarto[i].numeroQuarto = i;
		//atribui o numero de porta ao quarto
		Vquarto[i].capacidade = CriaCapacidadeQuarto;
		//atribui a capacidade de hospedes ao quarto
	}
}

void imprimeQuartos(int &CriaNumQuartos, quarto *Vquarto) {
	for (int i = 0; i < CriaNumQuartos; i++) {
		cout << "Os hospedes alojados no quarto " << Vquarto[i].numeroQuarto << " sao:" << endl;
		//imprime o numero do quarto
		for (int j = 0; j < Vquarto[i].capacidade; j++) {
			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;
		}

	}
}

void preencheQuartos(quarto * Vquarto, hospede*vHospede) { //Adicionar do vetor do Pedro em vez do vHospede
	int aux = 0;
	for (int j = 0; j<NumQuartos; j++) { //percorre os quartos
		for (int i = 0; i < Vquarto[i].capacidade; i++) { //percorre a capacidade de cada quarto
			Vquarto[i].familia = vHospede[aux].familia;
			Vquarto[i].ID = vHospede[aux].id;
			aux++;
		}
	}
}
