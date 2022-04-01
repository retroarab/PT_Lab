#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct songs{
	unsigned int year;
	char name[20];
	char autor[20];
}*data;


void sort_bubble(struct songs *all,int nL)
{
	for(int i=0;i<nL-1;i++)
	{
		for(int j=0;j<nL-i-1;j++)
		{
			if(all[j].year>all[j+1].year)
			{
				struct songs temp=all[j];
				all[j]=all[j+1];
				all[j+1]=temp;
			}
		}
	}
}

int cmpLines(const void* p1, const void*  p2)
{
	const struct songs *  l1=(struct songs *)p1;
	const struct songs * l2=(struct songs*)p2;
	return(l1->year<l2->year);
}

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
		int k=1;
		while(str!=NULL)
		{
			str=strtok(NULL,",");
		}
		nL++;
	}
	data=(struct songs*)malloc(nL*sizeof(struct songs));
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
				if(20-l>0)
				{
					strncpy(data[i].name,str+1,20);
					str=strtok(NULL,"\"");
					strncat(data[i].name,str,20-l);
				}
				else
					strncpy(data[i].name,str,20);

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
	clock_t start, end;
	start = clock();
	sort_bubble(data,1024);
	end = clock();
	printf ("Execution time of bubble sort %ld seconds \n", end - start);
	start = clock();
	qsort(data,1024,sizeof(struct songs),cmpLines);
	end = clock();
	printf ("Execution time of qsort %ld seconds \n Press enter to show data ", end - start);
	getchar();
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
