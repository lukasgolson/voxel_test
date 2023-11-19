//
// Created by lukas on 2023-11-18.
//

#ifndef VOXEL_TEST_QUADMESH_H
#define VOXEL_TEST_QUADMESH_H


#include "BaseMesh.h"

class QuadMesh : public BaseMesh {
protected:
    void SetVertexAttributes() override;

public:
    QuadMesh();
    std::vector<float> GetVertexData() override;
};


#endif //VOXEL_TEST_QUADMESH_H
