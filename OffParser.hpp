#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/regex.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/optional.hpp>

#include "LineReader.hpp"
#include "Object.hpp"
#include "Face.hpp"

using namespace std;

class OffParser {
private:
	static bool IsValidOffHeader(string str);
	static int* ParseVertexFaceEdgeCount(string str);
	static float* ParseVertexCoordinate(string str);
	static Face* ParseFaceDefinition(string str);
public:
	static Object* ParseOffFile(string filename);
};

