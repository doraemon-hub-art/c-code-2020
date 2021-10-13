#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int compare(int a, int b)
{
	if (a > b)
	{
		return 1;
	}
	else
		return -1;
}
void PaopaoNum(int* sb, int n, int(*compare)(int, int))
{
	int i = 0, k = 0, temp = 0;
	for (i = 0; i < n; i++)
	{
		for (k = 0; k < n - 1; k++)
		{
			if (compare(sb[k], sb[k + 1]) > 0)
			{
				temp = sb[k + 1];
				sb[k + 1] = sb[k];
				sb[k] = temp;
			}
		}
	}
}
int main(void)
{
	int sb[] = { 4,8,2,29,36,7 };
	PaopaoNum(sb, 6, compare);
	for (int i = 0; i < 6; i++)
	{
		printf("%d\n", *(sb + i));
	}
	return 0;
}
