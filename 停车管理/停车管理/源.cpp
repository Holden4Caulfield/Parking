#include<iostream>
#include<string>
using namespace std;
#define OK		1
#define ERROR	0
#define TRUE	1
#define FALSE	0

#define MAXSIZE 100

typedef struct car 
{
	string ID;  //车牌号
	int rank;   //排队序号
	float cost;
	int locate; //车位
	int dir;    //入口方向（0为南，1为北）
} car;

typedef struct Link             
{
	//排队进站
	car BWM;
	Link *next;
}*Link;

