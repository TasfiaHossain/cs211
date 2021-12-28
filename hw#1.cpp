#include <iostream>
using namespace std;

//Write a program to find and print the first perfect square (i*i) whose last two digits are both odd.

//make a function called perfectSquare
int perfectSquare() {

        //make a variable to initialize x and declare the variable perfectSquare

        int i;
        int perfectSquare;

        while(true) {

                //declare perfect square to be a variable that is a square

                perfectSquare = i * i;

                //perfectSquare % 2 == 1 finds the remainder is odd
                //((perfectSquare) / 10) % 2 checks the numbers and finds if the remainder is odd

                if ((perfectSquare % 2 == 1) && ((perfectSquare) / 10) % 2 == 1) {

                        break;

                }


        }

        return perfectSquare;
}


int main () {


            cout << perfectSquare() << endl;

}