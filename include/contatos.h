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
    void read_contatos(void);

    /*Função para gravar os contatos no arquivo */
    void white_contatos(void);

    /*Função para exibir contato pelo nome buscado*/
    void exibe_contato(Contato nome);


#endif /* End Contatos.h */