#pragma once

#include "engine/point.hpp"
#include "engine/size.hpp" // Include for TileWidth and TileHeight
#include "engine/animationinfo.h"
#include "engine/direction.hpp"

namespace devilution {

struct ActorPosition {
    Point tile;      // Position in tile coordinates
    Point offset;    // Sub-tile offset in pixels
    Point velocity;  // Movement velocity

    // Members used by legacy code
    Point future;
    Point old;
    Point temp;
    Point last;

    void UpdatePosition() {
        offset += velocity;

        // Handle offset overflow/underflow
        while (offset.x >= devilution::TileWidth) {
            offset.x -= devilution::TileWidth;
            tile.x++;
        }
        while (offset.x < 0) {
            offset.x += devilution::TileWidth;
            tile.x--;
        }
        while (offset.y >= devilution::TileHeight) {
            offset.y -= devilution::TileHeight;
            tile.y++;
        }
        while (offset.y < 0) {
            offset.y += devilution::TileHeight;
            tile.y--;
        }
    }

    // Stub for compatibility; implement as needed
    WorldTileDisplacement CalculateWalkingOffset(Direction /*direction*/, const AnimationInfo & /*animInfo*/) const
    {
        // Return zero displacement for now; replace with real logic if needed
        return { 0, 0 };
    }
};

} // namespace devilution
