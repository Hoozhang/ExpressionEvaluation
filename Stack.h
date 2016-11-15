//
//  Stack.hpp
//  primer
//
//  Created by 张昊 on 16/10/8.
//  Copyright © 2016年 张昊. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include<iostream>
using namespace std;

class Stack
{
public:
    Stack();
    bool empty();
    int  top();
    bool push(int i);
    int  pop();
    
private:
    
    struct Node
    {
        int content;
        Node *next;
    }*head;
};


#endif /* Stack_h */
