//HW#7: Stable Marriage

/*
  Question:
    https://venus.cs.qc.cuny.edu/~waxman/211/stable%20marriage%20using%20backtrack%20assignment.pdf
  References:
    https://repl.it/@CerverizzoE/StableMarriage-iterative-for-StudentUse
*/

#include <iostream>
using namespace std;

void printMatching(int q[]){
    
    int solution = 0;
    int j;
       
       cout << "Man" << "  " << "Woman" << endl;
       
       for(j = 0; j < 3; j++) {
       
          cout << " " << j <<"     "<< q[j] <<endl;          
       
       }
}
  
bool ok(int q[], int col){  

    //mp = man's preference; wp = women's preference
    //mp[i][j] gives man i's ranking of woman j
    //lower value implies higher ranking
    int mp[3][3] = {{0,2,1},   //man 0 likes woman 0 the most and woman 1 the least.
                    {0,2,1},
                    {1,2,0}};   

    int wp[3][3] = {{2,1,0},
                    {0,1,2},
                    {2,0,1}};

    //cm = a currently assigned man
    //cw = a currently assigned woman
    //nm = new man
    //nw = new woman
    //nm and nw are the proposed pair to add to the match

    int cm, cw, nm, nw;

    nm = col;
    nw = q[col];

    for (int cm = 0; cm < col; cm++)
        
        if(q[cm] == nw)
        
            return false;

    /*
       Check the new pair (new man, new woman) against each existing pair consisting of
       (current man, current woman) to see if the new pair would make the match unstable.
    */
    for (int cm = 0; cm < col; cm++) {
        
            cw = q[cm];
        
        //Lower value implies a higher preference

        //   a. if the current man prefers the new woman to his partner and
        //   b. if the new woman prefers the current man to her partner, reject
        
        if(mp[cm][nw] < mp[cm][cw] && wp[nw][cm] < wp[nw][nm]) 
        
            return false;

        //   c. if the new man prefers the current woman to his partner and
        //   d. if the current woman prefers the new man to her partner, reject
        
        if(mp[nm][cw] < mp[nm][nw] && wp[cw][nm] < wp[cw][cm]) 
        
            return false;
    }

    return true; //since the pair nm & nw do not introduce an instability
}

int main() {

    //Start with the first male
    
    int newMan = 0;
    int q[3] = {0};
    
    // While we have not backtracked beyond the first male:
    
    while (newMan >= 0){

        // If all the people have been matched, 
        
        if(newMan > 2){
           
            printMatching(q);// print 
            
            // backtrack
            
            newMan--;
            q[newMan]++;
        }
        
        // If all the available women are matched already
        
        else if (q[newMan] > 2){
            
            q[newMan] = 0;//reset new woman to starting value
            
            //backtrack
            
            newMan--;
            
            if(newMan != -1)
            
                q[newMan]++;
        }
        //check if the q is stable
        
        else if(ok(q,newMan)){
            
            newMan++;// move to the next man
        }
        else{
            
            // pair the man with the next available woman
            
            q[newMan]++;
        }
    }
    
    return 0;
}