//
// Created by burko on 13/11/2023.
//
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "timer.h"
#include "list.h"

void createlist(t_d_list* listsd, int niveau) {
    listsd->head = NULL;
    listsd->niveau = niveau;
}

void inserer_head(t_d_list* listsd, t_d_list_node* node) {
    t_d_list_node* newNode = (t_d_list_node*)malloc(sizeof(t_d_list_node));
    newNode->cell = node->cell;
    newNode->next = listsd->head;
    listsd->head = newNode;
}

void afficher_niveau(t_d_list* listsd, int niveau_demande) {
    t_d_list_node* current = listsd->head;
    printf("[ liste head%d @-]-->", niveau_demande-1);
    while (current != NULL)
    {
        if (current->cell.nb_niveaux >= niveau_demande)
        {
            printf("[ %d|@-]-->", current->cell.value);
        }
        else
        {
            if (current->cell.value/10 >= 1)
            {
                printf("-");
            }
            if (current->cell.value/100 >= 1)
            {
                printf("-");
            }
            if (current->cell.value/1000 >= 1)
            {
                printf("-");
            }
            printf("----------");
        }
        current = current->next;
    }
    printf("NULL\n");
}

void inserer_trie(t_d_list* listsd, t_d_list_node* node) {
    t_d_list_node* newNode = (t_d_list_node*)malloc(sizeof(t_d_list_node));
    newNode->cell = node->cell;
    if (listsd->head == NULL || newNode->cell.value < listsd->head->value) {
        newNode->next = listsd->head;
        listsd->head = newNode;
    } else {
        t_d_list_node* current = listsd->head;
        while (current->next != NULL && current->next->cell.value < newNode->cell.value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Fonction pour rechercher un élément dans la liste chaînée
int searchInDList(t_d_list* listsd, int key, int iter_lvl0) {
    t_d_list_node* current = listsd->head;
    while (current != NULL) {
        iter_lvl0++;
        if (current->cell.value == key) {
            return iter_lvl0;
        }
        current = current->next;
    }
    return iter_lvl0;
}

int searchInDListUp(t_d_list* listsd, int n_max, int key, int iter_all_levels) {
    t_d_list_node* current = listsd->head;
    t_d_list_node* temp = current;
    while (current != NULL) {
        if (current->cell.nb_niveaux >= n_max) {
            iter_all_levels++;
            if (current->cell.value == key) {
                return iter_all_levels;
            }
            else if (current->cell.value < key) {
                temp = current;
                n_max--;
            }
            else if (current->cell.value > key) {
                current = temp;
                n_max--;
            }
        }
        current = current->next;
    }
    return iter_all_levels;
}

void timelist()
{
    FILE *log_file = fopen("log.txt","w");
    char format[] = "%d\t%d\t%d\n" ;
    int level;
    t_d_list listvit;
    for (int l = 3; l<=20; l++) {
        int iter_lvl0 = 0;
        int iter_all_levels = 0;
        for (int attempt = 1; attempt <= 10; attempt++) {
            level = l;
            int j = pow(2, level) - 1, x = 1;
            createlist(&listvit, level);
            int L[j];
            for (int i = 1; i <= j; i++) {
                L[i] = 0;
            }
            while (pow(2, x) <= pow(2, level)) {
                for (int i = pow(2, x); i <= j; i = i + pow(2, x)) {
                    L[i]++;
                }
                x++;
            }
            for (int i = 1; i <= j; i++) {
                t_d_list_node node = *NewCellNode(j - i + 1, L[j - i + 1] + 1);
                inserer_head(&listvit, &node);
            }
            int nrand = rand() % j + 1;
            if (attempt == 1 && l==7){
                for (int i = 1;i<=l;i++){
                    afficher_niveau(&listvit, i);
                }
            }
            iter_all_levels = searchInDListUp(&listvit, level, nrand, iter_all_levels);
            iter_lvl0 = searchInDList(&listvit, nrand, iter_lvl0);
        }
        fprintf(log_file, format, level, iter_lvl0, iter_all_levels);
    }
    fclose(log_file);
}
