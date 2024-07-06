//ALUNOS: NÍCOLAS GABRIEL VIEIRA DO NASCIMENTO GOMES
// VÍTOR ANTÔNIO SILVESTRE SANTOS 

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(void) {
  turma t;
  inicializa_turma(&t);

  int opcao, opcao2;

do {
  printf("\nDigite a opção desejada: \n\n1 - Cadastrar aluno\n2 - Remover aluno\n3 - Listar alunos\n4 - Procurar aluno\n5 - Quantidade de alunos cadastrados\n0 - Para encerrar\n\n");
  scanf("%d", &opcao);

  switch (opcao) {
    case 1: {
      cadastrar_aluno(&t);
    } break;
    case 2:{
      remover_aluno(&t);
    }break;
    case 3:{
      printf("\nDigite a opção desejada: \n1 - Listar todos os alunos\n2 - Listar aprovados\n3 - Listar reprovados\n");
      scanf("%d", &opcao2);
        switch(opcao2){
          case 1:{
            listar_todos(&t);
          }break;
          case 2:{
            listar_aprovados(&t);
          }break;
          case 3:{
            listar_reprovados(&t);
          }break;
          default:{
            printf("Opção inválida");
          }break;
        }
        }break;
        case 4:{
          procurar_aluno(&t);
        }break;
        case 5:{
          quant_alunos(&t);
        }break;
        default:{
          if(opcao == 0){
            printf("Você encerou a sessão");

            FILE *arquivo;
                arquivo = fopen("relatorio.txt", "a");

                if (arquivo == NULL) {
                    printf("Erro ao abrir o arquivo.\n");
                    exit(EXIT_FAILURE);
                }
                fprintf(arquivo, "Sessão encerrada\n");

                fclose(arquivo);
            } else {
            printf("Opção inválida");
          }
        }break;
    }
} while (opcao != 0);

    free(t.alunos);

    return 0;
}