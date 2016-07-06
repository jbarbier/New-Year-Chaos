#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define IMPOSSIBLE "Too chaotic\n"

void calc_swaps(int *q, int q_size)
{
    int swaps;
    int i, j;
    int max;
    
    swaps = 0;
    for (i = q_size - 1; i >= 0; i--)    
    {
        if (q[i] - (i + 1) > 2)
        {
            printf(IMPOSSIBLE);
            return;
        }
        max = 0;
        if (q[i] - 2 > max) max = q[i] - 2;
        for (j = max; j < i; j++)
        {
            if (q[j] > q[i]) swaps++;    
        }
    }
    printf("%d\n", swaps);
}

int main(){
    int T; 
    scanf("%d",&T);
    for(int a0 = 0; a0 < T; a0++){
        int n; 
        scanf("%d",&n);
        int *q = malloc(sizeof(int) * n);
        for(int q_i = 0; q_i < n; q_i++){
           scanf("%d",&q[q_i]);
        }
        calc_swaps(q, n);
    }
    return 0;
}
