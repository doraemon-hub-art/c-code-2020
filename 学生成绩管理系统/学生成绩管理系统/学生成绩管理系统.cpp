#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<string.h>
#include<ctype.h>//����ַ�


#define RecordNums 15//�ṹ����������

int NowStudentNums = 0;//��ǰ��¼����






//��ʹ�����ݽṹ
//�ýṹ��������ļ�������ʵ��

//ѧ���ṹ�嶨��
typedef struct Student
{
	char s_Num[64];//ѧ��
	char s_Name[64];//����
	char s_Chinese[64];//��
	char s_Math[64];//��
	char s_English[64];//Ӣ
	double s_SumScore;//�ܷ�
}Student;


//����ѧ���ṹ������
Student StuArry[RecordNums];

//�����ɼ��ṹ��
typedef struct Score
{
	double SuScore;//subject score
}Score;

//�����ɼ��ṹ�塪����Сͬѧ���ṹ������
Score SoArry[RecordNums];

//��������Ա�ṹ��
typedef struct Admin
{
	char UserName[64];
	char PassWord[64];
}Admin;

//����һ������Ա�û�
Admin AdminUser;

//��ʾȫ�����ݵ�ҳ����ת��ʶ
int FlagAI = -1;
//��ѯ�ҵ�ҳ����ת��ʶ
int FlagFPT = -1;
/*
			MainSteps
	1.�ȴͼ�δ��ڵĴ�����̬
	2.��ʵ�����������
*/

/*
	ͼ�ν���ʵ��
*/

//ǰ�����������鿴����ת������鿴����˵��
void AdminPage();
void AdminSignIn();
void CommonUserPage();
void SaveInfor();
void ReadInfor();
void ShowAllInfor();
void InputInfor();
void S1mplePrint();
void AdDeSeMoPage();
void DeleteStuInfor();
int ReturnPosi();
void ModifyStudInfor();
void PrintFoudInfor();
void DeSomeStu();
void SortAcChinese();
void SortAcMath();
void SortAcEnglish();
void SortAcSumScore();
bool ScoreFormat(char PerSuSc[]);
//��ҳ
void FirstPage()
{
	//ֻҪ�������Ͷ�ȡ���ݡ�����ȡ��ǰNowStudentNums
	ReadInfor();

	//���ڴ�С
	initgraph(760, 760);
	//������1
	MOUSEMSG m1;


	cleardevice();
	IMAGE picture1;
	loadimage(&picture1, "./firstbc.jpg", 760, 760);
	putimage(0, 0, &picture1);
	setbkmode(TRANSPARENT);


	

	setfillcolor(GREEN);


	//�����
	char FirstTitle[20] = { "ѧ���ɼ�����ϵͳ" };
	settextstyle(60, 0, "����");
	outtextxy(150, 100, FirstTitle);

	//����ѡ��ı���
	fillrectangle(230, 445, 560, 490);
	fillrectangle(230, 505, 560, 550);
	fillrectangle(230, 565, 560, 610);

	setbkmode(TRANSPARENT);

	//����ѡ�������
	settextstyle(40, 0, "����");

	//����ѡ��
	char FirstSelect1[20] = { "����Ա��������" };
	char FirstSelect2[20] = { "��ͨ�û���������" };
	char FirstSelect3[20] = { "�˳�����" };
	outtextxy(240, 450, FirstSelect1);
	outtextxy(240, 510, FirstSelect2);
	outtextxy(240, 570, FirstSelect3);

	//����������ѡ���������
	while (1)
	{
		m1 = GetMouseMsg();//��ȡ������
		if (m1.x >= 230 && m1.x <= 560 && m1.y >= 445 && m1.y <= 490)//����Ա����
		{
			setlinecolor(RED);
			rectangle(230, 445, 560, 490);
			if (m1.uMsg == WM_LBUTTONDOWN)
			{
				//�������Ա��¼
				AdminSignIn();
			}
		}
		else if (m1.x >= 230 && m1.x <= 560 && m1.y >= 505 && m1.y <= 550)//��ͨ�û�����
		{
			setlinecolor(RED);
			rectangle(230, 505, 560, 550);
			if (m1.uMsg == WM_LBUTTONDOWN)
			{
				cleardevice();
				CommonUserPage();
			}
		}
		else if (m1.x >= 230 && m1.x <= 560 && m1.y >= 565 && m1.y <= 610)//�˳�
		{
			setlinecolor(RED);
			rectangle(230, 565, 560, 610);
			if (m1.uMsg == WM_LBUTTONDOWN)
			{
				exit(0);
			}
		}
		//��겻��������ͣ
		else
		{
			setlinecolor(WHITE);
			rectangle(230, 445, 560, 490);
			rectangle(230, 505, 560, 550);
			rectangle(230, 565, 560, 610);
		}
	}

}

//����Ա����
void AdminPage()
{
	initgraph(760, 760);
	//�����һ��
	cleardevice();
	//����ڶ���������
	MOUSEMSG m2;



	cleardevice();
	IMAGE picture1;
	loadimage(&picture1, "./firstbc.jpg", 760, 760);
	putimage(0, 0, &picture1);
	setfillcolor(GREEN);
	setbkmode(TRANSPARENT);

	char SecondTitle1[5] = { "��" };
	char SecondTitle2[5] = { "��" };
	char SecondTitle3[5] = { "Ա" };
	char SecondTitle4[5] = { "��" };
	char SecondTitle5[5] = { "��" };
	char SecondTitle6[5] = { "��" };
	char SecondTitle7[5] = { "��" };


	settextstyle(50, 0, "����");
	outtextxy(50, 150, SecondTitle1);
	outtextxy(50, 210, SecondTitle2);
	outtextxy(50, 270, SecondTitle3);
	outtextxy(50, 330, SecondTitle4);
	outtextxy(50, 390, SecondTitle5);
	outtextxy(50, 450, SecondTitle6);
	outtextxy(50, 510, SecondTitle7);


	setbkmode(TRANSPARENT);


	//����ѡ��ı���
	fillrectangle(230, 240, 560, 285);
	fillrectangle(230, 370, 560, 415);
	fillrectangle(230, 500, 560, 545);

	setbkmode(TRANSPARENT);

	//����ѡ�������
	settextstyle(40, 0, "����");

	//����ѡ��
	char SecondSelect1[20] = { "��ʾ��������" };
	char SecondSelect2[20] = { "��ɾ�������" };
	char SecondSelect3[20] = { "����" };


	outtextxy(270, 240, SecondSelect1);
	outtextxy(270, 370, SecondSelect2);
	outtextxy(350, 500, SecondSelect3);


	//����������ѡ���������
	while (1)
	{
		m2 = GetMouseMsg();//��ȡ������
		if (m2.x >= 230 && m2.x <= 560 && m2.y >= 240 && m2.y <= 285)
		{
			setlinecolor(RED);
			rectangle(230, 240, 560, 285);
			if (m2.uMsg == WM_LBUTTONDOWN)
			{
				//��ʾ��������
				FlagAI = 1;
				cleardevice();
				ShowAllInfor();

			}
		}
		else if (m2.x >= 230 && m2.x <= 560 && m2.y >= 370 && m2.y <= 415)
		{
			setlinecolor(RED);
			rectangle(230, 370, 560, 415);
			if (m2.uMsg == WM_LBUTTONDOWN)
			{
				//��ɾ��Ľ���
				cleardevice();
				AdDeSeMoPage();
			}
		}
		else if (m2.x >= 230 && m2.x <= 560 && m2.y >= 500 && m2.y <= 545)
		{
			setlinecolor(RED);
			rectangle(230, 500, 560, 545);
			if (m2.uMsg == WM_LBUTTONDOWN)
			{
				//����
				cleardevice();
				FirstPage();
			}
		}
		//��겻��������ͣ
		else
		{
			setlinecolor(WHITE);
			rectangle(230, 240, 560, 285);
			rectangle(230, 370, 560, 415);
			rectangle(230, 500, 560, 545);
		}
	}

}

//��ͨ�û�����
void CommonUserPage()
{
	initgraph(760, 760);////////////////////////////////////////////////////////////////�ǵ�ɾ

	//�����һ��
	cleardevice();
	//����ڶ���������
	MOUSEMSG m3;

	cleardevice();
	IMAGE picture1;
	loadimage(&picture1, "./firstbc.jpg", 760, 760);
	putimage(0, 0, &picture1);
	setbkmode(TRANSPARENT);



	setfillcolor(GREEN);


	char SecondTitle1[5] = { "��" };
	char SecondTitle2[5] = { "ͨ" };
	char SecondTitle3[5] = { "��" };
	char SecondTitle4[5] = { "��" };
	char SecondTitle5[5] = { "��" };
	char SecondTitle6[5] = { "��" };
	char SecondTitle7[5] = { "��" };
	char SecondTitle8[5] = { "��" };


	settextstyle(50, 0, "����");
	outtextxy(50, 150, SecondTitle1);
	outtextxy(50, 210, SecondTitle2);
	outtextxy(50, 270, SecondTitle3);
	outtextxy(50, 330, SecondTitle4);
	outtextxy(50, 390, SecondTitle5);
	outtextxy(50, 450, SecondTitle6);
	outtextxy(50, 510, SecondTitle7);
	outtextxy(50, 570, SecondTitle8);


	setbkmode(TRANSPARENT);


	//����ѡ��ı���

	fillrectangle(230, 240, 560, 285);
	fillrectangle(230, 370, 560, 415);
	fillrectangle(230, 500, 560, 545);

	setbkmode(TRANSPARENT);

	//����ѡ�������
	settextstyle(40, 0, "����");

	//����ѡ��
	char ThirdSelect1[20] = { "��ʾ��������" };
	char ThirdSelect2[20] = { "��ѯ����" };
	char ThirdSelect3[20] = { "����" };



	outtextxy(270, 240, ThirdSelect1);
	outtextxy(310, 370, ThirdSelect2);
	outtextxy(350, 500, ThirdSelect3);




	//����������ѡ���������
	while (1)
	{
		m3 = GetMouseMsg();//��ȡ������
		if (m3.x >= 230 && m3.x <= 560 && m3.y >= 240 && m3.y <= 285)//ѡ��1
		{
			setlinecolor(RED);
			rectangle(230, 240, 560, 285);
			if (m3.uMsg == WM_LBUTTONDOWN)
			{
				//��ʾ��������
				FlagAI = -1;
				cleardevice();
				ShowAllInfor();
			}
		}
		else if (m3.x >= 230 && m3.x <= 560 && m3.y >= 370 && m3.y <= 415)//ѡ��2
		{
			setlinecolor(RED);
			rectangle(230, 370, 560, 415);
			if (m3.uMsg == WM_LBUTTONDOWN)
			{
				//��ѯ����
				FlagFPT = -1;
				PrintFoudInfor();
				CommonUserPage();
			}
		}
		else if (m3.x >= 230 && m3.x <= 560 && m3.y >= 500 && m3.y <= 545)//ѡ��3��������
		{
			setlinecolor(RED);
			rectangle(230, 500, 560, 545);
			if (m3.uMsg == WM_LBUTTONDOWN)
			{
				cleardevice();
				FirstPage();
			}
		}
		//��겻��������ͣ
		else
		{
			setlinecolor(WHITE);
			rectangle(230, 240, 560, 285);
			rectangle(230, 370, 560, 415);
			rectangle(230, 500, 560, 545);
		}
	}
}

/*
	//////////////////////////////////����ʵ��//////////////////////////////////////
*/


//¼����Ϣ����ͨ����������&ϵͳ�Զ������ܷ�
void InputInfor()
{
	//InputBox�е����ֲ������������������ݵ�λ��


	//���ֿ����ظ�����ѧ�Ų����ظ�
	//ͨ��ѭ��������Ƿ����ظ���

	//����ѧ��
	while (1)
	{
		TCHAR InputWindow0[] = _T("�������ѧ����ѧ��");
		InputBox(StuArry[NowStudentNums].s_Num, 9, InputWindow0);

		int FlagInput2 = 0;
		//����������ַ�������
		int nums = strlen(StuArry[NowStudentNums].s_Num);
		//�ж�������Ƿ��Ǵ�����
		for (int i = 0; i < nums; i++)
		{
			if (StuArry[NowStudentNums].s_Num[i] >= '0' && StuArry[NowStudentNums].s_Num[i] <= '9')//�����������
			{

			}
			else
			{
				FlagInput2 = 1;
				HWND hwndInput2 = GetHWnd();
				int isok = MessageBox(hwndInput2, "�����ʽ��������������", "��ʾ", MB_OK);
				break;
			}
		}
		//�ж�������Ƿ��Ǵ�����
		for (int e = 0; e < nums; e++)
		{
			if (StuArry[NowStudentNums].s_Num[e] >= '0' && StuArry[NowStudentNums].s_Num[e] <= '9')//�����������
			{

			}
			else
			{
				FlagInput2 = 1;
				HWND hwndInput2 = GetHWnd();
				break;
				int isok = MessageBox(hwndInput2, "�����ʽ��������������", "��ʾ", MB_OK);
				
			}
		}

		if (FlagInput2 == 0)
		{
			//�ж��Ƿ������ظ�
			int FlagInput1 = 0;
			for (int i = 0; i < NowStudentNums; i++)
			{
				if (strcmp(StuArry[NowStudentNums].s_Num, StuArry[i].s_Num) == 0)
				{
					FlagInput1 = 1;
				}
			}
			if (FlagInput1 == 1)
			{
				HWND hwndInput1 = GetHWnd();
				int isok = MessageBox(hwndInput1, "��ѧ���Ѿ����ڣ�����������", "��ʾ", MB_OK);
			}
			if (FlagInput1 == 0)
			{
				break;
			}
		}
	}








	//��������
	TCHAR InputWindow1[] = _T("�������ѧ��������");
	InputBox(StuArry[NowStudentNums].s_Name, 10, InputWindow1);




	//�������ĳɼ�
	while (1)
	{
		TCHAR InputWindow2[] = _T("�������ѧ�������ĳɼ�");
		InputBox(StuArry[NowStudentNums].s_Chinese, 4, InputWindow2);

		if (ScoreFormat(StuArry[NowStudentNums].s_Chinese))//Ϊ������ѭ��
		{
			break;
		}
		
	}
	




	//������ѧ�ɼ�
	while (1)
	{
		TCHAR InputWindow3[] = _T("�������ѧ������ѧ�ɼ�");
		InputBox(StuArry[NowStudentNums].s_Math, 4, InputWindow3);

		if (ScoreFormat(StuArry[NowStudentNums].s_Math))//Ϊ������ѭ��
		{
			break;
		}

	}
	

	//����Ӣ��ɼ�
	while (1)
	{
		TCHAR InputWindow4[] = _T("�������ѧ����Ӣ��ɼ�");
		InputBox(StuArry[NowStudentNums].s_English, 4, InputWindow4);

		if (ScoreFormat(StuArry[NowStudentNums].s_English))//Ϊ������ѭ��
		{
			break;
		}

	}




	//�����ܷ�
	StuArry[NowStudentNums].s_SumScore =
		atof(StuArry[NowStudentNums].s_Chinese) +
		atof(StuArry[NowStudentNums].s_Math) +
		atof(StuArry[NowStudentNums].s_English);

	//��������
	SaveInfor();
}

//�ж�����ķ�����ʽ�Ƿ���ȷ
bool ScoreFormat(char PerSuSc[])
{
	//�ж�������Ƿ��Ǵ�����
	int nums = strlen(PerSuSc);
	//�ж�������Ƿ��Ǵ�����
	for (int i = 0; i < nums; i++)
	{
		if (PerSuSc[i] >= '0' && PerSuSc[i] <= '9')//�����������
		{
		}
		else
		{
			HWND hwndInput5 = GetHWnd();
			int isok = MessageBox(hwndInput5, "�����ʽ��������������", "��ʾ", MB_OK);
			return false;
		}
	}
	return true;
}

//��ɾ��Ľ���
void AdDeSeMoPage()
{


	//������
	MOUSEMSG SL;

	//Ĭ�Ͻ��ᰴ���ܷ�����


	initgraph(860, 760);

	


	cleardevice();
	IMAGE picture2;
	loadimage(&picture2, "./secondbc.jpg", 860, 760);
	putimage(0, 0, &picture2);
	setbkmode(TRANSPARENT);




	setfillcolor(GREEN);
	fillrectangle(690, 90, 850, 140);//��
	fillrectangle(690, 190, 850, 240);//ɾ
	fillrectangle(690, 290, 850, 340);//��
	fillrectangle(690, 390, 850, 440);//��
	fillrectangle(690, 490, 850, 540);//���
	fillrectangle(690, 590, 850, 640);//����

	//��ͷ���ֲ���
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "����");
	outtextxy(0, 0, "����");
	outtextxy(80, 0, "ѧ��");
	outtextxy(200, 0, "����");
	outtextxy(300, 0, "����");
	outtextxy(400, 0, "��ѧ");
	outtextxy(500, 0, "Ӣ��");
	outtextxy(600, 0, "�ܷ�");
	outtextxy(740, 0, "ѡ��");
	outtextxy(740, 100, "���");
	outtextxy(740, 200, "ɾ��");
	outtextxy(740, 300, "����");
	outtextxy(740, 400, "�޸�");
	outtextxy(740, 500, "���");
	outtextxy(740, 600, "����");


	//��ӡ��ǰ�Ѿ��е���Ϣ������¼Ϊ�յ���ʾҲ��������
	S1mplePrint();

	//��������������
	while (1)
	{
		SL = GetMouseMsg();
		if (SL.x >= 690 && SL.x <= 850 && SL.y >= 90 && SL.y <= 140)
		{

			setlinecolor(RED);
			rectangle(690, 90, 850, 140);
			if (SL.uMsg == WM_LBUTTONDOWN)
			{
				//���
				InputInfor();
				cleardevice();
				//��ɲ����������롪��ˢ��
				AdDeSeMoPage();
			}
		}
		else if (SL.x >= 690 && SL.x <= 850 && SL.y >= 190 && SL.y <= 240)
		{

			setlinecolor(RED);
			rectangle(690, 190, 850, 240);
			if (SL.uMsg == WM_LBUTTONDOWN)
			{
				//ɾ��
				DeSomeStu();
				//��ɲ����������롪��ˢ��
				AdDeSeMoPage();
			}
		}
		else if (SL.x >= 690 && SL.x <= 850 && SL.y >= 290 && SL.y <= 340)
		{

			setlinecolor(RED);
			rectangle(690, 290, 850, 340);
			if (SL.uMsg == WM_LBUTTONDOWN)
			{
				FlagFPT = 1;
				//��ѯ
				PrintFoudInfor();
				//��ɲ����������롪��ˢ��
				AdDeSeMoPage();
			}
		}
		else if (SL.x >= 690 && SL.x <= 850 && SL.y >= 390 && SL.y <= 440)
		{
			setlinecolor(RED);
			rectangle(690, 390, 850, 440);
			if (SL.uMsg == WM_LBUTTONDOWN)
			{
				//�޸�
				ModifyStudInfor();
				//��ɲ����������롪��ˢ��
				AdDeSeMoPage();
			}
		}
		else if (SL.x >= 690 && SL.x <= 850 && SL.y >= 490 && SL.y <= 540)
		{
			setlinecolor(RED);
			rectangle(690, 490, 850, 540);
			if (SL.uMsg == WM_LBUTTONDOWN)
			{
				//ȷ����ɾ��������������ʾ
				HWND hwndDel = GetHWnd();
				int isok = MessageBox(hwndDel, "ȷ�����?", "��ʾ", MB_OKCANCEL);
				if (isok == IDOK)
				{
					//������պ���
					DeleteStuInfor();
					//��ɲ����������롪��ˢ��
					AdDeSeMoPage();
					//������ʾ
					int tips1 = MessageBox(hwndDel, "��ճɹ���", "��ʾ", MB_OK);
				}
				else if (isok == IDCANCEL)
				{
					//���ȡ��������Ӧ
				}
			}
		}
		else if (SL.x >= 690 && SL.x <= 850 && SL.y >= 590 && SL.y <= 640)
		{
			//����
			setlinecolor(RED);
			rectangle(690, 590, 850, 640);
			if (SL.uMsg == WM_LBUTTONDOWN)
			{
				cleardevice();
				//��ɲ����������롪��ˢ��
				AdminPage();


				//�������ԡ�����ʾ��ǰ����
				/*char temptps[5];
				sprintf(temptps, "%d", NowStudentNums);


				HWND hwndTemp = GetHWnd();
				int tips2 = MessageBox(hwndTemp, temptps, "��ʾ", MB_OK);*/
			}
		}
		//��겻��ͣ
		else
		{
			setlinecolor(WHITE);
			rectangle(690, 90, 850, 140);//��
			rectangle(690, 190, 850, 240);//ɾ
			rectangle(690, 290, 850, 340);//��
			rectangle(690, 390, 850, 440);//��
			rectangle(690, 490, 850, 540);//���
			rectangle(690, 590, 850, 640);//����

		}
	}
}

//�������ݵ��ļ���
void SaveInfor()
{


	//���ѧ�ź����������ǿյĲ�д���ļ�
	if (strlen(StuArry[NowStudentNums].s_Num) != 0 && strlen(StuArry[NowStudentNums].s_Name) != 0)
	{
		FILE* fp = fopen("StudentInforFile.txt", "a");
		if (fp == NULL)
		{
			return;
		}
		fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%lf\n",
			StuArry[NowStudentNums].s_Num,
			StuArry[NowStudentNums].s_Name,
			StuArry[NowStudentNums].s_Chinese,
			StuArry[NowStudentNums].s_Math,
			StuArry[NowStudentNums].s_English,
			StuArry[NowStudentNums].s_SumScore);
		fclose(fp);
		//�����������++
		NowStudentNums++;
	}



}

//Ĩ��ȫ�������ٱ��桪����Ҫ�����޸Ĺ���
void SaveInforModi()
{
	//��ɾ�������ǲ��������ÿ����Բ��ܵ���֮ǰ��ɾ������
	remove("StudentInforFile.txt");
	//���ѧ�ź����������ǿյĲ�д���ļ�
	FILE* fp = fopen("StudentInforFile.txt", "a");
	if (fp == NULL)
	{
		return;
	}
	for (int i = 0; i < NowStudentNums; i++)
	{
		if (strlen(StuArry[i].s_Num) != 0 && strlen(StuArry[i].s_Name) != 0)
		{

			fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%lf\n",
				StuArry[i].s_Num,
				StuArry[i].s_Name,
				StuArry[i].s_Chinese,
				StuArry[i].s_Math,
				StuArry[i].s_English,
				StuArry[i].s_SumScore);
		}
	}

	fclose(fp);
}

//��ȡ�ļ��е���Ϣ-ͬ������ǰ�ṹ��������,��ͬ���õ�NowStudentNums
void ReadInfor()
{
	FILE* fp = fopen("StudentInforFile.txt", "r");
	if (fp == NULL)
	{
		return;
	}
	//���ļ��е����ݶ�ȡ����ǰ�Ľṹ��������
	for (int i = 0; i < RecordNums; i++)
	{

		fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%lf\t\n",
			StuArry[i].s_Num,
			StuArry[i].s_Name,
			StuArry[i].s_Chinese,
			StuArry[i].s_Math,
			StuArry[i].s_English,
			&StuArry[i].s_SumScore);
	}

	int FileStudentNums = 0;//�����ȵõ��ļ��е�����

	//��ȡ���ļ������ݵ���������
	for (int k = 0; k < RecordNums; k++)
	{
		if (strlen(StuArry[k].s_Name) != 0)
		{
			//��ǰ��������FileStudentNums������ȫ�ֱ����������ζ�ȡ��ʱ����������
			NowStudentNums = ++FileStudentNums;
		}
	}
	fclose(fp);
}

//������ա���ɾ���ļ�
void DeleteStuInfor()
{
	//ɾ���ļ�
	remove("StudentInforFile.txt");
	//�ÿյ�ǰ����
	NowStudentNums = 0;
}

//ͨ�õĵ�������Ļ�ϵĶ�Ӧλ�ô�ӡ���ṹ���е�ÿһ��Ԫ��
void S1mplePrint()
{
	//���Ϊ�վͲ�����ִ��
	if (NowStudentNums == 0)
	{

		settextstyle(50, 0, "����");
		outtextxy(200, 200, "��ǰ��¼Ϊ��!");
		return;
	}

	for (int q = 1; q <= NowStudentNums; q++)
	{


		//˳��
		settextstyle(30, 0, "����");
		char Nums[5];
		sprintf(Nums, "%d", q);

		//��������
		settextstyle(25, 0, "����");
		//ѧ��

		outtextxy(80, 40 + 40 * q, StuArry[q - 1].s_Num);
		//����
		outtextxy(200, 40 + 40 * q, StuArry[q - 1].s_Name);
		//���ĳɼ�
		outtextxy(300, 40 + 40 * q, StuArry[q - 1].s_Chinese);
		//��ѧ�ɼ�
		outtextxy(400, 40 + 40 * q, StuArry[q - 1].s_Math);
		//Ӣ��ɼ�
		outtextxy(500, 40 + 40 * q, StuArry[q - 1].s_English);
		//����ܷ�
		if (strlen(StuArry[q - 1].s_Name) != 0)
		{
			outtextxy(0, 40 + 40 * q, Nums);
			char SuSo[20];
			sprintf(SuSo, "%.2f", StuArry[q - 1].s_SumScore);//С���������λ
			outtextxy(600, 40 + 40 * q, SuSo);
		}
	}
}

//��ʾ��������-ͨ��
void ShowAllInfor()
{

	//������
	MOUSEMSG SA;
	initgraph(860, 760);
	//Ĭ��ֻ�Ǵ�ӡ���ݵ���Ļ��
	cleardevice();
	IMAGE picture2;
	loadimage(&picture2, "./secondbc.jpg", 860, 760);
	putimage(0, 0, &picture2);

	setfillcolor(GREEN);
	setbkmode(TRANSPARENT);




	fillrectangle(690, 90, 850, 140);
	fillrectangle(690, 190, 850, 240);
	fillrectangle(690, 290, 850, 340);
	fillrectangle(690, 390, 850, 440);
	fillrectangle(690, 590, 850, 640);



	//��ͷ���ֲ���
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "����");
	outtextxy(0, 0, "����");
	outtextxy(80, 0, "ѧ��");
	outtextxy(200, 0, "����");
	outtextxy(300, 0, "����");
	outtextxy(400, 0, "��ѧ");
	outtextxy(500, 0, "Ӣ��");
	outtextxy(600, 0, "�ܷ�");
	outtextxy(700, 0, "����ʽ");
	outtextxy(700, 100, "����������");
	outtextxy(700, 200, "����ѧ����");
	outtextxy(700, 300, "��Ӣ������");
	outtextxy(700, 400, "���ܷ�����");

	outtextxy(740, 600, "����");

	S1mplePrint();//Ĭ��ֻ�ǵ����Ĵ�ӡ

	while (1)
	{
		SA = GetMouseMsg();
		if (SA.x >= 690 && SA.x <= 850 && SA.y >= 90 && SA.y <= 140)
		{
			//��������
			setlinecolor(RED);
			rectangle(690, 90, 850, 140);
			if (SA.uMsg == WM_LBUTTONDOWN)
			{
				SortAcChinese();
				//ˢ����������
				ShowAllInfor();

			}
		}
		else if (SA.x >= 690 && SA.x <= 850 && SA.y >= 190 && SA.y <= 240)
		{
			//����ѧ��
			setlinecolor(RED);
			rectangle(690, 190, 850, 240);
			if (SA.uMsg == WM_LBUTTONDOWN)
			{
				SortAcMath();
				//ˢ����������
				ShowAllInfor();
			}
		}
		else if (SA.x >= 690 && SA.x <= 850 && SA.y >= 290 && SA.y <= 340)
		{
			//��Ӣ����
			setlinecolor(RED);
			rectangle(690, 290, 850, 340);
			if (SA.uMsg == WM_LBUTTONDOWN)
			{
				SortAcEnglish();
				//ˢ����������
				ShowAllInfor();
			}
		}
		else if (SA.x >= 690 && SA.x <= 850 && SA.y >= 390 && SA.y <= 440)
		{
			//�����ܷ���
			setlinecolor(RED);
			rectangle(690, 390, 850, 440);
			if (SA.uMsg == WM_LBUTTONDOWN)
			{
				SortAcSumScore();
				//ˢ����������
				ShowAllInfor();
			}

		}
		else if (SA.x >= 690 && SA.x <= 850 && SA.y >= 590 && SA.y <= 640)
		{
			//����
			setlinecolor(RED);
			rectangle(690, 590, 850, 640);
			if (SA.uMsg == WM_LBUTTONDOWN)
			{
				cleardevice();
				//�жϴ��ĸ����ڵ������
				if (FlagAI == 1)
				{
					AdminPage();
				}
				else if (FlagAI == -1)
				{
					CommonUserPage();
				}

			}
		}
		else
		{
			setlinecolor(WHITE);
			rectangle(690, 90, 850, 140);
			rectangle(690, 190, 850, 240);
			rectangle(690, 290, 850, 340);
			rectangle(690, 390, 850, 440);
			rectangle(690, 590, 850, 640);

		}

	}

}

//����Ҫ����/�޸�/ɾ�������ڽṹ����±�
int ReturnPosi()
{
	//�����û�����
	char ReceInput[64];
	TCHAR InputWindowFI[] = _T("������ѧ�Ż�����������(����)(�޸�)(ɾ��)");
	InputBox(ReceInput, 10, InputWindowFI);

	//����ѭ�����ң�һ����ͬ������ѭ��
	for (int w = 0; w < NowStudentNums; w++)
	{
		if (strcmp(StuArry[w].s_Name, ReceInput) == 0 || strcmp(StuArry[w].s_Num, ReceInput) == 0)//����0��ʾ�����ַ������
		{
			return w;
		}
	}
	//���û�ҵ����˾ͷ���-1
	return -1;
}


//��ӡ�ҵ��� ����Ϣ
void PrintFoudInfor(int Position)
{
	//������
	MOUSEMSG PFI;
	initgraph(860, 760);

	



	cleardevice();
	IMAGE picture2;
	loadimage(&picture2, "./secondbc.jpg", 860, 760);
	putimage(0, 0, &picture2);

	
	

	setfillcolor(GREEN);
	fillrectangle(690, 590, 850, 640);
	setbkmode(TRANSPARENT);

	//��ͷ���ֲ���
	settextstyle(30, 0, "����");
	outtextxy(40, 100, "ѧ��");
	outtextxy(200, 100, "����");
	outtextxy(300, 100, "����");
	outtextxy(400, 100, "��ѧ");
	outtextxy(500, 100, "Ӣ��");
	outtextxy(600, 100, "�ܷ�");
	outtextxy(740, 600, "����");

	//��ӡ�������˵���Ϣ


	//ѧ��
	outtextxy(40, 140, StuArry[Position].s_Num);
	//����
	outtextxy(200, 140, StuArry[Position].s_Name);
	//���ĳɼ�
	outtextxy(300, 140, StuArry[Position].s_Chinese);
	//��ѧ�ɼ�
	outtextxy(400, 140, StuArry[Position].s_Math);
	//Ӣ��ɼ�
	outtextxy(500, 140, StuArry[Position].s_English);
	//����ܷ�
	char SuSo[20];
	sprintf(SuSo, "%.2f", StuArry[Position].s_SumScore);//С���������λ
	outtextxy(600, 140, SuSo);

	while (1)
	{
		PFI = GetMouseMsg();
		if (PFI.x >= 690 && PFI.x <= 850 && PFI.y >= 590 && PFI.y <= 640)
		{
			//����
			setlinecolor(RED);
			rectangle(690, 590, 850, 640);
			if (PFI.uMsg == WM_LBUTTONDOWN)
			{
				cleardevice();
				if (FlagFPT == 1)
				{
					AdDeSeMoPage();
				}
				else if (FlagFPT = -1)
				{
					CommonUserPage();
				}
			}
		}
		//��겻��ѡ����
		else
		{
			setlinecolor(WHITE);
			rectangle(690, 590, 850, 640);
		}

	}
}


//��ѯ��������������յĵ���
void PrintFoudInfor()
{
	//����һ���������������±�
	int TempPosi = ReturnPosi();
	if (TempPosi == -1)//û�ҵ�
	{
		//��ȡ���ھ��
		HWND hndtipsF = GetHWnd();
		//��һ���ַ��������ܽ����
		int isok = MessageBox(hndtipsF, "���޴���!", "��ʾ", MB_OK);
	}
	else//�ҵ��ˡ�����ӡ���
	{
		cleardevice();
		PrintFoudInfor(TempPosi);
	}
}

//�޸�ѧ����Ϣ���ҵ������±꣬���¸�����ֵ�����棬����ֱ�ӵ�������
void ModifyStudInfor()
{
	//ֱ������������ҵĲ������ڴ˻����ϼ�һ���޸�ǰ
	//��Ϊ��Ҫ�õ�Ҫ�޸����ڽṹ�������е�λ��-�±꣬���Բ��ܽ�����ֱ���ù����ã���ճ������
	//����һ���������������±�
	int TempModi = ReturnPosi();
	if (TempModi == -1)//û�ҵ�
	{
		//��ȡ���ھ��
		HWND hndtipsM = GetHWnd();
		//��һ���ַ��������ܽ����
		int isok = MessageBox(hndtipsM, "���޴���!", "��ʾ", MB_OK);
	}
	else//�ҵ������ѧ����������Ĳ���
	{
		cleardevice();
		//������
		MOUSEMSG Modi;
		initgraph(860, 760);



		IMAGE picture2;
		loadimage(&picture2, "./secondbc.jpg", 860, 760);
		putimage(0, 0, &picture2);


		setfillcolor(GREEN);
		fillrectangle(690, 590, 850, 640);

		//��ͷ���ֲ���
		setbkmode(TRANSPARENT);
		settextstyle(50, 0, "����");
		outtextxy(40, 40, "�޸�ǰ");
		outtextxy(40, 240, "�޸ĺ�");
		settextstyle(30, 0, "����");
		outtextxy(40, 100, "ѧ��");
		outtextxy(200, 100, "����");
		outtextxy(300, 100, "����");
		outtextxy(400, 100, "��ѧ");
		outtextxy(500, 100, "Ӣ��");
		outtextxy(600, 100, "�ܷ�");
		outtextxy(740, 600, "����");

		outtextxy(40, 300, "ѧ��");
		outtextxy(200, 300, "����");
		outtextxy(300, 300, "����");
		outtextxy(400, 300, "��ѧ");
		outtextxy(500, 300, "Ӣ��");
		outtextxy(600, 300, "�ܷ�");

		//��ӡ�������˵���Ϣ
		//ѧ��
		outtextxy(40, 140, StuArry[TempModi].s_Num);
		//����
		outtextxy(200, 140, StuArry[TempModi].s_Name);
		//���ĳɼ�
		outtextxy(300, 140, StuArry[TempModi].s_Chinese);
		//��ѧ�ɼ�
		outtextxy(400, 140, StuArry[TempModi].s_Math);
		//Ӣ��ɼ�
		outtextxy(500, 140, StuArry[TempModi].s_English);
		//����ܷ�
		if (strlen(StuArry[TempModi].s_Name) != 0)
		{
			char SuSo1[20];
			sprintf(SuSo1, "%.2f", StuArry[TempModi].s_SumScore);//С���������λ
			outtextxy(600, 140, SuSo1);
		}







		//�������뵯������������д����

		//�޸�ѧ��
		while (1)
		{
			//���ڽ��������ѧ�ţ��ȸ��ǽ�ȥ
			char TempModiNums[64];

			TCHAR InputWindow0[] = _T("�������ѧ����ѧ��");
			InputBox(TempModiNums, 9, InputWindow0);

			if (strcmp(TempModiNums,StuArry[TempModi].s_Num)==0)//��������ѧ�źͱ���λ�õ�ѧ����ͬ
			{
				//�������仯,ֱ��break
				break;
			}
			else//��������ѧ�źͱ���λ�õ�ѧ�Ų�ͬ������Ҫ�ж��������ṹ�����Ƿ����ظ���
			{
				int FlagInput3 = 0;

				int nums = strlen(TempModiNums);

				//�ж�������Ƿ��Ǵ�����
				for (int i = 0; i < nums; i++)
				{
					if (TempModiNums[i] >= '0' && TempModiNums[i] <= '9')//�����������
					{

					}
					else
					{
						FlagInput3 = 1;
						HWND hwndInput3 = GetHWnd();
						int isok = MessageBox(hwndInput3, "�����ʽ��������������", "��ʾ", MB_OK);
						break;
					}
				}

				if (FlagInput3 == 0)
				{
					//Ϊʲô�����������ѧ�ţ�����ʾ�ڽṹ�������д��ڣ�
					//��Ϊ�����޸ĺ��������������ѧ���Ѿ����ǵ�����Ӧ��ȡ��λ�ã�
					/*
					˼·1.�ȱ��Ҫ�õ�ֵ���ǽ�ȥ���Ƚ����ж�
							�ж���ɷ�����������ٰ�ֵ��������
					˼·2.��ԭ����ѧ���ṹ�����鸴��һ��
							 ���µĽṹ�������б����ж�


							 //����ѡ���һ��
					*/
					//�ж��Ƿ������ظ�
					int FlagInput4 = 0;
					for (int i = 0; i < NowStudentNums; i++)
					{
						if (strcmp(TempModiNums, StuArry[i].s_Num) == 0)
						{
							FlagInput4 = 1;
							break;
						}
					}
					if (FlagInput4 == 1)
					{
						HWND hwndInput4 = GetHWnd();
						int isok = MessageBox(hwndInput4, "��ѧ���Ѿ����ڣ�����������", "��ʾ", MB_OK);
					}
					else if (FlagInput4 == 0)
					{
						//����
						memcpy(TempModiNums, StuArry[TempModi].s_Num, nums);
						break;
					}
				}
			}
		}

		//�޸�����
		TCHAR InputWindow1[] = _T("�������ѧ��������");
		InputBox(StuArry[TempModi].s_Name, 10, InputWindow1);

		//�������ĳɼ�
		while (1)
		{
			TCHAR InputWindow2[] = _T("�������ѧ�������ĳɼ�");
			InputBox(StuArry[TempModi].s_Chinese, 4, InputWindow2);

			if (ScoreFormat(StuArry[TempModi].s_Chinese))//Ϊ������ѭ��
			{
				break;
			}

		}





		//������ѧ�ɼ�
		while (1)
		{
			TCHAR InputWindow3[] = _T("�������ѧ������ѧ�ɼ�");
			InputBox(StuArry[TempModi].s_Math, 4, InputWindow3);

			if (ScoreFormat(StuArry[TempModi].s_Math))//Ϊ������ѭ��
			{
				break;
			}

		}


		//����Ӣ��ɼ�
		while (1)
		{
			TCHAR InputWindow4[] = _T("�������ѧ����Ӣ��ɼ�");
			InputBox(StuArry[TempModi].s_English, 4, InputWindow4);

			if (ScoreFormat(StuArry[TempModi].s_English))//Ϊ������ѭ��
			{
				break;
			}

		}

		//�����ܷ�
		StuArry[TempModi].s_SumScore =
			atof(StuArry[TempModi].s_Chinese) +
			atof(StuArry[TempModi].s_Math) +
			atof(StuArry[TempModi].s_English);

		//��ӡ�������˵���Ϣ
		//ѧ��
		outtextxy(40, 340, StuArry[TempModi].s_Num);
		//����
		outtextxy(200, 340, StuArry[TempModi].s_Name);
		//���ĳɼ�
		outtextxy(300, 340, StuArry[TempModi].s_Chinese);
		//��ѧ�ɼ�
		outtextxy(400, 340, StuArry[TempModi].s_Math);
		//Ӣ��ɼ�
		outtextxy(500, 340, StuArry[TempModi].s_English);
		//����ܷ�-��һ����������
		if (strlen(StuArry[TempModi].s_Name) != 0)
		{
			char SuSo2[20];
			sprintf(SuSo2, "%.2lf", StuArry[TempModi].s_SumScore);//С���������λ
			outtextxy(600, 340, SuSo2);
		}

		//�����ļ�
		SaveInforModi();





		while (1)
		{
			Modi = GetMouseMsg();
			if (Modi.x >= 690 && Modi.x <= 850 && Modi.y >= 590 && Modi.y <= 640)
			{
				//����
				setlinecolor(RED);
				setlinecolor(RED);

				rectangle(690, 590, 850, 640);
				if (Modi.uMsg == WM_LBUTTONDOWN)
				{
					cleardevice();
					//�ص���ɾ��Ľ���
					AdDeSeMoPage();

					//�������ԡ�����ʾ��ǰ����
					/*char temptps[5];
					sprintf(temptps, "%d", NowStudentNums);


					HWND hwndTemp = GetHWnd();
					int tips2 = MessageBox(hwndTemp, temptps, "��ʾ", MB_OK);*/
				}
			}
			//��겻��ͣ
			else
			{
				setlinecolor(WHITE);

				rectangle(690, 590, 850, 640);

			}
		}
	}
}

//ɾ��ĳ��ѧ������Ϣ
void DeSomeStu()
{
	//�Ƚ��в��ң��ҵ������±꣬Ȼ�����ν����±�����������ǰ�ƣ��������--
	//û�ҵ��Ͳ��޴���
	//����
	// 
	//��ΪҪʵ�ֵĹ��ܲ�ͬ�����Բ���ֱ�ӵ��ò��Һ���
	//����һ���������������±�
	int TempDelt = ReturnPosi();
	if (TempDelt == -1)//û�ҵ�
	{
		//��ȡ���ھ��
		HWND hndtipsD = GetHWnd();
		//��һ���ַ��������ܽ����
		int isok = MessageBox(hndtipsD, "���޴���!", "��ʾ", MB_OK);
	}
	else//�ҵ��ˣ�ȷ���Ƿ�ɾ��
	{
		//�ҵ��˾���ʾ�Ƿ�ȷ��ɾ��
		//��ȡ���ھ��
		//delete sure?
		HWND hndtipsDS = GetHWnd();
		//��һ���ַ��������ܽ����
		int isok = MessageBox(hndtipsDS, "ȷ��ɾ����", "��ʾ", MB_OKCANCEL);
		if (isok == IDOK)
		{
			//ȷ��ɾ������
			//�����Ԫ�صĺ�һ������Ǩ��
			for (int d = TempDelt; d < NowStudentNums - 1; d++)
			{
				StuArry[d] = StuArry[d + 1];
			}
			//���ڵ�����-1
			NowStudentNums--;
			//ɾ�����ֻ�ǽ���ǰ�ṹ���������������ˣ������ļ��в�û����������
			//���µ��ļ���
			SaveInforModi();//�����ȫ����յĺ������ٶ��ļ�������д
		}
		else if (isok == IDCANCEL)
		{
			//ȡ��ɾ����ִ���κβ���
		}
	}

}

//�������ĳɼ���������
void SortAcChinese()
{
	//ʹ��ð������������ĳɼ���ѧ����������


	//��ѭ����ÿ���˵ĳɼ�������ɼ��Ľṹ������
	for (int i = 0; i < NowStudentNums; i++)
	{
		SoArry[i].SuScore = atof(StuArry[i].s_Chinese);
	}
	//�Խṹ���������

	//ע��:���������ṹ���������ʱ����һ���ṹ�帨����һ���ṹ���������ʱ��
	//ע��������Ҫͬʱ�����仯�������ṹ�嶼��Ҫ�����仯�����۾���

	for (int r = 0; r < NowStudentNums; r++)
	{
		Score TempScore;
		Student TempStudent;
		for (int j = 1; j < NowStudentNums - r; j++)
		{
			if (SoArry[j - 1].SuScore < SoArry[j].SuScore)
			{
				TempScore = SoArry[j];
				TempStudent = StuArry[j];

				SoArry[j] = SoArry[j - 1];
				StuArry[j] = StuArry[j - 1];

				SoArry[j - 1] = TempScore;
				StuArry[j - 1] = TempStudent;
			}
		}
	}
	//���ñ��棬Ĭ���ǰ�����ӵ�˳������
}

//������ѧ�ɼ���������
void SortAcMath()
{
	//ÿ�θ��ɼ��ṹ�����鸳ֵ���ᱻ���¸���

	//��ѭ����ÿ���˵ĳɼ�������ɼ��Ľṹ������
	for (int i = 0; i < NowStudentNums; i++)
	{
		SoArry[i].SuScore = atof(StuArry[i].s_Math);
	}
	//�Խṹ���������

	//ע��:���������ṹ���������ʱ����һ���ṹ�帨����һ���ṹ���������ʱ��
	//ע��������Ҫͬʱ�����仯�������ṹ�嶼��Ҫ�����仯�����۾���

	for (int t = 0; t < NowStudentNums; t++)
	{
		Score TempScore;
		Student TempStudent;
		for (int j = 1; j < NowStudentNums - t; j++)
		{
			if (SoArry[j - 1].SuScore < SoArry[j].SuScore)
			{
				TempScore = SoArry[j];
				TempStudent = StuArry[j];

				SoArry[j] = SoArry[j - 1];
				StuArry[j] = StuArry[j - 1];

				SoArry[j - 1] = TempScore;
				StuArry[j - 1] = TempStudent;
			}
		}
	}
	//���ñ��棬Ĭ���ǰ�����ӵ�˳������
}

//����Ӣ��ɼ���������
void SortAcEnglish()
{
	//ÿ�θ��ɼ��ṹ�����鸳ֵ���ᱻ���¸���

	//��ѭ����ÿ���˵ĳɼ�������ɼ��Ľṹ������
	for (int i = 0; i < NowStudentNums; i++)
	{
		SoArry[i].SuScore = atof(StuArry[i].s_English);
	}
	//�Խṹ���������

	//ע��:���������ṹ���������ʱ����һ���ṹ�帨����һ���ṹ���������ʱ��
	//ע��������Ҫͬʱ�����仯�������ṹ�嶼��Ҫ�����仯�����۾���
	//��Ϊ˳����һ���ģ����԰����������һ��

	for (int y = 0; y < NowStudentNums; y++)
	{
		Score TempScore;
		Student TempStudent;
		for (int j = 1; j < NowStudentNums - y; j++)
		{
			if (SoArry[j - 1].SuScore < SoArry[j].SuScore)
			{
				TempScore = SoArry[j];
				TempStudent = StuArry[j];

				SoArry[j] = SoArry[j - 1];
				StuArry[j] = StuArry[j - 1];

				SoArry[j - 1] = TempScore;
				StuArry[j - 1] = TempStudent;
			}
		}
	}
	//���ñ��棬Ĭ���ǰ�����ӵ�˳������
}

//�����ֽܷ�������
void SortAcSumScore()
{
	for (int i = 0; i < NowStudentNums; i++)
	{
		Student TempStudent;
		for (int j = 1; j < NowStudentNums - i; j++)
		{
			if (StuArry[j - 1].s_SumScore < StuArry[j].s_SumScore)
			{

				TempStudent = StuArry[j];


				StuArry[j] = StuArry[j - 1];


				StuArry[j - 1] = TempStudent;
			}
		}
	}
}


//����Ա��¼
void AdminSignIn()
{
	//���ļ����˺ź����������
	FILE* fp = fopen("AdminSignIn.txt", "r");
	if (fp == NULL)
	{
		return;
	}
	//��ȡ����Ӧ�Ĺ���Ա�ṹ������
	fscanf(fp, "%s\t%s\t\n", AdminUser.UserName, AdminUser.PassWord);

	//�ر��ļ�
	fclose(fp);




	char ReceAcctNumber[64];
	TCHAR InputAcct[] = _T("�������û���");
	InputBox(ReceAcctNumber, 10, InputAcct);

	char ReceAcctPassWord[64];
	TCHAR InputPass[] = _T("����������");
	InputBox(ReceAcctPassWord, 10, InputPass);

	//����û��������붼��ȷ�Ž��ȵ�����Ա����
	//���򵯴���ʾ����
	if (strcmp(AdminUser.UserName, ReceAcctNumber) == 0 && strcmp(AdminUser.PassWord, ReceAcctPassWord) == 0)
	{
		cleardevice();
		AdminPage();
	}
	else
	{
		HWND SignError = GetHWnd();
		int isok = MessageBox(SignError, "�û������������!", "��ʾ", MB_OK);
	}
}



int main(void)
{
	FirstPage();
	return 0;
}