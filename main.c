#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "timer.h"


int main() {
    srand((unsigned int)time(NULL));
    t_d_list listsd;
    createlist(&listsd, 3);

    t_d_list_node node_trie0 = *NewCellNode(1,1);
    t_d_list_node node_trie1 = *NewCellNode(3,3);
    t_d_list_node node_trie2 = *NewCellNode(4,2);
    t_d_list_node node_trie3 = *NewCellNode(6,1);
    t_d_list_node node_trie4 = *NewCellNode(5,2);
    inserer_trie(&listsd, &node_trie0);
    inserer_trie(&listsd, &node_trie1);
    inserer_trie(&listsd, &node_trie2);
    inserer_trie(&listsd, &node_trie3);
    inserer_trie(&listsd, &node_trie4);

    for (int i = 1;i<=3;i++){
        afficher_niveau(&listsd, i);
    }
    printf("\n");

    timelist();
    return 0;
}
