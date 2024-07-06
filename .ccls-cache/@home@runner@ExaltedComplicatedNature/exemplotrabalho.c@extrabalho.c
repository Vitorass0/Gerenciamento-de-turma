#include <stdio.h>
#define MAX 50

typedef struct{
  char nome[50];
  int matricula;
  int notas[3];
}aluno;

void escrever_novo_aluno(aluno a);
void ler_alunos(int *qtde, aluno alunos[]);
void listar_aprovados();
void listar_cadastrados();
void cadastrar_aluno();
void procurar_aluno();

int qtde = 0;

//vetor global para armazenar os dados dos alunos
aluno alunos[MAX];

//Exemplo de um sistema simplificado para gestão de alunos usando arquivos. Pode servir de exemplo para o trabalho 1.

int main(){

  int op, i;

  do{
    printf("\n\nDigite a opcao desejada: \n1 - Cadastrar novo aluno\n2 - Listar todos os alunos cadastrados\n3 - Procurar aluno pela matricula\n4 - Listar aprovados\n0 - Para encerrar\n");
    scanf("%d", &op);

    switch(op){
      case 1:{
          cadastrar_aluno();
      }break;
      case 2:{
          listar_cadastrados();
      }break;

      case 3:{
          procurar_aluno();	
      }break;

      case 4:{
            listar_aprovados();
      }break;

      default:{
        printf("\n\nEscolha uma opcao valida!!");
      }break;
    }
  }while(op!=0);

  return 0;
}


//função para abrir o arquivo, ler os dados e armazenar no vetor global
void ler_alunos(int *qtde, aluno alunos[]){
  FILE *arq;
  int i=0;
  arq = fopen("arquivo-alunos.txt", "r");

  if(arq == NULL)
    printf("ERRO! Nao foi possivel abrir arquivo\n");
  else{

    while(fscanf(arq,"%d %d %d %d %s\n", &alunos[i].matricula, &alunos[i].notas[0], &alunos[i].notas[1], &alunos[i].notas[2], alunos[i].nome)!= EOF)
      i++;

    fclose(arq);
  }

  *qtde = i;
}


//função para salvar os dados de um aluno no fim do arquivo
void escrever_novo_aluno(aluno a){
  FILE *arq;
  arq = fopen("arquivo-alunos.txt", "a");
  fprintf(arq, "%d %d %d %d %s", a.matricula, a.notas[0],a.notas[1],a.notas[2],a.nome);
  fclose(arq);
}

void cadastrar_aluno(){
  aluno novo;

  getchar();			
  printf("\nInforme a matricula do aluno\n");
  scanf("%d", &novo.matricula);
  getchar();
  printf("\n\nInforme o nome do aluno\n");
  fgets(novo.nome,50, stdin);

  printf("\n\nInforme as tres notas do aluno\n");
  scanf("%d %d %d", &novo.notas[0],&novo.notas[1],&novo.notas[2]);

  escrever_novo_aluno(novo);
  printf("\nNovo aluno inserido no arquivo!\n");
}

void procurar_aluno(){
  int i;
  ler_alunos(&qtde, alunos);
  if(qtde == 0)
    printf("Nao ha alunos cadastrados!");
  else{		
    int mat;

    printf("\nInforme a matricula do aluno:\n");
    scanf("%d", &mat);
    int flag = 0;

    for(i=0; i<qtde; i++){
      if(mat == alunos[i].matricula){
        flag = 1;
        printf("Aluno encontrado!");
        printf("\nNome: %s", alunos[i].nome);
        printf("\nNotas: %d %d %d", alunos[i].notas[0],alunos[i].notas[1],alunos[i].notas[2]);
      }
    }

    if(flag == 0)
      printf("Aluno nao encontrado!");
    }
}