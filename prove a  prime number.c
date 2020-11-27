//检验一个数是否为质数（素数）
#include <stdio.h>
int main(void)
{
	int num;

	printf("请输入一个大于1的整数:");
	scanf("%d", &num);
	//for循环
	for (int i = 2; i <= num - 1; i++)
	{
		//判断num是否能被i整除 若能整除即不为质数
		if (num%i == 0)
		{
			printf("%d不是质数\n", num);
			//return终止函数
			return;

		}
	}
	printf("%d是质数\n", num);
	return 0;
}