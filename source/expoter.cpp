#include "exporter.hpp"
#include "utils.hpp"

const std::vector<glm::vec3> vertices = {
	{-0.6f, -1.4f, 0.0f},
	{-0.6f, -1.6f, 0.0f},
	{-0.8f, -1.6f, 0.0f},
	{-0.8f, -1.4f, 0.0f},
	{ 0.6f, -1.4f, 0.0f},
	{ 0.6f, -1.6f, 0.0f},
	{ 0.8f, -1.6f, 0.0f},
	{ 0.8f, -1.4f, 0.0f},
};

const std::vector<glm::uvec4> indices = {
	{ 0,  1,  9,  8},
	{ 1,  2, 10,  9},
	{ 2,  3, 11, 10},
	{ 3,  0,  8, 11},
	{ 4,  5, 13, 12},
	{ 5,  6, 14, 13},
	{ 6,  7, 15, 14},
	{ 7,  4, 12, 15},
};

void exportTrackSegment(const TrackPoint& a, const TrackPoint& b) {
	std::vector<glm::vec3> segmentVertices;
	for (glm::vec3 v : vertices) {
		segmentVertices.push_back(a.rot * v);
	}
	for (glm::vec3 v : vertices) {
		segmentVertices.push_back(b.rot * v);
	}
	std::vector<glm::uvec3> segmentIndices = util::convertIndices(indices);


	std::ofstream ofs("track.obj");
	if (ofs.is_open()) {
		for (const glm::vec3& v : segmentVertices) {
			ofs << "v " << v.x << " " << v.y << " " << v.z << std::endl;
		}
		for (const glm::uvec3& i : segmentIndices) {
			ofs << "f " << i.x+1 << " " << i.y+1 << " " << i.z+1 << std::endl;
		}
		ofs.close();
	}
}