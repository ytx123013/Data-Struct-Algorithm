/**
 * 画家问题
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void rotate_the_clock(int *);

int main(int argc, char const *argv[])
{

	return 0;
}

void rotate_the_clock(int *clock)
{
	int tmp = *clock;
	if (tmp == 3){
		tmp = 0;
	}else{
		tmp++;
	}
	*clock = tmp;
}

