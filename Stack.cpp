//
//  Stack.cpp
//
//  Created by 张昊 on 16/10/8.
//  Copyright © 2016年 张昊. All rights reserved.
//

#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack() {
    head = NULL;
}

bool Stack::empty() {
    return (head == NULL) ? true : false;
}

int Stack::top() {
    if(head == NULL) {
        cout<<"Stack is empty."<<endl;
        return -1;
    }
    return head->content;
}

bool Stack::push(int i) {
    Node *p = new Node;
    if(p == NULL) {
        cout<<"Stack is overflow."<<endl;
        return false;
    } else {
        // 头插法实现 Stack
        p->content = i;
        p->next = head;
        head = p;
        return true;
    }
}

int Stack::pop() {
    int i = -1;
    if(head == NULL) {
        cout<<"Stack is empty."<<endl;
        return i;
    } else {
        Node *p =  head;
        head = head->next;
        i = p->content;
        delete p;
        return i;
    }
}

