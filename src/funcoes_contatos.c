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
void ler_contatos_arquivo(Contato *lista_contatos, int *total_contatos){


    FILE *fp;
    if((fp=fopen(NOME_ARQUIVO,"rb"))==NULL){
        printf("A lista de cotatos nao pode ser aberta!\n");
        return;
    }

    printf("INFO: Arquivo de contatos encontrado. Carregando dados...\n");

    /**/
    while(*total_contatos < MAXIMO_CONTATOS && fread(&lista_contatos[*total_contatos], sizeof(Contato), 1, fp)==1){
        (*total_contatos)++;
    }

    fclose(fp);
    printf("INFO: %d contatos carregados com sucesso para a memória!\n", *total_contatos);


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

/*Função para gravar os contatos no arquivo */
void adicionar_contato(Contato *lista_contato, int *total_contatos){

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