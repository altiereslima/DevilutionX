#pragma once

#include "point.h"

namespace devilution {

struct Position {
    Point tile;       // Current tile position
    Point future;     // Target tile position
    Point temp;       // Temporary position used during movement
    Point old;        // Previous position
    int16_t subX;    // Sub-pixel X offset within current tile (0-31)
    int16_t subY;    // Sub-pixel Y offset within current tile (0-31)
};

} // namespace devilution