#include<stdio.h>
     
int main() 
{
     
    	long long N, count=0;
    	long long int carry=0;
    	scanf("%lli", &N);
            long long int curr;
    	while (N>0) 
    	{	
    		scanf("%lli", &curr);
     
    		while (carry>0 && curr>1)
    	       	{
    		        carry--;
    			curr=curr-2;
    			count++;
    		}
     
    		count=count+(curr/3);
    		carry=carry+(curr%3);
    		N--;
    	}
     
    	printf("%lli", count);
     
    	return 0;
}

// contributor - https://github.com/aditya113141
