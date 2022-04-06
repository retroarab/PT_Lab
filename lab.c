#include <stdio.h>
#include <stdlib.h>

void init_board(char* board)
{
	for(int i=0;i<9;i++)
	{
		board[i]='-';
	}
	printf("The board is initialised\n");
}

void print_board(char* board)
{
	printf("--------------------------------------------------\n");
	printf("|\t%c\t|\t%c\t|\t%c\t|\n",board[0],board[1],board[2]);
	printf("--------------------------------------------------\n");
	printf("|\t%c\t|\t%c\t|\t%c\t|\n",board[3],board[4],board[5]);
	printf("--------------------------------------------------\n");
	printf("|\t%c\t|\t%c\t|\t%c\t|\n",board[6],board[7],board[8]);
	printf("--------------------------------------------------\n");

}
unsigned check_win(char* board)
{
	//Check diagonal condition
	if((board[0]==board[4]) && (board[0]==board[8])&& board[0] !='-')
		return 1;
	for(int i=0;i<3;i+=2)
	{
		if((board[i]==board[i+1]) && (board[i]==board[i+2]) && board[i]!='-')
		{
			return 1;
		}
	}
	for(int i=0;i<3;i+=3)
	{
		if((board[i]==board[i+3]) && (board[i]==board[i+6]) && board[i]!='-')
		{
			return 1;
		}
	}
	if((board[2]==board[4]) && (board[2]==board[6]) && board[2]!='-')
		return 1;

	return 0;
}
void move_player1(char* board)
{
	int choice=0;
	int random_bot_move=-1;
	while(1)
	{
		printf("Give a number where to move (1-9)\n");
		if(scanf(" %d",&choice)!=1)
		{
			printf("Dont overflow my g");
		}
		choice-=1;
		if(choice<0 && choice >9)
		{
			return;
		}
		board[choice]='x';
		print_board(board);
		if(check_win(board))
		{
			return;
		}
	}
}
void show_winner()
{
	printf("Winner is \n");
}


int main()
{
	char board[9];
	init_board(board);
	print_board(board);
	move_player1(board);
	show_winner(board);
	return 0;
}

