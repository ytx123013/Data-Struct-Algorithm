/**
 * 青蛙问题
 *
 * 程序输入：
 * 	第一行输入两个整数 R，C 分别表示水稻的行数和列数，1<=R,C<=5000
 *  被踩到的水稻用 1 表示，没踩到的水稻用 0 表示
 * 	每棵被踩水稻只能被列出来一次
 *
 * 程序输出：
 * 	输出一个整数
 * 	如果再稻田中存在青蛙行走路径，则输出包含最多水稻的青蛙行走路径中的水稻数量，否则输出0
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int kRow = 50;
static int kCol = 100;

struct Point_2D
{
	int x;
	int y;
};
typedef struct Point_2D LocationInMap;
typedef int (*map_2D)[100];

map_2D init_map(int row,int col);		//初始化路径
void print_map(int (*)[kCol]);
void insert_route(int (*map)[kCol],int start_row,int start_col,int x_cross,int y_cross);	//插入路径



int main(int argc, char const *argv[])
{
	map_2D inital_map = init_map(50,100);
	
	return 0;
}

map_2D init_map(int row,int col)
{
	map_2D inital_map = (int (*)[col])malloc(row*col*sizeof(int));
	// int (*inital_map)[col] = (int (*)[col])malloc(row*col*sizeof(int));
	memset(inital_map,0,row*col*sizeof(int));
	// print_map(inital_route);
	insert_route(inital_map,0,1,1,3);
	insert_route(inital_map,10,2,0,8);
	insert_route(inital_map,34,1,-1,2);
	insert_route(inital_map,30,2,1,5);
	insert_route(inital_map,0,30,2,4);
	print_map(inital_map);

	return inital_map;
}

void print_map(int (*map)[kCol])
{
	for (int i = 0; i < kRow; ++i)
	{
		if (i>9)
		{
			printf("%d   ", i);
		}else{
			printf("%d    ", i);
		}
		for (int j = 0; j < kCol; ++j)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}

void insert_route(int (*map)[kCol],int start_row,int start_col,int row_cross,int col_cross)
{
	int count = 0;
	for (int cur_row = start_row,cur_col = start_col; cur_row<kRow && cur_row>=0 && cur_col < kCol && cur_col >=0; cur_row=cur_row+row_cross,cur_col = cur_col+col_cross)
	{
		count++;
		*(map[cur_row]+cur_col) = 1;
	}
	printf("the count is %d \n", count);
}