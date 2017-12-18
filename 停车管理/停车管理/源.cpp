#include<iostream>
#include<stdlib.h>
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

typedef struct LNode             
{
	//排队进站
	car BWM;
	struct LNode *next;
}*Link,LNode;
Link In_deque_north;//在排队的车的链表,north
Link In_deque_south;//在排队的车的链表,south
Link In_Park;//在停车场内的车
int node;            //判断车辆是否存在，存在1，否则0
int place()
{
	//查找第一个空出的车位
	return 0;
}
int Waiting()
{
	//遍历在排队的车,返回最后一辆车的排位号i;
	return 0;
}
bool Park_up_empty()
{
	//第一层判空，空返回true
	return true;
}
bool Park_down_empty()
{
	//第二层判空，空返回true
	return true;
}
bool Park_full()
{
	//车站满，返回true
	return true;
}
int compare()
{
	//毕竟南北入口第一辆车的开始等待时间，先来先进，返回先进入的入口序号
	return 0;
}
void goout()
{
	//停车场内车辆驶出
	cout << "1.车位" << endl;
	cout << "2.车牌" << endl;
	string N; int locat,n;
	cin >> n;
	switch (n)
	{
	case 1:
	{
		LNode *p,*e;
		cout << "输入车位" << endl;
		cin >> locat;
		p = In_Park;
		while (p->next)
		{
			if (p->next->BWM.locate == locat)
			{
				e = p;
				e->next = p->next->next;
				//p = p->next;
				//free(p);
				cout << "ok，该车辆已从停车场驶出" << endl;
				//node = 1;
				return;
			}
		}
	}break;
	case 2:
	{
		LNode *p, *e;
		cout << "输入车牌" << endl;
		cin >> N;
		p = In_Park;
		while (p->next)
		{
			if (p->next->BWM.ID == N)
			{
				e = p;
				e->next = p->next->next;
				//p = p->next;
				//free(p);
				cout << "ok,该车辆已从停车场驶出" << endl;
				//node = 1;
				return;
			}
		}
	}
		break;
	default:
		break;
	}
	cout << "无此车信息" << endl;
}
void In_deque(Link &In_deque_north,Link &In_deque_south)
{
	//增加一辆在排队的车辆
	LNode *e; LNode *p;
	e = new LNode;
	cout << endl;
	cout << "请输入车牌 : "; cin >> e->BWM.ID;
	cout << "请输入方向（0为南，1为北）"; cin >> e->BWM.dir;
	int i= Waiting();
	e->BWM.rank = i+1;
	e->BWM.locate = place();
	//在链表表尾添加
	if (e->BWM.dir)
	{
		//从北入口进
		p = In_deque_north;
		while (p ->next!= NULL)p = p->next;
		e->next = NULL;
		p->next = e;
	}
	else
	{
		//从南入口进
		p = In_deque_south;
		while (p->next != NULL)p = p->next;
		e->next = NULL;;
		p->next = e;
	}
	e = NULL;
	delete e;
	//free(p);
}
void OutPut(Link &In_deque_north, Link &In_deque_south)
{
	//输出南北排队队列
	LNode *p,*q; p = In_deque_south->next;
	cout << endl;
	cout << "南入口" << endl;
	while (p)
	{
		cout << p->BWM.ID << " ";
		p = p->next;
	}
	cout << endl<<endl;
	q = In_deque_north->next;
	cout << "北入口" << endl;
	while (q)
	{
		cout << q->BWM.ID << " ";
		q = q->next;
	}
	cout << endl;
}
void Increase()
{
	//增加菜单
	int tap;
	if (Park_full())
	{
		cout << "车站已满，请自行决定离开还是等待" << endl;
	}
	cout << "1.开始等待" << endl;
	cout << "2.车辆离开，返回上一级" << endl;
	cin >> tap;
	switch (tap)
	{
	case 1:In_deque(In_deque_north, In_deque_south); break;
	case 2:return;
	default:
		break;
	}
	cout << "OK" << endl;
	cout << "开始排队" << endl;
}
void delet_indeque(Link &In_deque_north, Link &In_deque_south)
{
	cout << "输入离开的车车牌号" << endl;
	string N;int direction,tap=0;
	cin >> N;
	cout << endl;
	cout << "入口位置（南0北1）" << endl;
	cin >> direction;
	if (direction==1)
	{
		//北入口的车
		LNode *p,*e;
		p = In_deque_north;
		while (p->next)
		{
			if (p->next->BWM.ID == N)
			{
				e = p;
				e->next = p->next->next;
				//p = p->next;
				//free(p);
				cout << "ok" << endl;
				node = 1;
				return;
			}
		}
	}
	else
	{
		LNode *p, *e;
		p = In_deque_south;
		while (p->next)
		{
			if (p->next->BWM.ID == N)
			{
				e = p;
				e->next = p->next->next;
				//p = p->next;
				//free(p);
				cout << "ok" << endl;
				node = 1;
				return;
			}
			p = p->next;
		}
	}
	cout << "无该车辆信息" << endl;
}
void Decrease()
{
	//删除菜单
	int tap;
	cout << "1.排队车辆离开" << endl;
	cout << "2.返回上一级" << endl;
	cin >> tap;
	switch (tap)
	{
	case 1:delet_indeque(In_deque_north, In_deque_south); break;
	case 2:return;
	default:
		break;
	}
	if(node)cout << "OK,这辆车已经滚了" << endl;
	if (node)node = 1;
	//cout << "这辆车已经滚了" << endl;
	
}
void menu()
{
	//菜单
	int tap;
	In_deque_north = new LNode;
	In_deque_south = new LNode;
	In_deque_north->next = NULL; In_deque_south->next = NULL;
	cout << "1.增加排队车辆" << endl;
	cout << "2.车辆驶出"<<endl;
	cout << "3.删除离开车辆" << endl;
	cout << "4.输出排队队列" << endl;
	cout << "10086.退出" << endl;
	//增加排队车辆
	while (cin>>tap)
	{
		switch (tap)
		{
		case 1:Increase(); break;
		case 2:goout(); break;
		case 3:Decrease(); break;
		case 4:OutPut(In_deque_north, In_deque_south); break;
		case 10086:return;
		default:
			break;
		}
		cout << "1.增加排队车辆" << endl;
		cout << "2.车辆驶出" << endl;
		cout << "3.删除离开车辆" << endl;
		cout << "4.输出排队队列" << endl;
		cout << "10086.退出" << endl;
	}
	OutPut(In_deque_north, In_deque_south);
}
int main()
{
	menu();
	delete In_deque_north;
	delete In_deque_south;
	system("pause");
	return 0;
}

