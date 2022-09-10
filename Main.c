#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cabecalho.h"


int main(void) {

    //Variaveis
    int tamanho, opcao2, opcao, posicao;
    char *verificaGeneroTerror, *verificaGeneroTerror2;
    char nome[101], diretor[101], genero[101];
    float preco;
    int p = 0;

    //Entrada do tamanho desejado
    printf("Entre com o tamanho que deseja: ");
    scanf("%d",&tamanho);
    flush_in();

    //caso o tamanho entrado não for maior que 0
    if(tamanho <= 0) {
        printf("\nO tamanho precisa ser um valor positivo!\n");
        printf("Digite outro tamanho: ");
        scanf("%d",&tamanho);
        flush_in();
    }

    //alocação
    Filme **filmes = malloc(tamanho * sizeof(Filme*));

    //cadastrando os filmes
    while(p < tamanho) {

        printf("\nCadastro do filme %d\n",p+1);
        
        filmes[p] = criar_filme();
        flush_in();

        //Variáveis para verificar se tem terror no genero
        verificaGeneroTerror = strstr(filmes[p]->info->genero,"Terror");
        verificaGeneroTerror2 = strstr(filmes[p]->info->genero,"terror");
                
        //se entrar no if é pq o genero é terror 
        if(verificaGeneroTerror!=0 || verificaGeneroTerror2!=0)  {

            //verificando a idade
            if(filmes[p]->info->faixaEtaria < 18) {

                printf("Filmes do genero terror nao podem ter faixa etaria abaixo de 18, entre com um novo valor\n\n");
                filmes[p] = criar_filme();
                
            }  
        }

        p++;

    }
    
    print_tabela(filmes, tamanho);
    menu();
    scanf("%d",&opcao);

    if(opcao==4) {
        printf("\nPrograma finalizado!");
    }
    
    flush_in();

    
    //parte do menu
    while(opcao!=4) {

        switch(opcao) {

            //Cadastrar novo filme
            case 1:
            
                tamanho++;

                //realocando para poder cadastrar um novo filme
                filmes = realloc(filmes, tamanho * (sizeof(Filme*)));

                filmes[p] = criar_filme();

                //Variáveis para verificar se tem terror no genero
                verificaGeneroTerror = strstr(filmes[p]->info->genero,"Terror");
                verificaGeneroTerror2 = strstr(filmes[p]->info->genero,"terror");
                
                //se entrar no if é pq o genero é terror
                if(verificaGeneroTerror!=0 || verificaGeneroTerror2!=0)  {

                    //Verificando a idade
                    if(filmes[p]->info->faixaEtaria < 18) {
                        printf("Filmes do genero Terror nao podem ter faixa etaria abaixo de 18, entre com um novo valor\n\n");
                        flush_in();
                        filmes[p] = criar_filme();
                        
                    } 

                } 
                
                p++;
                
                break;


            //Atualizar informações de títulos
            case 2:
                
                submenu();
                scanf("%d",&opcao2);
                flush_in();

                //Para renomear título
                if(opcao2==1) {

                    printf("Entre com o codigo do filme (ignore os zeros): ");
                    scanf("%d",&posicao);
                    flush_in();

                    while(posicao>tamanho || posicao<1) {
                        printf("\nposicao invalida!\n");
                        printf("Entre com o codigo do filme (ignore os zeros): ");
                        scanf("%d",&posicao);
                        flush_in();
                    }

                    printf("Entre com o novo nome do filme: ");
                    gets(nome);

                    printf("Entre com o novo nome do diretor: ");
                    gets(diretor);
                    
                    posicao = posicao-1;
                    set_nome(filmes[posicao],nome);
                    set_diretor(filmes[posicao], diretor);
                    printf("\n");


                    
                //Para atualizar preço de um título
                } else if(opcao2==2) {

                    printf("Entre com o codigo do filme (ignore os zeros): ");
                    scanf("%d",&posicao);
                    flush_in();

                    //Verificando se o código do filme é válido
                    while(posicao>tamanho || posicao<1) {
                        printf("\nposicao invalida!\n");
                        printf("Entre com o codigo do filme (ignore os zeros): ");
                        scanf("%d",&posicao);
                        flush_in();
                    }

                    printf("Entre com o novo preco: ");
                    scanf("%f",&preco);
                    flush_in();

                    posicao = posicao - 1;
                    set_preco(filmes[posicao],preco);
                    printf("\n");


                //Para atualizar o genero
                } else if(opcao2==3) {

                    printf("Entre com o codigo do filme (ignore os zeros): ");
                    scanf("%d",&posicao);
                    flush_in();

                    //Verificando se o código do filme é válido
                    while(posicao>tamanho || posicao<1) {
                        printf("\nposicao invalida!\n");
                        printf("Entre com o codigo do filme (ignore os zeros): ");
                        scanf("%d",&posicao);
                        flush_in();
                    }

                    printf("Entre com o novo genero: ");
                    gets(genero);

                    posicao=posicao-1;
                    set_genero(filmes[posicao], genero);
                    printf("\n");

                }

                break;


            //Para excluir um título
            case 3:

                printf("Entre com o codigo do filme (ignore os zeros): ");

                scanf("%d",&posicao);

                //Verificando se o código do filme é válido
                while(posicao>tamanho || posicao<1) {
                    printf("\nposicao invalida!\n");
                    printf("Entre com o codigo do filme (ignore os zeros): ");
                    scanf("%d",&posicao);
                    flush_in();
                }

                posicao = posicao-1;

                //Para excluir o filme
                free_filme(filmes[posicao]);

                //Iteração para substituir elemento do vetor pelo seu posterior
                for(int k=posicao+1 ; k <= tamanho-1; k++){
                    filmes[k-1] = filmes[k];
                }

                //Realocação do vetor
                filmes = realloc(filmes,(tamanho-1));
                tamanho--;
                p--;
                 
            break;
                    
                                           
            }

                //Verificando se a tabela é vazia
                if(tamanho==0) {
                    printf("\nA tabela esta vazia!\n");
                } else {
                    print_tabela(filmes, tamanho);  
                }

                //Impressão do menu 
                menu();
                    
                scanf("%d",&opcao);
                flush_in(); 
        
                if(opcao==4) {
                    printf("\n\nPrograma finalizado");
                }
           
                printf("\n");
           
        
        
    }
    return 0;
}
