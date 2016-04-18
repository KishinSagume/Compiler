#include "err.h"

std::vector<std::pair<int, std::string> > PRE_ERR;
std::vector<std::string> TOKEN_ERR;
std::vector<std::string> PARSER_ERR;
std::vector<std::string> MEAN_ERR;

void pre_err(const int line, const std::string err) {
	PRE_ERR.emplace_back(line,err);
}

void print_pre_err() {
	for (auto s : PRE_ERR)
		std::cout << s.first << s.second << std::endl;
}

void token_err(const std::string err) {
	TOKEN_ERR.push_back(err);
}

void print_token_err() {
	for (std::string s : TOKEN_ERR)
		std::cout << s << std::endl;
}

void parser_err(const std::string err) {
	PARSER_ERR.push_back(err);
}

void print_parser_err() {
	for (std::string s : PARSER_ERR)
		std::cout << s << std::endl;
}

void mean_err(const std::string err) {
	MEAN_ERR.push_back(err);
}

void print_mean_err() {
	for (std::string s : MEAN_ERR)
		std::cout << s << std::endl;
}
