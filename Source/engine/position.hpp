#pragma once

#include "engine/displacement.hpp"

namespace devilution {

struct Position {
    Point tile;      // Tile position (grid coordinates)
    Point offset;    // Sub-tile offset in pixels

    void UpdatePosition() {
        // Handle sub-tile offset overflow
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

struct ActorPosition {
    Position position;
    Point velocity;

    void Update() {
        position.offset.x += velocity.x;
        position.offset.y += velocity.y;
        position.UpdatePosition();
    }
};

} // namespace devilution
