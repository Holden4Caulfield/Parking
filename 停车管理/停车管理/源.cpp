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
	string ID;  //���ƺ�
	int rank;   //�Ŷ����
	float cost;
	int locate; //��λ
	int dir;    //��ڷ���0Ϊ�ϣ�1Ϊ����
} car;

typedef struct Link             
{
	//�Ŷӽ�վ
	car BWM;
	Link *next;
}*Link;

