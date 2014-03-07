#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
/* Head ends here */
int lonelyinteger(int a_size, int* a) {
    int i;
    int t[200];
    
    memset(t, 0, sizeof(int) * 200);
    
    for(i = 0; i < a_size; i++)
    {
        t[a[i]] = a[i];
        t[a[i] + 100]++;
    }
    
    for(i = 0; i < 100; i++)
    {
        if(t[i + 100] == 1)
        {
            i = t[i];
            break;
        }
            
    }
return i;

}

/* Tail starts here */
int main() {
    int res;
    
    int _a_size, _a_i;
    scanf("%d", &_a_size);
    int _a[_a_size];
    for(_a_i = 0; _a_i < _a_size; _a_i++) { 
        int _a_item;
        scanf("%d", &_a_item);
        
        _a[_a_i] = _a_item;
    }
    
    res = lonelyinteger(_a_size, _a);
    printf("%d\n", res);
    
    return 0;
}