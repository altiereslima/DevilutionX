// ...existing code...

void DrawPlayer(const Player &player)
{
    // Calculate exact screen position using tile and offset
    Point screenPos {
        (player.position.tile.x * TileWidth + player.position.offset.x) - ScrollInfo.x,
        (player.position.tile.y * TileHeight + player.position.offset.y) - ScrollInfo.y
    };

    const bool isInvalid = player._pHitPoints == 0 && player._pmode == PM_DEATH;
    const uint8_t transclucentAlpha = isInvalid ? 128 : 255;

    if (player.AnimInfo.sprites) {
        const auto &sprite = (*player.AnimInfo.sprites)[player.AnimInfo.currentFrame];
        if (sprite.width() != 0) {
            const Point position { screenPos.x - (sprite.width() - TileWidth) / 2, screenPos.y };
            if (isInvalid) {
                ClxDrawTRN(out, position, sprite, transclucentAlpha);
            } else {
                ClxDraw(out, position, sprite);
            }
        }
    }

    if (player.wReflections > 0) {
        DrawPlayerReflections(out, player, position);
    }
}

// ...existing code...