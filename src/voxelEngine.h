
#ifndef VOXEL_TEST_VOXELENGINE_H
#define VOXEL_TEST_VOXELENGINE_H



#include "Camera.h"
#include "ShaderProgram.h"
#include "Scene.h"

class voxelEngine {
    Camera *camera;
    ShaderProgram *shaderProgram;
    Scene *scene;

public:
    explicit voxelEngine(glm::vec2 window_size);
    ~voxelEngine() = default;
    void update();

    double deltaTime;
    double lastFrameTime;
};


#endif //VOXEL_TEST_VOXELENGINE_H
