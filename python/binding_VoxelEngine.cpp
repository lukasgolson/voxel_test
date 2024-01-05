//
// Created by olson.stu on 2024-01-04.
//

#include <pybind11/pybind11.h>
#include "../src/WindowManager.h"
#include "../src/types/Rgb.h"
#include "../src/types/Hsv.h"

namespace py = pybind11;





PYBIND11_MODULE(voxelTest, m) {
    m.doc() = "VoxelTest Python Binding";

    py::class_<RGB>(m, "RGB")
        .def(py::init<const double, const double, const double>())
        .def_readwrite("red", &RGB::red)
        .def_readwrite("g", &RGB::green)
        .def_readwrite("b", &RGB::blue)

        .def("__repr__",
             [](const RGB &a) {
                 return "<RGB red:" + std::to_string(a.red) + " g:" + std::to_string(a.green) + " b:" + std::to_string(a.blue) + ">";
             }
        )
        .doc() = "RGB color";

    py::class_<RGBA>(m, "RGBA")
        .def(py::init<const double, const double, const double, const double>())
        .def_readwrite("red", &RGBA::red)
        .def_readwrite("g", &RGBA::green)
        .def_readwrite("b", &RGBA::blue)
        .def_readwrite("a", &RGBA::alpha)
        .def("__repr__",
             [](const RGBA &a) {
                 return "<RGBA red:" + std::to_string(a.red) + " g:" + std::to_string(a.green) + " b:" + std::to_string(a.blue) + " a:" + std::to_string(a.alpha) + ">";
             }
        )
        .doc() = "RGBA color";

    py::class_<HSV>(m, "HSV")
        .def(py::init<const double, const double, const double>())
        .def_readwrite("h", &HSV::hue)
        .def_readwrite("s", &HSV::saturation)
        .def_readwrite("v", &HSV::value)
        .def("__repr__",
             [](const HSV &a) {
                 return "<HSV h:" + std::to_string(a.hue) + " s:" + std::to_string(a.saturation) + " v:" + std::to_string(a.value) + ">";
             }
        )
        .doc() = "HSV color";




}


