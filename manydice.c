/* manydice.c -- 多次掷骰子的模拟程序 */
#include <stdio.h>
#include <stdlib.h>	//为库函数srand()提供原型
#include <time.h>	//为time()提供原型
#include "diceroll.h"	//为roll_n_dice()提供原型，为roll_count变量提供声明

int main(void) {
	int dice, roll;
	int sides;
	int status;

	srand((unsigned int)time(0));	//随机种子
	printf("Enter the number of sides per die, 0 to stop.\n");
	while (scanf_s("%d", &sides) == 1 && sides > 0) {
		printf("How many dice?\n");
		if ((status = scanf_s("%d", &dice)) != 1) {
			if (status == EOF)
				break;	//退出循环
			else {
				printf("You should have entered an integer.");
				printf(" Let's begin again.\n");
				while (getchar() != '\n')
					continue;		//处理错误的输入
				printf("How many sides? Enter 0 to stop.\n");
				continue;		//进入循环的下一轮迭代
			}
		}
		roll = roll_n_dice(dice, sides);
		printf("You have rolled a %d using %d %d-sided dice.\n",
			roll, dice, sides);
		printf("How many sides? Enter 0 to quit.\n");
	}
	printf("The rollem() function was called %d times.\n",
		roll_count);		//使用外部变量
	printf("GOOD FORTUNE TO YOU!\n");

	return 0;
}