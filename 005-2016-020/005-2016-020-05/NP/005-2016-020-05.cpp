//#include <iostream>
#include <fstream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	ifstream ulazfajl("slovaul.txt");
	ofstream izlazfajl("slovaiz.txt");
	string ulaz;
	getline(ulazfajl,ulaz);
	
	int kraj=ulaz.length();	
	
	int ucestalost[22];
	
	for(int i=0;i<22;++i){
		ucestalost[i]=0;
	}
	
	for(int i=0;i<kraj;++i){			
		switch(ulaz[i]){
			case 'A':
				++ucestalost[0];
				break;
			
			case 'B':
				++ucestalost[1];
				break;
			
			case 'C':
				++ucestalost[2];
				break;
			
			case 'D':
				++ucestalost[3];
				break;	
				
			case 'E':
				++ucestalost[4];
				break;	
				
			case 'F':
				++ucestalost[5];
				break;
				
			case 'G':
				++ucestalost[6];
				break;	
			
			case 'H':
				++ucestalost[7];
				break;
			
			case 'I':
				++ucestalost[8];
				break;
			
			case 'J':
				++ucestalost[9];
				break;
			
			case 'K':
				++ucestalost[10];
				break;
			
			case 'L':
				++ucestalost[11];
				break;
			
			case 'M':
				++ucestalost[12];
				break;
				
			case 'N':
				++ucestalost[13];
				break;
			
			case 'O':
				++ucestalost[14];
				break;
			
			case 'P':
				++ucestalost[15];
				break;
			
			case 'R':
				++ucestalost[16];
				break;
			
			case 'S':
				++ucestalost[17];
				break;
				
			case 'T':
				++ucestalost[18];
				break;	
				
			case 'U':
				++ucestalost[19];
				break;	
				
			case 'V':
				++ucestalost[20];
				break;	
				
			case 'Z':
				++ucestalost[21];
				break;
			}
	}
	
	for(int i=10;i>0;--i){
		for(int j=0;j<22;++j){
			if(ucestalost[j]>=i){
				izlazfajl<<"*";
			}
			else{
				izlazfajl<<" ";
			}
		}
		izlazfajl<<endl;
	}
	
	izlazfajl<<"ABCDEFGHIJKLMNOPRSTUVZ";

	return 0;
}