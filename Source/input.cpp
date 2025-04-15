#include "player.h"

void HandlePlayerInput(Player &player)
{
	Direction dir = GetDirectionFromInput(); // Implemente conforme seu sistema de input
	if (dir != Direction::None) {
		StartPlayerPixelMovement(player, dir);
	}
}