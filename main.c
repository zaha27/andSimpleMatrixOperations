#include "header.h"
#include "lib.h"

int main(void) {
    int menu_key = 0;
    menu();
    scanf("%d", &menu_key);
    read_menu(menu_key);


}