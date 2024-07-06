
#ifndef funcoes_h
#define funcoes_h
#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int matricula;
    float notas[7];
    char nome[50];
    int codTurma;
    int faltas[7];
} aluno;

typedef struct {
    aluno *alunos;
    int qtdAlunos;
    int id;
} turma;

void inicializa_turma(turma *t);
void cadastrar_aluno(turma *t);
void remover_aluno(turma *t);
void listar_todos(turma *t);
void listar_aprovados(turma *t);
void listar_reprovados(turma *t);
void procurar_aluno(turma *t);
void quant_alunos(turma *t);

#define MAX 10
#endif