//
//  list.c
//  NodeList
//
//  Created by 陶越 on 17/3/21.
//  Copyright © 2017年 陶越. All rights reserved.
//

#include "list.h"
#define Type int
void Init(List* L)//初始化链表
{
    L->head = (Node*)malloc(sizeof(Node));
    if(L->head == NULL)
    {
        printf("error!\n");
        exit(1);
    }
    L->head->next = L->head->prev = NULL;
    L->tail = (Node*)malloc(sizeof(Node));
    if(L->tail == NULL)
    {
        printf("error!\n");
        exit(1);
    }
    L->tail->prev = L->tail->next = NULL;
    L->head->next = L->tail;
    L->tail->prev = L->head;
    L->size = 0;
}
void Exchange(Node* n1,Node* n2)//为什么一直有问题??交换两个结点？？。。。。。。已放弃，直接走捷径，八个线条调试难
{
   /*
    Node* temp = Get_prev(n1);
    Node* temp2 = Get_next(n1);
    Node* temp3 = Get_prev(n2);
    Node* temp4 = Get_next(n2);
    n1->prev = temp3;
    temp->next = n2;
    n2->prev = temp;
    temp2->prev = n2;
    n2->next = temp2;
    temp3->next = n1;
    temp4->prev = n1;
    n1->next = temp4;
    */
    Node* temp1,*temp2;
    n1->prev->next = n2;
    temp1 = n2->prev;
    n2->prev = n1->prev;
    n1->next->prev = n2;
    temp2 = n2->next;
    n2->next = n1->next;
    temp1->next = n1;
    n1->prev = temp1;
    temp2->prev = n1;
    n1->next = temp2;
}
void ExchangeNew(Node* q,Node* p)
{
    q->prev->next = p;
    p->prev= q->prev;
    p->next->prev= q;
    q->next = p->next;
    q->prev = p;
    p->next = q;
}
Node* Max3(List* L,Node*last)
{
    Node* p,*q,*max = Get_prev(last);
    for(q = Begin(L); q != Get_prev(last); q = Get_next(q))
    {
        if(Get_data(q) > Get_data(max))
        {
            p = q;
            if(p != Get_prev(max)) Exchange(p, max);
            else ExchangeNew(p, max);
            q = max;
            max = p;
        }
    }
    return max;
}
void Selection3(List* L)
{
    int i;
    Node*last = End(L);
    for(i = 0; i < size(L)- 1; i++)
    {
        Max3(L, last);
        last = Get_prev(last);
    }
}
Node* Max2(List* L,Node*begin)
{
    Node*max = begin,*p;
    Type temp;
    for(p = begin;p != End(L); p = Get_next(p))
    {
        if(Get_data(p) > Get_data(max))
        {
            temp = max->data;
            max->data = p->data;
            p->data = temp;
        }
    }
    return max;
}
void Selection2(List* L)
{
    Node*begin = Begin(L),*i = Begin(L);
    for(; i!= Get_prev(End(L)); i = Get_next(i))
    {
        Max2(L, begin);
        begin = Get_next(begin);
    }
}
Node* Max(List* L,Node*last)
{
    Node*max =Get_prev(last),*p;
    Type temp;
    for(p = Begin(L);p != last;p = Get_next(p))
    {
        if(Get_data(p) > Get_data(max) )
        {
            temp = max->data;
            max->data = p->data;
            p->data = temp;
        }
    }
    return max;
}
void Selection(List* L)
{
    Node*i = Begin(L),*last = End(L);
    for(;i != Get_prev(End(L));i = Get_next(i))
   {
       Max(L,last);
       last = Get_prev(last);
   }
}
void Bubble(List* L)//冒泡排序
{
    Node* first,*last = End(L);
    int i;
    for(i = 0; i < L->size-1; i ++)
    {
       for(first = Begin(L); first !=Get_prev(last) ;first = Get_next(first))
        {
            if( Get_data(first) > Get_data(Get_next(first)))
            {
                ExchangeNew(first, Get_next(first));
                first = Get_prev(first);
            }
        }
        last = Get_prev(last);
    }
}
void display_list(Node* first,Node* last)
{
    for(;first != last; first = Get_next(first))
    {
        printf("%d\t",first->data);
    }
    printf("\n");
}
Node* Begin(List* L)
//取左指针(闭)
{
    return L->head->next;
}
Node* End(List* L)
//取右指针(开)
{
    return L->tail;
}
Node* Insert(List* L, Node* current,Type item)
//在该指针之前插入结点
{
    if(current == L->head || current == NULL)
    {
        printf("error!\n");
        exit(1);
    }
    Node* p = current;
    p->prev->next = Get_node(item, p->prev,p);
    p->prev = p->prev->next;
    L->size++;
    return p;
}
void  Erase(List* L, Node* current)
//删除当前指针指向的结点
{
    L->size--;
    Node* p = current;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
}
Type* Front_pointer(List* L)
//取数据首结点的数据指针
{
    Node* current = L->head->next;
    return &(current->data);
}
Type  Front_data(List* L)
//取数据首结点的数据
{
    Node* current = L->head->next;
    return current->data;
}
Type* Back_pointer(List* L)
//取数据尾结点的数据指针
{
    Node* current = L->tail->prev;
    return &(current->data);
}
Type  Back_data(List* L)
//取数据尾结点的数据
{
    Node* current = L->tail->prev;
    return current->data;
}
void  Push_front(List* L ,Type item)
//在数据首结点前插结点
{
    Insert(L, L->head->next, item);
}
void  Push_back(List* L ,Type item)
//在数据尾结点后插结点
{
    Insert(L, L->tail, item);
}
void  Pop_front(List* L)
//删除数据首结点
{
    Erase(L, Begin(L));
}
void  Pop_back(List* L)
//删除数据尾结点
{
    Erase(L, End(L));
}
int size(List* L)
{
    return L->size;
}
int Empty(List* L)
{
    return L->size == 0;
}
void Clear(List* L)
{
    while(!Empty(L))
    {
        Pop_front(L);
    }
}
void Free(List* L)
{
    Clear(L);
    free(L->head);
    free(L->tail);
}
