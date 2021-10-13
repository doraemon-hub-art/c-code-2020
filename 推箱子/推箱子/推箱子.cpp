#include<stdio.h>
#include<graphics.h>//EasyXͼ�ο�
#include<stdlib.h>//���úڴ��ڵĴ�С
#include<conio.h>//��ȡ�������롪������س�
#include<time.h>//����ʱ��
#include<string.h>

#define ROW 10
#define COL 10

/*
	1.���Ƶ�ͼ
	2.���õ�ͼ�ϲ�ͬ����Ʒ������:������ǽ�����ӣ���������Ҫ�ŵ�λ��(Ŀ�ĵ�)
		��Ӧ����
		����				0
		ǽ					1
		Ŀ�ĵ�				2
		����				3
		���				4
		//���������Ƕ�̬�����仯��
		���ӱ��Ƶ���Ŀ�ĵ�	5

	3.
*/

/*
	С����

	1.���ùؿ�
	2.�����ؿ�
	4.�Ʋ���

*/

#define Space  0		//����
#define Wall   1		//ǽ
#define Final  2		//Ŀ�ĵ�
#define Box	    3		//����
#define Player  4      //���
//2+3 = 5�������ӵ���Ŀ�ĵ� 
//��ҵ���Ŀ�ĵغ����ӵ���Ŀ�ĵز�ͬ���壬��Ϊ�Ƕ�̬�仯��



/*
	�洢-����
	1.����һ���ṹ������
	2.�������浽�ļ���
	3.��ȡ
*/

#define RecordPlayerNums 10 //�ܹ���¼���������(����)

//����һ���ṹ�������洢ÿ����ҵ����ݡ���Ϊ������׼��
typedef struct RpArry
{
	char name[64];//����
	int steps;//����
}RpArry;

//����һ��ͼƬ���飬������ͼ
IMAGE img[6];

//����ͼƬ
void Loadimage()
{
	for (int i = 0; i < 6; i++)
	{
		char temFileName[50] = { 0 };
		sprintf(temFileName, "./images/%d.bmp", i);
		loadimage(img + i, temFileName, 63, 63);
	}
}

RpArry rparry[RecordPlayerNums];//ֱ�Ӵ���һ��ȫ�ֵĽṹ������

int RankPerson = 0;//���ڼ�¼������

int LEVEL = 0;//��ǰ�ؿ�����ͼ����

int Step = 0;//�Ʋ���

//�ȶ�ȡ�ļ��е����ݣ������¼��������RankPerson���Ŀ�ʼ
int FilePersonNums = 0;

//���˵�
void MainMenu()
{
	printf("------------------------\n");
	printf("------�������ӡ�-------\n");
	printf("------0.�˳�-----------\n");
	printf("------1.��ʼ��Ϸ-------\n");
	printf("------2.�鿴���а�------\n");
	printf("------------------------\n");
}

//�ö�ά�������洢��ͼ
//����ά�������洢��ͬ�ĵ�ͼ

//��ͼ
int Map[6][ROW][COL] =
{
	//��һ��
	{
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,1,1,1,0,0,0,0},
		{0,0,0,1,2,1,0,0,0,0},
		{0,0,0,1,3,1,1,1,1,0},
		{0,1,1,1,0,0,3,2,1,0},
		{0,1,2,3,0,4,1,1,1,0},
		{0,1,1,1,1,3,1,0,0,0},
		{0,0,0,0,1,2,1,0,0,0},
		{0,0,0,0,1,1,1,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
	},
	//�ڶ���
	{
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,1,1,0,0,1,1,0,0},
		{0,1,0,2,1,1,2,0,1,0},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,3,0,3,0,0,0,1},
		{1,0,0,0,4,0,0,0,0,1},
		{0,1,0,3,0,3,0,0,1,0},
		{0,0,1,2,0,0,2,1,0,0},
		{0,0,0,1,0,0,1,0,0,0},
		{0,0,0,0,1,1,0,0,0,0}
	},
	//������
	{
		{0,0,0,0,0,0,0,0,0,0},
		{0,1,1,1,1,1,1,1,1,0},
		{0,1,2,0,0,0,0,2,1,0},
		{0,1,0,0,0,0,0,0,1,0},
		{0,1,0,3,0,3,0,0,1,0},
		{0,1,0,0,4,0,0,0,1,0},
		{0,1,0,3,0,3,0,0,1,0},
		{0,1,2,0,0,0,0,2,1,0},
		{0,1,1,1,1,1,1,1,1,0},
		{0,0,0,0,0,0,0,0,0,0}
	},
	//���Ĺ�
	{
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,1,1,1,1,0,0,0},
		{0,1,1,1,0,2,1,0,0,0},
		{0,1,0,0,0,0,1,1,1,0},
		{0,1,2,0,0,3,3,0,1,0},
		{0,1,1,2,0,0,3,4,1,0},
		{0,0,1,1,1,1,1,1,1,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0}
	},

	//�����
	{
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,1,1,1,1,1,1,0,0},
		{0,1,2,2,3,0,0,2,1,0},
		{0,1,3,1,0,0,1,3,1,0},
		{0,1,0,0,0,0,0,0,1,0},
		{0,1,0,1,1,1,1,0,1,0},
		{0,1,0,0,0,0,0,0,1,0},
		{0,0,1,0,4,0,0,1,0,0},
		{0,0,0,1,1,1,1,0,0,0},
		{0,0,0,0,0,0,0,0,0,0}
	},
	//������
	{
		{0,0,0,0,0,0,0,0,0,0},
		{0,1,1,1,1,1,1,1,1,0},
		{0,1,2,3,0,0,3,2,1,0},
		{0,1,0,1,0,0,1,0,1,0},
		{0,1,0,1,0,0,1,0,1,0},
		{0,1,0,1,4,0,1,0,1,0},
		{0,1,0,1,0,0,1,0,1,0},
		{0,1,2,3,0,0,3,2,1,0},
		{0,1,1,1,1,1,1,1,1,0},
		{0,0,0,0,0,0,0,0,0,0}
		
	},
};

//���õ�ͼ��������
int FakeMap[6][ROW][COL] =
{
	//��һ��
	{
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,1,1,1,0,0,0,0},
		{0,0,0,1,2,1,0,0,0,0},
		{0,0,0,1,3,1,1,1,1,0},
		{0,1,1,1,0,0,3,2,1,0},
		{0,1,2,3,0,4,1,1,1,0},
		{0,1,1,1,1,3,1,0,0,0},
		{0,0,0,0,1,2,1,0,0,0},
		{0,0,0,0,1,1,1,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
	},
	//�ڶ���
	{
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,1,1,0,0,1,1,0,0},
		{0,1,0,2,1,1,2,0,1,0},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,3,0,3,0,0,0,1},
		{1,0,0,0,4,0,0,0,0,1},
		{0,1,0,3,0,3,0,0,1,0},
		{0,0,1,2,0,0,2,1,0,0},
		{0,0,0,1,0,0,1,0,0,0},
		{0,0,0,0,1,1,0,0,0,0}
	},
	//������
	{
		{0,0,0,0,0,0,0,0,0,0},
		{0,1,1,1,1,1,1,1,1,0},
		{0,1,2,0,0,0,0,2,1,0},
		{0,1,0,0,0,0,0,0,1,0},
		{0,1,0,3,0,3,0,0,1,0},
		{0,1,0,0,4,0,0,0,1,0},
		{0,1,0,3,0,3,0,0,1,0},
		{0,1,2,0,0,0,0,2,1,0},
		{0,1,1,1,1,1,1,1,1,0},
		{0,0,0,0,0,0,0,0,0,0}
	},
	//���Ĺ�
	{
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,1,1,1,1,0,0,0},
		{0,1,1,1,0,2,1,0,0,0},
		{0,1,0,0,0,0,1,1,1,0},
		{0,1,2,0,0,3,3,0,1,0},
		{0,1,1,2,0,0,3,4,1,0},
		{0,0,1,1,1,1,1,1,1,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0}
	},

	//�����
	{
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,1,1,1,1,1,1,0,0},
		{0,1,2,2,3,0,0,2,1,0},
		{0,1,3,1,0,0,1,3,1,0},
		{0,1,0,0,0,0,0,0,1,0},
		{0,1,0,1,1,1,1,0,1,0},
		{0,1,0,0,0,0,0,0,1,0},
		{0,0,1,0,4,0,0,1,0,0},
		{0,0,0,1,1,1,1,0,0,0},
		{0,0,0,0,0,0,0,0,0,0}
	},
	//������
	{
		{0,0,0,0,0,0,0,0,0,0},
		{0,1,1,1,1,1,1,1,1,0},
		{0,1,2,3,0,0,3,2,1,0},
		{0,1,0,1,0,0,1,0,1,0},
		{0,1,0,1,0,0,1,0,1,0},
		{0,1,0,1,4,0,1,0,1,0},
		{0,1,0,1,0,0,1,0,1,0},
		{0,1,2,3,0,0,3,2,1,0},
		{0,1,1,1,1,1,1,1,1,0},
		{0,0,0,0,0,0,0,0,0,0}

	},
};


//�����ͼ-����-ͼ��
void ShowMap()
{
	//����ѭ���������ж�����Ƕ������ӡ��ͼ
	//ע��i j��˳��˳��ͬ����ͼ��ͬ��
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (Map[LEVEL][i][j] == Space)
			{
				putimage(j * 63, i * 63, img + 0);
				printf("  ");
			}

			else if (Map[LEVEL][i][j] == Wall)
			{

				putimage(j * 63, i * 63, img + 1);
				printf("��");
			}
			else if (Map[LEVEL][i][j] == Final)
			{
				putimage(j * 63, i * 63, img + 2);
				printf("��");
			}
			else if (Map[LEVEL][i][j] == Box)
			{
				putimage(j * 63, i * 63, img + 3);
				printf("��");
			}
			else if (Map[LEVEL][i][j] == Player)
			{
				putimage(j * 63, i * 63, img + 4);
				printf("��");
			}
			else if (Map[LEVEL][i][j] == Box + Final)
			{
				putimage(j * 63, i * 63, img + 5);
				printf("��");
			}
			else if (Map[LEVEL][i][j] == Final + Player)
			{
				putimage(j * 63, i * 63, img + 4);
				printf("��");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
}

//���ùؿ�
void ReSetLevel()
{
	for (int s = 0; s < 10; s++)
	{
		for (int b = 0; b < 10; b++)
		{
			Map[LEVEL][s][b] = FakeMap[LEVEL][s][b];
		}
	}
}

//��ȡ�������룬�������Ӻ���ҵ��ƶ�����������
void PushBox()
{
	//Ӧ�����ҵ�������ģ�Ȼ���ٽ��п���
	//ʹ��һ��ѭ��Ƕ�����ҵ����Player
	//i���У�j����
	//����i��j�������ҵ���ҵ��±�
	int i = 0;//��-����
	int j = 0;//��-����
	//��ӱ������Ƕ��ѭ��
	int flag = 0;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			//ʲô����ң�
			//��Ҹ��������ҽ��뵽Ŀ�ĵ���
			if (Map[LEVEL][i][j] == Player || Map[LEVEL][i][j] == Player + Final)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}

	//��ʾ
	if (LEVEL < 4)
	{
		printf("���ո����ùؿ�\n");
		printf("���س������ؿ�\n");
		printf("��ǰ����%d", Step);
	}

	//_getch���ռ�������
	char KeyBorad = _getch();
	//�ƶ�����
	switch (KeyBorad)//���÷������wasd�����в���
	{
		/*
			ʲôʱ����Խ����ƶ���
			ǰ���ǿ��������������ӣ��������Ӻ��治����ǽ
		*/

		//�����ƶ�
	case 'w':
	case 'W':
	case  72:
	{
		//������ǰ����-��������-Ŀ�ĵؾͿ����ƶ�
		if (Map[LEVEL][i - 1][j] == Space || Map[LEVEL][i - 1][j] == Final)
		{
			//��ҽ����ƶ������Ӽ����������궨�����Ѿ��������������ʲô
			Map[LEVEL][i - 1][j] += Player;
			//֮ǰ�Ǹ�λ��ͬ�������˱仯
			Map[LEVEL][i][j] -= Player;
			Step++;
		}
		//�����ҵ�ǰ��������
		else if (Map[LEVEL][i - 1][j] == Box)
		{
			//�������ӵ�ǰ����Ŀ�ĵػ��߿���
			if (Map[LEVEL][i - 2][j] == Space || Map[LEVEL][i - 2][j] == Final)
			{
				//���������ƶ�
				Map[LEVEL][i - 2][j] += Box;
				//��Ҹ����ƶ���������֮ǰ�������ڵ�λ��
				Map[LEVEL][i - 1][j] -= Box;
				Map[LEVEL][i - 1][j] += Player;
				//���֮ǰ��λ�÷����仯
				Map[LEVEL][i][j] -= Player;
				Step++;
			}
		}
		break;
	}

	//�����ƶ�
	case 's':
	case 'S':
	case 80:
	{
		//��������ǿ���������Ŀ�ĵؾͿ��Խ����ƶ�
		if (Map[LEVEL][i + 1][j] == Space || Map[LEVEL][i + 1][j] == Final)
		{
			Map[LEVEL][i + 1][j] += Player;
			Map[LEVEL][i][j] -= Player;
			Step++;
		}
		//�������������
		else if (Map[LEVEL][i + 1][j] == Box)
		{
			//�������������ǿ���������Ŀ�ĵ�
			if (Map[LEVEL][i + 2][j] == Space || Map[LEVEL][i + 2][j] == Final)
			{
				//�����������ƶ�һ��λ�á�����ʵ�����Ƿ����ƶ�������Ҫ�ƶ������λ��������ʾ�����ݷ����˱仯,����ͬ��
				Map[LEVEL][i + 2][j] += Box;
				//���������ƶ�һ��λ��
				Map[LEVEL][i + 1][j] -= Box;
				Map[LEVEL][i + 1][j] += Player;
				//��֮ǰλ���ϱ�ɿ���
				Map[LEVEL][i][j] -= Player;
				Step++;
			}
		}
		break;
	}

	//�ж�ͬ�ϲ�������
	//�����ƶ�
	case 'a':
	case'A':
	case 75:
	{
		if (Map[LEVEL][i][j - 1] == Space || Map[LEVEL][i][j - 1] == Final)
		{
			Map[LEVEL][i][j - 1] += Player;
			Map[LEVEL][i][j] -= Player;
			Step++;
		}
		else if (Map[LEVEL][i][j - 1] == Box)
		{
			if (Map[LEVEL][i][j - 2] == Space || Map[LEVEL][i][j - 2] == Final)
			{
				Map[LEVEL][i][j - 2] += Box;
				Map[LEVEL][i][j - 1] -= Box;
				Map[LEVEL][i][j - 1] += Player;
				Map[LEVEL][i][j] -= Player;
				Step++;
			}
		}
		break;
	}

	//�����ƶ�
	case 'd':
	case 'D':
	case 77:
	{
		if (Map[LEVEL][i][j + 1] == Space || Map[LEVEL][i][j + 1] == Final)
		{
			Map[LEVEL][i][j + 1] += Player;
			Map[LEVEL][i][j] -= Player;
			Step++;
		}
		else  if (Map[LEVEL][i][j + 1] == Box)
		{
			if (Map[LEVEL][i][j + 2] == Space || Map[LEVEL][i][j + 2] == Final)
			{
				Map[LEVEL][i][j + 2] += Box;
				Map[LEVEL][i][j + 1] -= Box;
				Map[LEVEL][i][j + 1] += Player;
				Map[LEVEL][i][j] -= Player;
				Step++;
			}
		}
		break;
	}

	//�ո����ùؿ�
	case 32:
	{
		ReSetLevel();
		ShowMap();
		break;
	}

	//����
	case 13:
		if (LEVEL < 5)
		{
			LEVEL++;
		}
		break;
	}
}

//�ж��Ƿ����
bool PassLevel()
{
	//����������е�����ȫ����Ŀ�ĵأ���ͨ��
	//Ƕ��ѭ������ͼ����û�������˾���ͨ����
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (Map[LEVEL][i][j] == Box)
			{
				return false;
			}
		}
	}
	//system()
	//���˾����ùؿ�(�е��ظ�)
	ReSetLevel();
	return true;
}

void PopWindow();//ǰ������

//��ʼ��Ϸ
void StartGame()
{
	//system("cls");
	ShowMap();
	settextstyle(30, 0, NULL);
	settextcolor(RGB(0, 0, 0));
	setbkmode(TRANSPARENT);
	outtextxy(0, 0, "��ǰ����:");
	outtextxy(200,0,"��");
	char q[5];
	sprintf(q, "%d", LEVEL+1);
	outtextxy(300,0, q);
	outtextxy(380,0,"��");
	char s[5];
	sprintf(s, "%d", Step);
	outtextxy(0, 30, s);
	outtextxy(0, 570, "�ո�����õ�ǰ�ؿ�");
	outtextxy(0, 600, "�س���������ǰ�ؿ�");


	if (PassLevel())//�ж��Ƿ���أ����ؾ��л���һ�ŵ�ͼ
	{
		//���ء����л��ؿ�
		LEVEL++;

		//ͨ��
		if (LEVEL > 5)
		{
			//���뵽����˵�����йؿ����Ѿ�ͨ��
			//int End = clock();//����������ʱ
			//int TimeResult = End - Begin;
			printf("��ϲ��%s���������Ϸ\n", rparry[RankPerson].name);
			//printf("��ʱ%d��\n", TimeResult / 600);

			//�������洢���ṹ������
			printf("����%d��\n", Step);
			PopWindow();//��ϲ���صĵ�����ʾ

		}
	}
	PushBox();
}

//�����¼-�ļ�
void SavePlayerRecord()
{

	//�ļ�����
	FILE* fp = fopen("PlayerRecord.txt", "a");
	if (fp == NULL)
	{
		printf("��ȡ�ļ�ʧ��\n");
		return;
	}
	fprintf(fp, "\t%s\t%d\n", rparry[RankPerson].name, rparry[RankPerson].steps);
	fclose(fp);
	system("pause");
	system("cls");
}
/*
	Ҫʵ��һ�����ղ�����С�����а�
	Ҳ���Բ����ļ�����д�������ٶ�ȡ�ļ���ʱ������������������С��
*/
////��ȡ��¼-�ļ�
//void ReadPlayerRecord()
//{
//	FILE* fp = fopen("PlayerRecord.txt", "r");
//	if (fp == NULL)
//	{
//		printf("��ǰ��¼Ϊ��!\n");
//		return;
//	}
//
//	//�������
//	int i = 1;
//
//	//�Ƚ�ԭ�����ļ���ȡ���ṹ�������С�����������һ���Ѿ�ʵ��
//	//��ȡ��ϣ����������Ѿ������浽�ṹ��������
//	//���մ�С�����˳���������
//
//	//��ȡ��
//	char Gets[164];
//	while (!feof(fp))
//	{
//		fgets(Gets, 164, fp);
//		//feop�����⡪����Ҫ�ڶ��μ���β
//		if (feof(fp))
//		{
//			break;
//		}
//		else
//		{
//
//		}
//	}
//}
//���ļ���ȡ����ǰ�ṹ�����顪���ó��ļ����м�����
void ReadRecordFile()
{
	FILE* fp = fopen("PlayerRecord.txt", "r");//��һ���ļ�
	if (fp == NULL)
	{
		//printf("���ļ�ʧ��\n");
		return;
	}
	for (int i = 0; i < RecordPlayerNums; i++)
	{
		fscanf(fp, "%s%d", rparry[i].name, &rparry[i].steps);
	}
	//��ȡ���ļ������ݵ���������
	for (int i = 0; i < RecordPlayerNums; i++)
	{
		if (rparry[i].steps != 0)
		{
			//��ǰ����
			RankPerson = ++FilePersonNums;
		}
	}
	fclose(fp);
}
//����&���µ��ļ���
void RecordBubbSort()
{
	//ð������
	//������ʱ��ע���ǽṹ��
	for (int i = 0; i < RankPerson; i++)
	{
		RpArry Temprparry;
		for (int j = 1; j < RankPerson - i; j++)
		{
			if (rparry[j - 1].steps >= rparry[j].steps)
			{
				Temprparry = rparry[j];
				rparry[j] = rparry[j - 1];
				rparry[j - 1] = Temprparry;
			}
		}
	}

	//printf("����\t���\t\t����\t\n");
	//for (int i = 0; i < RankPerson; i++)
	//{
	//	printf("%d", i + 1);
	//	printf("\t%s\t\t%d\n", rparry[i].name, rparry[i].steps);
	//}
	//FILE* fp = fopen("PlayerRecord.txt", "w");
	//for (int i = 0; i < RankPerson; i++)
	//{
	//	if (rparry[i].steps != 0)
	//	{
	//		fprintf(fp,"\t%s\t%d\n",rparry[i].name,rparry[i].steps);
	//	}
	//}
}
/*
	���а�˼·
	1.�Զ���ȡ�ļ��е����ݣ����浱ǰ�Ľṹ��������
	2.�Խṹ�����鰴�ղ����Ĵ�С������������
	3.��ӡ���
*/
//ɾ���ļ�&����û���¼
void DeletePlayerRecord()
{
	//��ʾ
	//printf("ȷ����գ�\n");
	//printf("1.ȷ�� 2.ȡ��\n");
	//int select = 0;
	//scanf("%d", &select);
	//if (select == 1)
	//{
	//	//ֱ��ɾ����¼�ļ�
	//	remove("PlayerRecord.txt");
	//	//����ǰ�����ÿ�
	//	RankPerson = 0;
	//	printf("������!\n");
	//}
	//else
	//{
	//	printf("��¼��δ�����\n");
	//}

	//ֱ��ɾ����¼�ļ�
	remove("PlayerRecord.txt");
	//����ǰ�����ÿ�
	RankPerson = 0;
	//����
	printf("������!\n");
}

void GraphInputName();
void GraphRankPage();


//ͼ�ν������ҳ
void GraphFirImagesPg()
{
	MOUSEMSG m;
	//����ͼ�δ��ڴ�С
	initgraph(ROW * 63, COL * 63);//SHOWCONSOLE��ʾ�����д���
	Loadimage();

	setbkcolor(BLACK);

	cleardevice();//ˢ��һ�� �Ե����Ǹ�system(cls)

	IMAGE picture1;
	loadimage(&picture1, "./topbc.jpg", 630, 630);
	putimage(0, 0, &picture1);

	setfillcolor(GREEN);

	fillrectangle(230, 405, 400, 430);

	fillrectangle(230, 445, 400, 470);

	fillrectangle(230, 485, 400, 510);


	settextstyle(85, 0, "����");
	char Title[] = "������";
	char Select1[] = "��ʼ��Ϸ";
	char Select2[] = "���а�";
	char Select3[] = "�˳���Ϸ";


	//�����
	outtextxy(210, 150, Title);
	//�����ѡ��
	settextstyle(30, 0, NULL);
	setbkmode(TRANSPARENT);// ȥ�����ֱ���
	outtextxy(252, 405, Select1);
	outtextxy(268, 445, Select2);
	outtextxy(255, 485, Select3);



	while (1)
	{
		m = GetMouseMsg();//���
		if (m.x >= 230 && m.x <= 400 && m.y >= 405 && m.y <= 430)//��ʼ��Ϸ
		{
			setlinecolor(RED);
			rectangle(220, 400, 410, 440);
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				GraphInputName();


				cleardevice();//��ջ�ͼ�豸
				while (LEVEL < 6)
				{
					StartGame();

				}
				//�ȸ���Ӧ���˸�ֵ����ṹ��
				rparry[RankPerson].steps = Step;
				//�������ݽ��ļ�
				SavePlayerRecord();
				//���ù���
				LEVEL = 0;
				//���ò���
				Step = 0;
				//����洢��һ��
				RankPerson++;
				//���ùؿ�
				ReSetLevel();
				//���
				cleardevice();
				GraphFirImagesPg();
			}
		}
		else if (m.x >= 230 && m.x <= 400 && m.y >= 445 && m.y <= 470)//�鿴���а�&��ռ���������
		{
			setlinecolor(RED);
			rectangle(220, 440, 410, 480);
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				cleardevice();
				GraphRankPage();

			}

		}
		else if (m.x >= 230 && m.x <= 400 && m.y >= 485 && m.y <= 510)//�˳���Ϸ
		{
			setlinecolor(RED);
			rectangle(220, 480, 410, 520);
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				exit(0);
				break;
			}
		}
		//��겻����Ӧ�ķ�Χ�ڱ߿����ʧ
		else
		{
			setlinecolor(BLACK);
			rectangle(220, 400, 410, 440);
			rectangle(220, 440, 410, 480);
			rectangle(220, 480, 410, 520);
		}



	}
}


//ͼ�ν��濪ʼ��Ϸ-�����ǳ�
void GraphInputName()
{

	TCHAR InputWindow[] = _T("����������ǳ�");
	InputBox(rparry[RankPerson].name, 10, InputWindow);//�����ǳ�
}




//һ�������ĵ���
void PopWindow()
{


	//��ȡ���ھ��
	HWND hnd = GetHWnd();
	//����������ʾ�û�����
	//���ϴ��ھ�� ǿ���û��ȵ���ٽ��в���

	//��һ���ַ��������ܽ����
	int isok = MessageBox(hnd, "��ϲͨ��", "��ʾ", MB_OK);
}

void GraphDeleteRankPage();
//ͼ�ν������а�
void GraphRankPage()
{
	MOUSEMSG m1;//���
	cleardevice();
	
	//��հ�ť
	setbkcolor(BLACK);

	cleardevice();//ˢ��һ�� �Ե����Ǹ�system(cls)

	setfillcolor(GREEN);
	fillrectangle(440, 90, 580, 140);
	fillrectangle(440, 150, 580, 200);
	settextstyle(30, 0, "����");
	setbkmode(TRANSPARENT);
	char Delete[10] = { "�������" };//��հ�ť
	char Back[10] = { "����" };

	outtextxy(480, 158, Back);
	outtextxy(450, 100, Delete);
	outtextxy(60, 100, "����");
	outtextxy(220, 100, "�ǳ�");
	outtextxy(350, 100, "����");

	if (RankPerson == 0)
	{
		settextstyle(50, 0, "����");
		char TIPS[20] = { "��ǰ��¼Ϊ��!" };
		outtextxy(130, 238, TIPS);
	}

	RecordBubbSort();



	for (int i = 1; i <= RankPerson; i++)
	{
		char a[5];
		sprintf(a, "%d", rparry[i - 1].steps);
		char b[5];
		sprintf(b, "%d", i);
		outtextxy(60, 100 + (50 * i), b);
		outtextxy(220, 100 + (50 * i), rparry[i - 1].name);
		outtextxy(350, 100 + (50 * i), a);
	}

	//��հ�ť
	while (1)
	{
		m1 = GetMouseMsg();
		if (m1.x >= 440 && m1.x <= 580 && m1.y >= 85 && m1.y <= 150)
		{
			rectangle(430, 85, 590, 150);
			setlinecolor(RED);
			if (m1.uMsg == WM_LBUTTONDOWN)
			{
				GraphDeleteRankPage();//������а�
				cleardevice();//����
				GraphRankPage();
			}
		}
		else if (m1.x>=440 && m1.x<=580&&m1.y >=150 && m1.y<200)
		{
			rectangle(430, 145, 590, 210);
			setlinecolor(RED);
			if (m1.uMsg == WM_LBUTTONDOWN)
			{	
				cleardevice();
				GraphFirImagesPg();
			}
		}
		else
		{
			setlinecolor(BLACK);
			rectangle(430, 85, 590, 150);
			rectangle(430, 145, 590, 210);

		}
	}
}

//��ռ�¼��ͼ�ν���
void GraphDeleteRankPage()
{
	//��ȡ���ھ��
	HWND hnd = GetHWnd();
	//����������ʾ�û�����
	//���ϴ��ھ�� ǿ���û��ȵ���ٽ��в���
	//��һ���ַ��������ܽ����
	int isok = MessageBox(hnd, "ȷ�����?", "��ʾ", MB_OKCANCEL);
	if (isok == IDOK)
	{
		int tips1 = MessageBox(hnd, "��ճɹ���", "��ʾ", MB_OK);
		DeletePlayerRecord();
	}
	else if (isok == IDCANCEL)
	{
		//���ȡ��������Ӧ
	}
}


//������
int main(void)
{
	//�Ȱ��ļ��б����еĸ����������
	ReadRecordFile();

	//ͼ�ν����Լ������
	GraphFirImagesPg();


	//���������кڴ��ڵĴ�С
	//system("mode con cols=30 lines=20");//����cols��lines��ֵ��ʱ�����пո񣬷���ᱨ��
	//while (1)
	//{

	//	MainMenu();
	//	printf("���������ѡ��:\n");

	

	//	int Select = 0;
	//	scanf_s("%d", &Select);
	//	system("cls");


	//	switch (Select)
	//	{
	//		/////////////////////////////////////////////////////////////////////�˳�
	//	case 0:
	//		printf("��Ϸ�������ټ�:)��\n");
	//		exit(0);
	//		/////////////////////////////////////////////////////////////////////��ʼ��Ϸ
	//	case 1:
	//		//ͼ�ν��������û���
	//		GraphInputName();
	//		//������Ϸ֮ǰ����ʾ�������û���
	//		//printf("����������ǳ�:\n");
	//		//
	//		//scanf("%s", rparry[RankPerson].name);
	//		system("cls");

	//		//cleardevice();//��ջ�ͼ�豸

	//		while (LEVEL < 4)
	//		{
	//			StartGame();
	//		
	//		}
	//		//�ȸ���Ӧ���˸�ֵ����ṹ��
	//		rparry[RankPerson].steps = Step;
	//		//�������ݽ��ļ�
	//		SavePlayerRecord();
	//		//���ù���
	//		LEVEL = 0;
	//		//���ò���
	//		Step = 0;
	//		//����洢��һ��
	//		RankPerson++;
	//		//���ùؿ�
	//		ReSetLevel();

	//		//���
	//		cleardevice();
	//		break;
	//		//////////////////////////////////////////////////////////////////////���а�
	//	case 2:

			//ͼ�ν�������а�

			//�ɹ�����֮ǰ��ReadPlayerRecord
			//if (RankPerson == 0)
			//{
			//	printf("��ǰ��¼Ϊ�գ�\n");
			//}
			//else
			//{
			//	//��ǰ��¼��
			//	printf("��ǰ��¼��:%d\n", RankPerson);
			//	//����&���
			//	RecordBubbSort();
			//}
			//system("pause");
			//break;
			///////////////////////////////////////////////////////////////////////������а�&����ļ�
	//	case 3:
	//		//DeletePlayerRecord();
	//		GraphDeleteRankPage();
	//		break;


	//		//////////////////////////////////////////////////////////////////////��������
	//	default:
	//		printf("ѡ���������������롣\n");
	//		system("pause");
	//		break;
	//	}

	//	system("cls");
	//}


	return 0;
}