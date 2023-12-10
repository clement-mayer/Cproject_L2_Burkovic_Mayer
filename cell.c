//
// Created by burko on 13/11/2023.
//
#include <stdlib.h>
#include <stdio.h>
#include "cell.h"



t_d_list_node* NewCellNode(int value, int nb_niveaux) {
    t_d_list_node* newNode = (t_d_list_node *)malloc(sizeof(t_d_list_node));
    newNode->cell.value = value;
    newNode->cell.nb_niveaux = nb_niveaux;
    newNode->next = NULL;
    return newNode;
}


