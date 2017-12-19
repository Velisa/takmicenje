#include <iostream>
#include <cmath>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int s,a,b,c;
	cin>>s>>a>>b>>c;
	int izraz;
	
	cout<<a<<" "<<b<<" "<<c<<" ";
	
	while(izraz<s){
		izraz=pow(a,2)+pow(b,2)+pow(c,2);		
		if(izraz<s){
			cout<<izraz<<" ";
			a=b;
			b=c;
			c=izraz;
		}
	}	
	return 0;
}