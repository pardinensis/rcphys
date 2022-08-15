#include "utils.hpp"


std::vector<glm::uvec3> util::convertIndices(const std::vector<glm::uvec4>& quads) {
	std::vector<glm::uvec3> tris;
	tris.reserve(2 * quads.size());
	for (const glm::uvec4& quad : quads) {
		tris.push_back(glm::vec3(quad.x, quad.y, quad.z));
		tris.push_back(glm::vec3(quad.x, quad.z, quad.w));
	}
	return tris;
}