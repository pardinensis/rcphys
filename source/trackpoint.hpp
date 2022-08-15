#pragma once

#include "common.hpp"

class TrackPoint {
public:
    glm::vec3 pos;
    glm::quat rot;
    float linearVelocity;
    float rotationalVelocity;

public:
    TrackPoint() : pos(0, 0, 0), rot(1, 0, 0, 0), linearVelocity(10), rotationalVelocity(0) {}

    inline glm::vec3 getLeft() const {
        return rot * glm::vec3(-1, 0, 0);
    }

    inline glm::vec3 getRight() const {
        return rot * glm::vec3(1, 0, 0);
    }

    inline glm::vec3 getDown() const {
        return rot * glm::vec3(0, -1, 0);
    }

    inline glm::vec3 getUp() const {
        return rot * glm::vec3(0, 1, 0);
    }

    inline glm::vec3 getForward() const {
        return rot * glm::vec3(0, 0, -1);
    }

    inline glm::vec3 getBackward() const {
        return rot * glm::vec3(0, 0, 1);
    }

    glm::vec3 getTrackPos() const;


    TrackPoint next(float a_vertical, float a_horizontal, float a_rotational) const;

    friend std::ostream& operator<<(std::ostream& os, const TrackPoint& tp);
};