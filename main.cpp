#include <fstream>
#include <iostream>
#include <stdio.h>
#include <cstdlib>


using namespace std;

FILE* abrirArquivo(char modo, char const caminho[30]){
	FILE *arquivo;
	switch(modo){
		case 'g':
			arquivo = fopen(caminho, "wt");
			break;
		case 'l':
			arquivo = fopen(caminho, "rt");
			break;
		case 'a':
			arquivo = fopen(caminho, "a");
			break;
	}
	if(arquivo == NULL){
		cout << "Não foi possivel abrir arquivo" << endl;
		exit(0);
	}
	return arquivo;
}

void FecharArquivo(FILE *arquivo){
	fclose(arquivo);
}

void Cadastra(char nome[30], int telefone){
	FILE * arquivo;
	arquivo = abrirArquivo('a', "agenda.txt");
	fprintf(arquivo, "%s %d\n", nome, telefone);
	FecharArquivo(arquivo);

}

void Listar(){
	FILE *arquivo;
	char nome[30];
	int telefone;

	arquivo = abrirArquivo('l', "agenda.txt");

	while(!feof(arquivo)){
		fscanf(arquivo, "%s %d ", &nome, &telefone);
		cout << "Nome: %s - Telefone: %d\n", nome, telefone;
	}
	FecharArquivo(arquivo);
}

int main(){
	int opcao;
	char nome[30];
	int telefone;

	do{
		system("cls");

		cout << "\n\n\t\tBem vindo ao programa de AGENDA\n";
		cout << "\nMENU";
		cout << "\n 1 - Cadastrar contato";
		cout << "\n 2 - Listar todos os contatos";
		cout << "\n 3 - Sair";

		cout << "\nDigite uma opção: ";

		cin >> opcao;

		system("clear");

		switch(opcao){
			case 1:
				cout << "\n\nDigite o nome: ";
				cin >> nome;
				cout << "Digite o telefone: ";
				cin >> telefone;

				Cadastra(nome, telefone);
				break;

			case 2:
				Listar();
				break;

			case 3:
				cout << "\n\nFinalizando o programa...\n\n";
				break;
				exit(0);

			default:
				cout << "\n\nOpcao Invalida! Tente Novamente\n\n";
		}


	}while(opcao != 3);

	return 0;
}
