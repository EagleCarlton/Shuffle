// 洗牌（结构体）.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
typedef struct
{
	char suit;//花色
	int pips;//点数
}Card;
void shuffle(Card pa[], int n);//洗牌函数声明
void display_card(const Card pa[], int n);//输出函数声明
int main()
{
	int i;
	Card deck[52];
	for (i = 0; i < 52; ++i)
	{
		deck[i].suit = i / 13 + 3;
		deck[i].pips = i % 13 + 1;
	}
	printf("Before suffling:\n");
	display_card(deck, 52);
	shuffle(deck, 52);
	printf("After suffling:\n");
	display_card(deck, 52);
    return 0;
}
void shuffle(Card pa[], int n)
{
	int i, j;
	Card temp;
	srand(time(0));
	for (i = 0; i < n; ++i)
	{
		j = rand() % n;
		temp = pa[i];
		pa[i] = pa[j];
		pa[j] = temp;
	}
}
void display_card(const Card pa[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		printf("(%c%-2d)", pa[i].suit, pa[i].pips);
		if ((i + 1) % 13 == 0)
			printf("\n");
	}
}
