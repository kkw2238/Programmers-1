#include <iostream>

using namespace std;

void star(int a, int b){
	//���α���
	for (int i = 0; i < b; ++i) {
		//���α���
		for (int j = 0; j < a; ++j) {
			cout << "*";
		}
		cout << "\n";
	}
}