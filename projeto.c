#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct Veiculo{
  char proprietario[15];
  char combustivel[10];
  char modelo[10];
  char cor[10];
  int chassi;
  char placa[7];
  int ano;
  struct Veiculo *prox;
}Veiculo;

void limparBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

Veiculo* criarListavazia(){
  return NULL;
}

Veiculo* criarVeiculo(){
  Veiculo *novoVeiculo =(Veiculo*)malloc(sizeof(Veiculo));
  if(novoVeiculo == NULL){
    printf("\nNão foi possivel alocar memoria");
    exit(EXIT_FAILURE);
  }
  novoVeiculo->prox = NULL;
  return novoVeiculo;
}

Veiculo* verificarCombustivel(Veiculo *novo){
  char tipo1[] = "Diesel";
  char tipo2[] = "Gasolina";
  char tipo3[] = "Etanol";
  Veiculo *novoVeiculo = novo;
  fflush(stdin);
  printf("\nDigite o tipo de combustivel:");
  fflush(stdin);
  scanf("%s",novoVeiculo->combustivel);
  fflush(stdin);
  if(strcmp(novoVeiculo->combustivel, tipo1) != 0 && strcmp(novoVeiculo->combustivel, tipo2) != 0 && strcmp(novoVeiculo->combustivel, tipo3) != 0 ){
    printf("\ncombustivel invalido, tente novamente!");
    //free(novoVeiculo);
    return verificarCombustivel(novo);
  }else{
    return novoVeiculo;

  }
}

Veiculo* verificarPlaca(Veiculo *novo){
  Veiculo *novoVeiculo = novo;
  printf("\nDigite a placa do veiculo:");
  scanf("%s",novoVeiculo->placa);
  limparBuffer();
  if(strlen(novoVeiculo->placa) != 7){
    printf("placa invalida, tente novamente!");
    return verificarPlaca(novo);
  }

   for (int i = 0; i < 3; i++) {
        if (!isalpha(novoVeiculo->placa[i])) {
          printf("placa invalida, tente novamente!");
            return verificarPlaca(novo); 
        }
    }


    for (int i = 3; i < 7; i++) {
        if (!isdigit(novoVeiculo->placa[i])) {
          printf("placa invalida, tente novamente!");
            return verificarPlaca(novo); 
        }
    }



  return novoVeiculo;
}




Veiculo* inserirVeiculo(Veiculo *lista){
  Veiculo *novoVeiculo = criarVeiculo();
  limparBuffer();
  printf("\nDigite o nome do proprietario:");
  //limparBuffer();
  //fgets(novoVeiculo->proprietario, sizeof(novoVeiculo->proprietario), stdin);
  scanf("%s",novoVeiculo->proprietario);
  limparBuffer();
  verificarCombustivel(novoVeiculo);
  limparBuffer();
  printf("\nDigite o modelo do veiculo: ");
  fgets(novoVeiculo->modelo, sizeof(novoVeiculo->modelo), stdin);
  limparBuffer();
  printf("\nDigite a cor do veiculo: ");
  fgets(novoVeiculo->cor, sizeof(novoVeiculo->cor), stdin);
  limparBuffer();
  printf("\nDigite o chassi do veiculo: ");
  scanf("%d", &novoVeiculo->chassi);
  limparBuffer();
  verificarPlaca(novoVeiculo);
  limparBuffer();
  printf("\nDigite o ano do veiculo: ");
  scanf("%d", &novoVeiculo->ano);
  if(lista == NULL){
    lista = novoVeiculo;
  }else{
    Veiculo *atual = lista;
    while(atual->prox != NULL){
      atual = atual->prox;
    }
    atual->prox = novoVeiculo;
  }
  return lista;

}

void listarVeiculo(Veiculo *lista){
  Veiculo *atual = lista;
  if(atual == NULL){
    printf("\nLista vazia\n");
    return;
  }else{
    while(atual != NULL){
      printf("\nProprietario: %s", atual->proprietario);
      printf("\nCombustivel: %s", atual->combustivel);
      printf("\nModelo: %s", atual->modelo);
      printf("\nCor: %s", atual->cor);
      printf("\nChassi: %d", atual->chassi);
      printf("\nPlaca: %s", atual->placa);
      printf("\nAno: %d", atual->ano);
      printf("\n");
      atual = atual->prox;
    }
  }

}

void listar2010Diesel(Veiculo *lista ){
  Veiculo *atual = lista;
  int verificacao= 0;
  if(atual == NULL){
    printf("\nLista vazia\n");
    return;
  }else{
    while(atual !=NULL){
    
      if(atual->ano >=2010 && (strcmp(atual->combustivel,"Diesel") ==0)){
        printf("\nProprietario: %s", atual->proprietario);
          printf("\nCombustivel: %s", atual->combustivel);
          printf("\nModelo: %s", atual->modelo);
          printf("\nCor: %s", atual->cor);
          printf("\nChassi: %d", atual->chassi);
          printf("\nPlaca: %s", atual->placa);
          printf("\nAno: %d", atual->ano);
          printf("\n");
          verificacao++;
      }
      atual = atual->prox;

    }

  }

  if(verificacao ==0){
    printf("\nNão foi encontrado!");
  }

}

void listarPlacaJ(Veiculo *lista ){
  Veiculo *atual = lista;
  int verificacao= 0;
  if(atual == NULL){
    printf("\nLista vazia\n");
    return;
  }else{
    while(atual !=NULL){

      char primeiraLetra = tolower(atual->placa[0]);
      //for(int i = 0; i < 7; i++){
        if(atual->placa[0] == 'J' && (atual->placa[6] == '0' || atual->placa[6] == '2' || atual->placa[6] == '4' ||atual->placa[6] == '7')){
        printf("\nProprietario: %s", atual->proprietario);
          printf("\nCombustivel: %s", atual->combustivel);
          printf("\nModelo: %s", atual->modelo);
          printf("\nCor: %s", atual->cor);
          printf("\nChassi: %d", atual->chassi);
          printf("\nPlaca: %s", atual->placa);
          printf("\nAno: %d", atual->ano);
          printf("\n");
          verificacao++;
        }
      //}
      atual = atual->prox;
      return;

    }

  }

  if(verificacao ==0){
    printf("\nNão foi encontrado!");
  }

}

void listarVogal(Veiculo *lista ){
  Veiculo *atual = lista;
  int verificacao= 0;
  if(atual == NULL){
    printf("\nLista vazia\n");
    return;
  }else{
    while(atual !=NULL){
      if((atual->placa[1] == 'A' || atual->placa[1] == 'E' || atual->placa[1] == 'I' || atual->placa[1] == 'O' || atual->placa[1] == 'U') && (atual->placa[3] + atual->placa[4] + atual->placa[5] + atual->placa[6]) %2 == 0){
        printf("\nModelo: %s", atual->modelo);
        printf("\nCor: %s", atual->cor);
        verificacao++;
      }
      atual = atual->prox;
    }
  }

  if(verificacao ==0){
    printf("\nNão foi encontrado!\n");
  
  }
  
}

Veiculo* alterarProprietario(Veiculo *lista){
  Veiculo *novoProprietario = lista;
  int chassi;
  printf("\nDigite o chassi do veiculo: ");
  scanf("%d", &chassi);
  limparBuffer();
  while(novoProprietario != NULL){
    if(novoProprietario->chassi == chassi && novoProprietario->placa[3] != 0 && novoProprietario->placa[4] != 0 && novoProprietario->placa[5] != 0 && novoProprietario->placa[6] != 0 ){
      printf("\nDigite o novo proprietario: ");
      scanf("%s", novoProprietario->proprietario);
      limparBuffer();
      printf("\nProprietario alterado com sucesso!\n");
      return lista;
    
    }else{
      printf("\nNão é possivel trocar de proprietario!\n");
      return lista;
    }
  }
  printf("\nVeiculo não encontrado!");
  return lista;

}


int main() {
  Veiculo *lista = criarListavazia();

  int opcao;
  do{
    printf("1 - Inserir veiculo\n");
    printf("2 - Listar veiculos\n");
    printf("3 - listar 2010 diesel veiculos\n");
    printf("4 - listar placas que começa com a letra j e termine com o numero 0 ou 2 ou 4 ou 7\n");
    printf("5 - listar placas que a segunda letra é vogal e a soma dos numeros é par\n");
    printf("6 - Alterar Proprietario pelo numero de chassi\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch(opcao){
      case 1:
        lista = inserirVeiculo(lista);
      break;
      case 2:
         listarVeiculo(lista);
      break;
      case 3:
         listar2010Diesel(lista);
      break;
      case 4:
        listarPlacaJ(lista);
      break;
      case 5:
        listarVogal(lista);
      break;
      case 6:
        alterarProprietario(lista);
      break;
      case 0:
      break;
      default:
      printf("\nOpcao invalida\n");
    }

  }while(opcao !=0);

  free(lista);
}
