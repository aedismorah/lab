#include "labalib.h"
/*
bug list
file name must not contain spaces
matrix size isnt calculated aytomatically
cannot convert other formats except txt
have to use mfr.txt in order to change chars. but i want to iput them from keyboard
*/
int main(void)
{
    FILE *output;
    char S[200], new_file_name[200] = "output.txt";
    int number_of_lines, number_of_columns, counter;
    double **A, **B;
    output = fopen(new_file_name, "at");

    printf("cnf\n"); // create new file
    printf("mnk\n"); //linear regression
    printf("T\n");  //transpose given matrix (show transposed matrix while the matrix is being unchanged)
    printf("quit\n"); // pretty self-explanatory
    printf("mfr\n"); // make file radable (replaces commas with dots in file and only in file mfr (it shows the changed text? but the text in the file itself is not changed))
    printf("write\n"); // append output file
    printf("show\n"); // open file
    
    printf("possibilities are endless!\n\n");

    while(1)
    {
        scanf("%s", S);

        if(!strcmp(S, "mnk"))
        {
            printf("enter line number\n");
            scanf("%d", &number_of_lines);
            A = (double**) malloc(number_of_lines*sizeof(double));
            for (counter = 0; counter < number_of_lines; counter++)
				A[counter] = (double *) malloc(2 * sizeof(double));
            printf("enter your matrix\n");
            for (counter = 0; counter < number_of_lines; counter++)
            {
            	scanf("%lf", &A[counter][0]);
		        scanf("%lf", &A[counter][1]);
			}
            MNK(A, number_of_lines, output);
            for (counter = 0; counter < number_of_lines; counter++)
            	free(A[counter]);
            free(A);
            save_info(output, new_file_name);
            printf("action done succesfully!\n");
        }
        
        if(!strcmp(S, "smile"))
        {
        	printf("                 *****                       *****                 \n                 *****                       *****                 \n                 *****                       *****                 \n                 *****                       *****                 \n                 *****                       *****                 \n                 *****                       *****                 \n                 *****                       *****                 \n                 *****                       *****                 \n                 *****                       *****                 \n                 *****                       *****                 \n                 *****                       *****                 \n                 *****                       *****                 \n                 *****                       *****                 \n                 *****                       *****                 \n                 *****                       *****                 \n                 *****                       *****                 \n                                                                   \n                                                                   \n                                                                   \n     *****                                               *****     \n      ******                                           ******      \n         ******                                     ******         \n            ******                               ******            \n               ********                     ********               \n                   *****************************                   \n                       *********************                       \n                                                                   \n                                                                   \n");
		}
		
		if(!strcmp(S, "write"))
        {
        	char c;
        	fclose(output);
        	output = fopen(new_file_name, "at");
        	printf("I am ready to read, sir!\n"); 
        	while((c = getchar()) != '~')
				fprintf(output, "%c", c);
			printf("action done succesfully!\n");
    	}
    	
    	if(!strcmp(S, "show"))
        {
        	char c;
        	fclose(output);
        	FILE *vol;
        	printf("Which file would you like to open?\n");
        	get_file_name(S);
        	if((vol = fopen(S, "rt")) != NULL)
        	{
        		while((c = fgetc(vol)) != EOF)
				printf("%c", c);
				fclose(vol);
				output = fopen(new_file_name, "at");
				printf("\naction done succesfully!\n");
			}
			else 
				printf("the is no such file =(\n");
        	        		
    	}

       if(!strcmp(S, "cnf"))
        {
            printf("enter new file name\n");
            fclose(output);
            get_file_name(new_file_name);
            output = fopen(new_file_name, "at");
            printf("action done succesfully!\n");
        }
        
        if(!strcmp(S, "mfr"))
        {
            if(!make_file_readable(output))
            	printf("action done succesfully!\n");
        }

        if(!strcmp(S, "T"))
        {
            printf("enter matrix size\n");
            scanf("%d%d",&number_of_lines, &number_of_columns);
            A = (double **) malloc(number_of_lines * sizeof(double *));
            for (counter = 0; counter < number_of_lines; counter++)
                A[counter] = (double *) malloc(number_of_columns * sizeof(double));
            printf("enter your matrix\n");
            read_matrix(A, number_of_lines, number_of_columns);
            T(A, number_of_lines, number_of_columns, output);
            save_info(output, new_file_name);
            printf("action done succesfully!\n");
        }

        if(!strcmp(S, "quit"))
            break;
    }
    fclose(output);
}

