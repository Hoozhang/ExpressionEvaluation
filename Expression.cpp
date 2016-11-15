//
//  Expression.cpp
//  primer
//
//  Created by 张昊 on 16/10/8.
//  Copyright © 2016年 张昊. All rights reserved.
//

#include "Expression.h"
#include "Stack.h"
#include <stack>
#include <string>

Expression::Expression()
{
    length = 0;
}

Expression::Expression(char *args)
{
    length = 0;
    strcpy(exp, args);
}

bool Expression::isoperator(char op)
{
    switch(op)
    {
        case '+':
        case '-':
        case '*':
        case '/':
            return 1;
        default :
            return 0;
    }
}

int Expression::priority(char op)
{
    switch(op)
    {
        case '#':
            return -1;
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default :
            return -1;
    }
}

void Expression::suffix_string()
{
    int i = 0, j = 0;
    stack<char> S;
    S.push('=');
    
    while(exp[i] != '=')
    {
        if(exp[i] >= '0' && exp[i] <= '9')
        {
            post[j++] = exp[i];
            post[j++] = ' ';
        }
        else if (exp[i] == '(' )
        {
            S.push(exp[i]);
        }
        else if(exp[i] == ')' )
        {
            while(S.top() != '(')
            {
                post[j++] = S.top();
                post[j++] = ' ';
                S.pop();
            }
            S.pop();
        }
        else if(isoperator(exp[i]))
        {
            while( priority(exp[i]) <= priority(S.top()) )
            {
                post[j++] = S.top();
                post[j++] = ' ';
                S.pop();
            }
            S.push(exp[i]);
        }
        i++;
    }
    
    while(S.top() != '=') // 将所有的操作符加入后缀表达式
    {
        post[j++] = S.top();
        post[j++] = ' ';
        S.pop();
    }
    length = j;
    /*for(int count = 0; count < j; count++)
    {
        cout<<post[count];
    }*/
    cout<<post<<endl;
}

void Expression::infix_string()
{
    int i = 0, j = 0;
    while(exp[i] != '=')
    {
        infix[j++] = exp[i];
        i++;
    }
    /*for(int count = 0; count < j; count++)
    {
        cout<<infix[count];
    }*/
    cout<<infix<<endl;
}

int Expression::read_num(char str[], int *i)
{
    int x = 0;
    while(str[*i] >='0' && str[*i]<='9')
    {
        x = x*10+(str[*i]-'0');
        (*i)++;
    }
    return x;
}
int Expression::calculate()
{
    Stack st;
    
    int i=0 ;
    int x1,x2;
    
    while(i < length)
    {
        if(post[i] >='0' && post[i] <='9')
            st.push(read_num(post,&i));
        else if(post[i] == ' ')
            i++;
        else if (post[i] =='+')
        {
            x2 = st.pop();
            x1 = st.pop();
            st.push(x1+x2);
            i++;
        }
        else if (post[i] =='-')
        {
            x2 = st.pop();
            x1 = st.pop();
            st.push(x1-x2);
            i++;
        }
        else if (post[i] =='*')
        {
            x2 = st.pop();
            x1 = st.pop();
            st.push(x1*x2);
            i++;
        }
        else if (post[i] =='/')
        {
            x2 = st.pop();
            x1 = st.pop();
            st.push(x1/x2);
            i++;
        }
    }
    return st.top();
}

/*
int main()
{
    
    string s;
    getline(cin,s);
    char command[100];
    strcpy(command, s.c_str());
    //cout<<command;
    Expression E(command);
    E.infix_string();
    E.suffix_string();
    cout<<E.calculate()<<endl;
    return 0;
}*/