#include <stdio.h>

// Greedy
// �����ֵ̤w��
int main()
{
    printf("\nGreedy!\n");
    
    // �s��
    float change;
    
    change = 0.41;
//    scanf("%f",&change);
    
    // �Ѿl�s��
    int r = change*100;
    int coins = 0;
    
    // �s������
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

