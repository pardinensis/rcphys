#include "common.hpp"
#include "trackpoint.hpp"

TrackPoint TrackPoint::next(float aVertical, float aHorizontal, float aRotational) const {
	TrackPoint next(*this);

	float length = linearVelocity * T_STEP;

	glm::vec3 a_linear = aVertical * getDown() + aHorizontal * getLeft();
	glm::vec3 a_remainder = G - a_linear;
	glm::vec3 a_forward = glm::proj(a_remainder, getForward());
	glm::vec3 a_centripetal = a_remainder - a_forward;

	// rotation because of linear acceleration
	if (glm::length2(a_centripetal) > EPSILON) {
		glm::vec3 axis = glm::normalize(glm::cross(getForward(), a_centripetal));
		float radius = linearVelocity * linearVelocity / glm::length(a_centripetal);
		float angle = length / radius; // small angle approximation
		glm::quat relativeRot = glm::angleAxis(angle, axis);
		next.rot = relativeRot * next.rot;
	}

	// rotation because of rotational acceleration
	float angle = 0.5 * aRotational * T_STEP * T_STEP + rotationalVelocity * T_STEP;
	glm::quat relativeRot = glm::angleAxis(angle, glm::normalize(next.getForward()));
	next.rot = relativeRot * next.rot;

	// position
	next.pos += next.getForward() * length;

	// linearVelocity
	float dHeight = next.pos.y - pos.y;
	next.linearVelocity = std::sqrt(linearVelocity * linearVelocity + 2.f * G.y * dHeight);

	// rotationalVelocity
	next.rotationalVelocity += aRotational * T_STEP;

	return next;
}

glm::vec3 TrackPoint::getTrackPos() const {
	return pos + getDown() * HEARTLINE;
}

std::ostream& operator<<(std::ostream& os, const TrackPoint& tp) {
	os << "{" << std::endl;
	os << "  pos: " << glm::to_string(tp.pos) << std::endl;
	os << "  rot: " << glm::to_string(tp.rot) << std::endl;
	os << "  vel: " << tp.linearVelocity << std::endl;
	os << "}";
	return os;
}

