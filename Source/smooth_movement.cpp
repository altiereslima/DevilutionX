#include "smooth_movement.h"

// Initialize static members
Point SmoothMovement::currentOffset = { 0, 0 };
Point SmoothMovement::targetOffset = { 0, 0 };
Direction SmoothMovement::currentDirection = Direction::None;
bool SmoothMovement::isMoving = false;
float SmoothMovement::accumulator = 0.0f;

void SmoothMovement::Initialize()
{
    currentOffset = { 0, 0 };
    targetOffset = { 0, 0 };
    currentDirection = Direction::None;
    isMoving = false;
    accumulator = 0.0f;
}

void SmoothMovement::Update(float deltaTime)
{
    if (!isMoving)
        return;

    accumulator += deltaTime;
    float pixelsToMove = PIXELS_PER_SECOND * deltaTime;

    switch (currentDirection) {
    case Direction::North:
        currentOffset.y -= pixelsToMove;
        break;
    case Direction::South:
        currentOffset.y += pixelsToMove;
        break;
    case Direction::East:
        currentOffset.x += pixelsToMove;
        break;
    case Direction::West:
        currentOffset.x -= pixelsToMove;
        break;
    default:
        break;
    }

    // When reaching minimum movement, snap to tile and stop
    if (accumulator * PIXELS_PER_SECOND >= MIN_MOVEMENT) {
        StopMovement();
    }
}

Point SmoothMovement::GetSmoothOffset()
{
    return currentOffset;
}

void SmoothMovement::StartMovement(Direction dir)
{
    currentDirection = dir;
    isMoving = true;
    accumulator = 0.0f;
}

void SmoothMovement::StopMovement()
{
    isMoving = false;
    currentDirection = Direction::None;
    accumulator = 0.0f;
    currentOffset = { 0, 0 }; // Reset offset when stopping
}
