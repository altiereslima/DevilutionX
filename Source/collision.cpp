#pragma once

#include "engine/point.hpp"
#include "engine/direction.hpp"
#include "player.h"

namespace devilution {

constexpr int PixelsPerTile = 32;
constexpr int PlayerPixelStep = 3; // Pixels por movimento incremental

struct PlayerPixelPosition {
	Point pixelPosition;

	PlayerPixelPosition(Point tilePosition)
	    : pixelPosition(tilePosition.tileToPixel())
	{
	}

	void Move(Direction dir)
	{
		Displacement disp(dir);
		pixelPosition.x += disp.deltaX * PlayerPixelStep;
		pixelPosition.y += disp.deltaY * PlayerPixelStep;
	}

	Point GetTilePosition() const
	{
		return pixelPosition.pixelToTile();
	}
};

bool IsPlayerPositionWalkable(const Player &player)
{
	Point tilePos = player.pixelPos.GetTilePosition();
	return IsTileWalkable(tilePos);
}

} // namespace devilution