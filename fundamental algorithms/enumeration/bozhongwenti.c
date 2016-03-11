#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void rotate_the_clock(int *);
void rotate_the_clock_at_index(int *,int);
void rotate_the_clock_by_stratage(int *,int);
void print_clock_state(int *);
int convert_char_to_int(char);

static int move_0[4] = {'A','B','D','E'};
static int move_1[3] = {'A','B','C'};
static int move_2[4] = {'B','C','E','F'};
static int move_3[3] = {'A','D','G'};
static int move_4[5] = {'B','D','E','F','H'};
static int move_5[3] = {'C','F','I'};
static int move_6[4] = {'D','E','G','H'};
static int move_7[3] = {'G','H','I'};
static int move_8[4] = {'E','F','H','I'};

static int kNum_of_colock = 9;

int main(int argc, char const *argv[])
{
	int *move_stratagem[8] = {move_0,move_1,move_2,move_3,move_4,
			move_5,move_6,move_7,move_8};
	int move_stratagem_count[8] = {4,3,4,3,5,3,4,3,4};
	int *clock_state = (int *)malloc(9*sizeof(int));
	memset(clock_state,0,9*sizeof(int));


	print_clock_state(clock_state);
	return 0;
}

void rotate_the_clock_by_stratage(int *clock_state,int index)
{

}

int convert_char_to_int(char tmpChar)
{
	return (int)(tmpChar - 'A');
}

void rotate_the_clock_at_index(int *clock_state,int index)
{
	rotate_the_clock(clock_state+index);
}

void rotate_the_clock(int *clock)
{
	int tmp = *clock;
	if(tmp == 3){
		tmp = 0;
	}else {
		tmp++;
	}
	*clock = tmp;
}

void print_clock_state(int *clock_state)
{
	for(int i = 0;i < kNum_of_colock;i++){
		printf("%d ",*(clock_state+i));
	}
	printf("\n");
}