#include <iostream>
#include <cmath>
using namespace std;

void backtrack(int &c){
    c--;
		
}
bool ok(int cross[8], int c) {
	int help[8][5] = {{-1,-1,-1,-1,-1}, 
										{ 0,-1,-1,-1,-1}, 
										{ 0,-1,-1,-1,-1}, 
										{ 0, 1, 2,-1,-1}, 
										{ 0, 1, 3,-1,-1}, 
										{ 1, 4,-1,-1,-1}, 
										{ 2, 3, 4,-1,-1}, 
										{ 3, 4, 5, 6,-1} };
	for (int i = 0; i < c; i++){
		if (cross[i] == cross[c]){
			return false;
		}
	}
  for(int i = 0; help[c][i] != -1; i++) {
      if ((abs(cross[c]-cross[help[c][i]]) == 1)){
			return false;
			}
    }
  return true;
}

void print(int cross[], int c, int &sn){
	cout << "Solution #" << sn++ << endl;
	cout << " " << cross[0]+1 << cross[1]+1 <<endl;
	cout << cross[2]+1 << cross[3]+1 << cross[4]+1 << cross[5]+1<< endl;
	cout << " " << cross[6]+1 << cross[7]+1 << endl <<endl;
}

int main() {
  int cross[8] = {0}, c = 0, solution_num = 0;
	while (c >= 0){
		c++;
			if (c == 8){
				print(cross, c, solution_num);
				backtrack(c);
			}
			else {
				cross[c] = -1;
			}
		while (c >= 0){
			cross[c]++;
			if(cross[c] == 8){
				backtrack(c);
			}
			else if (ok(cross, c)){
				break;
			}
		}
	}
	return 0;
}