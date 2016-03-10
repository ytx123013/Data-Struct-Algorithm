#include "stdlib.h"
#include "stdio.h"

#define kNumber_of_list 10
// static int kNumber_of_list = 10;

int sort_compare(const void *elem_1,const void *elem_2)
{
	int *p1,*p2;
	p1 = (int *)elem_1;
	p2 = (int *)elem_2;
	return *p1 - *p2;	
}

void print_list(int *list)
{
	for (int i = 0; i < kNumber_of_list; ++i)
	{
		printf("%d ", *(list + i));
	}
	printf("\n");
}


int main(int argc, char const *argv[])
{
	int unsort_number[kNumber_of_list] = {55,7,68,125,30,771,200,74,0,1};
	print_list(unsort_number);
	qsort(unsort_number, kNumber_of_list, sizeof(int), sort_compare);
	print_list(unsort_number);
	return 0;
}

