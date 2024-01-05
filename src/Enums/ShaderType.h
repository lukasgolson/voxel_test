//
// Created by olson.stu on 2024-01-04.
//

#ifndef VOXEL_TEST_SHADERTYPE_H
#define VOXEL_TEST_SHADERTYPE_H

#include <string>
#include <stdexcept>

enum class ShaderType {
    Vertex = 0,
    Fragment = 1,
    Geometry = 2,
    TessellationControl = 3,
    TessellationEvaluation = 4,
    Compute = 5,
};


#endif //VOXEL_TEST_SHADERTYPE_H
