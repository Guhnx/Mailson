#include <iostream>

using namespace std;

// Luis Gustavo Machado Costa

struct dataNascimento{
    int dia, ano;
    string mes;
};

struct funcionario{
    string nome, cpf, cargo;
    char sexo;
    double salario;
    dataNascimento dataNasc;
    int codigoSetor, idade;
};

int main()
{
    char sexo;
    int op, cont, setor;
    funcionario vetorFunc[50];
    funcionario f1;
    cont = 0;
    do{
        cout << "--- CONTROLE DE FUNCIONARIOS ---" << endl;
        cout << "[1] CADASTRAR FUNCIONARIO" << endl;
        cout << "[2] LISTAR TODOS FUNCIONARIOS" << endl;
        cout << "[3] LISTAR FUNCIONARIOS POR SEXO" << endl;
        cout << "[4] LISTAR FUNCIONARIOS POR SETOR" << endl;
        cout << "[0] SAIR" << endl;
        cout << "Opcao: ";
        cin >> op;
        switch(op){
            case 1:
                cout << "--- CADASTRAR FUNCIONARIO ---" << endl;
                cout << "OBS: Preencha as informacoes a seguir: " << endl;
                cout << "Nome: ";
                cin.ignore();
                getline(cin, f1.nome);
                cout << "Idade: ";
                cin >> f1.idade;
                cout << "Sexo (M/F): ";
                cin >> f1.sexo;
                cout << "CPF: ";
                cin >> f1.cpf;
                cout << "Cargo: ";
                cin >> f1.cargo;
                cout << "Salario: ";
                cin >> f1.salario;
                cout << "Dia de nascimento: ";
                cin >> f1.dataNasc.dia;
                cout << "Ano de nascimento: ";
                cin >> f1.dataNasc.ano;
                cout << "Mes de nascimento: ";
                cin >> f1.dataNasc.mes;
                cout << "Codigo do setor onde trabalha [0/99]: ";
                cin >> f1.codigoSetor;
                vetorFunc[cont] = f1;
                cont++;
            break;
            case 2:
                cout << "--- LISTA DOS FUNCIONARIOS CADASTRADOS ---" << endl;
                for(int i=0; i<cont; i++){
                    cout << "Nome: " << vetorFunc[i].nome << endl;
                    cout << "CPF: " << vetorFunc[i].cpf << endl;
                    cout << "Sexo: " << vetorFunc[i].sexo << endl;
                }
            break;
            case 3:
                cout << "--- BUSCA FILTRADA POR SEXO ---" << endl;
                cout << "INFORME O SEXO: ";
                cin >> sexo;
                for(int i=0; i<cont; i++){
                    if(vetorFunc[i].sexo == sexo){
                        cout << "Nome: " << vetorFunc[i].nome << endl;
                        cout << "CPF: " << vetorFunc[i].cpf << endl;
                    	cout << "Sexo: " << vetorFunc[i].sexo << endl;
                    }
                }
            break;
            case 4:
                cout << "--- BUSCA FILTRADA POR SETOR ---" << endl;
                cout << "INFORME O NUMERO DO SETOR: ";
                cin >> setor;
                for(int i=0; i<cont; i++){
                    if(vetorFunc[i].codigoSetor == setor){
                        cout << "Nome: " << vetorFunc[i].nome << endl;
                        cout << "CPF: " << vetorFunc[i].cpf << endl;
                    	cout << "Sexo: " << vetorFunc[i].sexo << endl;
                    }
                }
            break;
            default:
                if(op != 0)
                    cout << "Opcao Invalida." << endl;
            break;
        }
    }while(op != 0);

    return 0;
}