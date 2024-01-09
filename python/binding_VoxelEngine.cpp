//
// Created by olson.stu on 2024-01-04.
//

#include <pybind11/pybind11.h>
#include "../src/types/Rgb.h"
#include "../src/types/Hsv.h"
#include "../src/Bindings/VoxelWindow.h"

namespace py = pybind11;


PYBIND11_MODULE(voxelTest, m) {
    m.doc() = "VoxelTest Python Binding";

    py::class_<RGB>(m, "rgb")
            .def(py::init<const double, const double, const double>())
            .def_readwrite("red", &RGB::red)
            .def_readwrite("g", &RGB::green)
            .def_readwrite("b", &RGB::blue)

            .def("__repr__",
                 [](const RGB &a) {
                     return "<RGB red:" + std::to_string(a.red) + " g:" + std::to_string(a.green) + " b:" +
                            std::to_string(a.blue) + ">";
                 }
            )
            .doc() = "RGB color. Values are 0-1.0.";

    py::class_<RGBA>(m, "rgba")
            .def(py::init<const double, const double, const double, const double>())
            .def_readwrite("red", &RGBA::red)
            .def_readwrite("g", &RGBA::green)
            .def_readwrite("b", &RGBA::blue)
            .def_readwrite("a", &RGBA::alpha)
            .def("__repr__",
                 [](const RGBA &a) {
                     return "<RGBA red:" + std::to_string(a.red) + " g:" + std::to_string(a.green) + " b:" +
                            std::to_string(a.blue) + " a:" + std::to_string(a.alpha) + ">";
                 }
            )
            .doc() = "RGBA color. Values are 0-1.0.";

    py::class_<HSV>(m, "hsv")
            .def(py::init<const double, const double, const double>())
            .def_readwrite("h", &HSV::hue)
            .def_readwrite("s", &HSV::saturation)
            .def_readwrite("v", &HSV::value)
            .def("__repr__",
                 [](const HSV &a) {
                     return "<HSV h:" + std::to_string(a.hue) + " s:" + std::to_string(a.saturation) + " v:" +
                            std::to_string(a.value) + ">";
                 }
            )
            .doc() = "HSV color";


    py::class_<Coordinate>(m, "coordinate")
            .def(py::init<const int, const int, const int>())
            .def_readwrite("x", &Coordinate::x)
            .def_readwrite("y", &Coordinate::y)
            .def_readwrite("z", &Coordinate::z)
            .def("__repr__",
                 [](const Coordinate &a) {
                     return "<Coordinate x:" + std::to_string(a.x) + " y:" + std::to_string(a.y) + " z:" +
                            std::to_string(a.z) + ">";
                 }
            )
            .doc() = "Coordinate in 3D space. Values are integers.";


    py::class_<VoxelWindow>(m, "voxelWindow")
            .def(py::init<int, int, const int, const int, const RGBA>(),
                 "Create a window with the given resolution and background color.")
            .def("update", &VoxelWindow::Update,
                 "Update the window / render the window. Call this in a loop every frame.")
            .def("ShouldClose", &VoxelWindow::ShouldClose,
                 "Returns true if the window should close. If true, you should stop calling update.")

            .def("SetVoxel", &VoxelWindow::SetVoxel, "Set the voxel at the given coordinate to the given color.")
            .def("GetVoxel", &VoxelWindow::GetVoxel, "Get the voxel color at the given coordinate.")
            .doc() = "Voxel Window Object; used to create a window and render voxels to it.";


}


