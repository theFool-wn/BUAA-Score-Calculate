/**
 * @       Project: BUAA Score Calculate.c
 * @        Author: WangNan
 * @ Creation Date: 2021.01.06 20:01
 * @   Update Date: 2024.06.21 01:58
 * @       Version: 5.0
 * @   Description: -std ISO C99
**/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>


double grade = 0;		//���Ƴɼ� 
double credit = 0;	//����ѧ�� 
double gpa = 0;		//����gpa 

int index = 0;
double GPA, ave_grade, weight_ave_grade;
double sum = 0;			//������ 
double sum_weight = 0;	//��Ȩ������ 
double sum_gpa = 0;		//��ȨGPA�� 
double sum_credit = 0;	//ѧ�ֺ� 


void score_calc(double grade, double credit)
{
	if(grade<0||grade>100||credit<=0)
	{
		system("color F4");
		printf("\n\n\n\n\n\t\t      ERROR!!!!\n\n\n");
		printf("\t      YOUR DATA IS INCORRECT!!!!\n\n\n\n\n");
		
		system("pause");
		exit(1);
	}
	
	sum += grade;
	sum_credit += credit;
	sum_weight += grade*credit;
	
	if(grade<60)
	{
		gpa=0;
	}
	else
	{
		gpa=4.0-3.0/1600.0*(100-grade)*(100-grade);
	}
	
	sum_gpa += gpa*credit;
	index++;
}

void getData(char* buffer)
{
	char* num = strtok(buffer, " ");

	while(num)
    {
    	grade = atof(num);
        num = strtok(NULL, " ");
        
        credit = atof(num);
        num = strtok(NULL, " ");
        score_calc(grade, credit);
    }
}

int fsize(FILE* fp)
{
	int n;
	fpos_t fpos;
	fgetpos(fp, &fpos);
	fseek(fp, 0, SEEK_END);
	n = ftell(fp);
	fsetpos(fp, &fpos);
	
	return n;
}

void input(const char* filename)
{
	FILE* fp = fopen(filename, "r");
	
	int fn = fsize(fp);
	char buffer[fn];
	
	while(!feof(fp))
	{
		fgets(buffer, (int)sizeof(buffer), fp);
		getData(buffer);
	}
	
	fclose(fp);
}

void GPA_calc()
{
	ave_grade = sum / index;
    weight_ave_grade = sum_weight / sum_credit;
    GPA = sum_gpa / sum_credit;
}

void print(int flag)
{
	if(flag == 1)
	{
		printf("�ɼ�����\n\n\n");
		printf("\tȫ���γ̣�");
		printf("\t����ƽ���֣�%.5lf\n", ave_grade);
		printf("\t\t\t��Ȩƽ���֣�%.5lf\n", weight_ave_grade);
		printf("\t\t\t       GPA��%lf\n", GPA);
		printf("\n\n");
	}
	else
	{
		printf("\t���޿γ̣�");
		printf("\t����ƽ���֣�%.5lf\n", ave_grade);
		printf("\t\t\t��Ȩƽ���֣�%.5lf\n", weight_ave_grade);
		printf("\t\t\t       GPA��%lf\n\n\n", GPA);
	}
}

void setWindows()
{
	system("title �ɼ����㡪��by WangNan");	//���� 
	system("mode con cols=53 lines=14");	//��С 
	system("color F0");	//��ɫ 
	
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);	//ȥ����� 
	
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hStdin, &mode);
	mode &= ~ENABLE_QUICK_EDIT_MODE;
	SetConsoleMode(hStdin, mode);	//�رտ��ٱ༭ģʽ 
}

int main()
{
	setWindows();
	
	char name[8] = "in";
	char* extension = ".txt";
	
	for(int i = 1; i < 3; i++)
	{
		grade = 0;
		credit = 0;
		gpa = 0;
		index = 0;
		sum = 0;
		sum_weight = 0;
		sum_gpa = 0;
		sum_credit = 0;
		
		name[2] = '\0';
		char temp[2];
		sprintf(temp, "%d", i);
		
		input(strcat(strcat(name, temp), extension));
		GPA_calc();
		print(i);
	}
	
	system("pause");

    return 0;
}
