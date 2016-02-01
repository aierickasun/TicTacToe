#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void dispbord(void);
int makeMove(int turn, char whoseturn[]);
int checkwin(char sss[][3], char winner);
void initliz(void);

char boardarray[3][3] = {'X', 'X', 'X', 'O', 'O', 'O','O', 'X', 'O'};
char winners = ' ';

int main(int argc, char *argv[]){
	char whoseturn[2] = {'X', 'O'};
	char menunxt = ' ';
	char dummy = ' ';
	int win = 0;
	int turn;
	int worksorno;
	int numturns = 1;
	char winner = ' ';
	while(1 == 1){
		printf("Hi, welcome to the tictactoe game. \nPress 1 if you'd like to start a new game or 2 if you'd like to quit. \n > ");
		scanf(" %c", &menunxt);
		while((dummy = getchar()) != '\n');
		if(menunxt == '1'){
			turn = 1;
			initliz();
			dispbord();
			while(1==1){
				worksorno = makeMove((turn-1) %2, whoseturn);
                        	if(worksorno == 2) continue;
				else if(worksorno == 1){
					dispbord();

					turn++;

				}

				if(checkwin(boardarray, winner) == 1) break;
				else if(checkwin(boardarray, winner) == 2) continue;
			}
			printf("\nCongratulations %c, you won!\n", winners);
		}

		else if(menunxt == '2') break;
		else continue;
	}
	return 0;
}

int checkwin(char sss[][3], char winner){
	int i;
	for(i = 0; i < 3; i++){
		if(sss[i][0] == sss[i][1] && sss[i][0]== sss[i][2]){
			if(sss[i][0] == 'X'){
				winners = 'X';
				return 1;
			}
			else if(sss[i][0] == 'O'){
				winners = 'O';
				return 1;
			}
		}
	        else if(sss[0][i] == sss[1][i] && sss[0][i] == sss[2][i]){
       
                	        if(sss[0][i] == 'X'){
                        	        winners = 'X';
                        	        return 1;
                      	        }
                      	        else if(sss[0][i] == 'O'){
                               		 winners = 'O';
                               		 return 1;
                                }
                        }

	else return 2;
	}
}

void dispbord(){
/*~   C   O   L
    1   2   3
R 1   |   |
   -----------
O 2   |   |
   -----------
W 3   |   | */
	int r, c;
	printf("\n\n\n\n\n");
	printf("TICTACTOE BOARD\n");

	for(r = 0; r < 7; r++){

			if(r == 0)
				printf("    C   O   L \n");
			else if(r == 1)
				printf("    1   2   3 \n");
			else if(r == 2)
				printf("R 1 %c | %c | %c \n", boardarray[0][0], boardarray[0][1], boardarray[0][2]);
			else if(r == 3 || r == 5)
				printf("   -----------\n");
			else if(r == 4)
				printf("O 2 %c | %c | %c \n", boardarray[1][0], boardarray[1][1], boardarray[1][2]);
			else if(r == 6)
				printf("W 3 %c | %c | %c \n", boardarray[2][0], boardarray[2][1], boardarray[2][2]);
	}
	printf("\n\n\n\n\n");
}

int makeMove(int turn, char whoseturn[]){
	int arraycol = 0;
	int arrayrow = 0;
	int check    = -1;
	printf("\nIt is now %c s turn. Please enter a row. > ", whoseturn[turn]);
	RETRY:		scanf(" %d", &arrayrow);
		if(arrayrow > 3 || arrayrow < 1){
			printf("\nPlease enter a row that's in bounds. ");
			goto RETRY;
		} 
	printf("\nNow enter a Column.                      > ");

	RETRY2:	scanf(" %d", &arraycol);
		if(arraycol > 3 || arrayrow < 1){
			printf("\nPlease enter a col that's i bounds. ");
			goto RETRY2;

		}
	if((boardarray[arrayrow-1][arraycol-1] == 'X' || boardarray[arrayrow-1][arraycol-1] == 'O')){
		dispbord();
		 return 2;
	}
	boardarray[arrayrow-1][arraycol-1] = whoseturn[turn];


	return 1;
}

void initliz(){
	int i, s;
	for(i = 0; i < sizeof(boardarray); i++){
		for( s = 0; s < sizeof(boardarray[i]); s++){
			boardarray[i][s] = ' ';
		}
	}
}
