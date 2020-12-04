//在屏幕上输出乘法口诀表
//分析：9行，多上行行号就是多少，先确定行，再确定列
#include <stdio.h>
int main(void)
{
	int i = 0;//行
	//确定打印9行
	for (i = 1; i <= 9; i++)
	{
		//打印1行
		int j = 1;
		for (j = 1; j <= i; j++)
		{
			printf(" %d * %d = %-2d ", i, j, i*j);

		}
		//输出回车换行
		printf("\n");
	}
	return 0;
}