/*
 * AppWrap.hpp
 */

#ifndef APPWRAP_HPP_
#define APPWRAP_HPP_

#include "Application.hpp"
#include "Projection.hpp"

#include <string>



extern "C" void call_SetFov(Application* a, float fov);
extern "C" void call_SetParallellProjection(Application* a);
extern "C" void call_SetTop(Application* a, float top);
extern "C" void call_SetFar(Application* a, float far);
extern "C" void call_SetObliqueScale(Application* a, float oblique_scale);
extern "C" void call_SetObliqueAngle(Application* a, float oblique_angle);
extern "C" void call_SetPerspectiveProjection(Application* a);

extern "C" void call_SetLightIntensityR(Application* a, float value);
extern "C" void call_SetLightIntensityG(Application* a, float value);
extern "C" void call_SetLightIntensityB(Application* a, float value);


extern "C" void call_OpenOffFile(Application* a, char* filename);
extern "C" void call_FlipNormals(Application* a, bool flip_normals);

#endif /* APPWRAP_HPP_ */
