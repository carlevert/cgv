#include "LineReader.hpp"

LineReader::LineReader()
{
	input_stream = nullptr;
	line_no = 0;
}

LineReader::~LineReader()
{
	input_stream->close();
}

LineReader* LineReader::Open(string filename)
{
	ifstream* input_stream = new ifstream();
	input_stream->open(filename);
	if (!input_stream->is_open()) {
		cerr << "Could not open " << filename << " for reading" << std::endl;
		delete input_stream;
		return nullptr;
	}
	else {
		LineReader* line_reader = new LineReader();
		line_reader->filename = filename;
		line_reader->input_stream = input_stream;
		return line_reader;
	}
}

boost::optional<string> LineReader::GetLine()
{
	string line;
	getline(*this->input_stream, line);
	line_no++;
	if (input_stream->fail()) {
		if (input_stream->eof())
			return boost::none;
		cerr << filename << ":" << line_no;
		if (input_stream->bad())
			cerr << " Irrecoverable stream error" << endl;
		else
			cerr << " Input/output operation failed" << endl;
		return boost::none;
	}
	return line;
}

int LineReader::GetLineNo()
{
	return line_no;
}

string LineReader::GetFilename()
{
	return filename;
}