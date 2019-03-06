#pragma once

#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

#define GLM_ENABLE_EXPERIMENTAL
#define GLM_FORCE_RADIANS
#include <glm/vec3.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/norm.hpp>
#include <glm/gtx/projection.hpp>
#include <glm/gtx/string_cast.hpp>

#include <zlib.h>

// gravity [m/s^2]
const glm::vec3 G = {0.f, -9.81f, 0.f};

// stepsize of a track piece [s]
const float T_STEP = 0.1f;

// epsilon
const float EPSILON = 0.00001f;

// height of the heartline [m]
const float HEARTLINE = -2.0f;

// distance between the track splines [m]
const float GAUGE = 1.6f;

