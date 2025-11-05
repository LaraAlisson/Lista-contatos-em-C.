#ifndef CONTATOS_H
    #define CONTATOS_H

    #include<stdlib.h.>
    #include<stdio.h>

    #define MAXIMO_CONTATOS 1000
    #define TAMANHO_NOME 50
    #define TAMANHO_TELEFONE 15
    #define TAMANHO_EMAIL 50


    typedef struct{
        char nome[TAMANHO_NOME];
        char telefone[TAMANHO_TELEFONE];
        char email[TAMANHO_EMAIL];

    }Contato;

    /*Função para exibir o menu do opções */
    void exibe_menu(void);

    /*Obter pelo teclado a opção do usuario*/
    int obter_opcao();

    /*Função para carregar os contaos do arquivo*/
    void ler_contatos_arquivo(Contato *contatos, int total_contatos);

    /*Função para gravar os contatos no arquivo*/
    void gravar_contatos_no_arquivo(Contato *lista_contato, int total_contato);

    /*Função para gravar os contatos no arquivo */
    void add_contato(Contato *lista_contato, int *total_contatos);

    /*Função para ordenar contatos após a adição ou remoção dos mesmo*/
    void ordenar_contato(Contato *lista_contato, int total_contatos);

    /*Função para listar todos os contatos e imprimir na tela*/
    void listar_contato(Contato *lista_contato, int total_contatos);

    /*Função para procuarar contato pelo nome*/
    void buscar_contato_nome(Contato *lista_contato, int total_contatos);

    /*Função para excluir contato pelo numero*/
    void excluir_contato_nome(Contato *lista_contato, int *total_contatos, char *telefone);




#endif /* End Contatos.h */