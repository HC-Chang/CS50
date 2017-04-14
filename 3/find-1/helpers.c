/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

// Find - Less

// 基偶個數問題
/**
 * Returns true if value is in array of n values, else false.
 */
 // 搜尋值 , 被搜尋陣列 , 陣列大小
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
	int bounds[2] = {0,n-1};
	int b_index;
	
	while( value <= values[bounds[1]] && value >= values[bounds[0]])
	{	
		b_index = (bounds[1] + bounds[0])/2;		
			
		// 中間
		if (value == values[b_index])
		{
			return true;
		}
		
		// 搜尋右半邊
		else if (value > values[b_index])
		{
			bounds[0] = b_index + 1;
		}
		
		// 搜尋左半邊
		else if (value < values[b_index])
		{
			bounds[1] = b_index -1;
		}
		
		if(b_index == (bounds[1] + bounds[0])/2)
		{
			return false;
		}		
		
	}
	
		
    return false;
}

/**
 * Sorts array of n values.
 */
 // 排序陣列 , 陣列大小
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
	int temp;
	int i;
	int j;
	for(i = 0;i<n;i++)
	{
		for(j = 0;j<i;j++)
		{
			if(values[j]>values[i])
			{
				temp = values[j];
				values[j] = values[i];
				values[i] = temp;
			}
		}
	}
	
    return;
}
