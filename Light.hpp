#ifndef LIGHT_HPP_
#define LIGHT_HPP_

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;

class Light {
public:
	Light();
	virtual ~Light();
	void SetInvalidLightPosRef(bool* invalid_light_pos);
	float* GetIntensity();
	void SetIntensityR(float intensity);
	void SetIntensityG(float intensity);
	void SetIntensityB(float intensity);
	float* GetPosition();
private:
	void InvalidateLightPos();
	vec3 position = vec3(1.0f, 1.0f, 5.0f);
	vec3 intensity = vec3(0.5f, 0.6f, 0.7f);
	bool* invalid_light_pos = nullptr;
};

#endif
