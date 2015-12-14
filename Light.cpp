/*
 * Light.cpp
 *
 *  Created on: Dec 14, 2015
 *      Author: dv14cks
 */

#include "Light.hpp"

Light::Light()
{
	// TODO Auto-generated constructor stub

}

Light::~Light()
{
	// TODO Auto-generated destructor stub
}

void Light::InvalidateLightPos() {
	if (invalid_light_pos != nullptr)
		*invalid_light_pos = true;
}

void Light::SetInvalidLightPosRef(bool* invalid_light_pos) {
	this->invalid_light_pos = invalid_light_pos;
}

float* Light::GetIntensity() {
	return value_ptr(intensity);
}

float* Light::GetPosition() {
	return value_ptr(position);
}
