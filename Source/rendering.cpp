#include "player.h"
#include "rendering.h"

void DrawPlayer(const Player &player)
{
	// Use a posição em pixels para calcular a posição na tela
	const Point &pixelPos = player.pixelPos.pixelPosition;
	// Exemplo: desenhe o sprite do jogador em pixelPos.x, pixelPos.y
	DrawSprite(player.currentSprite(), pixelPos.x, pixelPos.y);
}