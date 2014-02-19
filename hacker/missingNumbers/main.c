#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int i;
    int j;
    int k;
    int x;
    int min;
    int r[200];
    
    scanf("%d\n", &j);
    
    min = 10000;
    memset(r, 0, sizeof(int) * 200);

    int f[j];
    
    for(i = 0; i < j; i ++)
    {
        scanf("%d", &k);
        if(k < min)
            min = k;
        f[i] = k;
    }
    
    scanf("%d\n", &x);
    
    int s[x];
    
    for(i = 0; i < x; i ++)
    {
        scanf("%d", &k);
        if(k < min)
            min = k;
        s[i] = k;
    }

    for(i = 0; i < j; i ++)
    {
        r[(f[i] % min)] = f[i];
        r[(f[i] % min) + 100] -= 1;
    }

    for(i = 0; i < x; i ++)
        r[(s[i] % min) + 100] += 1;

        
    for(i = 0; i < 100; i ++)
        if(r[i + 100] > 0)
            printf("%d ", r[i]);
    
    return 0;
}
