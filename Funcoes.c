#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cabecalho.h"


//tivemos que colocar essa função para limpar o buffer, pois não tava querendo ler as strings de jeito nenhum
void flush_in() { 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}


//criando um filme
Filme* criar_filme() {
    
    //alocando
    Filme * temp = malloc(sizeof(Filme));
    temp->info = malloc(sizeof(Info));

    //entrada dos dados
    printf("Nome: ");
    gets(temp->nome);
                
    printf("Preco: ");
    scanf("%f",&temp->preco);
    flush_in();
              
    printf("Diretor: ");
    gets(temp->info->diretor);
              
    printf("Ano: ");
    scanf("%d",&temp->info->ano);
    flush_in();
              
    printf("Genero: ");
    gets(temp->info->genero);
              
    printf("Faixa etaria: ");
    scanf("%d",&temp->info->faixaEtaria);
    printf("\n");

    return temp;

}


//exclui um filme e libera memória
void free_filme(Filme* f) {
    f->info = NULL;
    free(f->info);
    free(f);
}


//imprime o menu principal
void menu() {

    printf("\nMENU DE OPCOES\n\n");
    printf("1 - CADASTRAR UM NOVO TITULO\n");
    printf("2 - ATUALIZAR INFO DE UM TITULO\n");
    printf("3 - EXCLUIR UM TITULO\n");
    printf("4 - FINALIZAR OPERACAO\n\n");
    printf("Entre com sua opcao: ");

}


//impressão do menu se caso a opção atualizar info de um título seja escolhida
void submenu() {

    printf("\n");
    printf("1 - RENOMEAR TITULO\n");
    printf("2 - ATUALIZAR PRECO\n");
    printf("3 - ATUALIZAR GENERO\n\n");
    printf("Entre com sua opcao: ");

}


//imprime informações de um filme
void imprimir_filme(Filme* f){

    printf("%.2f R$ || ",f->preco);
    printf("%s ",f->nome);
    printf("(%s, %d) || ",f->info->genero, f->info->faixaEtaria);
    printf("%s %d\n", f->info->diretor, f->info->ano);

}


//imprime a tabela com todos os filmes
void print_tabela(Filme** tabela, int tam){

    printf("\n\n-------------TABELA DE FILMES-------------\n\n");

    for(int i = 0; i < tam; i++){
        printf("%.4d -- ",i+1); //código de 4 caracteres
        imprimir_filme(tabela[i]);
    }
    printf("\n\n");

}


//função que acessa e modifica o nome de um filme
void set_nome(Filme* f, char* novo){
    strcpy(f->nome, novo);
}


//função que acessa e modifica o preço de um filme
void set_preco(Filme* f, float novo){
    f->preco = novo;
}


//função que acessa e renomeia um diretor de um filme
void set_diretor(Filme* f, char* novo){
    strcpy(f->info->diretor, novo);
}


//função que acessa e renomeia os gêneros de um filme
void set_genero(Filme* f, char* novo){
    strcpy(f->info->genero, novo);
}


//função que acessa e modifica o ano de um filme
void set_ano(Filme* f, int novo) {
    f->info->ano = novo;
}


//função que acessa e modifica a faixa etária de um filme
void set_faixaetaria(Filme* f, int novo) {
    f->info->faixaEtaria = novo;
}





