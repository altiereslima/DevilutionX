#include "engine.h"
#include "smooth_movement.h"

// ...existing code...

void RenderTile(const Surface &out, Point position, const Surface &tile)
{
    Point smoothOffset = SmoothMovement::GetSmoothOffset();
    position += smoothOffset; // Apply smooth movement offset
    RenderLine(out, position, tile.height(), [&](auto y) {
        return ClxPixelAt(tile, 0, y);
    });
}

// ...existing code...