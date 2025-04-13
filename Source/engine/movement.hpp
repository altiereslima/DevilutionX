#pragma once

#include <cstdint>

namespace devilution {

struct SmoothMovementSettings {
    static constexpr float PixelsPerSecond = 85.0f; // Ajuste este valor para controlar a velocidade
    static constexpr float MinPixelStep = 1.0f;     // Movimento mínimo por frame
    static constexpr float MaxPixelStep = 3.0f;     // Movimento máximo por frame
};

class SmoothMovement {
public:
    static float GetPixelSteps(uint32_t ticks);
    static bool IsAtDestination(int currentX, int currentY, int targetX, int targetY);
    static void GetNextPosition(int& currentX, int& currentY, int targetX, int targetY, float steps);

private:
    static float ClampMovement(float steps);
};

} // namespace devilution
