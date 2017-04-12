//
//  main.c
//  NodeList
//
//  Created by 陶越 on 17/3/21.
//  Copyright © 2017年 陶越. All rights reserved.
//

#include <stdio.h>
#include "list.h"
#include "node.h"
int main(int argc, const char * argv[]) {
    // insert code here...
    List L;
    Init(&L);
    Push_front(&L, 55);
    Push_front(&L, 35);
    Push_front(&L, 15);
    Push_front(&L, 25);
    Insert(&L, L.head->next->next, 77);
    display_list(Begin(&L),End(&L));
    Selection3(&L);
    display_list(Begin(&L),End(&L));
    //Exchange(Begin(&L), Get_next(Begin(&L)));
    //display_list(Begin(&L),End(&L));
   // Selection(&L);
   // Selection2(&L);
   // display_list(Begin(&L),End(&L));
    //Bubble(&L);
    //display_list(Begin(&L),End(&L));
    //Exchange(Get_prev(End(&L)),Get_next(Begin(&L)));
  //  display_list(Begin(&L),End(&L));
    Free(&L);
    return 0;
}
