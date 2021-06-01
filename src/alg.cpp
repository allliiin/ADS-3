// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"

int priority(char Pr) {
  switch (Pr) {
    case '(': return 0;
    case ')': return 1;
    case '+': return 2;
    case '-': return 2;
    case '*': return 3;
    case '/': return 3;
    default: return -1;
  }
}
int calculating(char Op, int Num1, int Num2) {
    switch (Op) {
    case '+':return Num1 + Num2;
    break;
    case '-':return Num1 - Num2;
    break;
    case '*':return Num1 * Num2;
    break;
    case '/':return Num1 / Num2;
    break;
    }
}
std::string infx2pstfx(std::string inf) {
char Top = 0;
    TStack<char> stack;
    std::string str;
    for (int i = 0; i < inf.length(); i++) {
        int pr;
        pr = priority(inf[i]);
        if (pr > -1) {
            if ((pr == 0 || pr > priority(Top) ||
            stack.isEmpty()) && inf[i] != ')') {
            if (stack.isEmpty())
                Top = inf[i];
            stack.push(inf[i]);
            } else if (inf[i] == ')') {
                while (stack.get() != '(') {
                    str.push_back(stack.get());
                    str.push_back(' ');
                    stack.pop();
                }
                stack.pop();
                if (stack.isEmpty())
                    Top = 0;
            } else {
                while (!stack.isEmpty() && priority(stack.get()) >= pr) {
                    str.push_back(stack.get());
                    str.push_back(' ');
                    stack.pop();
                }
                if (stack.isEmpty())
                    Top = inf[i];
                stack.push(inf[i]);
            }
        } else {
            str.push_back(inf[i]);
            str.push_back(' ');
        }
    }
    while (!stack.isEmpty()) {
        str.push_back(stack.get());
        str.push_back(' ');
        stack.pop();
    }
    str.erase(str.end() - 1, str.end());
    return str;
}
int eval(std::string pst) {
  TStack<int> stack2;
    int res = 0, i = 0;
    char x = pst[i];
    while (x) {
        if (x >= '0' && x <= '9') {
            int insInt = 0;
            int d = 1;
            while (x != ' ') {
                insInt += (x - 48) * d;
                d *= 10;
                x = pst[++i];
            }
            stack2.push(insInt);
        } else {
            char Op = x;
            i++;
            int Num2 = stack2.get();
            stack2.pop();
            int Num1 = stack2.get();
            stack2.pop();
            int res = calculating(Op, Num1, Num2);
            stack2.push(res);
        }
        if (i < pst.size())
            x = pst[++i];
        else
            x = 0;
    }
    res = stack2.get();
    stack2.pop();
    return res;
}
