// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"

std::string infx2pstfx(std::string inf) {
	TStack<char> inf1;
	int a = 0;
	int a1 = 0;
	std::string inf2;
	std::string inf3;
	char temp1 = 0;
	char temp2 = 0;
	char temp3 = 0;
	
	while(a < inf.size()-1){      
		if(PrOp(inf[a]) == -1){
			inf1.push(inf[a]);
			a++;
		} else if((PrOp(inf[a]) == 3)||(PrOp(inf[a]) == 2)){
			if(PrOp(inf[a+1]) != 0){
				temp1 = inf[a];
				a++;
			} else {
				if((PrOp(inf[a-3]) == 1)&&(PrOp(inf[a-2]) == 3)){
					temp3 = inf[a];
					a++;
				} else {
					temp2 = inf[a];
					a++;
				}
			}
		} else if(PrOp(inf[a]) == 0){
			a++;
			while(PrOp(inf[a]) != 1){
				if(PrOp(inf[a]) == -1){
					inf1.push(inf[a]);
					a++;
				} else if((PrOp(inf[a]) == 3)||(PrOp(inf[a]) == 2)){
					temp1 = inf[a];
					a++;
				}
			}
			if(PrOp(inf[a]) == 1){
				inf1.push(temp1);
				temp1 = 0;
				a++;
			}
			if(temp2 != 0){
				inf1.push(temp2);
				temp2 =0;
			}
		}
		if((temp1!= 0)&&(PrOp(inf[a]) == -1)){
			inf1.push(inf[a]);
			inf1.push(temp1);
			temp1 = 0;
			a++;
		}
	}
	if(temp3 != 0){
		inf1.push(temp3);
	}
	while(inf1.isEmpty() == false){
		inf2 += inf1.get();
		inf1.pop();
	} 
	a1 = inf2.size()-1;
	while(a1 > -1){
		inf3 += inf2[a1];
		if(a1 > 0){
		inf3 += ' ';
		}
		a1--;
	} 
	return inf3;
}
