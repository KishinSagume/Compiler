#include "pre.h"
#include<iostream>
extern std::fstream file;

bool deal_line() {
	while (file.peek()!=-1) {

		std::cout << (char)file.peek(); system("pause");
		switch (file.peek()) {

		case 'd':
			file.get();
			if (file.get() == 'e')
				if (file.get() == 'f')
					if (file.get() == 'i')
						if (file.get() == 'n')
							if (file.get() == 'e')
								if (file.get() == ' ') {
									std::string old_str = get_pre_old();
									if (!old_str.empty() && file.get() == ' ') {
										std::string new_str = get_pre_new();
										if (!new_str.empty())
											//加入宏替换
											;
									}
								}
			pre_err(pre_line, " line:  not a #include ");
			return false;

			
			/*
		case '\\':
			file.get();
			if (file.peek() == '\n') {
				char_stream.push_back(file.get());
				pre_line++;
				return false;
			}
			else {
				pre_err(pre_line, " line:  should \\r\\n after \\ ");
				while (file.peek() != -1) {//错误恢复,放弃当前行
					if (file.peek() == '\n') {
						char_stream.push_back(file.get());
						pre_line++;
						return false;
					}
					file.get();
				}
				pre_err(pre_line, " line:  meet eof in wrong place ");
				return false;
			}*/

			//////


		default:file.get(); break;




		}

		
	}
}

bool deal_pre() {
	while (file.peek() != -1) {
		switch (file.peek()) {

		case '#':
			if(!deal_line()) return false;
			break;

		case '/':
			deal_xiegang();
			break;

		case '\n':
			char_stream.push_back(file.get());
			pre_line++;
			break;

		default:
			char_stream.push_back(file.get());
			break;
		}
	}
	return true;
}

bool deal_xiegang() {
	file.get();

	switch (file.peek()) {

	case '/':
		file.get();
		zhushiyihang();
		break;

	case '*':
		file.get();
		zhushiyikuai();
		break;

	default:
		char_stream.push_back('/');
		char_stream.push_back(file.get());
		break;
	}
	return false;
}

bool zhushiyihang() {
	while (file.peek()!=-1) {
		switch (file.peek()) {
		case '\n':
			pre_line++;
			char_stream.push_back(file.get());
			return true;
			
		default:
			file.get();
			break;
		}
	}
	pre_err(pre_line, " line:  lack \\n after //");
	return false;
}

bool zhushiyikuai() {
	while (file.peek() != -1) {
		switch (file.peek()) {
		case '\n':
			pre_line++;
			char_stream.push_back(file.get());
			break;

		case '*':
			file.get();
			if (file.get() == '/')
				return true;

		default:
			file.get();
			break;
		}
	}
	pre_err(pre_line, " line:  lack */ after //");
	return false;
}

std::string get_pre_old() {
	return std::string();
}

std::string get_pre_new() {
	return std::string();
}

bool deal_define() {
	return false;
}

bool deal_undef(){
	return false;
}

bool deal_include(std::string file){
	return false;
}

bool deal_ifdef(){
	return false;
}

bool deal_ifndef(){
	return false;
}

bool deal_endif(){
	return false;
}

