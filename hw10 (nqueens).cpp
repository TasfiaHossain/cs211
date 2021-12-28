//Homework #10: N-Queens

#include <iostream>
#include <cmath>
using namespace std;


bool checkBoard(int queen[], int c){
	for (int i = 0; i < c; i++){
		if (queen[c] == queen[i] || (c-i) == abs(queen[c] - queen[i])){ 
			return false;
		}
	}
	return true;
}

void backtrack(int& c){
	c--;
}

void print (int &i, int &s_n){
	cout << "There are "<< s_n <<" number of solutions for the "<< i <<" queens problem.\n";
	i++;
	s_n = 0;
}

int main() {
	int n = 8;
	for(int i = 1; i <= n; i++){
	    
	    //make an array of a different length - to allocate the array off the heap and not the run-time stack
	    
		int *queen = new int[i];
		
		int c = 0, solution_num = 0;
		queen[i] = {0};

		while (c >= 0){
			c++;
			if (c == i){
				solution_num++;
				backtrack(c);
			}
			else {
				queen[c] = -1;
			}
			while (c >= 0){
				queen[c]++;
				if(queen[c] == i){
					backtrack(c);
				}
				else {
					if(checkBoard(queen, c)){
					break;
					}
				}
			}
		}
		cout << "There are "<< solution_num <<" number of solutions for the "<< i <<" queens problem.\n";
		solution_num = 0;
		
		//when we no longer need the memory allocated to the array: 
		
		delete[] queen;
	}
	return 0;
}