#include<iostream>
#include<fstream>
#include<string>
std::fstream file;
bool deal_pre();
void print_pre_err();

int main() {
	file.open("C:/Users/Administrator/Desktop/test/test1.txt", std::fstream::in);
	if (!file) {
		std::cout << "can't open source file" << std::endl;
		system("pause");
		return 0;
	}
	deal_pre();
	print_pre_err();
	file.close();
	system("pause");
	return 0;
}