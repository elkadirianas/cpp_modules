#include <iostream>
#include <fstream>

std::string replace_all(const std::string& line, const std::string& s1, const std::string& s2) {
    if (s1.empty()) 
        return line;

    std::string res;
    size_t pos = 0;
    size_t found;

    while ((found = line.find(s1, pos)) != std::string::npos) {
        res.append(line, pos, found - pos); 
        res.append(s2);                      
        pos = found + s1.length();           
    }

    res.append(line, pos, line.size() - pos);
    return res;
}

int main(int argc, char **argv) {
	if (argc!=4) {
		std::cerr<<"Error"<<std::endl;
		return 1;
	}
	std::string file_Name = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream in_f(file_Name.c_str());

	if (!in_f.is_open()) {
		std::cerr<<"Cannot open the file"<<std::endl;
		return (1);
	}
	std::string outfileName = file_Name + ".replace";
	std::ofstream out_f(outfileName.c_str());

	if (!out_f.is_open()) {
		std::cerr<<"Cannot open the file"<<std::endl;
		return 1;
	}
	std::string buff;
	std::getline(in_f, buff, '\0');
	out_f << replace_all(buff, s1, s2);
	return 0;
}