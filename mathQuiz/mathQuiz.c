#include <stdio.h>
#include<stdlib.h>

int quizData[30];

int main(){
	
	srand(time(NULL));
	
	int x;
	int i;
	int opr;
	int op1;
	int op2;
	int ans;
	int score = 0;
	int temp;
	FILE *wp;
	wp = fopen("results.txt", "w");
	
	
	readData();	
	
	for(i = 0; i < 10; i++){
		
		
		//selects a random question and sets up the operands and operators
		x = rand() % 10 * 3;
		opr = quizData[x];
		op1 = quizData[x+1];
		op2 = quizData[x+2];
		
		printf("\nWhat is %d %c %d?\n", op1, opr, op2);
		fprintf(wp, "\nWhat is %d %c %d?\n", op1, opr, op2);
		scanf("%d", &ans);
		fprintf(wp, "%d", ans);

		
		
		//prompts and scores a question
		switch(opr){
			
			case '+':
			if(ans == add(op1, op2)){
				score++;
				printf("\nGood Job!, your score is %d\n", score);
				fprintf(wp, "\nGood Job!, your score is %d\n", score);
			}
			else
				printf("\nSorry, the correct answer is %d, your score is %d", add(op1, op2), score);
				fprintf(wp, "\nSorry, the correct answer is %d, your score is %d", add(op1, op2), score);

			break;
			
			case '-':
			if(ans == sub(op1, op2)){
				score++;
				printf("\nGood Job!, your score is %d\n", score);
				fprintf(wp, "\nGood Job!, your score is %d\n", score);
			}
			else
				printf("\nSorry, the correct answer is %d, your score is %d", sub(op1, op2), score);
				fprintf(wp, "\nSorry, the correct answer is %d, your score is %d", sub(op1, op2), score);
			break;
			
			case '*':
			if(ans == mult(op1, op2)){
				score++;
				printf("\nGood Job!, your score is %d\n", score);
				fprintf(wp, "\nGood Job!, your score is %d\n", score);
			}
			else
				printf("\nSorry, the correct answer is %d, your score is %d", mult(op1, op2), score);
				fprintf(wp, "\nSorry, the correct answer is %d, your score is %d", mult(op1, op2), score);
			break;
			
			case '/':
			if(ans == idiv(op1, op2)){
				score++;
				printf("\nGood Job!, your score is %d\n", score);
				fprintf(wp, "\nGood Job!, your score is %d\n", score);
			}
			else
				printf("\nSorry, the correct answer is %d, your score is %d", div(op1, op2), score);
				fprintf(wp, "\nSorry, the correct answer is %d, your score is %d", div(op1, op2), score);
			break;
		}
		
		//post randomization switching
		int y = i * 3;
		quizData[x] = quizData[y];
		quizData[y] = opr;
		quizData[x+1] = quizData[y+1];
		quizData[y+1] = op1;
		quizData[x+2] = quizData[y+2];
		quizData[y+2] = op2;
		
		
		
	}
	
	
	
	fclose(wp);	
	return 0;
	
}



int readData()
{
  int  i, j;
  FILE *fp;
  fp = fopen("/gaia/class/student/srivatss/csc60_18/shell/data.input","r");
  if (fp == NULL)
  {
    printf("Unable to open the file.\n");
    exit(EXIT_FAILURE);
  }

  printf("The contents of the file are:\n", fp);
  i = 0 ;
  while ( 1 )
  {
    char ch;
    ch = fgetc (fp);
    if ( ch == '+' || ch == '*' || ch == '-' || ch == '/' )
      {
         printf ( "i=%c ", ch );
         quizData[i++] = ch; // not casting, but I should actually
         fscanf ( fp, "%d", &quizData [i++]);
         printf ( "%d ", quizData [i-1] );
         fscanf ( fp, "%d", &quizData [i++]);
         printf ( "%d \n ", quizData [i-1] );
      }

    ch = fgetc (fp);
    if ( ch == EOF )
       break;
  }

  fclose(fp);
}


