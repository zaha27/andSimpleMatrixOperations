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
    int l, c; //lines and columns 
    scanf("%d%d", &l, &c);

    menu();
    scanf("%d", &menu_key);
    switch(menu_key) {
        case 1 : 
            determinant_function(l, c);
            break;

        case 2 : 
            transpose_function();
            break;
        
        case 3 : 
            adjugate_function();
            break;
        
        case 4 : 
            inverse_function();
            break;
        
        default : printf("invalid command");
    }
}

double** read_matrix(int l, int c){
    double **matrix;
    matrix = alocation(l, c);
}

//TODO : alocation 
//       Read Matrix


//functions
void determinant_function(int l, int c){
    //for the determinant l and c should be equal
    if(l != c){
        printf("Line and Columns should be equal");
        return 0;
        }

    double **matrix;
    matrix = read_matrix(l, c);

    //cream matricea diagonala pt a 
    //calcula determinantul cel mai usor
    int conditie = 1;
    while(conditie) {
        conditie = 0;
        for(int i = 0; i < l; ++i) {
            for(int j = 0; j < l; ++j) {
                if(i != j && matrix[i][j])
                    conditie = 1;
            }
        }
    }
    
}
void transpose_function(){

}
void adjugate_function(){

}
void inverse_function(){

}