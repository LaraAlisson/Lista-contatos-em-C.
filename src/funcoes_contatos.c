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
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
            
        
        return obter_opcao();
    }

    if(opcao < 0 || opcao > 4){
        printf("ERRO: Opcao fora do intervalo permitido (1 a 4).\n");

        int c;

        while ((c = getchar()) != '\n' && c != EOF);

        return obter_opcao();
    }

    return opcao;
};

/*Função para carregar os contaos do arquivo*/
void ler_contatos_arquivo(Contato *contatos, int total_contatos){
    /*codigo da função para carregar os contatos do arquvivo caso eles existam
    caso não exista o arquivo cria o mesmo e deixa preparado para a 
    */

}
/*Função para gravar os contatos no arquivo*/
void gravar_contatos_no_arquivo(Contato *lista_contato, int total_contato){
    printf("Contatos gravados");
}

/*Função para gravar os contatos no arquivo */
void add_contato(Contato *lista_contato, int *total_contatos){
     /* CODIGO GRAVAR NO ARQUIVO*/
    
}

void ordenar_contato(Contato *lista_contato, int total_contatos){
    /*codigo para exibir contos com conforme o nome solicitado*/
}

void listar_contato(Contato *lista_contato, int total_contatos){
    /*codigo para listar o contato*/
}

/*Função para procuarar contato pelo nome*/
void buscar_contato_nome(Contato *lista_contato, int total_contatos){
    /*codigo buscar contato por nome*/
}

/*Função para excluir contato pelo numero*/
void excluir_contato_nome(Contato *lista_contato, int *total_contatos, char *telefone){
    /*excluir contato pelo numero de telefone e nome pelo fato de nomes poderem ser repetido*/
}