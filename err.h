#pragma once
#include<iostream>
#include<string>
#include<vector>

void pre_err(const int line, const std::string err);

void print_pre_err();

void token_err(const std::string err);

void print_token_err();

void parser_err(const std::string err);

void print_parser_err();

void mean_err(const std::string err);

void print_mean_err();