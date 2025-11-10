#include "../include/contatos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Função para exibir o menu do opções */
void exibe_menu(void){
/*codigo exibe menu de funções para usuarios.*/
    printf("+---------------------------------------+\n");
    printf("|          MENU DE CONTATOS             |\n");
    printf("+---------------------------------------+\n");
    printf("| 1. Adicionar Novo Contato             |\n");
    printf("| 2. Listar Todos os Contatos           |\n");
    printf("| 3. Pesquisar Contato por Nome         |\n");
    printf("| 4. Excluir Contato                    |\n");
    printf("| 0. Sair                               |\n");
    printf("+---------------------------------------+\n");
   

}

int obter_opcao(){

     printf("Escolha uma opcao:\n ->  ");
    int opcao = 0;

    if(scanf("%d",&opcao) != 1){

        printf("ERRO: Entrada invalida. Por favor, digite um numero.\n");
    
        // Limpeza de buffer em caso de entrada válida mas fora do range (ex: "50\n")
        limpar_buffer();
            
        
        return obter_opcao();
    }

    if(opcao < 0 || opcao > 4){
        printf("ERRO: Opcao fora do intervalo permitido (1 a 4).\n");

        limpar_buffer();

        return obter_opcao();
    }

    return opcao;
};

/*Função para carregar os contaos do arquivo*/
void ler_contatos_arquivo(Contato *lista_contatos, int *total_contatos){


    FILE *fp;
    if((fp=fopen(NOME_ARQUIVO,"rb"))==NULL){
        printf("A lista de cotatos nao pode ser aberta!\n");
        return;
    }

    printf("INFO: Arquivo de contatos encontrado. Carregando dados...\n");

    /*função pra ler um contato por vez e carregar no array lista_contatos*/
    while(*total_contatos < MAXIMO_CONTATOS && fread(&lista_contatos[*total_contatos], sizeof(Contato), 1, fp)==1){
        (*total_contatos)++;
    }

    fclose(fp);
    printf("INFO: %d contatos carregados com sucesso para a memoria!\n", *total_contatos);


}/*end ler arquivo_contatos*/


/*Função para gravar os contatos no arquivo*/
void gravar_contatos_no_arquivo(Contato *lista_contato, int total_contatos){

    FILE *fp;

    if((fp = fopen(NOME_ARQUIVO,"wb")) == NULL){
        printf("A lista de cotatos nao pode ser aberta!\n");
        return;
    }

    size_t contatos_gravados = fwrite(lista_contato,sizeof(Contato),total_contatos,fp);

    if(contatos_gravados != total_contatos ){
        printf("Foram gravados %d contatos de um total de %d :",contatos_gravados, total_contatos);
    }else{
        printf("Contatos gravados com Sucesso !!!");
    }
    fclose(fp);

}

/*Função para adicionar  os contatos  */
void adicionar_contato(Contato *lista_contato, int *total_contatos){

    /*Verificação de Capacidade*/ 
    if (*total_contatos >= MAXIMO_CONTATOS) {
        printf("ERRO: O limite maximo de %d contatos foi atingido. Nao eh possivel adicionar mais.\n", MAXIMO_CONTATOS);
        return; 
    }


    /*Ponteiro para a proxima posição da lsita de contato livre*/
    Contato *novo_contato = &lista_contato[*total_contatos];
    char buffer_entrada[TAMANHO_NOME];
    
    printf("+---------------------------------------+\n");
    printf("|          ADICIONAR CONTATOS           |\n");
    printf("+---------------------------------------+\n");

    limpar_buffer();

    /*Adiciona o nome a Estrutura*/
    printf("Nome:\n -> "); 
    if(fgets(buffer_entrada,TAMANHO_NOME,stdin)==NULL){
        printf("ERRO: Falha ao ler o nome.\n");
        return;
    }

    size_t len = strlen(buffer_entrada);

    /*Sunstitui o \n por \0*/
    if(len > 0 && buffer_entrada[len-1] == '\n'){
        buffer_entrada[len-1]='\0';
    }

    if (strlen(buffer_entrada) == 0) {
        printf("ERROR: Campo nome eh obrigatorio\n\n"); 
        return;
    }

    strcpy(novo_contato->nome,buffer_entrada);

    /*Adiciona o telefone a Estrutura*/
    printf("Telefone:\n -> ");
    if(fgets(buffer_entrada,TAMANHO_TELEFONE,stdin)==NULL){
        printf("ERRO: Falha ao ler o telefone.\n");
        return;
    }

    len = strlen(buffer_entrada);

    /*Sunstitui o \n por \0*/
    if(len > 0 && buffer_entrada[len-1] == '\n'){
        buffer_entrada[len-1]='\0';
    }

    strcpy(novo_contato->telefone,buffer_entrada);

    /*Adiciona o e-mail a Estrutura*/
    printf("E-mail:\n -> ");
    if(fgets(buffer_entrada,TAMANHO_EMAIL,stdin)==NULL){
        printf("ERRO: Falha ao ler o telefone.\n");
        return;
    }

    len = strlen(buffer_entrada);

    /*Sunstitui o \n por \0*/
    if(len > 0 && buffer_entrada[len-1] == '\n'){
        buffer_entrada[len-1]='\0';
    }

    strcpy(novo_contato->email,buffer_entrada);


    (*total_contatos)++;

}
    


void ordenar_contato(Contato *lista_contato, int total_contatos){
    /*codigo para exibir contos com conforme o nome solicitado*/
}


/*Lista todos os contatos*/
void listar_contato(Contato *lista_contato, int total_contatos){
    printf("+---------------------------------------+\n");
    printf("|          LISTA CONTATOS               |\n");
    printf("+---------------------------------------+\n");

    for(int i = 0; i < total_contatos; i++){
        printf("\nNome: %s\n", lista_contato[i].nome);
        printf("Telefone: %s\n", lista_contato[i].telefone);
        printf("Email: %s\n", lista_contato[i].email);

        
    }
}

/*Função para procuarar contato pelo nome*/
void buscar_contato_nome(Contato *lista_contato, int total_contatos){

    char buffer_entrada[TAMANHO_NOME];

    printf("+---------------------------------------+\n");
    printf("|          PESQUISAR CONTATOS           |\n");
    printf("+---------------------------------------+\n");
    printf("Nome:\n -> ");
    limpar_buffer();

    fgets(buffer_entrada,TAMANHO_NOME,stdin);

    size_t len = strlen(buffer_entrada);
    if(len > 0 && buffer_entrada[len-1]=='\n'){
        buffer_entrada[len-1] = '\0';
    }

    for(int i = 0; i < total_contatos; i++){
        if(strcmp(buffer_entrada,lista_contato[i].nome) == 0){
            printf("\nNome : %s\n",lista_contato[i].nome);
            printf("Telefone : %s\n",lista_contato[i].telefone);
            printf("E-mail : %s\n",lista_contato[i].email);
            
        }

    }
    
}

/*Função para excluir contato pelo numero*/
void excluir_contato_nome(Contato *lista_contato, int *total_contatos){
    
    char buffer_entrada[TAMANHO_NOME];
    int opcao = 0;

    printf("+---------------------------------------+\n");
    printf("|          EXLUIR CONTATOS              |\n");
    printf("+---------------------------------------+\n");
    printf("Nome:\n -> ");

    limpar_buffer();
    fgets(buffer_entrada,TAMANHO_NOME,stdin);

    size_t len = strlen(buffer_entrada);

    if(len > 0 && (buffer_entrada[len-1]=='\n')){
        buffer_entrada[len-1] = '\0';
    }

    
    for(int i = 0; i < *total_contatos; i++){
        if(strcmp(buffer_entrada,lista_contato[i].nome) == 0){
            printf("\nid: %d \n",i);
            printf("Nome: %s\n",lista_contato[i].nome);
            printf("Telefone: %s\n",lista_contato[i].telefone);
            printf("Email: %s\n",lista_contato[i].email);
           
        }
        
    }

    printf("\nDigite o Id do contato que deseja excluir ou \"S\" para Sair\n->");
 
    if(scanf("%d",&opcao) != 1){
        printf("Operacao Cancelada!!!\n");
        limpar_buffer();
        return;
    }

    for( opcao ; opcao < *total_contatos - 1; opcao++){

        lista_contato[opcao] = lista_contato[opcao+1];

    }

    printf("Contato Excluido com sucesso !\n");
    


    (*total_contatos)--;
    
    limpar_buffer();
     
}

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Apenas consome o caractere, não faz nada com ele
    }
}