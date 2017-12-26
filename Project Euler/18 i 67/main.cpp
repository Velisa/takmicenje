#include <iostream>
#include <math.h>
#include <fstream>
#include <sstream>

struct Pyramid{
	int *data;
	unsigned int datac;
	Pyramid(const int* passData, const unsigned int& datac);
	~Pyramid();
	void transform();
	void reduce(const unsigned int& row);
	void print();
	void printP();
	void printr();
};

unsigned int max(const unsigned int& n1, const unsigned int& n2){
	return n1 < n2 ? n2 : n1;
}

bool isCorrectCount(const unsigned int& datac){
	unsigned int sum = 0;
	for(unsigned int i = 0; true; i++){
		sum += i;
		if(datac == sum) return true;
		if(datac < sum) return false;
	}
}

Pyramid::Pyramid(const int* passData, const unsigned int& passDatac){
	datac = passDatac;
	data = new int[datac];
	if(!isCorrectCount(datac)){
		std::cout << "The passed array size doesn't correspond to a triangular number, therefor it may result in a future error. The pyramid is not initialized correctly" << std::endl;
		return;
	}
	for(unsigned int i = 0; i < datac; i++){
		data[i] = passData[i];
	}
}

Pyramid::~Pyramid(){
	delete[] data;
}

void Pyramid::printP(){
	int count = 0;
	int lineEnder = 1;
	for(int i = 0; i < datac; i++){
		std::cout<<data[i];
		count ++;
		if(count == lineEnder){
			count = 0;
			lineEnder++;
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

void Pyramid::transform(){
	int height = (-1 + sqrt(1+8*datac) / 2) + 1;
	int *tempData = new int[height * height];
	unsigned int skip = 0;
	unsigned int count = 0;
	for(unsigned int y = 0; y < height; y++){
		for(unsigned int x = 0; x < height; x++){
			unsigned int toFetch = count;
			unsigned int dataAt = x + y * height;
			if(x > y) {
				tempData[dataAt] = -1;
				continue;
			}
			count++;
			tempData[dataAt] = data[toFetch];
		}
		skip++;
	}
	delete[] data;
	data = new int[height * height];
	for(unsigned int i = 0; i < height * height; i++){
		data[i] = tempData[i];
	}
	delete[] tempData;
	datac = height;
}

void Pyramid::print(){
	for(unsigned int y = 0; y < datac; y++){
		for(unsigned int x = 0; x < datac; x++){
			std::cout << data[x + y * datac];
		}
		std::cout << std::endl;
	}
}

void Pyramid::reduce(const unsigned int& row){
	for(unsigned int i = 0; i < datac; i++){
		if(data[i + (row - 1) * datac] < 0) break;
		data[i + (row - 1) * datac] += max(data[i + row * datac], data[i+1 + row * datac]);
	}
	for(int i = 0; i < datac; i++) data[i + row * datac] = -1;
}

void Pyramid::printr(){
	for(unsigned int i = 0; i < datac * datac; i++){
		if(data[i] > -1) std::cout << data[i] << std::endl;
	}
}

int main(){
	int data[5050];
	std::string line;
	std::ifstream myfile ("numbers.txt");
	unsigned int counter = 0;
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
			std::stringstream reg;
			for(unsigned int i = 0; i < line.length(); i++){
				if(line[i] == ' '){
					data[counter] = std::stoi(reg.str());
					reg.str("");
					reg.clear();
					counter++;
					continue;
				}
				reg << line[i];
			}
    }
    myfile.close();
  }else  std::cout << "Unable to open file" << std::endl; 
	Pyramid pyramid(&(data[0]), sizeof(data) / sizeof(int));
	pyramid.transform();
	for(unsigned int i = pyramid.datac - 1; i > 0; i--){
		pyramid.reduce(i);
	}
	pyramid.printr();
}

