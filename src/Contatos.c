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

    exibe_menu();
    opcao_menu = obter_opcao();
    printf("Minha Opcao foi:  %d ",opcao_menu);




    return 0;
}


