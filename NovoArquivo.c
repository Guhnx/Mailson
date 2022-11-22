#include <stdio.h>
#define ncolunas 5
#define nprovas 3
#define nalunos 5


int main(void)
{
  /*Criando a struct */
  struct ficha_de_aluno
  {
    char nome[30];
    float notas[1];
    float nota[2];
  };
  
  //void imprime (struct tipoaluno alunos[nalunos]);
  //void leitura (struct tipoaluno alunos[nalunos]);

  struct ficha_de_aluno aluno;
  
  printf("Nome do aluno: ");
  fflush(stdin);
  
  fgets(aluno.nome, 40, stdin);
  
  printf("Informe a 1a nota:  ");
  scanf("%f", &aluno.notas[1]);
  printf("Informe a 2a nota:  ");
  scanf("%f", &aluno.nota[2]);

  
  
  printf("\n--Resultado--\n");
  printf("Nome: %s", aluno.nome);
  printf("Nota da Prova 1: %.2f\n" , aluno.notas[1]);
  printf("Nota da Prova 2: %.2f\n" , aluno.nota[2]);
  
  return(0);
}