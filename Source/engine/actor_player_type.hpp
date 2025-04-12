#pragma once

#include <cstdint>

namespace devilution {

enum _player_mode : uint8_t {
	PM_STAND,
	PM_WALK,  // Add the walk mode constant
	PM_WALK2,
	PM_WALK3,
	PM_ATTACK,
	PM_RATTACK,
	PM_BLOCK,
	PM_SPELL,
	PM_GOTHIT,
	PM_DEATH,
	PM_NEWLVL,
	PM_QUIT,
};

} // namespace devilution