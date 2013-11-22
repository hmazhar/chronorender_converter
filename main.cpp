#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <algorithm>

using namespace std;

std::string ZeroPadNumber(int num, int pad)
{
    std::ostringstream ss;
    ss << std::setw( pad ) << std::setfill( '0' ) << num;
    return ss.str();
}

void ReplaceChar(string & input_output, char from, char to){
std::replace( input_output.begin(), input_output.end(), from, to);

}


void Convert(string input, string output){
	ifstream t(input.c_str());
	string str;
	t.seekg(0, std::ios::end);
	str.reserve(uint(t.tellg()));
	t.seekg(0, std::ios::beg);
	str.assign((std::istreambuf_iterator<char>(t)),std::istreambuf_iterator<char>());
	
	ReplaceChar(str,',',' ');


cout<<"lines: " <<std::count(str.begin(), str.end(), '\n')<<" chars: "<<str.size()<<endl;

	//stringstream ss;
	//ss << str;





}

int main(int argc, char * argv[]){
	string prefix,filetype;
	int pad_zeros;
	int start,end;

	prefix = argv[1];
	pad_zeros = atoi(argv[2]);
	filetype= argv[3];

	start = atoi(argv[4]);
	end = atoi(argv[5]);


for(int i=start; i<end; i++){
	stringstream fname;
	fname<<prefix<<ZeroPadNumber(i,pad_zeros)<<filetype;
	//cout<<fname.str();
	Convert(fname.str(),"blah");

}

}