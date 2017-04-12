//
//  node.c
//  NodeList
//
//  Created by 陶越 on 17/3/21.
//  Copyright © 2017年 陶越. All rights reserved.
//

#include "node.h"
Type Get_data(Node* current)                        //取当前结点数据
{
    return current->data;
}
Node* Get_next(Node* current)                       //取下一结点
{
    return current->next;
}
Node* Get_prev(Node* current)                       //取上一结点
{
    return current->prev;
}
Node* Get_node(Type item,Node*prev0,Node*next0)     //生成结点
{
    Node *p;
    p = (Node*)malloc(sizeof(Node));
    if(p == NULL)
    {
        printf("error!\n");
        exit(1);
    }
    p->data = item;
    p->next = next0;
    p->prev = prev0;
    return p;
}
