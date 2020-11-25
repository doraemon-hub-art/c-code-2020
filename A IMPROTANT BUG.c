#include <stdio.h>
int main(void)
{
	char password, prove;
	printf("请输入密码:");
	scanf("%s", &password);
	getchar();
	printf("请确认密码Y/N");
	prove = getchar();
	if (prove == 'Y')
		printf("确认成功");
	else
		printf("确认失败");
	return 0;
}