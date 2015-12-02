#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include "boost/optional.hpp"

using namespace std;

class LineReader {
public:
	static LineReader* Open(string filename);
	int GetLineNo();
	boost::optional<string> GetLine();
	string GetFilename();
	~LineReader();
private:
	LineReader();
	ifstream* input_stream;
	string filename;
	int line_no;
};