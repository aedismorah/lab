#include "labalib.h"

void get_file_name(char *new_file_name)
{
    int i = 0;
    char c;
    c = getchar();
    while((c = getchar()) != '\n')
    {
        new_file_name[i] = c;
        i++;
    }
    new_file_name[i] = '.';
    i++;
    new_file_name[i] = 't';
    i++;
    new_file_name[i] = 'x';
    i++;
    new_file_name[i] = 't';
    i++;
    new_file_name[i] = '\0';
}

void T(double **A, int number_of_lines, int number_of_columns, FILE *file_in_which_information_will_be_saved)
{
	int current_line, current_column;
	for(current_column = 0; current_column < number_of_columns; current_column++)
	{
		for(current_line = 0; current_line < number_of_lines; current_line++)
		{
			printf("%lg   ", A[current_line][current_column]);
			fprintf(file_in_which_information_will_be_saved, "%lg   ", A[current_line][current_column]);
		}
		printf("\n");
		fprintf(file_in_which_information_will_be_saved, "\n");
	}	
}

int make_file_readable(FILE *file_in_which_we_save_information)
{
	FILE *which_file_information_is_being_took_from;
	if((which_file_information_is_being_took_from = fopen("mfr.txt", "rt")) != NULL)
    {
    	char c;
	    printf("\n");
	    fprintf(file_in_which_we_save_information, "\n");
	    while((c = fgetc(which_file_information_is_being_took_from)) != EOF)
	    {
	    	if(c == ',')
	    		c = '.';
	    	printf("%c", c);
	    	fprintf(file_in_which_we_save_information, "%c", c);
		}	
		printf("\n");
	    fprintf(file_in_which_we_save_information, "\n");
	    fclose(which_file_information_is_being_took_from);
	    return 0;
	}
    else
    {
    	printf("An ERROR has occured during the reading process!\n");
    	printf("probably the is no such file =( \n");
    	return -1;
	}
}

void save_info(FILE *file_which_is_being_saved, char *its_name)
{
    fclose(file_which_is_being_saved);
    file_which_is_being_saved = fopen(its_name, "at");
}

void show_martrix(double **A, int number_of_lines, int number_of_columns)
{
	int current_line, current_column;
    for(current_line = 0; current_line < number_of_lines; current_line++)
    {
        for(current_column = 0; current_column < number_of_columns; current_column++)
            printf("%lf",A[current_line][current_column]);
        printf("\n");
    }
}

void read_matrix(double **A, int number_of_lines, int number_of_columns)
{
	int current_line, current_column;
	for(current_line = 0; current_line < number_of_lines; current_line++)
		for(current_column = 0; current_column < number_of_columns; current_column++)
			scanf("%lf", &A[current_line][current_column]);
}

void MNK(double **A, int number_of_lines, FILE *file_where_information_will_be_saved_opened)
{
    int i;
    double xy_average=0, x_average=0, y_average=0, x_squared_average=0, y_squared_average=0, k, sigma_k, b, sigma_b;
    for (i = 0; i < number_of_lines; i++)
    {
        x_average += A[i][0];
        xy_average += A[i][0]*A[i][1];
        y_squared_average += A[i][1]*A[i][1];
        x_squared_average += A[i][0]*A[i][0];
        y_average += A[i][1];
    }
    xy_average /= number_of_lines;
    x_average /= number_of_lines;
    x_squared_average /= number_of_lines;
    y_squared_average /= number_of_lines;
    y_average /= number_of_lines;
    k = (xy_average - x_average * y_average)/(x_squared_average - x_average * x_average);
    sigma_k = 1/sqrt(number_of_lines)*sqrt((y_squared_average - y_average * y_average)/(x_squared_average - x_average*x_average)-k*k);
    b = y_average - k*x_average;
    sigma_b = sigma_k*sqrt(x_squared_average-x_average*x_average);

	printf("\n\n");
    fprintf(file_where_information_will_be_saved_opened, "\n\n");
    printf("k = %lg\nsigma_k = %lg\nb = %lg\nsigma_b = %lg\n", k, sigma_k, b, sigma_b);
    if(cor0(k) == 1)
   		printf("y=x%+lg\n", b);
   	else
   		printf("y=%lgx%+lg\n", k, b);
    fprintf(file_where_information_will_be_saved_opened, "k = %lg\nsigma_k = %lg\nb = %lg\nsigma_b = %lg\n", k, sigma_k, b, sigma_b);
    //prints the equation 
    if(cor0(k) == 1)
   		fprintf(file_where_information_will_be_saved_opened, "y=x%+lg\n", b);
   	else
   		fprintf(file_where_information_will_be_saved_opened, "y=%lgx%+lg\n", k, b);
    //show points for plotting
	for(i = 0; i < number_of_lines; i++)
    {
        printf("%lg,%lg\n", A[i][0], A[i][1]);
        fprintf(file_where_information_will_be_saved_opened,"%lg,%lg\n", A[i][0], A[i][1]);
    }
}