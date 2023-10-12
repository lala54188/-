#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
using namespace std;

typedef struct SqStack
{
    int data;
    struct SqStack *next;
}SqStack;

void InitSqStack(SqStack * &s)
{
    s=(SqStack *)malloc(sizeof(SqStack));
    s->next=NULL;
}

bool Push(SqStack *&s,char e)
{   SqStack *p;
    p=(SqStack *)malloc(sizeof(SqStack));
    p->data=e;
    p->next=s->next;
    s->next=p;
    return true;
}
bool Match(char exp[],int n)
{
    int i=0;
    char e;
    bool match=true;

}
void pop(SqStack *&s)
{
    char e;
    SqStack *p;
    p=s->next;
    e=p->data;
    s->next=p->next;
    free(p);
}
char qc(SqStack *s)
{
    char e;
    e=s->next->data;
    return e;
}
bool qcc(char a,char b)
{
    if(a=='[' && b==']')
        return true;
    if(a=='{' && b=='}')
        return true;
    if(a=='(' && b==')')
        return true;
    else
        return false;
}
void pd(char exp[],int n)
{
    int i=0;
    char e;
    int match=1;
    SqStack *st;
    InitSqStack(st);
    while(i<n && match==1)
    {
        char sttop;
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
            Push(st,exp[i]);
        else if(exp[i]==')' || exp[i]==']' || exp[i]=='}')
        {
            if(qcc(qc(st),exp[i])==true)
            {
                pop(st);
            }
            else
                match=2;
        }
        i++;
    }
    if(st->next!=NULL)
        match=2;
    if(match==2)
        printf("Not match!\n");
    if(match==1)
        printf("Match!\n");
    return;
}
int main()
{
    int n,x;
    char a[100];
    scanf("%d",&x);
    for(int i=0;i<x;i++)
{
        scanf("%s",a);
        n=strlen(a);
        pd(a,n);
}
    return 0;
}
