#include<iostream>
#include<fstream>
#include<string>
#include<vector>

#include"pre.h"
#include"err.h"
extern std::vector<std::pair<std::pair<std::string, std::string&>, int> > all_line;
extern std::vector<std::string> file_name;

int main() {
	std::string name = "C:/Users/Kisin Sagume/Desktop/test/err.cpp";
	read_file(name,1);
	print_a_l();
	std::cout << std::endl;
	std::vector<std::pair<std::pair<std::string, std::string&>, int> >::iterator now = all_line.begin();
	
	deal_first(now);
	std::cout << std::endl;
	print_a_l();
	std::cout << std::endl;
	print_pre_err();
	system("pause");
	return 0;
}