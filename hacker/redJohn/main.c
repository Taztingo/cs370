#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int sieve(int n)
{
	char* sieve;
	int i, j, m, c;

	if (n < 2) { c = 0; return 0; }

	c = n-1;
	m = (int) sqrt ((double) n);

	/* calloc initializes to zero */
	sieve = calloc (n+1, sizeof(char));

	sieve[0] = 1;
	sieve[1] = 1;

	for (i = 2; i <= m; i++)
		if (sieve[i] == 0)
			for (j = i*i; j <= n; j += i)
				if (sieve[j] == 0)
				{
					sieve[j] = 1; 
					--c;
				}
	return c;
}

int main() {
	int t, //Number of test cases
	n, //Width of test wall
	i, //Iteration var
	bricks[41];

	bricks[0]= 1;
	bricks[1]= 1;
	bricks[2] = 1;
	bricks[3] = 1;
	

	for(i = 4; i < 41; i++)
		bricks[i] = bricks[i-1] + bricks[i-4];

	scanf("%d", &t);

	for(i = 0; i < t; i ++)
	{
		scanf("%d",&n);
        printf("%d\n",sieve(bricks[n]));
	}

    return 0;
}