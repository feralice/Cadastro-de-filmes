//TAD -- Cabecalho.h//

typedef struct info {
    char diretor[101]; //101 caracteres + 1 para fim de string
    char genero[51]; //50 caracteres + 1 para fim de string
    int ano;
    int faixaEtaria; // Use 0 para classificação livre
} Info;


typedef struct filme{
    char nome[101]; //100 caracteres + 1 para fim de string
    float preco; // Até duas casas decimais
    Info* info; // Ponteiro para struct Info
} Filme;

//estrutura para um Filme
typedef struct filme Filme;

//Função que cria e retorna um ponteiro simples para o tipo Filme
Filme* criar_filme();

//Função que exclui um filme e libera memória
void free_filme(Filme* f);

//função que imprime informações de um filme
void imprimir_filme(Filme* f);

//função que imprime a tabela de filmes
void print_tabela(Filme** tabela, int tam);

//função para limpar o buffer para ler strings
void flush_in();

//função que imprime o menu inicial
void menu();

//função que imprime o menu se a pessoa escolher atualizar informações de um título
void submenu();


//FUNÇÕES DE MANIPULAÇÃO
//função que acessa e modifica o nome de um filme
void set_nome(Filme* f, char* novo);

//função que acessa e modifica o preço de um filme
void set_preco(Filme* f, float novo);

//função que acessa e renomeia um diretor de um filme
void set_diretor(Filme* f, char* novo);

//função que acessa e renomeia os gêneros de um filme
void set_genero(Filme* f, char* novo);

//função que acessa e modifica o ano de um filme
void set_ano(Filme* f, int novo);

//função que acessa e modifica a faixa etária de um filme
void set_faixaetaria(Filme* f, int novo);
