#ifndef HEADER_H_
#define HEADER_H_

void menu();
void read_menu(int menu_key);

double **read_matrix(int dimension);
double **alocation(int dimension);
void print_matrix(double **x, int dimension);
void free_matrix(double **matrix, int dimension);
//functions

double determinant_function(int n);
void transpose_function();
void adjugate_function();
void inverse_function();
void gauss_elimination();

#endif
