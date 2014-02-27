#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int t, //Number of test cases
	n, //Width of test wall
	i; //Iteration var

	scanf("%d", &t);

	for(i = 0; i < t; i ++)
	{
		scanf("%d",&n);
		printf("%d\n", tile(n));
	}

    return 0;
}

//Recursive function to calculate wall width
int tile(int n)
{
	if(n < = 4)
		return n;
	else
		return tile(n-1) + tile(n-3);
}