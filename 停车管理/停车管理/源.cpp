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
	string ID;  //���ƺ�
	int rank;   //�Ŷ����
	float cost;
	int locate; //��λ
	int dir;    //��ڷ���0Ϊ�ϣ�1Ϊ����
} car;

typedef struct LNode             
{
	//�Ŷӽ�վ
	car BWM;
	struct LNode *next;
}*Link,LNode;
Link In_deque_north;//���Ŷӵĳ�������,north
Link In_deque_south;//���Ŷӵĳ�������,south
Link In_Park;//��ͣ�����ڵĳ�
int node;            //�жϳ����Ƿ���ڣ�����1������0
int place()
{
	//���ҵ�һ���ճ��ĳ�λ
	return 0;
}
int Waiting()
{
	//�������Ŷӵĳ�,�������һ��������λ��i;
	return 0;
}
bool Park_up_empty()
{
	//��һ���пգ��շ���true
	return true;
}
bool Park_down_empty()
{
	//�ڶ����пգ��շ���true
	return true;
}
bool Park_full()
{
	//��վ��������true
	return true;
}
int compare()
{
	//�Ͼ��ϱ���ڵ�һ�����Ŀ�ʼ�ȴ�ʱ�䣬�����Ƚ��������Ƚ����������
	return 0;
}
void goout()
{
	//ͣ�����ڳ���ʻ��
	cout << "1.��λ" << endl;
	cout << "2.����" << endl;
	string N; int locat,n;
	cin >> n;
	switch (n)
	{
	case 1:
	{
		LNode *p,*e;
		cout << "���복λ" << endl;
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
				cout << "ok���ó����Ѵ�ͣ����ʻ��" << endl;
				//node = 1;
				return;
			}
		}
	}break;
	case 2:
	{
		LNode *p, *e;
		cout << "���복��" << endl;
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
				cout << "ok,�ó����Ѵ�ͣ����ʻ��" << endl;
				//node = 1;
				return;
			}
		}
	}
		break;
	default:
		break;
	}
	cout << "�޴˳���Ϣ" << endl;
}
void In_deque(Link &In_deque_north,Link &In_deque_south)
{
	//����һ�����Ŷӵĳ���
	LNode *e; LNode *p;
	e = new LNode;
	cout << endl;
	cout << "�����복�� : "; cin >> e->BWM.ID;
	cout << "�����뷽��0Ϊ�ϣ�1Ϊ����"; cin >> e->BWM.dir;
	int i= Waiting();
	e->BWM.rank = i+1;
	e->BWM.locate = place();
	//�������β���
	if (e->BWM.dir)
	{
		//�ӱ���ڽ�
		p = In_deque_north;
		while (p ->next!= NULL)p = p->next;
		e->next = NULL;
		p->next = e;
	}
	else
	{
		//������ڽ�
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
	//����ϱ��ŶӶ���
	LNode *p,*q; p = In_deque_south->next;
	cout << endl;
	cout << "�����" << endl;
	while (p)
	{
		cout << p->BWM.ID << " ";
		p = p->next;
	}
	cout << endl<<endl;
	q = In_deque_north->next;
	cout << "�����" << endl;
	while (q)
	{
		cout << q->BWM.ID << " ";
		q = q->next;
	}
	cout << endl;
}
void Increase()
{
	//���Ӳ˵�
	int tap;
	if (Park_full())
	{
		cout << "��վ�����������о����뿪���ǵȴ�" << endl;
	}
	cout << "1.��ʼ�ȴ�" << endl;
	cout << "2.�����뿪��������һ��" << endl;
	cin >> tap;
	switch (tap)
	{
	case 1:In_deque(In_deque_north, In_deque_south); break;
	case 2:return;
	default:
		break;
	}
	cout << "OK" << endl;
	cout << "��ʼ�Ŷ�" << endl;
}
void delet_indeque(Link &In_deque_north, Link &In_deque_south)
{
	cout << "�����뿪�ĳ����ƺ�" << endl;
	string N;int direction,tap=0;
	cin >> N;
	cout << endl;
	cout << "���λ�ã���0��1��" << endl;
	cin >> direction;
	if (direction==1)
	{
		//����ڵĳ�
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
	cout << "�޸ó�����Ϣ" << endl;
}
void Decrease()
{
	//ɾ���˵�
	int tap;
	cout << "1.�Ŷӳ����뿪" << endl;
	cout << "2.������һ��" << endl;
	cin >> tap;
	switch (tap)
	{
	case 1:delet_indeque(In_deque_north, In_deque_south); break;
	case 2:return;
	default:
		break;
	}
	if(node)cout << "OK,�������Ѿ�����" << endl;
	if (node)node = 1;
	//cout << "�������Ѿ�����" << endl;
	
}
void menu()
{
	//�˵�
	int tap;
	In_deque_north = new LNode;
	In_deque_south = new LNode;
	In_deque_north->next = NULL; In_deque_south->next = NULL;
	cout << "1.�����Ŷӳ���" << endl;
	cout << "2.����ʻ��"<<endl;
	cout << "3.ɾ���뿪����" << endl;
	cout << "4.����ŶӶ���" << endl;
	cout << "10086.�˳�" << endl;
	//�����Ŷӳ���
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
		cout << "1.�����Ŷӳ���" << endl;
		cout << "2.����ʻ��" << endl;
		cout << "3.ɾ���뿪����" << endl;
		cout << "4.����ŶӶ���" << endl;
		cout << "10086.�˳�" << endl;
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

