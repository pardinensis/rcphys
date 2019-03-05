#include "exporter.hpp"
#include "utils.hpp"

const std::vector<glm::vec3> vertices = {
    {-0.6f, -1.4f, 0.0f}, {-0.6f, -1.6f, 0.0f}, {-0.8f, -1.6f, 0.0f}, {-0.8f, -1.4f, 0.0f},
    {0.8f, -1.4f, 0.0f},  {0.8f, -1.6f, 0.0f},  {0.6f, -1.6f, 0.0f},  {0.6f, -1.4f, 0.0f},
};

const std::vector<glm::uvec3> triangles = {
    {0, 1, 9},  {0, 9, 8},   {1, 2, 10}, {1, 10, 9},  {2, 3, 11}, {2, 11, 10}, {3, 0, 8},  {3, 8, 11},
    {4, 5, 13}, {4, 13, 12}, {5, 6, 14}, {5, 14, 13}, {6, 7, 15}, {6, 15, 14}, {7, 4, 12}, {7, 12, 15},
};

void exportTrackSegment(const std::vector<TrackPoint>& track) {
    std::vector<glm::vec3> segmentVertices;
    std::vector<glm::uvec3> segmentIndices;
    for (unsigned int i = 0; i < track.size(); ++i) {
        for (glm::vec3 v : vertices) {
            segmentVertices.push_back(track[i].rot * v + track[i].pos);
        }
    }
    for (unsigned int i = 0; i < track.size() - 1; ++i) {
        unsigned int indexOffset = i * vertices.size();
        for (glm::uvec3 t : triangles) {
            segmentIndices.push_back(glm::uvec3(t.x + indexOffset, t.y + indexOffset, t.z + indexOffset));
        }
    }

    std::ofstream ofs("track.obj");
    if (ofs.is_open()) {
        for (const glm::vec3& v : segmentVertices) {
            ofs << "v " << v.x << " " << v.y << " " << v.z << std::endl;
        }
        for (const glm::uvec3& i : segmentIndices) {
            ofs << "f " << i.x + 1 << " " << i.y + 1 << " " << i.z + 1 << std::endl;
        }
        ofs.close();
    }
}