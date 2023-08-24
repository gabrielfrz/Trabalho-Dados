#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void opcaoa(FILE **arquivo, int *fim){
  char nome[60];
  char genero[15];
  int idade;
  char resp1[4];
  char resp2[4];
  char resp3[4];
  char resp4[4];

  *arquivo = fopen("arquivo.txt", "a");       // Criação do arquivo no modo de escrita no final do texto
  if(*arquivo == NULL){             // Verificação de abertura do arquivo
    printf("Erro ao abrir arquivo\n");
  }
  else{
    // Programa faz as perguntas, armazena em variáveis que serão gravadas no arquivo
    printf("Insira seu nome:\n");
    scanf(" %[^\n]", nome);
    fprintf(*arquivo, "Nome: %s\n", nome);
    
    printf("Insira sua idade:\n");
    scanf("%d", &idade);
    fprintf(*arquivo, "Idade: %d\n", idade);
    
    printf("Insira seu gênero (masculino, feminino ou outro):\n");
    scanf(" %s", genero);
    fprintf(*arquivo, "Gênero: %s\n" ,genero);
    
    printf("Você já testemunhou algum ato de corrupção em sua comunidade?\n");
    scanf(" %s", resp1);
    fprintf(*arquivo, "Já testemunhou atos de corrupção? - %s\n", resp1);
    
    printf("Você já sofreu exclusão ou discriminação devido à sua condição socioeconômica?\n");
    scanf(" %s", resp2);
    fprintf(*arquivo, "Já sofreu exclusão ou discriminação devido à sua condição socioeconômica? - %s\n", resp2);
    
    printf("Você já enfrentou discriminação por conta da religião ou crenças pessoais?\n");
    scanf(" %s", resp3);
    fprintf(*arquivo, "Já enfrentou discriminação por conta da religião ou crenças pessoais? - %s\n", resp3);
    
    printf("Você já teve seus direitos de liberdade de expressão cerceados em um contexto político ou social?\n");
    scanf(" %s", resp4);
    fprintf(*arquivo, "Teve seus direitos de liberdade de expressão cerceados em um contexto político ou social? - %s\n", resp4);
    
    fprintf(*arquivo, "\n\n\n");
    fclose(*arquivo);  // Encerra operações no arquivo
  }
}

void opcaob(FILE **arquivo){
  printf("Dados dos entrevistados:\n\n");
  *arquivo = fopen("arquivo.txt", "r");
  if(*arquivo == NULL){
    printf("Erro ao abrir arquivo\n");
  }
  else{
    char car;
    while((car = fgetc(*arquivo)) != EOF){ // Lê caractere do arquivo enquanto não for nulo
      putchar(car); // Imprime no console
    }
  }
  fclose(*arquivo);
}

void opcaoc(FILE **arquivo){
  *arquivo = fopen("arquivo.txt", "r");
  if(*arquivo == NULL){
    printf("Erro ao abrir arquivo\n");
  }
  else{
    char nome[30];
    printf("Digite o nome da pessoa que deseja buscar:\n");
    scanf(" %[^\n]", nome); // Entrada do nome, podendo ser nome composto
    char palavra[100];
    int encontrou = 0;
    while(fgets(palavra, sizeof(palavra), *arquivo) != NULL){ // Percorre o arquivo
      if(strstr(palavra, nome) != NULL){ // Verifica se há a string nome dentro das strings do arquivo
        encontrou = 1; // Variável para facilitar o controle da busca
        char car[100]; // Linhas abaixo do nome
        for(int i = 0; i <= 6; i++){ 
          if(fgets(palavra, sizeof(palavra), *arquivo) != NULL){
            printf("%s", palavra); // Imprime as 6 linhas abaixo do nome
          }
        }
        break;
      }
    }
    if(encontrou == 0){ // Caso a palavra não tenha sido encontrada
      printf("Nome não encontrado\n");
    }
  }
  fclose(*arquivo);
}

void opcaod(FILE **arquivo){
  *arquivo = fopen("arquivo.txt", "r");
  if(*arquivo == NULL){
    printf("Erro ao abrir arquivo\n");
  }
  else{
    char palavra[100];
    int total = 0;
    int corrupcao = 0, socioeconomico = 0, religiao = 0, liberdade = 0;
    while(fscanf(*arquivo, "%s", palavra) == 1){ 
      if(strcmp(palavra, "sim") == 0 || strcmp(palavra, "Sim") == 0){
        total++; 
      }
    }
  
    *arquivo = fopen("arquivo.txt", "r");
    while(fgets(palavra, sizeof(palavra), *arquivo) != NULL){
      if(strstr(palavra, "testemunhou") != NULL && (strstr(palavra, "sim") != NULL || strstr(palavra, "Sim") != NULL)){
        corrupcao++;
      }
    }
    *arquivo = fopen("arquivo.txt", "r");
    while(fgets(palavra, sizeof(palavra), *arquivo) != NULL){
      if(strstr(palavra, "devido") != NULL && (strstr(palavra, "sim") != NULL || strstr(palavra, "Sim") != NULL)){
        socioeconomico++;
      }
    }
    *arquivo = fopen("arquivo.txt", "r");
    while(fgets(palavra, sizeof(palavra), *arquivo) != NULL){
      if(strstr(palavra, "conta") != NULL && (strstr(palavra, "sim") != NULL || strstr(palavra, "Sim") != NULL)){
        religiao++;
      }
    }
    *arquivo = fopen("arquivo.txt", "r");
    while(fgets(palavra, sizeof(palavra), *arquivo) != NULL){
      if(strstr(palavra, "contexto") != NULL && (strstr(palavra, "sim") != NULL || strstr(palavra, "Sim") != NULL)){
        liberdade++;
      }
    }
    
    int masculino = 0, feminino = 0, outro = 0;
    *arquivo = fopen("arquivo.txt", "r");
    while(fgets(palavra, sizeof(palavra), *arquivo) != NULL){ 
      if(strstr(palavra, "masculino") != NULL || strstr(palavra, "Masculino") != NULL){ 
        for(int i = 0; i <= 6; i++){ 
          if(fgets(palavra, sizeof(palavra), *arquivo) != NULL){
            if(strstr(palavra, "sim") != NULL || strstr(palavra, "Sim") != NULL){
              masculino++; // Recebe como resposta sim/Sim, a variável contabiliza uma unidade nas estatísticas
            }
          }
        }
      }
      else if(strstr(palavra, "feminino") != NULL || strstr(palavra, "Feminino") != NULL){ 
        for(int i = 0; i <= 6; i++){ 
          if(fgets(palavra, sizeof(palavra), *arquivo) != NULL){
            if(strstr(palavra, "sim") != NULL || strstr(palavra, "Sim") != NULL){
              feminino++; 
            }
          }
        }
      }
      else if(strstr(palavra, "outro") != NULL || strstr(palavra, "Outro") != NULL){ 
        for(int i = 0; i <= 6; i++){ 
          if(fgets(palavra, sizeof(palavra), *arquivo) != NULL){
            if(strstr(palavra, "sim") != NULL || strstr(palavra, "Sim") != NULL){
              outro++; 
            }
          }
        }
      }
    }
    
    // Contabilizar de acordo com a idade
    int idade = 0;
    int totalma = 0, totalme = 0;
    *arquivo = fopen("arquivo.txt", "r");
    while(fgets(palavra, sizeof(palavra), *arquivo) != NULL){
      if(strstr(palavra, "Idade") != NULL){
        sscanf(palavra, "Idade: %d", &idade); // Valores lidos na string
        if(idade >= 18){
          for(int i = 0; i <= 6; i++){ 
            if(fgets(palavra, sizeof(palavra), *arquivo) != NULL){
              if(strstr(palavra, "sim") != NULL || strstr(palavra, "Sim") != NULL){
                totalma++; // A cada sim/Sim, a variável contabiliza uma unidade
              }
            }
          }
        }
        else if(idade < 18){
          for(int i = 0; i <= 6; i++){ 
            if(fgets(palavra, sizeof(palavra), *arquivo) != NULL){
              if(strstr(palavra, "sim") != NULL || strstr(palavra, "Sim") != NULL){
                totalme++; // A cada sim/Sim, a variável contabiliza uma unidade
              }
            }
          }
        }
      }
    }
    
    printf("\nTotal de infrações: %d\n", total);
    
    printf("Atos de corrupção: %d\n", corrupcao);
    
    printf("Discriminações devido à condição socioeconômica: %d\n", socioeconomico);
    
    printf("Discriminações por conta de crenças pessoais: %d\n", religiao);
    
    printf("Direito de liberdade de expressão restringido: %d\n", liberdade);
    
    printf("Total de infrações para homens: %d\n", masculino);
    
    printf("Total de infrações para mulheres: %d\n", feminino);
    
    printf("Total de infrações para outros gêneros: %d\n", outro);
    
    printf("Total de infrações para maiores de 18 anos: %d\n", totalma);
    
    printf("Total de infrações para menores de 18 anos: %d\n", totalme);
  }
  fclose(*arquivo);
}

  


int opcaoe(int fim, FILE **arquivo){
  fim = 1;
  printf("Fim\n");
  fopen("arquivo.txt", "w"); //abertura de um arquivo no modo w permite a escrita apos limpar o arquivo
  if(*arquivo != NULL)
    fclose(*arquivo);      //fechar o arquivo após a limpa
  return fim;
}
