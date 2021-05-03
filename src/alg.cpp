// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"

int sum(char q) {
if((q == '/')||(q == '*')) {
return 3;
} else if((q == '+')||(q == '-')) {
return 2;
} else if(q == ')') {
return 1;
} else if(q == '(') {
return 0;
} else {
return -1;
}
}

std::string infx2pstfx(std::string inf) {
TStack<char> inf1;
int i = 0;
int j = 0;
std::string inf2;
std::string inf3;
char k = 0;
char k2 = 0;
char k3 = 0;

while(i < inf.size()) {
if(sum(inf[i]) == -1) {
inf1.push(inf[i]);
i++;
} else if((sum(inf[i]) == 3) || (sum(inf[i]) == 2)) {
if(sum(inf[i + 1]) != 0) {
k = inf[i];
i++;
} else {
if((sum(inf[i-3]) == 1) && (sum(inf[i-2]) == 3)) {
k3 = inf[i];
i++;
} else {
k2 = inf[i];
i++;
}
}
} else if(sum(inf[i]) == 0) {
i++;
while(sum(inf[i]) != 1) {
if(sum(inf[i]) == -1) {
inf1.push(inf[i]);
i++;
} else if((sum(inf[i]) == 3) || (sum(inf[i]) == 2)) {
k = inf[i];
i++;
}
}
if(sum(inf[i]) == 1) {
inf1.push(k);
k = 0;
i++;
}
if(k2 != 0) {
inf1.push(k2);
k2 = 0;
}
}
if((k != 0) && (sum(inf[i]) == -1)) {
inf1.push(inf[i]);
inf1.push(k);
k = 0;
i++;
}
}
if(k3 != 0) {
inf1.push(k3);
}
while(inf1.isEmpty() == false) {
inf2 += inf1.get();
inf1.pop();
}
j = inf2.size() - 1;
while(j > -1) {
inf3 += inf2[j];
if(j) {
inf3 += ' ';
}
j--;
}
return inf3;
}

int eval(std::string pst) {
TStack<std::string> stack1;
int result = 0;    
std::string k;
int g = 0;
int c;
int d;

while(g < pst.size()) {
if((sum(pst[g]) == -1) && (pst[g+1] == ' ')) {
k = pst[g];
stack1.push(k);
g += 2;
} else if((sum(pst[g]) == -1) && (sum(pst[g+1]) == -1)) {
k = pst[g]+pst[g + 1];
stack1.push(k); 
g += 2;
} else if(pst[g] == '+') {
c = 0;
for(int m = 0; m < 2; m++) {
c += atoi(stack1.get().c_str());
stack1.pop();
}
k = std::to_string(c);
stack1.push(k);
g += 2;
} else if(pst[g] == '-') {
c = 0;
d = 0;
d = atoi(stack1.get().c_str());
stack1.pop();
c = atoi(stack1.get().c_str());
stack1.pop();
c -= d;
k = std::to_string(c);
stack1.push(k);
g += 2;
} else if(pst[g] == '*') {
c = 1;
for(int m = 0;m < 2; m++) {
c *= atoi(stack1.get().c_str());
stack1.pop();
}
k = std::to_string(c);
stack1.push(k);
g += 2;
} else if(pst[g] == '/') {
c = 0;
d = 0;
d = atoi(stack1.get().c_str());
stack1.pop();
c = atoi(stack1.get().c_str());
stack1.pop();
c /= d;
k = std::to_string(c);
stack1.push(k);
g += 2;
}
}
result = atoi(stack1.get().c_str());
return result;
}
