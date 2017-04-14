/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

// Find - More

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
    // TODO: implement an O(n) sorting algorithm
	const int MAX = 65536;
	int arr [MAX];
	
	// 陣列重設歸0
	memset(arr,0,n);
	
	// 將待排序之值丟入arr陣列中計算次數
	int i;
	for(i = 0;i<n;i++)
	{
		arr[values[i]] ++;
	}
	
	// 找出有放入arr陣列中的值
	// 並帶入陣列中做新的排序
	int j = 0;
	for(i = 0;i<MAX;i++)
	{
		if(arr[i]!= 0)
		{
			int k ;
			for(k = 0;k<arr[i];k++)
			{	
				values[j] = i;
				j++;
			}
		}
		
		// 如果已有j個值放入陣列
		if(j == n)
		{
			break;
		}
	}
		
	
	
    return;
}
