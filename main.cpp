#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <algorithm>

using namespace std;

std::string ZeroPadNumber(int num, int pad) {
	std::ostringstream ss;
	ss << std::setw(pad) << std::setfill('0') << num;
	return ss.str();
}

void ReplaceChar(string & input_output, char from, char to) {
	std::replace(input_output.begin(), input_output.end(), from, to);

}

void Convert(string input, string output) {
	ifstream t(input.c_str());
	string str;
	t.seekg(0, std::ios::end);
	str.reserve((unsigned int) (t.tellg()));
	t.seekg(0, std::ios::beg);
	str.assign((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());

	ReplaceChar(str, ',', ' ');

	unsigned int num_lines = std::count(str.begin(), str.end(), '\n');
	unsigned int num_chars = str.size();

	cout << "lines: " << num_lines << " chars: " << num_chars << endl;


	float pos_x,pos_y,pos_z;
	float quat_w,quat_x,quat_y,quat_z;
	float vel_x,vel_y,vel_z;
	float rad_x,rad_y,rad_z;
	int type;

	stringstream data_stream(str);

	for (int i = 0; i < num_lines; i++) {
		data_stream>>pos_x>>pos_y>>pos_z;
		data_stream>>quat_w>>quat_x>>quat_y>>quat_z;
		data_stream>>vel_x>>vel_y>>vel_z;
		data_stream>>type;

		if(type==0){
			data_stream>>rad_x;
		}

		cout<<type<<endl;
	}
}

int main(int argc, char * argv[]) {
	string prefix = "", filetype = "";
	int pad_zeros = 0;
	int start = 0, end = 0;

	if (argc == 6) {

		prefix = argv[1];
		pad_zeros = atoi(argv[2]);
		filetype = argv[3];

		start = atoi(argv[4]);
		end = atoi(argv[5]);
	} else if (argc == 5) {

		pad_zeros = atoi(argv[1]);
		filetype = argv[2];

		start = atoi(argv[3]);
		end = atoi(argv[4]);

	}

	for (int i = start; i < end; i++) {
		stringstream fname;
		fname << prefix << ZeroPadNumber(i, pad_zeros) << filetype;
		cout << fname.str() << endl;
		Convert(fname.str(), "blah");

	}

}
