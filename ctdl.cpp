#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* nxt;
};
node* get_node()
{
    int data;
    cout<<"Nhap du lieu : ";
    cin>>data;
    node* tmp=new node;
    tmp->data=data;
    tmp->nxt=NULL;
    return tmp;
}
// Stack
typedef node* Stack;

void Create(Stack& a)
{
    a=NULL;
}

void Push(Stack& a)
{
    node* tmp=get_node();
    tmp->nxt=a;
    a=tmp;
}

void show(const Stack& a)
{
    node* tmp=a;
    while(tmp!=NULL)
    {
        cout<<"data : "<<tmp->data<<endl;
        tmp=tmp->nxt;
    }
}

void Pop(Stack& a)
{
    if(a!=NULL)
    {
        node* p=a;
        a=p->nxt;
        delete p;
    }
}
// Queue
typedef node* Queue;

void Create(Queue& First,Queue& Last)
{
    First=NULL;
    Last=NULL;
}

void Push(Queue& First,Queue& Last)
{
    node* tmp=get_node();
    if(First==NULL)
    {
        First=tmp;
        Last=tmp;
    }
    else
    {
        Last->nxt=tmp;
        Last=tmp;
    }
}

void Pop(Queue& First,Queue& Last)
{
    if(First!=NULL)
    {
        node* tmp=First;
        First=First->nxt;
        delete tmp;
    }
}

void show(Queue& First,Queue& Last)
{
    node* tmp=First;
    while(tmp!=NULL)
    {
        cout<<"du lieu : "<<tmp->data<<endl;
        tmp=tmp->nxt;
    }
}
// Tree
struct ver
{
    int data;
    ver* left;
    ver* right;
};

typedef ver* Tree;

void Create(Tree& a)
{
    a=NULL;
}

ver* get_ver(int x)
{
    ver* tmp=new ver;
    tmp->data=x;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}

int Ins(Tree& t,int x)
{
    if(t!=NULL)
    {
        if(t->data==x) return 0;
        if(x>t->data) return Ins(t->right,x);
        else return Ins(t->left,x);
    }
    else
    {
        ver* tmp=get_ver(x);
        t=tmp;
        return 1;
    }
}

void show(const Tree& a)
{
    if(a==NULL) return;
    cout<<a->data<<" ";
    show(a->left);
    show(a->right);
}
int del_ver(Tree& a,int x);

int leftleft(Tree& a)
{
    if(a->left==NULL)
    {
        int data=a->data;
        del_ver(a,data);
        return data;
    }
    return leftleft(a->left);
}

int del_ver(Tree& a,int x)
{
    if(a==NULL) return 0;
    if(x<a->data) return del_ver(a->left,x);
    if(x>a->data) return del_ver(a->right,x);
    else
    {
        ver* cur=a;
        if(a->left==NULL&&a->right==NULL)
        {
            a=NULL;
            cur=a;
            delete cur;
            return 1;
        }
        if(a->left==NULL) return a=a->right,1;
        if(a->right==NULL) return a=a->left,1;
        else
        {
            cur->data=leftleft(a->right);
            return 1;
        }
    }

}

int main()
{
    cout<<"Hello world"<<endl;
    return 0;
}
