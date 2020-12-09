//
//  main.cpp
//  ExpressionEvaluation
//
//  Created by 张昊 on 2020/12/9.
//

#include "Expression.h"
#include <string>

int main() {
    string s;
    getline(cin,s);
    char command[100];
    strcpy(command, s.c_str());
    cout<<command<<endl;
    Expression E(command);
    E.infix_string();
    E.suffix_string();
    cout<<E.calculate()<<endl;
    return 0;
}
