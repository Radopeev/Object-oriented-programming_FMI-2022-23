#include "UI.h"

namespace {
	const char FILENAME[] = "set.dat";
	const char CHOOSE_MODE[] = "Choose mode for work(1 or 2):";
	const char WRONG_INPUT[] = "Wrong input";
	const char INPUT_A[] = "Input a:";
	const char INPUT_B[] = "Input b:";
	const char TYPE_NEXT[] = "Type 'next' to see the next element:";
	const char NEXT[] = "next";
	const char NO_MORE_ELEMENTS[] = "No more elements";
}

UI::UI():setFromFile(FILENAME) {
	int input;
	std::cout << CHOOSE_MODE;
	std::cin >> input;
	if (input == 1) {
		std::cout << INPUT_A;
		std::cin >> a;
		std::cout << INPUT_B;
		std::cin >> b;
		interval();
	}
	else if (input == 2) {
		generatingAllElements();
	}
	else std::cout << WRONG_INPUT << std::endl;
}

void UI::interval()const{
	for (int i = a; i < b; i++) {
		if (setFromFile.getSet()->contains(i)){
			std::cout << i << " ";
		}
	}
}


void UI::generatingAllElements()const  {
	int i = INT_MIN;
	std::cout << TYPE_NEXT<<std::endl;
	while(true){
		char buffer[10];
		std::cin >> buffer;
		if (strcmp(buffer, NEXT) == 0) {
			while (!setFromFile.getSet()->contains(i) &&  i!=INT_MAX) {
				i++;
			}
			if (i == INT_MAX) {
				std::cout <<NO_MORE_ELEMENTS ;
				break;
			}
			std::cout << i++ << std::endl;
		}
	}
}
