#pragma once

#include <cstdint>
#include <cmath>

namespace devilution {

struct Point {
	int x;
	int y;

	Point() = default;
	Point(int x, int y)
	    : x(x)
	    , y(y)
	{
	}

	bool operator==(const Point &other) const
	{
		return x == other.x && y == other.y;
	}

	bool operator!=(const Point &other) const
	{
		return !(*this == other);
	}

	Point &operator+=(const Point &other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	Point &operator-=(const Point &other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Point operator+(const Point &other) const
	{
		return Point(x + other.x, y + other.y);
	}

	Point operator-(const Point &other) const
	{
		return Point(x - other.x, y - other.y);
	}

	Point operator*(int scalar) const
	{
		return Point(x * scalar, y * scalar);
	}

	Point operator/(int scalar) const
	{
		return Point(x / scalar, y / scalar);
	}

	double Distance(const Point &other) const
	{
		return std::sqrt(static_cast<double>((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y)));
	}
};

struct Position {
	Point tile;
	Point offset;
	Point velocity;

	[[nodiscard]] bool IsMoving() const
	{
		return velocity.x != 0 || velocity.y != 0;
	}

	void UpdatePosition()
	{
		offset.x += velocity.x;
		offset.y += velocity.y;

		// Normalize offsets that exceed tile boundaries
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