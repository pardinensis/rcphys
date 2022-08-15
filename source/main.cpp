#include "common.hpp"
#include "exporter.hpp"
#include "trackpoint.hpp"


int main() {
    std::vector<float> verticalAccels;
    std::vector<float> rotationalAccels;

    // fill in the acceleration values
    // the following values generate a zero-G roll inversion
    for (int i = 0; i < 8; ++i) {
        verticalAccels.push_back(30);
        rotationalAccels.push_back(0);
    }
    verticalAccels.push_back(20);
    rotationalAccels.push_back(0);
    verticalAccels.push_back(10);
    rotationalAccels.push_back(0);
    for (int i = 0; i < 15; ++i) {
        verticalAccels.push_back(0);
        rotationalAccels.push_back(2.79);
    }
    for (int i = 0; i < 15; ++i) {
        verticalAccels.push_back(0);
        rotationalAccels.push_back(-2.79);
    }
    verticalAccels.push_back(20);
    rotationalAccels.push_back(0);
    verticalAccels.push_back(10);
    rotationalAccels.push_back(0);
    for (int i = 0; i < 8; ++i) {
        verticalAccels.push_back(30);
        rotationalAccels.push_back(0);
    }


    TrackPoint tp;
    tp.linearVelocity = 30;
    tp.rotationalVelocity = 0;

    std::vector<TrackPoint> track;
    track.push_back(tp);
    for (unsigned int i = 0; i < verticalAccels.size(); ++i) {
        tp = tp.next(verticalAccels[i], 0, rotationalAccels[i]);
        track.push_back(tp);
    }

    exportTrackSegment(track);

    return 0;
}
