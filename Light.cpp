/*
 * Light.cpp
 *
 *  Created on: Dec 14, 2015
 *      Author: dv14cks
 */

#include "Light.hpp"

Light::Light()
{
}

Light::~Light()
{
}

void Light::InvalidateLightPos() {
	if (invalid_light_pos != nullptr)
		*invalid_light_pos = true;
}

void Light::SetInvalidLightPosRef(bool* invalid_light_pos) {
	this->invalid_light_pos = invalid_light_pos;
}

void Light::SetIntensityR(float intensity) {
	this->intensity.r = intensity;
	std::cout << "Red intensity " << intensity << std::endl;
	InvalidateLightPos();
}

void Light::SetIntensityG(float intensity) {
	this->intensity.g = intensity;
	InvalidateLightPos();
}

void Light::SetIntensityB(float intensity) {
	this->intensity.b = intensity;
	InvalidateLightPos();
}

float* Light::GetIntensity() {
	return value_ptr(intensity);
}

float* Light::GetPosition() {
	return value_ptr(position);
}
