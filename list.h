//
//  list.h
//  NodeList
//
//  Created by 陶越 on 17/3/21.
//  Copyright © 2017年 陶越. All rights reserved.
//

#ifndef list_h
#define list_h

#include <stdio.h>
#include "node.h"
typedef struct _list
{
    Node* head;
    Node* tail;
    int size;
}List;
Node* Max(List* L,Node*last);//升序（交换data）
Node* Max2(List* L,Node*begin);//降序（交换data）
Node* Max3(List* L,Node*last);//升序（交换节点）
void Selection3(List* L);
void Selection(List* L);
void Selection2(List* L);
void Init(List* L);//初始化链表
Node* Begin(List* L);
Node* End(List* L);
Node* Insert(List* L, Node* current,Type item);
void  Erase(List* L, Node* current);
Type* Front_pointer(List* L);
Type  Front_data(List* L);
Type* Back_pointer(List* L);
Type  Back_data(List* L);
void  Push_front(List* L ,Type item);
void  Push_back(List* L ,Type item);
void  Pop_front(List* L);
void  Pop_back(List* L);
int   size(List* L);
int Empty(List* L);
void Clear(List* L);
void Free(List* L);
void display_list(Node* first,Node* last);
void Bubble(List* L);//实现冒泡排序
void Exchange(Node* n1,Node* n2);//交换节点（不相邻）
void ExchangeNew(Node* n1,Node* n2);//交换相邻节点
#endif /* list_h */
