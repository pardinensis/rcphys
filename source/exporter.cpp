#include "exporter.hpp"
#include "utils.hpp"

const std::vector<glm::vec3> spineVertices = {
    // left spine
    {-0.8f + 0.1414f, -1.5f + 0.0f, 0.0f},
    {-0.8f + 0.1f, -1.5f + 0.1f, 0.0f},
    {-0.8f + 0.0f, -1.5f + 0.1414f, 0.0f},
    {-0.8f - 0.1f, -1.5f + 0.1f, 0.0f},
    {-0.8f - 0.1414f, -1.5f + 0.0f, 0.0f},
    {-0.8f - 0.1f, -1.5f - 0.1f, 0.0f},
    {-0.8f + 0.0f, -1.5f - 0.1414f, 0.0f},
    {-0.8f + 0.1f, -1.5f - 0.1f, 0.0f},

    // right spine
    {0.8f + 0.1414f, -1.5f + 0.0f, 0.0f},
    {0.8f + 0.1f, -1.5f + 0.1f, 0.0f},
    {0.8f + 0.0f, -1.5f + 0.1414f, 0.0f},
    {0.8f - 0.1f, -1.5f + 0.1f, 0.0f},
    {0.8f - 0.1414f, -1.5f + 0.0f, 0.0f},
    {0.8f - 0.1f, -1.5f - 0.1f, 0.0f},
    {0.8f + 0.0f, -1.5f - 0.1414f, 0.0f},
    {0.8f + 0.1f, -1.5f - 0.1f, 0.0f},

    // center spine
    {0.0f + 0.3f, -2.0f + 0.3f, 0.0f},
    {0.0f - 0.3f, -2.0f + 0.3f, 0.0f},
    {0.0f - 0.3f, -2.0f - 0.3f, 0.0f},
    {0.0f + 0.3f, -2.0f - 0.3f, 0.0f},
};

const std::vector<glm::uvec3> spineTriangles = {
    // left spine
    {0, 20, 1},
    {1, 20, 21},
    {1, 21, 2},
    {2, 21, 22},
    {2, 22, 3},
    {3, 22, 23},
    {3, 23, 4},
    {4, 23, 24},
    {4, 24, 5},
    {5, 24, 25},
    {5, 25, 6},
    {6, 25, 26},
    {6, 26, 7},
    {7, 26, 27},
    {7, 27, 0},
    {0, 27, 20},

    // right spine
    {8, 28, 9},
    {9, 28, 29},
    {9, 29, 10},
    {10, 29, 30},
    {10, 30, 11},
    {11, 30, 31},
    {11, 31, 12},
    {12, 31, 32},
    {12, 32, 13},
    {13, 32, 33},
    {13, 33, 14},
    {14, 33, 34},
    {14, 34, 15},
    {15, 34, 35},
    {15, 35, 8},
    {8, 35, 28},

    // center spine
    {16, 36, 17},
    {17, 36, 37},
    {17, 37, 18},
    {18, 37, 38},
    {18, 38, 19},
    {19, 38, 39},
    {19, 39, 16},
    {16, 39, 36},
};

void exportTrackSegment(const std::vector<TrackPoint>& track) {
    std::vector<glm::vec3> segmentVertices;
    std::vector<glm::uvec3> segmentIndices;

    // spines
    for (unsigned int i = 0; i < track.size(); ++i) {
        for (glm::vec3 v : spineVertices) {
            segmentVertices.push_back(track[i].rot * v + track[i].pos);
        }
    }
    for (unsigned int i = 0; i < track.size() - 1; ++i) {
        unsigned int indexOffset = i * spineVertices.size();
        for (glm::uvec3 t : spineTriangles) {
            segmentIndices.push_back(glm::uvec3(t.x + indexOffset, t.y + indexOffset, t.z + indexOffset));
        }
    }

    //

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