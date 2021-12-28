//Homework #2: Write a main program that loops asking the user for the two numbers a and b. The program should terminate if the user enters done what asked for number $//September 2nd, 2020                                                                                                                                                   

#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

//function:

string add(string a, string b) {

        //create swap value in case first value is smaller than the second value to add

        if (a.length() > b.length()) {

                swap(a, b);

        }

        //declare some variables:

        string str = "";
        int carry=0;
        int sum;
        int a1 = a.length();
        int b1 = b.length();
        int diff = b1-a1; //this will count for the remainder

        // addition function

        for (int i=a1-1; i>=0; i--) { //will start at last number in the index first

                sum = ((a[i]-'0') + (b[i+diff]-'0') + carry); //a[i] will start at last index, b[i+diff] will calculate the last index #

                str.push_back(sum%10 + '0'); //will add character to the end of the array

                carry = sum/10;

        }


        for (int i=(diff)-1; i>=0; i--) {
                                                                                                                                                                                        int sum = ((b[i]-'0')+carry);

                str.push_back(sum%10 + '0');                                                                                                                                                                                                                                                                                                                    carry = sum/10;
        }

        // Add remaining carry

        if (carry != 0) {

                str.push_back(carry+'0');
        }

        // reverse resultant string

        reverse(str.begin(), str.end());


        return str;
}



//driver code:

int main () {

        //declare string variables

        string a= "";
        string b= "";

        while(true) {

                cout<<"Enter the first value or enter 'done' to terminate the program: ";

                cin>>a;

                if(a == "done") {

                        break;
                }
                cout<<"Enter the second value: ";

                cin>>b;                                                                                                                                                                                                                                                                                                                                         cout<< "The sum is: "<< add(a,b) << endl;
        }

        return 0;
}


