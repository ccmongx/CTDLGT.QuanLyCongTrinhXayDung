#include "bits/stdc++.h"
using namespace std;

struct film{
    char name[30];
    char director[30];
    int year;
    char firm[30];
};

struct node{
    film data;
    struct node *next;
};

typedef struct node NODE;

struct lst{
    NODE*Head;
    NODE*Tail;
};

typedef struct lst L;

void iniLst(lst &L){
    L.Head=NULL;
    L.Tail=NULL;
}

NODE *iniNode(film x){
    NODE*p;
    p=new NODE();
    if(p==NULL) exit(1);

    p->data=x;
    p->next=NULL;
    return p;
}


NODE *iniLst(film x){
    NODE*p=new NODE;
    if (p==NULL) exit(1);
    else{
        p->data=x;
        p->next=NULL;
        return p;
    }
    
}

void addTail(lst &L, NODE *p){
    if(L.Head == NULL) L.Head = p = L.Tail;
    else{
        L.Tail->next=p;
        L.Tail = p;
    }
}

void addHead(lst &L, NODE *p){
    if(L.Head == NULL) L.Head = p = L.Tail;
    else{
        L.Head->next=p;
        L.Head = p;
    }
}

void addRandom(lst &L, NODE *p, NODE *x){
	if (x != NULL){
		p->next = x->next;
		x->next = p;
		if (L.Tail == x)
			L.Tail = p;
	}
	else addHead(L,p);
}

void input(lst &L, film x){
    NODE *p;
    int n;
    printf("enter the number of film: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("\n The %d film:\n", i+1);
        printf("enter film name : "); fflush(stdin); gets(x.name);
        printf("enter film director: "); fflush(stdin); gets(x.director);
        printf("enter film year: "); scanf("%d",&x.year);
        printf("enter film firm: "); fflush(stdin); gets(x.firm);
        p=iniNode(x);
        addTail(L, p);
    }
}

void sc(film x){
    printf("\n%s ", x.name);
    printf("\n%s ", x.director);
    printf("\n%d ", x.year);
    printf("\n%s ", x.firm);
}

void output(lst &L){
    for(NODE *p=L.Head;p!=NULL;p=p->next){
        sc(p->data);
    }
}

int main(){
    lst L;
    iniLst(L);
    film x;
    input(L,x);
    output(L);
}