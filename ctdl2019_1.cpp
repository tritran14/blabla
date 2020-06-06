#include <bits/stdc++.h>

using namespace std;

struct node
{
    string s;
    int data;
    node* nxt;
};

struct List
{
    node* head;
};

void Create(List& a)
{
    a.head=NULL;
}

node* get_node(int data,string id)
{
    node* tmp=new node;
    tmp->s=id;
    tmp->data=data;
    tmp->nxt=NULL;
    return tmp;
}

void input(List& a)
{
    int n;
    cout<<"Nhap so luong node : ";
    cin>>n;
    node* p=a.head;
    for(int i=0;i<n;++i)
    {
        string id;
        cout<<"Nhap id : ";
        cin>>id;
        cout<<"Nhap data : ";
        int data;
        cin>>data;
        if(!i)
        {
            a.head=get_node(data,id);
            p=a.head;
            continue;
        }
        p->nxt=get_node(data,id);
        p=p->nxt;
    }
}

void output(const List& a)
{
    node* tmp=a.head;
    cout<<"Output : ";
    while(tmp!=NULL)
    {
        cout<<"id : "<<tmp->s<<endl;
        cout<<"data : "<<tmp->data<<endl;
        cout<<"---------------"<<endl;
        tmp=tmp->nxt;
    }
}

node* Search(const List& a,int data)
{
    node* tmp=a.head;
    while(tmp!=NULL)
    {
        if(tmp->data==data) return tmp;
        tmp=tmp->nxt;
    }
    cout<<"Khong tim thay :'("<<endl;
    return NULL;
}

int main()
{
    List a;
    Create(a);
    input(a);
    int x;
    cout<<"Nhap data can tim : ";
    cin>>x;
    node* tmp=Search(a,x);
    if(tmp!=NULL)
    {
        cout<<"id : "<<tmp->s<<endl;
        cout<<"data : "<<tmp->data<<endl;
        cout<<"---------------"<<endl;
    }
    return 0;
}
