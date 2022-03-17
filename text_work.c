#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct songs{
	unsigned int year;
	char name[21];
	char autor[21];
}*data;
	
int main(int argc,char* argv[])
{
	if(argc!=3)
	{
		printf("ERROR");
		return -1;
	}
	char s[1024];
	FILE* f=fopen(argv[1],"r");
	int nL;
	char* str;
	int cnt;
	while(fgets(s,1023,f)!=NULL)
	{
		str=strtok(s,",");
		while(str!=NULL)
		{
			str=strtok(NULL,",");
		}
		nL++;
	}
	data=(struct songs*) malloc(nL*sizeof(struct songs));
	fclose(f);
//	printf("%d\n",nL);
	f=fopen(argv[1],"r");
	int i=0;
	while(fgets(s,1023,f)!=NULL)
	{
		str=strtok(s,",");
		cnt=0;
		while(str!=NULL)
		{
			if(cnt==0)
			{
				if(s[0]=='"')
				{
					int l=strlen(str);
					if(19-l>0)
					{	
						strncpy(data[i].name,str+1,19);
						str=strtok(NULL,"\"");
						strncat(data[i].name,str,19-l);
					}
					//This code section works perfectly but doesn't include Another brick in the wall and be careful with the axe since their size is over 20 to avoid buffer overflow 
					//str=strtok(NULL,",");

				}
				else
					strncpy(data[i].name,str,20);
			}
			if(cnt==1)
			{
				strncpy(data[i].autor,str,20);
			}
			if(cnt==2)
			{
				data[i].year=atoi(str);
			}
			str=strtok(NULL,",");
			cnt++;
		}
		i++;
	}
	int yr=atoi(argv[2]);
	for(int j=0;j<i;j++)
	{
		if(data[j].year==yr)
		{
			printf("%d . %s , %s , %d\n",j,data[j].name,data[j].autor,data[j].year);
		}
	}
	free(data);
	return 0;
}
