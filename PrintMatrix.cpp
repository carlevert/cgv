#include "PrintMatrix.hpp"

void PrintMatrix(glm::mat4 matrix, std::string text) {
	float* values = glm::value_ptr(matrix);
	std::cout << text << std::endl;
	for (int i = 0; i < 16; i++) {
		std::cout << std::fixed << std::right << values[i] << "  ";
		if ((i + 1) % 4 == 0)
			std::cout << std::endl;
	}
}

