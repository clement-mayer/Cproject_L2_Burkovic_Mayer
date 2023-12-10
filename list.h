//
// Created by burko on 13/11/2023.
//

#ifndef UNTITLED4_LIST_H
#define UNTITLED4_LIST_H

#endif //UNTITLED4_LIST_H
#include "cell.h"

typedef struct s_d_list {
    t_d_cell* head;
    int niveau;
} t_d_list;


void createlist(t_d_list * listsd,int niveau);

void inserer_head(t_d_list *listsd, t_d_list_node* node);

void afficher_niveau(t_d_list *listsd, int niveau);

void inserer_trie(t_d_list* listsd, t_d_list_node* node);

int searchInDList(t_d_list* listsd, int key, int iter_lvl0);

int searchInDListUp(t_d_list* listsd, int n_max, int key, int iter_all_levels);

void timelist();
