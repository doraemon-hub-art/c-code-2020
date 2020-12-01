//计算五个数的平均数
#include <stdio.h>
int main(void)
{
	int a, b, c, d, e;
	float ret;
	printf("请输入五个成绩：\n");
	//格式化字符串 取地址符
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	ret = (a + b + c + d + e) / 5.0;
	//小数点后保留一位小数
	printf("%.1f", ret);
	return 0;
}