//辗转相除法求两个数的最大公约数
#incldue<stdio.h>
int main(void)
{	
	int r, n, m;
	printf("输入两个大于零的整数：");
	scanf_s("%d %d", &m, &n);
	while (m%n)
	{
		m = n;
		n = r;
	}
	printf("%d\n", n);
	return 0;
}