#include "pre.h"
#include "err.h"

std::vector<std::pair<std::pair<std::string, std::string&>,int> > all_line;
std::vector<std::string> file_name;

void read_file(std::string & filename, int fileline) {
	std::fstream file;
	file.open(filename);
	if (!file) {
		pre_err(fileline, filename + " can't open.");
		return;
	}
	int line = 1;
	std::string str;
	while (getline(file, str)) {
		std::pair<std::string, std::string&> r(str, filename);
		std::pair<std::pair<std::string, std::string&>, int> t(r, line++);
		all_line.push_back(t);
	}
	file.close();
}

void deal_first(std::vector<std::pair<std::pair<std::string, std::string&>, int> >::iterator & now) {//处理一行
	while (now != all_line.end()) {
		if (now->first.first.begin() == now->first.first.end()) {
			now++;
			continue;
		}
		switch (*(now->first.first.begin())) {
		case '#':
			if (now->first.first.find("include", 1) != std::string::npos)
				if (now->first.first.size() > 8)
					include(now->first.first.substr(8));
				else {
					pre_err(now->second, " lack file after #include.");
					now->first.first.clear();
					break;
				}
			break;


		case ' ':
		case '	':
			now->first.first.erase(0, first_real(now->first.first));
			continue;


		default:
			std::string::size_type left = now->first.first.find("/*");
			std::string::size_type linedel = now->first.first.find("//");
			if (linedel != std::string::npos && linedel<left) {
				now->first.first.erase(linedel);
				break;
			}
			if (left != std::string::npos && left<linedel) {
				std::string::size_type right = now->first.first.find("*/", left + 2);
				if (right != std::string::npos)
					now->first.first.erase(left, right - left + 2);
				else {
					now->first.first.erase(left);
					while (++now != all_line.end()) {
						std::string::size_type right = now->first.first.find("*/");
						if (right != std::string::npos) {
							now->first.first.erase(0, right + 2);
							break;
						}
						else now->first.first.erase(0);
					}
					continue;
				}
			}
			
			
		}//switch
		now++;
	}
}

void print_a_l() {
	for (auto s : all_line)
		std::cout << s.first.second<< " " << s.second << ":  " << s.first.first << std::endl;
}

int first_real(std::string & str) {
	std::string::iterator it = str.begin();
	int i = 0;
	while (it != str.end()) {
		if (*it == ' ' || *it == '	') {
			it++;
			i++;
			continue;
		}
		else return i;
	}
	return -1;
}

void include(std::string str) {

}