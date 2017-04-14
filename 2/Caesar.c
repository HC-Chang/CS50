#include <stdio.h>

char change(int,int,char);

// Caesar
// 資料加密 --- key: 單一字元
int main(int argc, char *argv[])
{
    int key = atoi(argv[1]);
    
    if(argc == 2)
    {
        printf("\nCaesar\nKey:%i\nPlaintext:\t",key);
    
        int size = 50;
        char p_c [size];
        char *p_text = p_c;
        char d_c [size];
    
        // 輸入資料
        scanf("%[^\n]", p_text);
    
        // 資料加密
        int i ;
        int i_temp = 0;
        for(i=0;i<size;i++)
        {
            i_temp = (int)p_c[i]; 
       
            // 大寫轉換
            if( i_temp >= 65 && i_temp <= 90)
            {
                d_c[i] = change(key,65,i_temp);
            }
       
            // 小寫轉換
            else if(i_temp >= 97 && i_temp <= 122)
            {
                d_c[i] = change(key,97,i_temp);
            }
       
            // 不轉換
            else
            {
                d_c[i] = p_c[i];
            }
        }
   
   
        // 加密後資料
        printf("Ciphertext:\t%s\n",d_c);
    }
    return 0;
}

// 位移
char change(int s_key,int start,char c_c)
{
    char c = (char)start+(((int)c_c-start+s_key)%26) ;
    return c;
}