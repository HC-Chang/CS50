#include <stdio.h>

void c_judge(int,int,int);

// Reference
// https://www.paypalobjects.com/en_US/vhelp/paypalmanager_help/credit_card_numbers.htm

// Credit
// 信用卡卡號確認
int main()
{
    printf("\nCredit!\n");
    
    long long number;
	
	number = 4111111111111111;
//    scanf("%lld",&number);
    
	// R 基.偶位數加總
    int R = 0;
	
	// 紀錄開頭
    int temp1 = 0;
    int temp2 = 0;
    long long r = number;
	
	// 長度
    int count = 0;
    // 開頭
	int head = 0;
    
    while( r !=0)
    {
        // 基數位加總
        temp1 = (r%10);
        R += temp1/10+temp1%10;
        r = r/10;
        count +=1;
        
        // 偶數位加總
        if( r !=0)
        {
            temp2 = (r%10);
            R += (temp2*2)/10 + (temp2*2)%10;
            r = r/10;
            count +=1;
        }
    }
    
	printf("number --- %lld\nLength --- %i\n",number,count);
	
	// Check Sum
	if(r%2 != 0)
	{
		printf("INVALID --- Number Error !!!\n");
	}
	else
	{
		// 判斷公司
		c_judge(count,temp1,temp2);
	}
 

    
    return 0;
}

// 判斷公司
void c_judge(int j_count,int jt1,int jt2)
{
	int j_head = 0;
	
	
	// 判斷開頭
    if(j_count % 2 == 1)
    {
        j_head = jt1*10+jt2;
    }
    else
    {
        j_head = jt2*10+jt1;
    }
	
	// 判斷公司
	if( j_count == 15 && (j_head == 34 || j_head == 37) )
	{
		printf("Company --- Amex\n");
	}
	else if (j_count == 16 && j_head >= 51 && j_head <= 55 )
	{
		printf("Company --- Master Card\n");
	}
	else if( (j_count == 13 || j_count == 16) && (j_head/10 == 4) )
	{
		printf("Company --- Visa\n");
	}
	else
	{
		printf("INVALID --- Number Error !!!\n");
	}
	
}
