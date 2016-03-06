/**
	熄灯问题
	问题描述
	现有 6x5 的灯
	0	0	0	0	0	0
	0	0	0	0	0	0
	0	0	0	0	0	0
	0	0	0	0	0	0
	0	0	0	0	0	0
	每按一次(x,y)上的按钮，则该位置和其上下左右共5个灯会改变状态
	如果灯原来是点亮的，则会被熄灭
	如果灯原来是熄灭的，则会被点亮
	若(x,y)临近边缘则超出部分不考虑
	现请设计一个程序，确定需按下哪些按钮，恰好使所有灯都熄灭



	找寻局部状态去枚举，即枚举第一行或第一列所有情况便可确定剩下的状态
*/

/**
 * 当输入初始状态时 0为灯灭 1为灯亮
 * 当输出时，0为不按，1为按下
 */

#include "stdio.h"
#include "stdlib.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>


static int kRow_count = 5;
static int kCol_count = 5;
static int kInitial_state[5][5] = {1,1,1,1,1
						  	  	  ,1,1,1,1,1
							 	  ,1,1,1,1,1
							 	  ,1,1,1,1,1
							 	  ,1,1,1,1,1};

void change_at_index(int (*light_state)[kCol_count],int row,int col);
void print_light_state(int (*light_state)[kCol_count]);
int is_all_lights_outs(int (*light_state)[kCol_count]);
void enumeration_01(int (*initial_state)[kCol_count]);
void change_around_at_index(int (*light_state)[kCol_count],int row,int col);


int main(int argc, char const *argv[])
{
	enumeration_01(kInitial_state);
 	return 0;
}

/**
 * 枚举所有可能开关状态并检测所有最后的状态
 */
void enumeration_01(int (*initial_state)[kCol_count])
{
	int (*light_state)[kCol_count] = (int (*)[kCol_count])malloc(kCol_count * kRow_count * sizeof(int));
	for (int i = 0; i < kRow_count; ++i)
	{
		for (int j = 0; j < kCol_count; ++j)
		{
			light_state[i][j] = initial_state[i][j];
		}
	}


	int total_count = kCol_count * kRow_count;

	//只需列举第一行所有情况即可，换算成用十进制换算成二进制
	int max = pow(2,kCol_count) - 1;
	for (int i = 0; i <= max; ++i)
	{
		int (*tmp_light_state)[kCol_count] = (int (*)[kCol_count])malloc(kCol_count * kRow_count * sizeof(int));
		for (int i = 0; i < kRow_count; ++i)
		{
			for (int j = 0; j < kCol_count; ++j)
			{
				tmp_light_state[i][j] = light_state[i][j];
			}
		}

		int (*press_state)[kCol_count] = (int (*)[kCol_count])malloc(kCol_count * kRow_count * sizeof(int));
		memset(press_state,0,kCol_count*kRow_count*sizeof(int));

		//换算成二进制
		int n = 0,count = i;
		do{
			*(press_state[0]+n) = count % 2;
			count = count/2;
			n++;
		}while(count!=0);

		for (int k = 0; k < kCol_count; ++k)
		{
			if (*(press_state[0]+k) == 1)
			{
				change_around_at_index(tmp_light_state,0,k);
			}
		}

		//若前一行改变后的状态有 1 ，则下一行的对应列数操作应该为按下
		for (int m = 0; m < kRow_count-1; ++m)
		{
			for (int n = 0; n < kCol_count; ++n)
			{
				if (*(tmp_light_state[m]+n) == 1)
				{
					*(press_state[m+1]+n) = 1;
					change_around_at_index(tmp_light_state,m+1,n);
				}
			}
		}

		if (is_all_lights_outs(tmp_light_state) == 1)
		{
			print_light_state(press_state);
			print_light_state(tmp_light_state);
		}
		
	}
}

/**
 * 改变周围的灯状态
 */
void change_around_at_index(int (*light_state)[kCol_count],int row,int col)
{
	int up_row = row - 1;
	int down_row = row + 1;
	int left_col = col - 1;
	int right_col = col + 1;

	change_at_index(light_state,row,col);
	if (up_row >= 0)
	{
		change_at_index(light_state,up_row,col);
	}
	if (down_row <=kRow_count - 1)
	{
		change_at_index(light_state,down_row,col);
	}
	if (left_col >= 0)
	{
		change_at_index(light_state,row,left_col);
	}
	if (right_col <= kCol_count - 1)
	{	
		change_at_index(light_state,row,right_col);
	}
}

/**
 * 改变具体数组位置的值
 */
void change_at_index(int (*light_state)[kCol_count],int row,int col)
{
	int state = light_state[row][col];
	*(light_state[row]+col) = -state + 1;
}

/**
 * 检查是否所有灯都熄灭
 */
int is_all_lights_outs(int (*light_state)[kCol_count])
{
	int total_count = kRow_count * kCol_count;
	int is_all_lights_out = 1;
	for (int i = 0; i < kRow_count; ++i)
	{
		for (int j = 0; j < kCol_count; ++j)
		{
			if (light_state[i][j] != 0)
			{
				is_all_lights_out = 0;
			}
		}
	}
	return is_all_lights_out;
}

void print_light_state(int (*light_state)[kCol_count])
{
	for (int i = 0; i < kRow_count; ++i)
	{
		for (int j = 0; j < kCol_count; ++j)
		{
			printf("%d ",light_state[i][j] );
		}
		printf("\n");
	}
	printf("-----------------------\n");
}

