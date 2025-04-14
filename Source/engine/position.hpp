#pragma once

#include "engine/point.hpp"

namespace devilution {

struct Position {
    Point tile;      // Tile position (grid coordinates)
    Point offset;    // Sub-tile offset in pixels
};

struct MovementSettings {
    int speed;       // Movement speed in pixels
    bool smooth;     // Whether to use smooth movement
};

} // namespace devilution
