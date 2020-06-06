#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

typedef node* Tree;

void Create(Tree& t)
{
    t=NULL;
}

node* get_node(int data)
{
    node* a=new node;
    a->data=data;
    a->left=NULL;
    a->right=NULL;
    return a;
}

void Duyet(const Tree& t)
{
    if(t==NULL) return;
    cout<<t->data<<" ";
    Duyet(t->left);
    Duyet(t->right);
}

void Ins(Tree& t,int x)
{
    if(t!=NULL)
    {
        if(t->data==x) return;
        if(x>t->data) Ins(t->right,x);
        else Ins(t->left,x);
    }
    else
    {
        node* tmp=get_node(x);
        t=tmp;
        return;
    }
}

int Dem(const Tree& a)
{
    if(a==NULL) return 0;
    return 1+Dem(a->left)+Dem(a->right);
}

int main()
{
    Tree a;
    Create(a);
    for(int i=0;i<10;++i)
    {
        int x;
        cin>>x;
        Ins(a,x);
    }
    Duyet(a);
    cout<<endl;
    cout<<"So luong node : "<<Dem(a)<<endl;
    return 0;
}
