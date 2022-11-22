#include <iostream>

using namespace std;

void prencher (int vector[], int tam){
		for (int n = 0; n < tam; n++){
		cout << n+1 <<"- " "Insira o valor desta posicao: ";
		cin >> vector[n];
	}
}
void imprimir (int vector[], int tam){
		for (int n = 0; n < tam; n++){
		cout << n+1 << "- " << vector[n] << endl;
	}
}

void selectionSort(int vector[], int tam){
	int qtdComparacoes = 0;
	int qtdTrocas = 0;
	int aux, menor;
	for (int a = 0; a < tam - 1; a++){
		menor = a;
		for (int b = a+1; b < tam; b++){
			if(vector[menor] > vector[b]){
				menor = b;	
			}
	}
	qtdComparacoes++;
	if(a!=menor){
		aux = vector[a];
		vector[a] = vector[menor];
		vector[menor] = aux;
		qtdTrocas++;
	}
}
	cout << "--------------------------------" <<endl; 	
	cout << "Comparacoes: " << qtdComparacoes<< endl;
	cout << "Trocas: " << qtdTrocas << endl;
	cout << "--------------------------------" <<endl;
}
void insertionSort(int vector[], int tam){
	int qtdComparacoes = 0;
	int qtdTrocas = 0;
	int aux;
	for (int i = 0; i < tam; i++){
		for (int j = 1+1; j > 0 ; j--){
			qtdComparacoes++;
			if (vector[j] < vector[j-1]){
				aux = vector[j];
				vector[j] = vector[j-1];
				vector[j-1] = aux;
				qtdTrocas++;
			}
				
		}
	}
	cout << "--------------------------------" <<endl; 	
	cout << "Comparacoes: " << qtdComparacoes<< endl;
	cout << "Trocas: " << qtdTrocas << endl;
	cout << "--------------------------------" <<endl;
}
void bubbleSort(int vector[], int tam){
	int qtdComparacoes = 0;
	int qtdTrocas = 0;
	int aux;
	for (int i = 0; i < tam; i++){
		for (int f = 0; f < tam - 1; f++){
			qtdComparacoes++;
			if (vector[f] > vector[f+1]){
				aux = vector[f];
				vector[f] = vector[f+1];
				vector[f+1] = aux;
				qtdTrocas++;
			}
		}
	}
	cout << "--------------------------------" <<endl; 	
	cout << "Comparacoes: " << qtdComparacoes << endl;
	cout << "Trocas: " << qtdTrocas << endl;
	cout << "--------------------------------" <<endl; 	
}
int main (){
	int tam = 0;
	int vector[tam];
	cout << "Insira o quantidade de numeros: ";
	cin >> tam;
    prencher(vector, tam);
	cout << "" << endl;
	int op;
	do{
	cout << "--------------------------------" <<endl; 	
	cout << "1- SelectionSort." << endl;
	cout << "2- InsertSort." << endl;
	cout << "3- BubbleSort." << endl;
	cout << "--------------------------------" << endl;
	cout << "Escolha: ";
	cin >> op;
	cout << "--------------------------------" << endl;
	switch(op){
		case 1:
	selectionSort(vector, tam);
	cout << "------ Ordenados SelectionSort ------" << endl;
	imprimir(vector, tam);
	break;
		case 2:
	insertionSort(vector, tam);
	cout << "------ Ordenados InsertionSort ------" << endl;
	imprimir(vector, tam);
	break;
		case 3:
	bubbleSort(vector, tam);
	cout << "------ Ordenados BubbleSort ------" << endl;
	imprimir(vector, tam);
	}
}while(op != 0);
}