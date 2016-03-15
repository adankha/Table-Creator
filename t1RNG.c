#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(int argc, char *argv[]){

int i;
int rowNumb;
int colNumb;
FILE *fp;
char str[30];
char *newStr;
double randNumb;
int j;
//srand(time(NULL));

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

    if (sscanf(argv[1], "%i", &rowNumb) == 1 && sscanf(argv[2], "%i", &colNumb) == 1){
	if (rowNumb > 100 || rowNumb <= 0){
	  printf("Row number doesn't meet the range.\n");
          return 0;
	}

        if (colNumb > 20 || colNumb <= 0){
	  printf("Col number doesn't meet the range.\n");
	  return 0;
        }
       
    }//if sscanf(..); 
 
    else{
      printf("One of your inputs is not parsing as an integer. Bye\n");
      return 0;
    }  	
    printf("        "); 
    for (i = 0; i < colNumb; i++){
      printf("Column%d:   ", i+1);
    }
    printf("\n");
    for (i = 0; i < rowNumb; i++){
	 fscanf(fp, "%s", str);
	 printf("%s:", str);
      
      for (j = 0; j < colNumb; j++){
	randNumb = (double)(rand() % 200);
        printf("%7.2lf ", randNumb);
      }
	printf("\n");
    }
    
}
