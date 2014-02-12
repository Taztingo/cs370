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
    
    scanf("%d\n", &j);
    
    int f[j];
    
    for(i = 0; i < j; i ++)
    {
        scanf("%d", &k);
        f[i] = k;
        //printf("%d: %d\n", i, k);
    }
    
    scanf("%d\n", &x);
    
    int s[x];
    
    for(i = 0; i < x; i ++)
    {
        scanf("%d", &k);
        s[i] = k;
        //printf("%d: %d\n", i, k);
    }
    
    for(i = 0; i < x; i ++)
    {
        for(k = 0; k < j; k ++)
        {
            if(s[i] == f[k])
            {
                s[i] = 0;
                f[k] = 0;
                break;
            }
        }
    }
    
    for(i = 0; i < x; i ++)
    {
        if(s[i] != 0)
            printf("%d ", s[i]);
    }
    
    return 0;
}
