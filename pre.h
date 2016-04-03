#pragma once
#include<fstream>
#include<vector>
#include"err.h"
int pre_line = 1;

bool deal_line();
bool deal_pre();
bool deal_define();
bool deal_undef();
bool deal_include(std::string file);
bool deal_ifdef();
bool deal_ifndef();
bool deal_endif();
bool deal_xiegang();
bool zhushiyihang();
bool zhushiyikuai();
std::string get_pre_old();
std::string get_pre_new();


void def(std::string str_old, std::string str_new);
bool is_def(std::string str);
void use_def(std::string str);


std::vector<char> char_stream;


static class pre {
public:
	void add_pre(std::string str_old, std::string str_new, int line);
	std::string swap_pre(std::string str, int line);
	void del_pre(std::string str_old, int line);
	bool find_pre(std::string str_old, int line);
private:
	std::vector<std::pair<int, std::pair<std::string, std::string> > > pre_swap;
}pre_swap;