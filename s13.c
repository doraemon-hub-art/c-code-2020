#include<stdio.h>
#include<math.h>
int main(void)
{	
	float a, b, result = 0;
	char op;
	scanf_s("%f %f", &a, &b);
	getchar( );
	scanf_s("%c", &op );
	switch (op)
	{
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
	case '/':
		if (fabs(b) <= 1e-6)
		{
			printf("error\n");
		}
		else
		{
			result = a / b;
		}
		break;
	}
	if (fabs(b) <= 1e-6)
	{
		printf("error\n");
	}
	else
	{
		printf("%f %c %f = %f", a, op, b, result);
	}

	return 0;
}