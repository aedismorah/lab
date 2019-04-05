#ifndef _labalib_H_
#define _labalib_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define max(a,b) ((a) >= (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))
#define cor0(x) ((x) > -1e-10 && (x) < 1e-10 ? 0 : (x))

void MNK(double **A, int number_of_lines, FILE *file_where_information_will_be_saved_opened);
void read_matrix(double **A, int number_of_lines, int number_of_columns);
void show_martrix(double **A, int number_of_lines, int number_of_columns);
void save_info(FILE *file_which_is_being_saved, char *its_name);
int make_file_readable(FILE *file_in_which_we_save_information);
void T(double **A, int number_of_lines, int number_of_columns, FILE *file_in_which_information_will_be_saved);
void get_file_name(char *new_file_name);

#endif

