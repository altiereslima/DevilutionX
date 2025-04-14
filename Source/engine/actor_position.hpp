#pragma once

#include "engine/point.hpp"
#include "engine/size.hpp" // Include for TILE_WIDTH and TILE_HEIGHT

namespace devilution {

struct ActorPosition {
    Point tile;      // Position in tile coordinates
    Point offset;    // Sub-tile offset in pixels
    Point velocity;  // Movement velocity

    void UpdatePosition() {
        offset += velocity;

        // Handle offset overflow/underflow
        while (offset.x >= TileWidth) {
            offset.x -= TileWidth;
            tile.x++;
        }
        while (offset.x < 0) {
            offset.x += TileWidth;
            tile.x--;
        }
        while (offset.y >= TileHeight) {
            offset.y -= TileHeight;
            tile.y++;
        }
        while (offset.y < 0) {
            offset.y += TileHeight;
            tile.y--;
        }
    }
};

} // namespace devilution
