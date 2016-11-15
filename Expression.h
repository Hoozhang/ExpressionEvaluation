//
//  Expression.hpp
//  primer
//
//  Created by 张昊 on 16/10/8.
//  Copyright © 2016年 张昊. All rights reserved.
//

#ifndef Expression_hpp
#define Expression_hpp

#include <iostream>
using namespace std;
#include <string>

class Expression
{
public:
    Expression();
    Expression(char *args);
    void infix_string();
    void suffix_string();
    int calculate();
    bool isoperator(char op);
    int priority(char op);
    int read_num(char str[], int *i);
private:
    int  length;
    char exp[100];
    char infix[100];
    char post[100];
};

#endif /* Expression_hpp */
