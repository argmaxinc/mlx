#pragma once

#include <pybind11/pybind11.h>
#include <unordered_map>
#include <variant>
#include "mlx/ops.h"

namespace py = pybind11;
using namespace mlx::core;

using DictOrArray = std::variant<array, std::unordered_map<std::string, array>>;

DictOrArray mlx_load_helper(py::object file, StreamOrDevice s);
void mlx_save_helper(py::object file, array a, bool retain_graph = true);
void mlx_savez_helper(
    py::object file,
    py::args args,
    const py::kwargs& kwargs,
    bool compressed = false);