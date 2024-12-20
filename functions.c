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
    menu();
    scanf("%d", &menu_key);

    printf("Introduce Dimensiunea matricei: ");
    int dimension = 0;
    scanf("%d", &dimension);

    switch(menu_key) {
        case 1 : {
            double det = 0;
            det = determinant_function(dimension);
            printf("The determinant is %.3lf", det);
            break;
        }
            

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

double **alocation(int dimension) {
    double **matrix = malloc(dimension * sizeof(double *));
    for (int i = 0; i < dimension; ++i) {
        matrix[i] = malloc(dimension * sizeof(double));
    }
    return matrix;
}

double **read_matrix(int dimension) {
    double **matrix = alocation(dimension);
    printf("Introduceți elementele matricei (rânduri x coloane):\n");
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            scanf("%lf", &matrix[i][j]);
        }
    }
    return matrix;
}


double determinant_function(int n) {
    double **matrix = read_matrix(n);
    double det = 1.0;
    int semn = 0; 

    for (int i = 0; i < n; ++i) {

        if (fabs(matrix[i][i]) < 1e-9) {
            int swap_row = -1;
            for (int k = i + 1; k < n; ++k) {
                if (fabs(matrix[k][i]) > 1e-9) {
                    swap_row = k;
                    break;
                }
            }
            if (swap_row == -1) {
                free_matrix(matrix, n);
                return 0.0;
            }
            for (int j = 0; j < n; ++j) {
                double temp = matrix[i][j];
                matrix[i][j] = matrix[swap_row][j];
                matrix[swap_row][j] = temp;
            }
            semn++;
        }
        for (int k = i + 1; k < n; ++k) {
            double factor = matrix[k][i] / matrix[i][i];
            for (int j = i; j < n; ++j) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
        det *= matrix[i][i];
        printf("\n Pasul %d", i+1);
        print_matrix(matrix, n);
        printf("\n#################\n");
        }

    if (semn % 2 != 0) {
        det = -det;
    }

    free_matrix(matrix, n);
    return det;
}
      
void transpose_function(){ return;

}
void adjugate_function(){ return;

}
void inverse_function(){ return;

}

void print_matrix(double **x, int dimension) {
    for(int i = 0; i < dimension; i++) {
        printf("\n");
        for(int j = 0; j < dimension; j++) {
            printf("%3.2lf ", x[i][j]);
        }
    }
}

void free_matrix(double **matrix, int dimension) {
    for (int i = 0; i < dimension; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}