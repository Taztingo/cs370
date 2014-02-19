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
    int r[100];
    
    scanf("%d\n", &j);
    
    min = 10000;
    memset(r, 0, sizeof(int) * 100);

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

    for(i = 0; i < x; i ++)
        for(k = 0; k < j; k ++)
            if(s[i] == f[k])
            {
                s[i] = 0;
                f[k] = 0;
                break;
            }

    for(i = 0; i < x; i++)
    {
        r[(s[i] % min)] = s[i];
    }
        
    for(i = 0; i < 100; i ++)
    {
        if(r[i] != 0)
            printf("%d ", r[i]);
    }
    
    return 0;
}
