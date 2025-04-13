#include "engine/movement.hpp"

#include <algorithm>
#include <cmath>

namespace devilution {

float SmoothMovement::GetPixelSteps(uint32_t ticks)
{
    float steps = (SmoothMovementSettings::PixelsPerSecond * ticks) / 1000.0f;
    return ClampMovement(steps);
}

bool SmoothMovement::IsAtDestination(int currentX, int currentY, int targetX, int targetY)
{
    return currentX == targetX && currentY == targetY;
}

void SmoothMovement::GetNextPosition(int& currentX, int& currentY, int targetX, int targetY, float steps)
{
    float dx = static_cast<float>(targetX - currentX);
    float dy = static_cast<float>(targetY - currentY);
    
    float distance = std::sqrt(dx * dx + dy * dy);
    if (distance <= steps) {
        currentX = targetX;
        currentY = targetY;
        return;
    }

    float ratio = steps / distance;
    currentX += static_cast<int>(dx * ratio);
    currentY += static_cast<int>(dy * ratio);
}

float SmoothMovement::ClampMovement(float steps)
{
    return std::clamp(steps, 
        SmoothMovementSettings::MinPixelStep,
        SmoothMovementSettings::MaxPixelStep);
}

} // namespace devilution
