#include "header.h"
#include "lib.h"

//functions

void menu() {
    printf("Menu: \n\t1.Determinant - press 1 \n");
    printf("\t2.Transpose matrix - press 2 \n");
    printf("\t3.Adjugate matrix - press 3\n");
    printf("\t4.Inverse matrix - press 4\n");
}
void read_menu(int menu_key) {
    printf("%d", menu_key);
}