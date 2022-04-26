#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000
char maze[N][N];
int n,m,ok=0;
void print_sol()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			printf("%c",maze[i][j]);
		}
	}
}
void readfile(FILE* f)
{
	char junk[1001];
	while(fgets(junk,1000,f))
	{
		if(ok<2)
		{
			ok++;
			m=strlen(junk);
		}
		n++;
	}
	fseek(f,0,SEEK_SET);
	char a;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			fscanf(f,"%c",&a);
			maze[i][j]=a;
		}
	}
}
int movexy(int r,int c,FILE* f1)
{
	if(maze[r][c]=='E')
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				fprintf(f1,"%c",maze[i][j]);
			}
		}
		//print_sol();
		return -1;
	}

	if(r>0 && c>0 && r<n && c<m && maze[r][c]!='#' && maze[r][c]!='.')
	{
		maze[r][c]='.';
		
		if(movexy(r+1,c,f1))
		{

			return 1;
		}
		if(movexy(r,c+1,f1))
		{	
			return 1;
		}
		if(movexy(r-1,c,f1))
		{
			return 1;
		}
		if(movexy(r,c-1,f1))
		{
			return 1;
		}
		maze[r][c]=' ';


		return 0;
	}
	else
	{
		/*print_sol();
		getchar();*/
		// These two above are in order to see how the solution is generated and with an enter in between frames.
		return 0;
	}


	return 0;

}

int main(int argc,char** argv)
{
	if(argc<3)
	{
		printf("Error sir \n");
 		return -1;
	}
	FILE* f=fopen(argv[1],"r");
	FILE* f1=fopen(argv[2],"w");
	if(!f1)
	{
		printf("File not able to open sir \n");
		return -1;
	}
	if(!f)
	{
		printf("File could not be opened ... EXITING \n");
		return -1;
	}
	readfile(f);
	printf("%d and %d\n",n,m);
	movexy(1,1,f1);
	return 0;
}