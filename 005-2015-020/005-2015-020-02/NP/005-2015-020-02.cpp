#include <iostream>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	cin>>n;
	string cenzura[n];
	for(int i=0;i<n;i++){
		cin>>cenzura[i];
	}
	cin.ignore(); //program mi je preskakao getline naredbu pa sam našao ovo rješenje na internetu
	string recenica;
	getline(cin,recenica);
	
	string prije,posle,rijec;
	int indeks;
	
	for(int i=0;i<n;++i){
			indeks=recenica.find(cenzura[i]);
				if(indeks>-1){
				prije=recenica.substr(0,indeks);
				posle=recenica.substr(indeks+cenzura[i].length(),recenica.length());
				rijec=recenica.substr(indeks,cenzura[i].length());
			
				for(int j=0;j<cenzura[i].length();++j){
					rijec[j]='*';
				}
			
				recenica=prije+rijec+posle;
				}
	}
	
	cout<<recenica;
	
	return 0;
}