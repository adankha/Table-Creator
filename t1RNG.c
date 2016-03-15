#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(int argc, char *argv[]){
    
    
    int i = 0;
    int j = 0;
    int k = 0;
    int rowNumb;    // Holds row input
    int colNumb;    // Holds col input
    char str[30];   // Holds namesread from file
    double randNumb;// Holds random number
    int storeLen = 0;   // Holds largest name length
    int colSpaces = 0;  // Separates columns evenly
    //srand(time(NULL));
    FILE *fp;
    
    /* Error checkers */
    if (argc == 1){
        printf("Please enter two numbers separated with spaces with ./a.out to generate a table of RxC\n");
        return 0;
    }
    
    if (argc > 4){
        printf("Please enter only 2 numbers. and the rnames.txt files\n");
        return 0;
    }
    
    fp = fopen("rnames.txt", "r");
    
    if (fp == NULL){
        printf("Error opening rnames.txt\n");
        return 0;
    }
    /*
Welcome to the random table generator... Well kind of.
Since I am not including srand(TIME(NULL)), the numbers aren't really random.
If you use the same numbers for the rows and columns each time you execute the program,
you will see get the same results. So please keep that in mind when you run this.
*/
    
    
    /* Error checkers for rol/col input */
    if (sscanf(argv[1], "%i", &rowNumb) == 1 && sscanf(argv[2], "%i", &colNumb) == 1){
        if (rowNumb > 100 || rowNumb <= 0){
            printf("Row number doesn't meet the range.\n");
            return 0;
        }
        
        if (colNumb > 20 || colNumb <= 0){
            printf("Col number doesn't meet the range.\n");
            return 0;
        }        
    }
    
    else{
        printf("One of your inputs is not parsing as an integer. Bye\n");
        return 0;
    }
    
        
    /* Find the largest length from file */
    while(i != rowNumb){
               
        fgets(str, 30, fp);
        i++;
        if (strlen(str) > storeLen)
            storeLen = strlen(str);
    }
    
    colSpaces = storeLen / 2;   // Used to separate columns evenly and in line.
        
    /* Print col names */
    for (i = 0; i < colNumb; i++){
        
        /* Print enough spaces for the largest name to place the columns correctly/ in line */
        if (i == 0){
            while (j != storeLen){
                printf(" ");
                j++;
            }
        }
        else{
            
            while (j != colSpaces){
                printf(" ");
                j++;
            }
        }
        printf("Column%d:", i+1);
        j = 0;
    }
    printf("\n");
    
    /*Print rows*/
    for (i = 0; i < rowNumb; i++){
        fscanf(fp, "%s", str);  // Scan name(s) from file and print
        printf("%s:", str);
        
        /* Print numbers for rows */
        for (j = 0; j < colNumb; j++){
            
            randNumb = (double)(rand() % 200);
            
            if (j == 0) // Each time we move to the next row, the spaces between the name and 1st number differ than the other numbers.
            {
                while (k < (storeLen - strlen(str))){   // That difference of spacing is the largest length - the string length.
                    printf(" ");
                    k++;
                }
            }
            else{                                       // If it's not the first row, then print largest string length number of spaces
                while (k < colSpaces){
                    printf(" ");
                    k++;
                }
            }
            k = 0;  // Reset our counter.
            
            printf("%7.2lf ", randNumb);                // Print your beautiful lined up numbers.
        }
        printf("\n");
    }
}
