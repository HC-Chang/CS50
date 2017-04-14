#include <stdio.h>

// Greedy
// 換取最少硬幣
int main()
{
    printf("\nGreedy!\n");
    
    // 零錢
    float change;
    
    change = 0.41;
//    scanf("%f",&change);
    
    // 剩餘零錢
    int r = change*100;
    int coins = 0;
    
    // 零錢種類
    int avaliable[4] = {25,10,5,1};
    
    int i ;
    for( i =0;i<4;i++)
    {
        coins += r / avaliable[i];
        r = r% avaliable[i];
    }
    
    printf("Change --- %f\nCoins --- %i\n",change,coins);
        
    return 0;
}

