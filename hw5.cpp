#include <iostream>
#include <cmath>
using namespace std;

int count = 0;
int p = 0;

//checks queens in columns
bool ok(int q[], int c) {

   for(int i = 1; i <= c; i++){ 

      if(q[c] == q[i-1] || q[c-i] == q[c]-i || q[c-i] == q[c]+ i) 

         return false;
   }
   
   return true;

}

//prints board
void print(int q[]){

    cout<< "Solution #" << count++ <<endl;

        for (int i = 0; i < 8; i++) {

                for (int j = 0; j < 8; j++) {

                        if (q[i] == j)

                            cout << "1 ";

                        else cout << "0 ";

                }

                        cout<<endl;
        }                                                                                                                   
    cout<<endl;                                                                                                       }    

int main() {
   
   int q[8]={};   

   int c = 0;
   int r = 0;
   
   //checks the columns
   while (c >= 0){
    
      c++;                    
     
      if(c > 7){              
       
         print(q);            
       
         c--;        

      }

      else if (c < 0)

        break;
     
      else
        
         r = -1;

      while (c >= 0) {
        
         r++;
       
         q[c] = r;                      

         if(r > 7){
          
            c--; //backtrack
            
            r = q[c];        

         }

         else if(ok(q,c)){   
           
            break;
         }                  

      }
   
   }
   
   return 0;

}