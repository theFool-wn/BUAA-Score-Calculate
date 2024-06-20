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


double grade = 0;		//单科成绩 
double credit = 0;	//单科学分 
double gpa = 0;		//单科gpa 

int index = 0;
double GPA, ave_grade, weight_ave_grade;
double sum = 0;			//分数和 
double sum_weight = 0;	//加权分数和 
double sum_gpa = 0;		//加权GPA和 
double sum_credit = 0;	//学分和 


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
		printf("成绩计算\n\n\n");
		printf("\t全部课程：");
		printf("\t算数平均分：%.5lf\n", ave_grade);
		printf("\t\t\t加权平均分：%.5lf\n", weight_ave_grade);
		printf("\t\t\t       GPA：%lf\n", GPA);
		printf("\n\n");
	}
	else
	{
		printf("\t必修课程：");
		printf("\t算数平均分：%.5lf\n", ave_grade);
		printf("\t\t\t加权平均分：%.5lf\n", weight_ave_grade);
		printf("\t\t\t       GPA：%lf\n\n\n", GPA);
	}
}

void setWindows()
{
	system("title 成绩计算——by WangNan");	//标题 
	system("mode con cols=53 lines=14");	//大小 
	system("color F0");	//颜色 
	
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);	//去除光标 
	
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hStdin, &mode);
	mode &= ~ENABLE_QUICK_EDIT_MODE;
	SetConsoleMode(hStdin, mode);	//关闭快速编辑模式 
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
