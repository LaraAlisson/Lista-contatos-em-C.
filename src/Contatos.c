/*
    Projeto baseado ao estudo do livro C completo e total...
    autor Alisson Lara
    .....

*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "../include/contatos.h"


int main(){

    Contato list_contato[MAXIMO_CONTATOS];
    int total_contato = 0;
    int opcao_menu = 0;
    char telefone[15];

    /*Ao inicializar carrega os dados do arquivo na memoria*/
    ler_contatos_arquivo(list_contato, &total_contato);
    

    do{
        exibe_menu();

        opcao_menu = obter_opcao();

        switch (opcao_menu){
            case 1:
                adicionar_contato(list_contato, &total_contato);
                ordenar_contato(list_contato, total_contato);
                break;
            case 2:
                listar_contato(list_contato, total_contato);
                break;
            case 3:
                buscar_contato_nome(list_contato, total_contato);
                break;
            case 4:
                excluir_contato_nome(list_contato, &total_contato);
                break;
            case 0:
                gravar_contatos_no_arquivo(list_contato, total_contato);
                break;


        }

    }while(opcao_menu != 0);

   


    return 0;
}


