// ...existing code...

void DrawPlayer(const Player &player)
{
	const Point tile = player.position.tile;
	const Point offset = player.position.offset;

	// Calculate exact pixel position for rendering
	Point screenPosition {
		(tile.x * TileWidth + offset.x),
		(tile.y * TileHeight + offset.y)
	};

	// Adjust for camera position
	screenPosition.x -= ScrollInfo.x;
	screenPosition.y -= ScrollInfo.y;

	const bool isInvalid = player._pHitPoints == 0 && player._pmode == PM_DEATH;
	const uint8_t transclucentAlpha = isInvalid ? 128 : 255;

	if (player.AnimInfo.sprites) {
		const auto &sprite = (*player.AnimInfo.sprites)[player.AnimInfo.currentFrame];
		if (sprite.width() != 0) {
			const Point position { screenPosition.x - (sprite.width() - TileWidth) / 2, screenPosition.y };
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