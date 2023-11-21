//
// Created by lukas on 2023-11-19.
//

#pragma once


#include <cstdint>

struct VoxelVertex {
    float x, y, z; // Position position
    float r, g, b, a; // Color components
    float faceID; // Identifier for the face


    VoxelVertex(int x, int y, int z, const Voxel& voxel, uint8_t faceID)
            : x(x), y(y), z(z),
              r(voxel.red / 255.0f),
              g(voxel.green / 255.0f),
              b(voxel.blue / 255.0f),
              a(voxel.alpha / 255.0f),
              faceID(faceID) {}
};

inline static void AddVerticesToData(std::vector<float>& data, const std::initializer_list<VoxelVertex>& vertices) {
    for (const auto& vertex : vertices) {
        data.push_back(vertex.x);
        data.push_back(vertex.y);
        data.push_back(vertex.z);
        data.push_back(vertex.r);
        data.push_back(vertex.g);
        data.push_back(vertex.b);
        data.push_back(vertex.a);
        data.push_back(vertex.faceID);
    }
}
