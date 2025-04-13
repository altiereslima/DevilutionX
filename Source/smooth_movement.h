#pragma once

#include "engine.h"
#include "utils/point.hpp"

enum class Direction {
    None,
    North,
    South,
    East,
    West
};

class SmoothMovement {
public:
    static constexpr float PIXELS_PER_SECOND = 60.0f;  // Adjust for desired speed
    static constexpr float MIN_MOVEMENT = 2.0f;        // Minimum pixels to move

    static void Initialize();
    static void Update(float deltaTime);
    static Point GetSmoothOffset();
    static void StartMovement(Direction dir);
    static void StopMovement();

private:
    static Point currentOffset;
    static Point targetOffset;
    static Direction currentDirection;
    static bool isMoving;
    static float accumulator;
};
