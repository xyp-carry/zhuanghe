#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <windef.h>
#include <math.h>
#include<fstream>
#include<iomanip>
using namespace std;

FILE *in;

double nums[100];
char str[100], tt;
int n, Max, long1, q = 1;
int challenge;
bool decimal,         ///是否输入小数
brackets;       ///是否输入括号
int site = 0,         ///site为 + - * /的位置
site1 = -1,        ///site1,siet2为括号位置
site2 = -1;
ofstream ofile;


void randomNumber()                                   /*生成数字*/
{
	long1 = rand() % challenge + 2;
	for (int i = 0; i < long1; i++)
	{
		if (decimal)
		{
			nums[i] = (rand() % Max) + (rand() % 100 * 0.01);
		}
		else
		{
			nums[i] = (rand() % Max) + 1;
		}
	}
}

void randomBrackets()                              /*括号*/
{
	site1 = -1;
	site2 = -1;
	if (brackets)
	{
		while (1)
		{
			site1 = rand() % long1;
			site2 = rand() % long1;
			if (abs(site1 - site2))
			{
				site1 = min(site1, site2);
				site2 = max(site1, site2);
				break;
			}
		}
		if (long1 == 2)
		{
			site1 = -1;
			site2 = -1;
		}
	}
}

void priduction()                                  /*生成*/
{
	errno_t err;
	err = fopen_s(&in, "四则运算.txt", "a");
	for (int i = 0; i < long1; i++)
	{
		
		int k = rand() % site;                  ///str[i]为随机的符号
		if (i == site1 && site1 != site2)
		{
			cout << "(" << " ";
			tt = '(';
			fprintf(in, "%s", &tt);
		}
		cout << nums[i] << " ";
		fprintf(in, "%.2lf", nums[i]);
		if (i == site2 && site1 != site2)
		{
			cout << ")" << " ";
			tt = ')';
			fprintf(in, "%s", &tt);
		}
		if (i != long1 - 1)
		{
			cout << str[k] << " ";
			fprintf(in, "%c", str[k]);
		}
	}
	fprintf(in, "\n");
	fclose(in);
}



int main() {
	printf("请输入题目数量以及题目中出现的最大数:");
	scanf_s("%d %d", &n,&Max);
	printf("请输入想要的运算符（+-*/）");
	getchar();
	gets_s(str);
	printf("是否需要小数?");
	scanf_s("%d", &decimal);
	printf("是否需要括号?");
	scanf_s("%d", &brackets);
	printf("请输入难度级别");
	scanf_s("%d", &challenge);
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			str[site++] = str[i];                       ///str 存四则运算中将出现的符号
		}
	}

	while (n--)
	{
		randomNumber();
		randomBrackets();
		priduction();
		cout << endl;
	}
	system("pause");
	return 0;
}
}
