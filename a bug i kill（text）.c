//#include <stdio.h>
//int main(void)
//{
//	//定义字符变量
//	char prove;
//	//数组 字符串
//	char password[20] = { 0 };
//	printf("请输入密码:");
//	//数组本身就是地址不用加&
//	scanf("%s", password);
//	//回收\n防止他干预下面的接收 
//	//在代码运行窗口输入的回车也会被当做字符而被获取
//	
//	printf("请确认密码Y/N:");
//	prove = getchar();
//	if (prove == 'Y')
//		printf("确认成功");
//	else
//		printf("确认失败");
//	return 0;
//}
#include <stdio.h>
int main()
{	
	int a, b;
	printf("请输入两个数：")
	scanf("%d,%d", a, b);
	c1 = getchar();
	c2 = getchar();
	printf("%d,%d"c1, c2);
	return 0;
}