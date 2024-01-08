#include "src/Helpers/OpenGlCommon.h"
#include <iostream>
#include <memory>
#include "src/VoxelEngine.h"
#include "src/Window/WindowManager.h"
#include "src/Bindings/VoxelWindow.h"


int main() {

    VoxelWindow voxelWindow(32,16,800, 600, RGBA(0, 0, 0, 1));


    while (!voxelWindow.ShouldClose()) {
        voxelWindow.Update();

        voxelWindow.SetVoxel(Coordinate(1, 1, 1), RGBA(1, 0, 0, 1));
    }
}

