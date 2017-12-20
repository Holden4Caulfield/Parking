#include"common.h"

Status Init_In_Park(Park *In_Park) {
    //初始化In_Park Link//
    Link up, down;

    *In_Park = new ParkNode;
    up = new Node;
    down = new Node;
    if(!(*In_Park && up && down))
        return ERROR;
    (*In_Park)->up = up;
    (*In_Park)->down = down;

    return OK;
}

Status Insert_In_Park(Park *In_Park, ElemType *e) {
    //等候车辆链表删除，停车场链表插入// //*//
    //开始计时//
    //修改车位// //*//
    //写入文件// //*//
    int pla = place(*In_Park);

    if(Park_full(*In_Park)) {  //上下停车场都满//
       std::cout << "停车场满" << std::endl;
       return ERROR;
    }

    if (!Park_up_full((*In_Park))) {//上停车场未满，车进入//
        Insert_pla(&(*In_Park)->up, pla, *e);
        Write_up(&(*In_Park)->up);
    }
    else {  //上停车场满，下停车场进
        Insert_pla(&(*In_Park)->down, pla - MAXSIZE_up,  *e);
         Write_down(&(*In_Park)->up);
    }
    (*e).locate = pla; //修改车位//

    /*开始计时 {}*/

    return OK;
}

Status Insert(Link *L, ElemType e) { //头插
    Link p, q;
    if(!(p = new Node))
        return ERROR;
    p->BMW = e;

    q = (*L)->next;
    (*L)->next = p;
    p->next = q;

    return OK;
}

Status Insert_pla(Link *L, int pla, ElemType e) { //插入车位
    Link p, q;
    int i = 1;

    if(!(q = new Node))
        return ERROR;
    q->BMW = e;

    for (p = *L; i < pla; i++) {
        p = p->next;
    }

    q->next = p->next;
    p->next = q;

    return OK;
}

Status Delete_In_Park(Park *In_Park) {
    //车开出停车场//
    //打印停车费用//

    int i,j;//i为要删除节点的位置
    Link p, q, r;
    std::string str;

    //std::cout << "请输入车牌号：" << std::endl;
    //std::cin >> str;
    //i = Search();//
    for (j = 0, r = (*In_Park)->up; r && j < i - 1;j++) //在上层查找
        r = r->next;
    if(r == NULL)   //如果在上层没找到
        for (r = (*In_Park)->down; r && j < i - 1;j++)
            r = r->next;
    p = r->next;

    Cost(&(p->BMW));
    std::cout << "停车费用为：" << (p->BMW).cost <<std::endl;

    q = p->next;
    r->next = p;
    return OK;
}

int place(Park In_Park) { //查找第一个空车位
    int i;
    Link p, q, r;

    if(!Park_up_full(In_Park)) {
        q = p = In_Park->up->next;
        q = q->next;
        if(p->BMW.locate != 1) 
            return 1;
        else
            while (q->BMW.locate - p->BMW.locate == 1) {
                q = q->next;
                p = p->next;
            }
        return p->BMW.locate + 1;
    }
    else {
        q = p = In_Park->down->next;
        q = q->next;
        if(p->BMW.locate != 1) 
            return 1 + MAXSIZE_up;
        else
            while (q->BMW.locate - p->BMW.locate == 1) {
                q = q->next;
                p = p->next;
            }
        return p->BMW.locate + 1 + MAXSIZE_up;
    }
}


bool Park_full(Park P)
{
    int i=0;
    Link pu,pd;
    pu=P->up;
    pd=P->down;
    while(pu->next)
        i+=1;
    while(pd->next)
        i+=1;
    if(i==(MAXSIZE_up+MAXSIZE_down))
        return TRUE;
    else
        return FALSE;
}

bool Park_up_full(Park P) {
    int i=0;
    Link pu;
    pu=P->up;
    while(pu->next)
        i+=1;
    if(i==(MAXSIZE_up))
        return TRUE;
    else
        return FALSE;
}

void Write_up(Link *up) {
    fstream ofile;
	ofile.open("up.txt",ios::ate|ios::out);
	Link p = new Node;
	p = *up;
	while(p) {
		ofile.write((char *)(&p),sizeof(Node));
		p = p->next;
	}
	ofile.close();
}

void Write_down(Link *down) {
    fstream ofile;
	ofile.open("up.txt",ios::ate|ios::out);
	Link p = new Node;
	p = *down;
	while(p) {
		ofile.write((char *)(&p),sizeof(Node));
		p = p->next;
	}
	ofile.close();
}

void read_up(Link *up) {
    fstream ifile("up.txt",ios::in);
	*up = new Node;
	ifile.read((char *)(&(*up)),sizeof(Node));
	ifile.close();
}

void read_down(Link *down) {
    fstream ifile("down.txt",ios::in);
	*down = new Node;
	ifile.read((char *)(&(*down)),sizeof(Node));
	ifile.close();
}

void Write_up_history(Link *up) {
    fstream ofile;
	ofile.open("up_history.txt",ios::ate|ios::out);
	Link p = new Node;
	p = *up;
	while(p) {
		ofile.write((char *)(&p),sizeof(Node));
		p = p->next;
	}
	ofile.close();

}
