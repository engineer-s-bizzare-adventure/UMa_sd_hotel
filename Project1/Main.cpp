#include <iostream>
#include <string>
#include <cstdlib> //  Função rand() e srand()
#include <time.h> // Lib para relogio do sistema
#include <stdlib.h>
#include <fstream> // Lib para ler/escrita ficheiros
#include "Hospedes.h"
#include "Recepcao.h"
#include "Quartos.h"
#include <locale.h>		// Lib para Acentuação para portugues
#include <Windows.h>	////////////////////////////////////////////
#include <conio.h>		// Lib para _getch()

#define KEY_RIGHT 224 // define o Int 224 como código da seta do lado direito

using namespace std;

// Declaracao VAR Globais
bool activo,menuActivo, activarRandom;// Var tipo bool para manter o programa sempre em funcionamento.
int counter = 0;
int contanome = 0;
int contafam = 0;
int contanac = 0;
int counterHospQuartos = 0;
int counterHosRecepcao = 0;
int Num = rand() % 10 + 10;

// Declaração dos protótipos das funções
void printIniciar();
void menuOpcoesSub(hospede*vHospede);
void menuOpcoes(hospede*vHospede);


int main() {
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, "Portuguese"); //habilita a acentuação para o português
	
	lerFicheiros(counter,contanome,contafam,contanac);
	//cout << "Counter" << counter << "Nome:" << contanome <<"Familia:" <<contafam <<"Nac:" << contanac << endl;

	hospede * vHospede = new hospede[counter]; // Apontador para a estruta de Hospede.h
	
	//rececao * vRececao = new rececao[Tamanho];
	activo = true;// inicialização variavel a true

	int escolhaOpcao, escolhaSaida; // var escolhaOpcão -> Menu || -> Sair  Var escolhaSaida -> y || n saida do programa. 
	
	printIniciar(); // Função imprime parte gráfica

	while (activo)
	{
		cin.clear();
		escolhaOpcao = _getch();  // Deteta a tecla premida
		if (escolhaOpcao == 111)    // Acesso aos menus opcoes e opcao saida.
		{
			cin.clear();
			system("CLS");
			menuOpcoes(vHospede);

		}
		
		else if (escolhaOpcao == 115)
		{
			cout << " Deseja sair do Programa? Y/N " << endl;
			cin.clear();
			escolhaSaida = _getch();

			if (escolhaSaida == 89 || escolhaSaida == 121)
			{
				cin.clear();
				activo = false;
			}
		}

		else if (escolhaOpcao == 224)

		{
			cin.clear();
			cout << "Seta Direita" << endl;
			criaRandomHospede(vHospede,Num,contanome,contafam,contanac,counterHosRecepcao);

		}
		//	else
		//	cout << "Opção Inválida" << endl;
		//system("PAUSE");
	}
}

// Definação das funções

void printIniciar() {
	cin.clear();
	cout << " (o)pçoes   (s)air " << endl;
	cout << " *********************** " << endl;
	cout << "  " << endl;
	cout << " ----------------------- " << endl;
	cout << " Hotel EDA - Grupo 9 " << endl;
	cout << " ----------------------- " << endl;
	cout << "  " << endl;
	cout << "  " << endl;
	cout << "========================" << endl;
	cout << "        Recepção         " << endl;
	cout << "========================" << endl;

	cin.clear();
}

void menuOpcoesSub(hospede*vHospede) {
	int escolhaSub;
	cin.clear();

	system("CLS");
	cout << " ----------------------- " << endl;
	cout << " Hotel EDA - Opçoes - Apresentação " << endl;
	cout << " ----------------------- " << endl;
	cout << "   " << endl;
	cout << "1 - Hospedes de origem estrangueira" << endl;
	cout << "2 - Hospedes de origem portuguesa ou sul-africana" << endl;
	cout << "0 - Voltar" << endl;

	escolhaSub = _getch();

	switch (escolhaSub) {
	case 49:
		cout << " Apresentacao de dados hospedes de origem estrangueira" << endl;
		nacionalidadeHospedesEstrangeiros(vHospede, counterHosRecepcao);
		system("pause");
		cin.clear();
	case 50:
		cout << "Hospedes de origem portuguesa ou sul-africana" << endl;
		nacionalidadeHospedesPTSA(vHospede, counterHosRecepcao);
		system("pause");
		cin.clear();
	case 48:
		cin.clear();
		menuOpcoes(vHospede);
		cin.clear();
	default:
		cin.clear();
		cout << "Opção não válida" << endl;
	}
	
}

void menuOpcoes(hospede*vHospede) {
	int escolha;
	system("CLS");

	cout << " ----------------------- " << endl;
	cout << " Hotel EDA - Opcoes " << endl;
	cout << " ----------------------- " << endl;
	cout << "   " << endl;
	cout << "1 - Limpar Quarto" << endl;
	cout << "2 - Apresentacao" << endl;
	cout << "0 - Voltar" << endl;
	
	escolha = _getch();
	
	switch (escolha) {
	case 49:
		cin.clear();
		cout << " Opcao 1 ecolhida" << endl;
		system("PAUSE");
	case 50:
		cin.clear();
		menuOpcoesSub(vHospede); // Certo Final
	case 48:
		cin.clear();
		system("CLS");
		printIniciar();//
	default:
		cin.clear();
		cout << "Opcao nao valida." << endl;
	}
	
}

