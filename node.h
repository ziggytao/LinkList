//
//  node.h
//  NodeList
//
//  Created by 陶越 on 17/3/21.
//  Copyright © 2017年 陶越. All rights reserved.
//

#ifndef node_h
#define node_h
#define  Type int
#include <stdio.h>
#include <mm_malloc.h>
typedef struct _node
{
    Type data;
    struct _node* prev;
    struct _node* next;
}Node;
Type Get_data(Node* current);                       //取当前结点数据
Node* Get_next(Node* current);                      //取下一结点
Node* Get_prev(Node* current);                      //取上一结点
Node* Get_node(Type item,Node*prev0,Node*next0);    //生成结点
#endif /* node_h */
