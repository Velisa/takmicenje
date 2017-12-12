#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	string sa,sb;
	cin>>sa>>sb;
	
	int a,b,brojac=0;
	string tempa, tempb;
		
	int temp1,temp2;
	string temp3;
	
	temp1=stoi(sa);
	temp2=stoi(sb);
	if(temp1<temp2){ //pronasao sam da kod ove moje metode program ne bi radio ukoliko je prvi broj npr 100 a drugi 101
		temp3=sb;    //jer nize u kodu mijenjam svaku cifru koji je ista u oba broja sa nulom
		sb=sa;		//za potrebe ovog zadatka i testova ovaj dio nije potreban, ali sam dodao da bi program bio 100% tacan
		sa=temp3;
	}	
	
	for(int i=0;i<sa.length();++i){
		tempa=sa[i];
		a=stoi(tempa);	
		for(int j=0;j<sb.length();++j){
			tempb=sb[j];	
			b=stoi(tempb);
			if(a==b){
				++brojac; //plan je da izbrojim koliko se cifri poklapa
				sb[j]='0'; //a zatim cifru koja se poklapa u drugom broju zamjenim sa 0 kako se više ne bi brojala (primjer sa brojevima 661 i 116)
				break;
			}
		}
	}
	
	
	cout<<sa.length()-brojac; //jednostavno oduzmem broj istih cifri od ukupnog broja cifri u brojevima 
	
	return 0;
}