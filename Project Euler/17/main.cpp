#include <iostream>
#include <string>

unsigned int countLetters(unsigned int size, const char* sentence){
	unsigned int count = 0;
	for(unsigned int i = 0; i < size; i++){
		char c = sentence[i];
		if(c != ' ' && c!= '-')
		count++;
	}
	return count;
}

unsigned int stringToLetterCount(unsigned int num){
	std::string ones[] = {
		"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
	};
	std::string tens[] = {
		"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
	};
	std::string weird[] = {
		"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
	};
	#define c(x) countLetters(x.length(),x.c_str())
	if(num < 10){
		std::cout << ones[num - 1] << std::endl;
		return c(ones[num-1]);
	}
	if(num == 10){
		std::cout << "ten" << std::endl;
		return c(std::string("ten"));
	}
	if(num < 20){
		std::cout << weird[num % 10 - 1] << std::endl;
		return c(weird[num%10 - 1]);
	}
	if(num < 100){
		std::string otherString = tens[num / 10 % 10 - 1];
		if(num % 10 != 0){
			otherString  += '-' + ones[num % 10 - 1];
		}
		std::cout << otherString << std::endl;
		return c(otherString);
	}
	if(num == 100){
		std::cout << "one hundred" << std::endl;
		return c(std::string("one hundred"));
	}
	if(num < 1000){
		std::string otherString = ones[num / 100 - 1] + " hundred";
		unsigned int rest = num % 100;
		if(rest != 0){
			otherString += " and ";
			if(rest / 10 == 0){
				otherString += ones[rest % 10 - 1];
			}else{
				if(rest %10 == 0){
					otherString += tens[rest / 10 - 1];
				}else if(rest < 20){
					otherString += weird[rest % 10 - 1];
				}else{
					otherString += tens[rest / 10 % 10 - 1] + '-' + ones[rest % 10 - 1];
				}
			}
		}
		std::cout << otherString << std::endl;
		return c(otherString);
	}
	return c(std::string("one thousand"));
	#undef c
}

int main(){
	unsigned long long sum = 0;
	for(unsigned int i = 1; i <= 1000; i++){
		sum += stringToLetterCount(i);
	}
	std::cout << sum << std::endl;
	std::cout << stringToLetterCount(115);
}
