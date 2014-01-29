#include <stdio.h>

int main()
{
	int heights[20000] = {0};
	int x;
	int y;
	int height;
	int i;

	while (scanf("%d %d %d\n", &x, &height, &y) == 3)
	{
		for(i = x; i < y; i++)
		{
			if(height > heights[i])
				heights[i] = height;
		}
	}

	for(i = 0; i < 20000; i++)
	{
		if(heights[i] != heights[i-1])
			printf("%d %d ", i, heights[i]);
	}

	printf("\n");
}