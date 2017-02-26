#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

bool ok(int q[], int col){
      for (int i = 0; i<col; i++)
         if (q[i] == q[col] || (col-i) == abs(q[col] - q[i]))
            return false;
            
      return true;
    }
   
   void backTrack(int &col){
      col--;
      if (col == -1) 
         exit(1);
    }
    
   void print(int q[]){
      static int counter = 1;
      cout << "\nSolution " << counter << ":"<<endl;
   
      int a[8][8] = {0};
  
      for (int j =0; j<8; j++){
        for (int k=0; k<8; k++){
          if (q[j] == k)
             a[k][j] = 1;
        
          cout << a[k][j] << " ";
        }    
      cout << endl;
      }
      counter++;
   }	
int main(){
	int q[8];
   int c = 0;
   q[0] = 0;
   bool trace_backTrack = false;

   while (true){
      while (c < 8){
         if (!trace_backTrack)
            q[c] = -1;
         
         while (q[c] < 8){
            q[c]++;
            
            if(q[c] == 8){
               backTrack(c);
               continue;
            }
            if (ok (q, c))
               break;
         }
         c++;
         trace_backTrack = false;
      }
      
      print(q);
      backTrack(c);
      trace_backTrack = true;
   }
   
   return 0;
}
