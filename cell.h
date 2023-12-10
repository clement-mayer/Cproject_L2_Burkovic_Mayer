//
// Created by burko on 13/11/2023.
//

#ifndef UNTITLED4_CELL_H
#define UNTITLED4_CELL_H

#endif //UNTITLED4_CELL_H

typedef struct s_d_cell {
    int value;
    int nb_niveaux;
} t_d_cell;

typedef struct s_d_list_node {
    t_d_cell cell;
    struct s_d_list_node* next;
} t_d_list_node;

t_d_list_node* NewCellNode(int value, int nb_niveaux);
