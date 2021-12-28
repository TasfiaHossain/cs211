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

void backtrack(int queen[], int& c){
	c--;
}

//print function for the chess board
void print(int queen[], int &s) {
	int i,j,k,l;
	typedef char box[5][7];
	box bb,wb,*board[8][8];
	box bq = { {char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
               {char(219),' '      ,char(219),' '      ,char(219),' '      ,char(219)},
               {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
               {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
               {char(219),char(219),char(219),char(219),char(219),char(219),char(219)} };
               
   box wq = { {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      },
              {' '      ,char(219),' '      ,char(219),' '      ,char(219),' '      },
              {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
              {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
              {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      } };
 
	for(i = 0; i < 5; i++){
		for(j = 0; j < 7; j++){
			bb[i][j] = ' ';
			wb[i][j] = char(219);
      
		}
	}
	for(i = 0; i < 8; i++){
		for(j = 0; j < 8; j++){
			if((i+j) % 2 == 0){
				board[i][j] = &wb;
			}
			else {
				board[i][j] = &bb;
			}
		}
	}

	for(i = 0; i < 8; i++){
  	if( (queen[i] + i) % 2 == 0){
    	board[queen[i]][i] = &wq;
		}
    else{
    	board[queen[i]][i] = &bq;
		}
	}
	cout <<endl<< "Solution #: " << s++ << endl;
	cout << "  ";
	for(i = 0; i < 7*8; i++){
		cout << '_';
	}
	cout << endl;

	for(i = 0; i < 8; i++){
		for(k = 0; k < 5; k++){
			cout << "  " << char('-');
		for(j = 0; j < 8; j++){
			for(l = 0; l < 7; l++){
				cout << (*board[i][j])[k][l];
			}
		}
		cout << char('-') << endl;
	}
	}
	cout << "  ";
	for(i = 0; i < 7*8; i++){
		cout << char('-');
	}
	cout << endl;
}



int main() {
  int queen[8] = {0}, c = 0, solution_num = 0;

	while (c >= 0){
		c++;
		if (c == 8){
			print(queen, solution_num);
			backtrack(queen, c);
		}
		else {
			queen[c] = -1;
		}
		while (c >= 0){
			queen[c]++;
			if(queen[c] == 8){
				backtrack(queen, c);
			}
			else {
				if(checkBoard(queen, c)){
				break;
				}
			}
		}
	}
	return 0;
}
