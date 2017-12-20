#include<fstream>
#include<iostream>
#include<iomanip>
#include<string>

#define OK		1
#define ERROR	0
#define TRUE	1
#define FALSE	0
#define MAXSIZE_up 50
#define MAXSIZE_down 100
#define MAXSIZE 150
using namespace std;

typedef struct car {
    string ID;  //车牌号
    int rank;   //排队序号
    float cost; 
    int locate; //车位
    int dir;    //入口方向（0为南，1为北）
} car;

typedef int Status;
typedef car ElemType;

typedef struct Node {
    ElemType BMW;
    struct Node *next;
} Node, *Link;

typedef struct ParkNode {
    Link up, down; //up为上停车场头指针，down时下停车场头指针
} *Park;

/*Link In_deque;//在排队的车的链表

Link In_Park;//在停车场内的车

typedef struct Link             
{
	//排队进站
	car BWM;
	struct Link *next;
}*Link;*/


int place(Park In_Park);//查找第一个空出的车位

int Waiting(); //遍历在排队的车,返回最后一辆车的排位号i;

bool Park_up_empty();//第一层判空，空返回true

bool Park_up_full(Park P);//第一层判满

bool Park_down_empty();//第二层判空，空返回true

bool Park_full(Park In_Park); //车站满，返回true

float Cost(ElemType *e); //计算停车费用

Status Init_In_Park(Park *In_Park); //创建ParkLink//

Status Insert_In_Park(Park *In_Park, ElemType *e); //等候车辆链表删除，停车场链表插入//

Status Delete_In_Park(Link *In_Park, int i, ElemType *e);//停车链表删除//

Status Insert_pla(Link *L, int pla, ElemType e);

void Write_up(Link *up);

void Write_down(Link *down);

void read_up(Link *up);

void read_down(Link *down);

void Write_up_history(Link *up);

void Write_down_history(Link *down);
