//
// Created by lukas on 2023-11-18.
//

#pragma once

#include "BaseMesh.h"

class QuadMesh : public BaseMesh {
protected:
    void SetVertexAttributes() override;

public:
    QuadMesh();
    std::vector<float> GetVertexData() override;
};
