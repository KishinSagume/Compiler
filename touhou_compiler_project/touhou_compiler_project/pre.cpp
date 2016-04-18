#include "pre.h"
#include "err.h"

std::vector<std::pair<std::pair<std::string, std::string>,int> > all_line;//每一行
std::vector<std::string> file_name;

void read_file(std::string & filename, int fileline) {//把一个文件的字符流加入all_line,并且是带行数的(在自己文件中的行数)
	std::fstream file;
	file.open(filename);
	if (!file) {
		pre_err(fileline, filename + " can't open.");
		return;
	}
	int line = 1;
	std::string str;

	while (getline(file, str)) {
		std::pair<std::string, std::string> r(str, filename);
		std::pair<std::pair<std::string, std::string>, int> t(r, line++);
		all_line.push_back(t);
	}
	file.close();
}

void include_file(std::string & filename, int fileline, std::vector<std::pair<std::pair<std::string, std::string>, int> >::iterator & it) {//把一个文件的字符流加入all_line指定行之后,并且是带行数的(在自己文件中的行数)
	std::fstream file;
	file.open(filename);
	if (!file) {
		pre_err(fileline, filename + " can't open.");
		return;
	}
	int line = 1;
	std::string str;
	int count = 0;
	while (getline(file, str)) {
		std::pair<std::string, std::string> r(str, filename);
		std::pair<std::pair<std::string, std::string>, int> t(r, line++);
		it = all_line.insert(it + 1, t);
		count++;
	}
	it = it - count;
	file.close();
}

void deal_first(std::vector<std::pair<std::pair<std::string, std::string>, int> >::iterator & now) {//第一次处理
	while (now != all_line.end()) {
		if (now->first.first.begin() == now->first.first.end()) {
			now++;
			continue;
		}
		switch (*(now->first.first.begin())) {
		case '#':
			now->first.first.erase(0, 1);                                           //删除#
			now->first.first.erase(0,first_real(now->first.first));                 //删除#之后的空格
			now->first.first.insert(0, "#");                                        //把#加回来...
			if (now->first.first.compare(1, 7, "include") == 0)
				if (now->first.first.size() > 8) {
					include(now->first.first.substr(8), now);                      //include一个文件
					now->first.first.clear();
				}
				else {
					pre_err(now->second, " lack file after #include.");
					now->first.first.clear();
					break;
				}

			break;


		case ' ':
		case '	':
			now->first.first.erase(0, first_real(now->first.first));            //删除空格
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

void deal_second(std::vector<std::pair<std::pair<std::string, std::string>, int> >::iterator & now) {//处理define和ifdef等
	//while (now != all_line.end()) {
	//	if (now->first.first.begin() == now->first.first.end()) {
	//		now++;
	//		continue;
	//	}
	//	switch (*(now->first.first.begin())) {
	//	case '#':
	//	}
	//}
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
}

void include(std::string str, std::vector<std::pair<std::pair<std::string, std::string>, int> >::iterator & it) {//it为#include语句这行的迭代器
	std::string name = str;
	name.erase(0, first_real(name));//删除前面的空格
	if (name[0] == '"') {
		name.erase(0, 1);
		int i = name.find_last_of('"');
		if (i == std::string::npos) {
			pre_err(all_line.back().second, " lack of \" after file name.");
			return;
		}
		name.erase(i, 1);
		std::cout << "++++++++++++>>>   " << name << "    <<<+++++++++++++++";
		include_file(name, 1, it);
		return;
	}
	if (name[0] == '<') {
		std::cout << "还没写" << std::endl;
		return;
	}
	else pre_err(all_line.back().second, "some err in #include");
}