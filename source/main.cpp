#include "common.hpp"
#include "trackpoint.hpp"


int main() {
	std::vector<float> verticalAccels;
	for (int i = 0; i < 8; ++i) {
		verticalAccels.push_back(30);
	}
	verticalAccels.push_back(20);
	verticalAccels.push_back(10);
	for (int i = 0; i < 30; ++i) {
		verticalAccels.push_back(0);
	}
	verticalAccels.push_back(20);
	verticalAccels.push_back(10);
	for (int i = 0; i < 8; ++i) {
		verticalAccels.push_back(30);
	}


    TrackPoint tp;
    tp.linearVelocity = 30;
    tp.rotationalVelocity = 1.2;

	std::cout << "x: " << glm::to_string(tp.getRight()) << std::endl;
	std::cout << "y: " << glm::to_string(tp.getUp()) << std::endl;
	std::cout << "z: " << glm::to_string(tp.getBackward()) << std::endl;

    std::ofstream ofs("airtime.txt");
    for (float a : verticalAccels) {
    	ofs << tp.pos.x << " " << -tp.pos.z << " " << tp.pos.y << " ";
    	glm::vec3 trackpos = tp.getTrackPos();
    	ofs << trackpos.x << " " << -trackpos.z << " " << trackpos.y << std::endl;
    	tp = tp.next(a, 0, 0);
    }

    return 0;
}
