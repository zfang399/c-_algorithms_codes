#include<iostream>
#include<cstdio>
using namespace std;

struct NODE{
	int data;
	struct NODE *left;
	struct NODE *right;
};

void insert (NODE* bst, NODE *s)
{   NODE *p = bst; NODE *q= NULL;
    while (p!=NULL) 
	{
    switch (s->data)
	{
    	case(s->data < p->data):    q=p;  p=p->left;
        case(s->data >= p->data):  q=p;   p=p->right;
    }
    switch()
	{
        bst = NULL:            bst = s;
        s->data < q->data:   q->left = s;
        s->data>=q->data:   q->right = s;
    }
}


void create ( NODE *bst,  int n)
{   bst = NULL;
    for (i=1; i<=n; i++)  
	{
    cin >> x;
    s = new  node;
    s->data = x;
    s->left = NULL;
    s->right =NULL;
    insert (bst, s);
    }
}

int main()
{
	bst=new node;
	create(NODE *bst, 5);
	return 0;
}

