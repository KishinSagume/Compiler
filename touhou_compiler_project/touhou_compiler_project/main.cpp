#include<iostream>
#include<fstream>
#include<string>
#include<vector>

#include"pre.h"
#include"err.h"
extern std::vector<std::pair<std::pair<std::string, std::string>, int> > all_line;
extern std::vector<std::string> file_name;

int main() {
	std::string name = "C:/Users/Administrator/Desktop/touhou_compiler_project/Debug/pre.h";
	read_file(name,1);
	std::cout << "����֮ǰ" << std::endl;
	print_a_l();
	std::cout << std::endl;

	std::vector<std::pair<std::pair<std::string, std::string>, int> >::iterator now = all_line.begin();
	deal_first(now);
	std::cout << std::endl << "��һ�δ���֮��" << std::endl;
	print_a_l();

	now = all_line.begin();
	deal_second(now);
	std::cout << std::endl << "�ڶ��δ���֮��" << std::endl;
	print_a_l();

	std::cout << std::endl << "����:" << std::endl;
	print_pre_err();
	system("pause");
	return 0;
}