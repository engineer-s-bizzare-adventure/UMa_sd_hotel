#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> //Remove
#include "Quartos.h"
#include "Hospedes.h"
#include "Recepcao.h"
#include "time.h"

//#define Tamanho 8

using namespace std;

vector <string> nomes;
vector <string> familias;
vector <string> nacionalidades;


void lerFicheiros(int &counter, int &contanome, int &contafam, int &contanac) { //Ler o numero de linhas de cada ficheiro text

	fstream nome("nome.txt");
	fstream nacionalidade("nacionalidade.txt");
	fstream familia("familia.txt");

	string linhaNome;
	string linhaFam;
	string linhaNac;

	/*int numlinhasnome = 0; COUNTERS
	int numlinhasfam = 0;
	int numlinhasnac = 0;*/

	int i = 0;
	//char chars[] = "abc"; //**Se quiser remover

	for (int i = 0; getline(nome, linhaNome); i++) {
		nomes.push_back(linhaNome);
		/*if (i == 0) { //**Remover
		//str.erase (std::remove(str.begin(), str.end(), chars[i]), str.end());
		nomes[i].erase(remove(nomes[i].begin(), nomes[i].end(), chars[i]));
		}*/
		//cout << "Nome: " << nomes[i] << endl;
		counter++;
		contanome++;
	}
	nome.close();

	for (int i = 0; getline(nacionalidade, linhaNac); i++) {
		nacionalidades.push_back(linhaNac);
		//cout << "Nacionalidade: " << nacionalidades[i] << endl;
		counter++;
		contanac++;
		//cout << i << endl; //Nacionalidade Portugues/Sul Africano = 160/178
	}
	nacionalidade.close();

	for (int i = 0; getline(familia, linhaFam); i++) {
		familias.push_back(linhaFam);
		//cout << "Familia: " << familias[i] << endl;
		counter++;
		contafam++;
	}
	familia.close();

	/*
	for (int i = 0; getline(nome,linhaNome);i++) { //Tamanho para os nomes
	//numlinhasnome++;
	vHospede[i].nome.push_back(linhaNome);
	}
	---------------------------------------------------------------------------------
	//char *nomeHos = new char[numlinhasnome++];
	nome.close();

	for (int i = 0; getline(familia, linhaFam); i++) { //Tamanho para as familias
	//numlinhasfam++;
	vHospede[i].familia = linhaFam;
	}
	//char *familiaHos = new char[numlinhasfam++];
	familia.close();

	for (int i = 0; getline(nacionalidade, linhaFam); i++) { //Tamanho para as nacionalidades
	//numlinhasnac++;
	vHospede[i].nacionalidade = linhaNac;
	}
	//char *nacionalidadeHos = new char[numlinhasnac];
	nacionalidade.close();

	for (int i = 0; i < numlinhasnome && i < numlinhasfam && i < numlinhasnac; i++) {
	if (i < numlinhasnome) {
	vHospede[i].nome = linhaNome;
	}
	else if (i < numlinhasfam) {
	vHospede[i].familia = linhaFam;
	}
	else if (i < numlinhasnac) {
	vHospede[i].nacionalidade =linhaNac;
	}
	}
	*/

	/*for (int i = 0; i < 40; i++) {
	cout << "Nomes guardados: " << nomes[i] << endl;
	}*/
}

void criaRandomHospede(hospede * vHospede,int &numHospedes,int &contanome, int &contafam, int &contanac, int &counterHosRecepcao) { //Depende de quantos queremos fazer para o dia
	int randomNome;
	int randomNacionalidade;
	int randomFamilia;
	int nID;

	for (int i = 0; i < numHospedes; i++) {
		randomNome = rand() % contanome;
		randomNacionalidade = rand() % contanac;
		randomFamilia = rand() % contafam;
		nID = rand() % 899999+1000000;

		/*cout << "Numero do Nome: " << randomNome << endl;
		cout << "Numero da Nacionalidade: " << randomNacionalidade << endl;
		cout << "Numero da Familia: " << randomFamilia << endl;
		cout << "nID" << nID <<endl;*/

		vHospede[i].nome = nomes[randomNome];
		vHospede[i].nacionalidade = nacionalidades[randomNacionalidade];
		vHospede[i].familia = familias[randomFamilia];
		vHospede[i].id = nID;

		/*cout << "Nome:" << vHospede[i].nome << endl;
		cout << "Nacionalidade:" << vHospede[i].nacionalidade << endl;
		cout << "Familia:" << vHospede[i].familia << endl;*/

		/*string hospede = vHospede[i].nome + " " + vHospede[i].familia;
		cout << hospede << endl;*/

		/*delete items[5];   Vetor
		items[5] = NULL;*/  //NULL para não dar erro na proxima alocação do mesmo indice

		/*//Apagar:             
		vHospede->nome.clear;
		vHospede->familia.clear;
		vHospede->nacionalidade.clear;
		for (int i = 0; i < numHospedes; i++) {
			vHospede[i].id = NULL;
		}*/
	}
	copiaHospedesRececao(vHospede, numHospedes, counterHosRecepcao);

	/*int e = 0;
	while (e < 5) {
	cout << vHospede[e].nome << " " << vHospede[e].nacionalidade << " " << vHospede[e].familia << endl;
	e++;
	}*/
}

//-------------------------------------------------------------------------------------------------------------

/*void verificaID(hospede * vRececao,int hospedesExistentes) {
	int aux = hospedesExistentes - hospedesRemovidos; //Indice dos hospedes a serem usados
	int aux2 = aux;
	for (int i = 0; i < vagas; i++) {
		for (int e = 0; e < vagas; e++) {
			if (i == e) {
				e++;
			}
			else if (vHospede[aux].id == vHospede[aux2].id) {
			}
			aux2++;
		}
		aux++;
	}
}
*/

/*void verificaID(int ** hospedesMesmoID[][Tamanho], hospede * vHospede, int vagasHospedesQuartos) { //Matriz (Hospede, Hospede)
	for (int i = 0; i<vagasHospedesQuartos; i++) {
		int ** hospedesMesmoID = new int*[Tamanho];
		for (int e = 0; e < Tamanho; e++) {
			if (i == e) {
				e++;
			}
			else if (vHospede[i].id == vHospede[e].id) {
				hospedesMesmoID[vHospede[i].id][e];
				cout << "ID " << hospedesMesmoID[i] << " Numero de Pessoas: " << hospedesMesmoID[i][e] << endl;
			}
		}
	}
}*/



//Ler Nacionalidades Portuguesas e Sul Africanas:

void nacionalidadeHospedesPTSA(hospede *vHospede, int &counterHosRecepcao) {
	//cout << "Hospedes Portugueses / Sul Africanos:" << endl;
	for (int i = 0; i < counterHosRecepcao; i++) {
		if (vHospede[i].nacionalidade == "Portugal" || vHospede[i].nacionalidade == "South Africa") {
			string PTSA = vHospede[i].nome + " " + vHospede[i].familia; +" - " + vHospede[i].nacionalidade;
			cout << PTSA << endl;
		}
	}
}

void nacionalidadeHospedesEstrangeiros(hospede *vHospede, int &counterHosRecepcao) {
	//cout << "Hospedes Estrangeiros:" << endl;
	for (int i = 0; i < counterHosRecepcao; i++) {
		if (vHospede[i].nacionalidade != "Portugal" && vHospede[i].nacionalidade != "South Africa") {
			string Estrangeiros = vHospede[i].nome + " " + vHospede[i].familia; +" - " + vHospede[i].nacionalidade;
			cout << Estrangeiros << endl;
		}
	}
}