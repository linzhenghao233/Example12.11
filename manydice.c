/* manydice.c -- ��������ӵ�ģ����� */
#include <stdio.h>
#include <stdlib.h>	//Ϊ�⺯��srand()�ṩԭ��
#include <time.h>	//Ϊtime()�ṩԭ��
#include "diceroll.h"	//Ϊroll_n_dice()�ṩԭ�ͣ�Ϊroll_count�����ṩ����

int main(void) {
	int dice, roll;
	int sides;
	int status;

	srand((unsigned int)time(0));	//�������
	printf("Enter the number of sides per die, 0 to stop.\n");
	while (scanf_s("%d", &sides) == 1 && sides > 0) {
		printf("How many dice?\n");
		if ((status = scanf_s("%d", &dice)) != 1) {
			if (status == EOF)
				break;	//�˳�ѭ��
			else {
				printf("You should have entered an integer.");
				printf(" Let's begin again.\n");
				while (getchar() != '\n')
					continue;		//������������
				printf("How many sides? Enter 0 to stop.\n");
				continue;		//����ѭ������һ�ֵ���
			}
		}
		roll = roll_n_dice(dice, sides);
		printf("You have rolled a %d using %d %d-sided dice.\n",
			roll, dice, sides);
		printf("How many sides? Enter 0 to quit.\n");
	}
	printf("The rollem() function was called %d times.\n",
		roll_count);		//ʹ���ⲿ����
	printf("GOOD FORTUNE TO YOU!\n");

	return 0;
}