#include<iostream>
using namespace std;

int main() {
	int b[8][8]={0},r,c=0,i,counter=1;
	b[0][0]=1;
	
	nc: c++;		//inside loop
	if(c==8) goto print;
	
	
	r=-1;			//outside loop
	nr: r++;
 	if(r==8) goto backtrack;

	//row test
	for(i=0; i<c; i++){
		if(b[r][i]==1) goto nr;
	}
	//up diagonal test
	for(i=1; (r-i)>=0&&(c-i)>=0; i++){
		if(b[r-i][c-i]==1) goto nr;
	}
	//down diagonal test
	for(i=1; (r+i)<8&&(c-i)>=0; i++){
		if(b[r+i][c-i]==1) goto nr;
	}
	//place the Queen
	b[r][c]=1;
	goto nc;
	backtrack: c--;
	if(c==-1) return 0;
	
	r=0;
	while (b[r][c]!=1)
		r++;
	b[r][c]=0;
	goto nr;
	
print:

	cout<<"The solution number "<<counter<<":"<<endl;
	
	for(c=0; c<=7; c++){
		for(r=0; r<=7;r++){
	
			if( b[r][c]==1) cout<<"Q";
			else cout<<"I";
		}
		cout<<endl;
	}
	counter+=1;
	cout<<endl;	
		
	goto backtrack;
			
		
}



