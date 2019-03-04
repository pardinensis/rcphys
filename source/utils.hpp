#pragma once

#include "common.hpp"

namespace util {
	std::vector<glm::uvec3> convertIndices(const std::vector<glm::uvec4>& quads);
}