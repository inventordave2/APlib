// NATIVE_C
// APLIB SUBMODULE FOR NATIVE (CHIP_LIMITED_PRECISION) FUNCTIONS.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "native.h"


// i = ith prime number, if n is set, i is ignored. n will test for a prime number. f is a flag, set to TRUE if you want the ith prime number, or if you want to test if the arg u pass is literally prime.
large isprime ( large i )	{
	
	toggle report;
	
	if( f==L )	{
		// trial division algorithm, divide n by every integer between 2 and sqrt(n), as at n = a . b, either a
		// or b will not be bigger than sqrt(n), which means all tests have been performed
		
		if( i==1 )	{
			// base case: 1, the smallest prime number is 2...
			
			if( report==ON )
				printf("1 is too small to be a prime number! The smallest prime number is 2.");
			
			return 0;
		}
		
		if( i==2 )	{
			// base case 2, it interferes with the test conditional, as 2 % 2 == 0, which fails the value 2 for the test. 
			// Subsequent n % k tests don't have to check if n == k, as k will never be more than sqrt(n)
			
			if( report==ON )
				printf("2 is the 1st Prime, you know that!");
			
			return 2;
		}
		
		large sqrt_ = ceil(sqrt(n)) + 1;
		for (large k = 2; k < sqrt_; k++)
			if( (i % k) == 0 )	{
				
				if( report==ON )
					printf("%d is NOT prime. It was divisable at %d.\n", i, k);
				
				return 0;
			}
		
		if( report==ON )
			printf("%d IS A PRIME NUMBER!\n", n);
		
		return i;
	}
	

	large j = 3;
	large k = 0;
	large p = 0;
	
	#ifndef TRUE
	#define TRUE 1
	while( TRUE )	{
		
		if(
		
		p = isprime(j, R)// 
		
		){
			
			++k;
			if( k==i )
				break;
			
		}
		
		++j;

	}
	// p <--- i-th prime number
	
	if( report==ON )
		printf("Prime number %d is %d.", i, p);
	
	// RETURN VALUE
	return p;
}



int primedata(unsigned int min, unsigned int max, unsigned int step)	{
	// step: if set to 1, the step increment is to accumulate +1 for each prime number discovered.
	// if set to 2, the step increment is the distance to the current prime from the last prime (v. low number, usually single digits)
	// otherwise, the step increment is accumulative of each step-change between each pair of current & last prime number.
	// remember, the only even prime number is 2, so only need to check odd-numbers.
	
	char * s = allocs(1024*8*10);
	
	unsigned int p = 0;
	unsigned int p2 = 0;
	unsigned int c = 0;
	
	max += 1;
	
	if(min<=2)	{
	
		cat(5, s, "['", itoa2(2), "', ", itoa2(0), "],\n");
		
		/**
		strcat(s, itoa(2));
		strcat(s, "', ");
		strcat(s, itoa(0));
		strcat(s, "],\n");
		*/
		
		min = 3;
		
		p2 = prime(0, 2, 0);
		c++;
	}
	
	if((min%2)==0)
		min++;
	
	if(p2==0)
		p2 = prime(0, min, 0);
	
	while(min<max)	{
		
		if(p = prime(0, min, 0))	{
			
			if(step==1)
				c++;
			
			else if(step==2)
				c = p - p2;
			
			else
				c = c + (p - p2);
			
			sprintf(s, "%s%s%d", s, "['", p);
			strcat(s, "', ");
			strcat(s, itoa2(c));
			strcat(s, "],  ");
			
			p2 = p;
		}
		
		min += 2;
	}

	printf("\n%s\n", s);

	free(s);
	return 1;
	
	/**
	
		The outputted string is in the following format, but the numbers will be different:
		
		['2',  2],
		['3',  3],
		['4'   3],
		['5',  5]	
	*/
}

