#include "OffParser.hpp"

Object * OffParser::ParseOffFile(string filename)
{
  LineReader *line_reader = LineReader::Open(filename);
  Object *object;
  boost::optional<string> line;
  const unsigned int VERTEX = 0;
  const unsigned int FACE = 1;
  const unsigned int EDGE = 2;

  /* Check if first line is a valid header, if not return nullptr */
  line = line_reader->GetLine();
  if (line && IsValidOffHeader(*line))
    object = new Object();
  else {
    cerr << filename << " does not have a valid header" << endl;
    return nullptr;
  }

  /* First line after header line contains some metadata */
  int *count = nullptr;
  if ((line = line_reader->GetLine())) {
    count = ParseVertexFaceEdgeCount(*line);
    if (count != nullptr) {
      object->SetNumVertices(count[VERTEX]);
      object->SetNumFaces(count[FACE]);
      object->SetNumEdges(count[EDGE]);
    }
  }

  /* Add vertices to object */
  while ((count[VERTEX]-- > 0) && (line = line_reader->GetLine())) {
    float *vertex = ParseVertexCoordinate(*line);
    if (vertex != nullptr) {
      object->AddVertex(vertex);
    }
    else {
      delete object;
      return nullptr;
    }
  }

  /* Add faces to object */
  while ((count[FACE]-- > 0) && (line = line_reader->GetLine())) {
    Face *face = ParseFaceDefinition(*line);
    object->AddFace(face);
  }

  delete count;
  return object;
}

bool OffParser::IsValidOffHeader(string line)
{
  string header_pattern = "^OFF(?:\\s*$)|(?:\\s+\\#.*$)";
  boost::regex header_expr(header_pattern);
  return boost::regex_match(line, header_expr);
}

float* OffParser::ParseVertexCoordinate(string line)
{
  // https://regex101.com/r/fU6qC3/2
  // ^\s*(-?\d*(?:\.\d+)?)\s+(-?\d*(?:\.\d+)?)\s+(-?\d*(?:\.\d+)?)(?:(?:\s*$)|(?:\s+\#.*$))

  string triplet_pattern =
    "(?:^\\s*(-?\\d*(?:\\.\\d+)?)\\s+(-?\\d*(?:\\.\\d+)?)\\s+(-?\\d*(?:\\.\\d+)?)(?:(?:\\s*$)|(?:\\s+\\#.*$)))";

  float *coordinates = nullptr;
  boost::regex triplet_expr(triplet_pattern);
  boost::smatch what;
  if (boost::regex_match(line, what, triplet_expr)) {
    coordinates = new float[3];
    for (unsigned int i = 1; i < what.size(); i++)
      coordinates[i - 1] = boost::lexical_cast<float>(what[i]);
  }
  return coordinates;
}


int* OffParser::ParseVertexFaceEdgeCount(string line)
{
  string int_triplet_pattern = "^\\s*(\\d*)\\s+(\\d*)\\s+(\\d*)(?:(?:\\s*$)|(?:\\s+\\#.*$))";

  int *count = nullptr;
  boost::regex int_triplet_expr(int_triplet_pattern);
  boost::smatch what;
  if (boost::regex_match(line, what, int_triplet_expr)) {
    count = new int[3];
    for (unsigned int i = 1; i < what.size(); i++)
      count[i - 1] = boost::lexical_cast<unsigned int>(what[i]);
  }
  return count;
}



Face* OffParser::ParseFaceDefinition(string line)
{
  Face *face = new Face();

  /* Get num vertices for face */
  boost::regex num_vertices_expr("^\\s*(\\d+)\\s+(.*)$");
  boost::smatch what;
  unsigned int num_vertices = 0;
  if (boost::regex_match(line, what, num_vertices_expr) && what.size() == 3) {
    num_vertices = boost::lexical_cast<unsigned int>(what[1]);
    line = what[2];
  }

  /* Get vertices */
  unsigned int *vertices = new unsigned int[num_vertices];
  string vertices_pattern = "^((?:\\d+)(?:\\s+(?:\\d+)){" + std::to_string(num_vertices - 1) + "})\\s*(.*)$";
  boost::regex vertices_expr(vertices_pattern);
  if (boost::regex_match(line, what, vertices_expr)) {
    /* Capture num_vertices from line, split on ' ' and parse integer values */
    vector<string> vertices_vector;
    string w = what[1];
    boost::split(vertices_vector, w, boost::is_any_of(" "), boost::token_compress_on);
    for (unsigned int i = 0; i < num_vertices; i++)
      vertices[i] = boost::lexical_cast<unsigned int>(vertices_vector[i]);

    /* Rest of line should be color information and/or comments */
    // line = what[2];
  }

  face->SetNumVertices(num_vertices);
  face->SetVertexIndicies(vertices);

  return face;
}
