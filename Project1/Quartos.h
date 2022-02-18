#ifndef H_Quartos
#define H_Quartos
#include <string>
#include <iostream>
#include <vector>
#include "Hospedes.h"

using namespace std;

struct quarto {
	int numeroQuarto;
	int capacidade;
	string familia;
	int ID;
	//struct ocupantes {
	//string familia;
	//int ID;
};

//void CriaQuantidadeQuartos();
void CriaRandomQuarto(quarto *Vquarto);
void imprimeQuartos(int &NumQuartos, quarto *Vquarto);
void preencheQuartos(quarto * Vquarto, hospede*vHospede);


//void criaCapacidadeQuartos(quarto *Vquarto);


#endif