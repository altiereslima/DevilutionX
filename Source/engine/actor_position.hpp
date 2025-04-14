#pragma once

#include "engine/point.hpp"

namespace devilution {

struct ActorPosition {
    Point tile;      // Grid position
    Point offset;    // Pixel offset within tile
    Point velocity;  // Movement velocity

    void UpdatePosition() {
        offset += velocity;

        // Handle offset overflow/underflow
        while (offset.x >= TILE_WIDTH) {
            offset.x -= TILE_WIDTH;
            tile.x++;
        }
        while (offset.x < 0) {
            offset.x += TILE_WIDTH;
            tile.x--;
        }
        while (offset.y >= TILE_HEIGHT) {
            offset.y -= TILE_HEIGHT;
            tile.y++;
        }
        while (offset.y < 0) {
            offset.y += TILE_HEIGHT;
            tile.y--;
        }
    }
};

} // namespace devilution
