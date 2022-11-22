#include <iostream>


using namespace std;


void imprimirinsertionSort(int *vetor, int contador)
{
	for(int i = 0; i < contador; i++)
	{
		cout << "[" << i + 1 << "] = " << vetor[i] << endl;
	}
}

void quicksort(int *vetor, int contador)
{
	for(int i = 0; i < contador; i++)
	{
		cout << "[" << i + 1 << "] = " << vetor[i] << endl;
	}
}


void imprimirbuble(int vetor[], int contador)
{
	for(int i = 0; i < contador; i++)
	{
		cout << "[" << i + 1 << "] = " << vetor[i] << endl;
	}
}

void bubbleSort(int vetor[], int contador)
{
	for(int x = 0; x < contador - 1; x++)
	{
		for(int i = 0; i < contador - 1; i++)
		{
			if(vetor[i] > vetor[i + 1])
			{
				int temp = vetor[i];
				vetor[i] = vetor[i + 1];
				vetor[i + 1] = temp;
			}
		}
	}
}

void insertionsort(int vetor[], int contador)
{
	int i, j, x;
	for (i = 1; i < contador; i++)
	{
		j = i;
		while (j > 0 && vetor[j - 1] /*''*/ > /*''*/ vetor[j])//basta trocar o sinal > para ficar decrescente//
		{
			x = vetor[j];
			vetor[j] = vetor[j - 1];
			vetor[j - 1] = x;
			j--;
		}
	}
}

void quicksort(int vetor[], int comeco, int fim)
{
	int i, j, variavel, auxiliar;
	i = comeco;
	j = fim - 1;
	variavel = vetor[(comeco + fim) / 2];
	while(i <= j)
	{
		while(vetor[i] < variavel && i < fim)
		{
			i++;
		}
		while(vetor[j] > variavel && j > comeco)
		{
			j--;
		}
		if(i <= j)
		{
			auxiliar = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = auxiliar;
			i++;
			j--;
		}
	}
	if(j > comeco)
		quicksort(vetor, comeco, j + 1);
	if(i < fim)
		quicksort(vetor, i, fim);
}



int main()
{
	int contador = 0;
	int opcao = 0;
	int vetor[contador];
	cout << "Qual o tamanho do vetor?" << endl;
	cin >> contador;
	for (int i = 0; i < contador; i++)
	{
		cout << "Informe os elementos:" << "[" << i + 1 << "]" << endl;
		cin >> vetor[i];
	}

	while (opcao != 4)
	{

		cout << " ----------------------- ";

		cout << "\n 1 - Opcao 1 - insertionSort";
		cout << "\n 2 - Opcao 2 - quicksort ";
		cout << "\n 3 - Opcao 3 - bubbleSort ";
		cout << "\n 4 - Fechar Programa ";
		cout << "\n\n Escolha uma opcao: ";
		cin >> opcao;

		switch (opcao)
		{

		case 1:
		{

			cout << "Opcao escolhida - 1 " << endl;
			imprimirinsertionSort(vetor, contador);

			break;
		}

		case 2:
		{
			bubbleSort(vetor, contador);
			cout << " opcao escolhida - 2 " << endl;
			imprimirbuble(vetor, contador);

			break;
		}
		case 3:
		{
			cout << " opcao escolhida - 3 " << endl;
			quicksort(vetor, 0, contador);
			for(int i = 0; i < contador; i++)
			{
				cout << "[" << i + 1 << "] = " << vetor[i] << endl;
			}
			break;
		}

		case 4:
			if( opcao == 4)
				cout << "fechando...";
			break;
			return 0;
		}
	}
}

