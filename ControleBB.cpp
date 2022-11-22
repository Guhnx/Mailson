#include <iostream>
#include <fstream>   
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct pessoa{
    string nome, usuario, senha;
    int tipo;
};

struct livro{
  string titulo, autor, genero;
  int anoLancamento;
};

struct emprestimo{
    string titulo, nome;
};

string nomeUsuario = "";

// ######################################################
// Login
int login(){
    system("cls");
    string  login, senha;
    pessoa p1;
    cout << "-_______ LOGIN _______-" << endl << endl;
    cout << "USUARIO: ";
    cin >> login;
    cout << "SENHA: ";
    cin >> senha;
    
    ifstream arquivo("usuarios.txt");
    while(arquivo >> p1.nome >> p1.usuario >> p1.senha >> p1.tipo){
        if(login == p1.usuario && senha == p1.senha){
            nomeUsuario = p1.nome;
            return p1.tipo;
        }
    }
    arquivo.close();
    cout << "Usuario ou senha invalidos" << endl;
    return -1;
}

// ######################################################
// ADMINISTRADOR
void cadastroUsuario(){
    system("cls");
    ofstream arquivo;
    arquivo.open("usuarios.txt", ios::app);
    pessoa p1;
    
    cout << "-_______ CADASTRO DE USUARIO _______-" << endl << endl;
    cout << "NOME: ";
    cin >> p1.nome;
    cout << "USUARIO: ";
    cin >> p1.usuario;
    cout << "SENHA: ";
    cin >> p1.senha;
    cout << "[1] ADMINISTRADOR - [2] FUNCIONARIO - [3] ALUNO" << endl;
    cout << "TIPO: ";
    cin >> p1.tipo;
    
    if(p1.tipo == 1 || p1.tipo == 2 || p1.tipo == 3){
        arquivo << p1.nome << " " << p1.usuario << " " << p1.senha << " " << p1.tipo << endl;
        cout << "Cadastro realizado com sucesso!" << endl;
    }else{
        cout << "Dados invalidos!" << endl;
        cadastroUsuario();
    }
    
    arquivo.close();
}

void editarUsuario(string nome){
    system("cls");
    bool editar = false;
    ifstream arquivo("usuarios.txt");
    if(!arquivo.is_open()){
        cout << "Falha ao abrir o arquivo" << endl;
        return;
    }
    ofstream temp("temp.txt");
    pessoa p1;
    pessoa p2;
    while(arquivo >> p1.nome >> p1.usuario >> p1.senha >> p1.tipo){
        if(nome == p1.nome){
            cout << "ALTERAR DADOS DO USUARIO " << p1.nome << endl;
            cout << "NOME: ";
            cin >> p2.nome;
            cout << "USUARIO: ";
            cin >> p2.usuario;
            cout << "SENHA: ";
            cin >> p2.senha;
            cout << "[1] ADMINISTRADOR - [2] FUNCIONARIO - [3] ALUNO" << endl;
            cout << "TIPO: ";
            cin >> p2.tipo;
            temp << p2.nome << " " << p2.usuario << " " << p2.senha << " " << p2.tipo << endl;
            editar = true;
        }else{
            temp << p1.nome << " " << p1.usuario << " " << p1.senha << " " << p1.tipo << endl;
        }
    }
    if(editar){
        cout << "Usuario alterado com sucesso!" << endl;
    }else{
        cout << "Nao e possivel alterar o usuario!" << endl;
    }
    arquivo.close();
    temp.close();
    remove("usuarios.txt");
    rename("temp.txt", "usuarios.txt");
}

void excluirUsuario(string nome){
    bool excluir = false;
    ifstream arquivo("usuarios.txt");
    if(!arquivo.is_open()){
        cout << "Falha ao abrir o arquivo" << endl;
        return;
    }
    ofstream temp("temp.txt"); 
    pessoa p1;
    while(arquivo >> p1.nome >> p1.usuario >> p1.senha >> p1.tipo){
        if(nome != p1.nome){
            temp << p1.nome << " " << p1.usuario << " " << p1.senha << " " << p1.tipo << endl;
        }else{
            excluir = true;
        }
    }
    if(excluir){
        cout << "Usuario excluido com sucesso!" << endl;
    }else{
        cout << "Nao e possivel excluir o usuario!" << endl;
    }
    arquivo.close();
    temp.close();
    remove("usuarios.txt");
    rename("temp.txt", "usuarios.txt");
}

void imprimirArquivo(){
    pessoa p1;
    ifstream arquivo;
    arquivo.open("usuarios.txt", ios::in);
    cout << "-_______ LISTA USUARIOS _______-" << endl;
    while(arquivo >> p1.nome >> p1.usuario >> p1.senha >> p1.tipo){
        cout << p1.usuario << endl;
    }
    arquivo.close();
}

void administrador(){
    system("cls");
    int op;
    string nome;
    do{
        cout << "-_______ ADMINISTRADOR _______-" << endl << endl;
        cout << "[1] LISTAR USUARIOS" << endl;
        cout << "[2] CADASTRAR USUARIO" << endl;
        cout << "[3] EDITAR USUARIO" << endl;
        cout << "[4] EXCLUIR USUARIO" << endl;
        cout << "[0] SAIR" << endl;
        cout << "OPCAO: ";
        cin >> op;
        switch(op){
            case 1:
                imprimirArquivo();
            break;
            case 2:
                cadastroUsuario();
            break;
            case 3:
                cout << "NOME DO USUARIO PARA ALTERACAO: ";
                cin >> nome;
                editarUsuario(nome);
            break;
            case 4:
                cout << "NOME DO USUARIO PARA EXCLUSAO: ";
                cin >> nome;
                excluirUsuario(nome);
            break;
        }
    }while(op != 0);
}

// ######################################################
// FUNCAO GERAL
void buscaLivro(string titulo){
    system("cls");
    livro l1;
    ifstream arquivo;
    arquivo.open("livros.txt", ios::in);
    cout << "-_______ CONSULTA LIVRO _______-" << endl;
    while(arquivo >> l1.titulo >> l1.autor >> l1.genero >> l1.anoLancamento){
        if(l1.titulo == titulo){
            cout << "TITULO: " << l1.titulo << endl;
            cout << "AUTOR: " << l1.autor << endl;
            cout << "GENERO: " << l1.genero << endl;
            cout << "ANO DE LANCAMENTO: " << l1.anoLancamento << endl;
            return;
        }
    }
    arquivo.close();
}

void imprimirLivros(){
    system("cls");
    livro l1;
    ifstream arquivo;
    arquivo.open("livros.txt", ios::in);
    cout << "-_______ LISTA DE LIVROS _______-" << endl;
    while(arquivo >> l1.titulo >> l1.autor >> l1.genero >> l1.anoLancamento){
        cout << l1.titulo << endl;
    }
    arquivo.close();
}

// ######################################################
// FUNCIONARIO
void cadastroLivro(){
    system("cls");
    ofstream arquivo;
    arquivo.open("livros.txt", ios::app);
    livro l1;
    
    cout << "-_______ CADASTRAR LIVRO _______-" << endl << endl;
    cout << "TITULO DO LIVRO: ";
    cin >> l1.titulo;
    cout << "AUTOR DO LIVRO: ";
    cin >> l1.autor;
    cout << "GENERO DO LIVRO: ";
    cin >> l1.genero;
    cout << "ANO DE LANCAMENTO: ";
    cin >> l1.anoLancamento;
    
    arquivo << l1.titulo << " " << l1.autor << " " << l1.genero << " " << l1.anoLancamento << endl;
    arquivo.close();
}

void editarLivro(string titulo){
    system("cls");
    ifstream arquivo("livros.txt");
    if(!arquivo.is_open()){
        cout << "Falha ao abrir o arquivo" << endl;
        return;
    }
    ofstream temp("temp.txt");
    livro l1;
    livro l2;
    while(arquivo >> l1.titulo >> l1.autor >> l1.genero >> l1.anoLancamento){
        if(titulo == l1.titulo){
            cout << "ALTERAR DADOS DO LIVRO " << l1.titulo << endl;
            cout << "TITULO: ";
            cin >> l2.titulo;
            cout << "AUTOR: ";
            cin >> l2.autor;
            cout << "GENERO: ";
            cin >> l2.genero;
            cout << "ANO DE LANCAMENTO: ";
            cin >> l2.anoLancamento;
            temp << l2.titulo << " " << l2.autor << " " << l2.genero << " " << l2.anoLancamento << endl;
        }else{
            temp << l1.titulo << " " << l1.autor << " " << l1.genero << " " << l1.anoLancamento << endl;
        }
    }
    arquivo.close();
    temp.close();
    remove("livros.txt");
    rename("temp.txt", "livros.txt");
}

void excluirLivro(string titulo){
    ifstream arquivo("livros.txt");
    if(!arquivo.is_open()){
        cout << "Falha ao abrir o arquivo" << endl;
        return;
    }
    ofstream temp("temp.txt"); 
    livro l1;
    while(arquivo >> l1.titulo >> l1.autor >> l1.genero >> l1.anoLancamento){
        if(titulo != l1.titulo){
            temp << l1.titulo << " " << l1.autor << " " << l1.genero << " " << l1.anoLancamento << endl;
        }
    }
    arquivo.close();
    temp.close();
    remove("livros.txt");
    rename("temp.txt", "livros.txt");
}

void emprestimoLivro(){
    system("cls");
    emprestimo e1;
    livro l1;
    pessoa p1;
    bool achou = false;
    
    ofstream arquivo;
    arquivo.open("emprestimo.txt", ios::app);
    
    cout << "-_______ EMPRESTIMO DE LIVRO _______-" << endl << endl;
    cout << "TITULO DO LIVRO: ";
    cin >> e1.titulo;
    cout << "NOME DO ALUNO: ";
    cin >> e1.nome;
    
    ifstream arquivo2("livros.txt");
    ifstream arquivo3("usuarios.txt");
    while(arquivo2 >> l1.titulo >> l1.autor >> l1.genero >> l1.anoLancamento){
        if(e1.titulo == l1.titulo){
            while(arquivo3 >> p1.nome >> p1.usuario >> p1.senha >> p1.tipo){
                if(e1.nome == p1.nome){
                    arquivo << e1.titulo << " " << e1.nome << endl;
                    achou = true;
                }
            }
        }
    }
    if(!achou){
        cout << "Livro ou usuario nao encontrado nos arquivos!" << endl;
    }
    arquivo.close();
    arquivo2.close();
    arquivo3.close();
    
}

void imprimirEmprestimos(){
    system("cls");
    emprestimo e1;
    ifstream arquivo;
    arquivo.open("emprestimo.txt", ios::in);
    cout << "-_______ LISTA DE EMPRESTIMOS _______-" << endl;
    while(arquivo >> e1.titulo >> e1.nome ){
        cout << "TITULO: " << e1.titulo << " - ALUNO: " << e1.nome << endl;
    }
    arquivo.close();
}

void funcionario(){
    system("cls");
    int op, op2;
    string titulo;
    do{
        cout << "-_______ FUNCIONARIO _______-" << endl << endl;
        cout << "[1] LISTAR LIVROS CADASTRADOS" << endl;
        cout << "[2] BUSCAR LIVRO" << endl;
        cout << "[3] INSERIR, ALTERAR E EXLCUIR LIVRO" << endl;
        cout << "[4] LISTAR EMPRESTIMOS" << endl;
        cout << "[5] FAZER EMPRESTIMO" << endl;
        cout << "[0] SAIR" << endl;
        cout << "OPCAO: ";
        cin >> op;
        switch(op){
            case 1:
                imprimirLivros();
            break;
            case 2:
                cout << "TITULO DO LIVRO PARA CONSULTA: ";
                cin >> titulo;
                buscaLivro(titulo);
            break;
            case 3:
                system("cls");
                cout << "-_______ LIVROS _______-" << endl;
                cout << "[1] CADASTRAR LIVRO" << endl;
                cout << "[2] ALTERAR LIVRO" << endl;
                cout << "[3] EXCLUIR LIVRO" << endl;
                cout << "[0] VOLTAR" << endl;
                cout << "OPCAO: ";
                cin >> op2;
                switch(op2){
                    case 0:
                    break;
                    case 1:
                        cadastroLivro();
                    break;
                    case 2:
                        cout << "TITULO DO LIVRO PARA ALTERACAO: ";
                        cin >> titulo;
                        editarLivro(titulo);
                    break;
                    case 3:
                        cout << "TITULO DO LIVRO PARA EXCLUSAO: ";
                        cin >> titulo;
                        excluirLivro(titulo);
                    break;
                }
            break;
            case 4:
                imprimirEmprestimos();
            break;
            case 5:
                emprestimoLivro();
            break;
        }
    }while(op != 0);
}

// ######################################################
// ALUNO
void emprestimos(){
    emprestimo e1;
    ifstream arquivo;
    arquivo.open("emprestimo.txt", ios::in);
    cout << "-_______ LIVROS EMPRESTADOS A " << nomeUsuario << " _______-" << endl;
    while(arquivo >> e1.titulo >> e1.nome ){
        if(nomeUsuario == e1.nome){
            cout << e1.titulo << endl;
        }
    }
    arquivo.close();
}

void aluno(){
    system("cls");
    int op;
    string titulo;
    do{
        cout << "-_______ ALUNO _______-" << endl << endl;
        cout << "[1] LISTAR LIVROS CADASTRADOS" << endl;
        cout << "[2] BUSCAR LIVRO" << endl;
        cout << "[3] LIVROS PEGADO EMPRESTADO" << endl;
        cout << "[0] SAIR" << endl;
        cout << "OPCAO: ";
        cin >> op;
        switch(op){
            case 1:
                imprimirLivros();
            break;
            case 2:
                cout << "TITULO DO LIVRO PARA CONSULTA: ";
                cin >> titulo;
                buscaLivro(titulo);
            break;
            case 3:
                emprestimos();
            break;
            default:
                if(op != 0)
                cout << "OPCAO INVALIDA" << endl;
            break;
        }
    }while(op != 0);
}

int main()
{
    string enter;
    int op;
    int permissao;
    do{
        system("cls");
        cout << "___________ BIBLIOTECA ___________" << endl;
        cout << "-_______ CONTROLE VIRTUAL _______-" << endl << endl;
        cout << "[1] LOGIN" << endl;
        cout << "[0] SAIR" << endl;
        cout << "Opcao: ";
        cin >> op;
        switch(op){
            case 1:
                permissao = login();
                switch(permissao){
                    case 1:
                        administrador();
                    break;
                    case 2:
                        funcionario();
                    break;
                    case 3:
                        aluno();
                    break;
                }
            break;
            default:
                if(op != 0){
                    cout << "Opacao Invalida" << endl;
                }
        }
    }while(op != 0);
    return 0;
}