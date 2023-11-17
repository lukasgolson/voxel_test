//
// Created by lukas on 2023-11-13.
//

#ifndef VOXEL_TEST_QUADMESH_H
#define VOXEL_TEST_QUADMESH_H


#include "BaseMesh.h"

class QuadMesh : public BaseMesh {

    std::vector<float> GetVertexData() override;

    GLuint GetVertexArrayObject() override;

    void SetVertexAttributes() override;

public:
    void Render() override;
};


#endif //VOXEL_TEST_QUADMESH_H
