#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*	Write a program to test the performance of the binary search
	technique. Populate a vector array of 2N elements with random
	numbers using the rand() function from <stdlib . h> . N is given as
	input, with N=10 being a good starting point. 210 = 1024. Search
	for the presence of a given number X in the sequence. Before
	sorting you can use linear search, reading the array element by
	element from 0 to N-1 or from N-1 down to 0. Sort the array and
	search again using binary search. Count the number of steps
	during each search attempt. Compare the final counters and
	display the results: was the given X number found? Repeat the
	steps for different values of N.
 */




void generate(int* array,unsigned size)
{
	for(int i=0;i<size;i++)
	{
		array[i]=rand();// Generate pseudo-random numbers;
	}
}
int linear_search(int* array,unsigned size,int find)
{
	int k=0,ok=0;
	for(int i=0;i<size;i++)
	{
		k++; // Count the number of steps;
		if(array[i]==find)
		{
			printf("The number has been found in position %d !\n",k);
			return k;// If we found the number no need to search any further;
		}
			
	}
	printf("Number not found sir \n");
	return k;
}

 int cmplines(const void* p1,const void*p2)
{
	const int* ia=(const int*)p1;// There is no need for a pointer we could as well do const int* ia=*(const int*)p1;
	const int* ib=(const int*)p2;
	return *ia - *ib;//returns negative if ib>ia or positive if ia>ib;
}
int binary_search(int * array,int x, int low, int high)
{
	int k=0;
	while(low<=high)
	{
		k++;// Each step is counted
		int mid=low+(high-low)/2;
		if(array[mid]==x)
		{
			printf("Number is found in position : %d\n",mid);
			return k;
		}
		if(array[mid]<x)
		{
			low=mid+1;
		}
		if(array[mid]>x)
		{
			high=mid-1;
		}
	}
	printf("Number not found sir\n");
	return k;
}


int main()
{
	int n;
	printf("Give a number n to generate 2^n numbers (n=10 is a good start)\n ");
	if(scanf("%d",&n)!=1)
	{
		printf("Overflowing.... EXITING\n");
		return -1;
	}
	n=pow(2,n);
	int array[n];
	generate(array,n);
	printf("Enter a number you would like to find in the array \n");
	int find;
	if(scanf("%d",&find)!=1)
	{
		printf("Overflowing.... EXITING \n");
		return -1;
	}
	printf("---------------------------------------\n");
	clock_t start,end;
	start=clock();
	printf("The number of steps in linear search is : %d \n",linear_search(array,n,find));
	end=clock();
	printf("Execution time of linear search is %ld seconds  \n",end-start);
	printf("---------------------------------------\n");
	qsort(array,n,sizeof(int),cmplines);
	start=clock();
	printf("Number of steps in binary search is: %d \n",binary_search(array,find,0,n-1));
	end=clock();
	printf("Execution time of binary search is : %ld seconds  \n",end-start);
	printf("---------------------------------------\n");
	return 0;
}
