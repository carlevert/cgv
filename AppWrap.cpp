#include "AppWrap.hpp"

void call_SetFov(Application* a, float fov)
{
  a->GetProjection()->SetFovDegrees(fov);
}

void call_OpenOffFile(Application* a, char* filename) {
  a->OpenOffFile(string(filename));
}

void call_SetParallellProjection(Application* a) {
  a->GetProjection()->SetProjectionType(ProjectionType::PARALLEL);
}

void call_SetTop(Application* a, float top) {
  a->GetProjection()->SetTop(top);
}

void call_SetFar(Application* a, float far) {
  a->GetProjection()->SetZFar(far);
}

void call_SetObliqueScale(Application* a, float oblique_scale) {
  a->GetProjection()->SetObliqueScale(oblique_scale);
}

void call_SetObliqueAngle(Application* a, float oblique_angle) {
  a->GetProjection()->SetObliqueAngleDegrees(oblique_angle);
}

void call_SetPerspectiveProjection(Application* a) {
  a->GetProjection()->SetProjectionType(ProjectionType::PERSPECTIVE);
}

void call_SetLightIntensityR(Application* a, float value) {
	a->GetLight()->SetIntensityR(value);
}
void call_SetLightIntensityG(Application* a, float value) {
	a->GetLight()->SetIntensityG(value);
}
void call_SetLightIntensityB(Application* a, float value) {
	a->GetLight()->SetIntensityB(value);
}

void call_FlipNormals(Application* a, bool flip_normals) {
	a->GetObject()->SetFlipNormals(flip_normals);
}
