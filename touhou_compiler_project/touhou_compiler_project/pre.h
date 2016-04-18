#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

void read_file(std::string&, int);
void deal_first(std::vector<std::pair<std::pair<std::string, std::string>, int> >::iterator &);
void include(std::string, std::vector<std::pair<std::pair<std::string, std::string>, int> >::iterator&);
void define();
void undef();
void ifdef();
void ifndef();
void endif();
//void del_line();
void del(std::vector<std::pair<std::pair<std::string, std::string&>, int> >::iterator & now);



void print_a_l();
int first_real(std::string&);



