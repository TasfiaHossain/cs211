#include <iostream>
#include <cmath>
using namespace std;
int main () {

    //declare variables for 1-D array (8 postions - starts from 0)
    int q[8];
    int c= 0;
    int solution = 0;

    //put the queen in the upper left corner (first position)

    q[0] = 0; //b[0][0] in the 2D version

nc: c++;

    if (c==8) goto print;

    q[c] = -1;

nr: q[c]++;

    if(q[c] == 8) goto backtrack;

    for(int i = 0; i < c; i++)

        if(q[i] == q[c] || (c-i) == abs(q[c] - q[i])) goto nr;

    goto nc;

backtrack:

    c--;

    if(c == -1) return 0;

    goto nr;

print:

    solution++;

    cout<<"Solution #"<<solution<<":\n";

    for(int i = 0; i < 8; i++) {

        for(int j = 0; j < 8; j++)

            if(i==q[j]) 

                cout << "1";

            else cout << "0";

        cout<<endl;

    }

    goto backtrack;

}