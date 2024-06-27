#include_next "halconf.h"
#pragma once

#undef HAL_USE_SPI
#define HAL_USE_SPI TRUE
#define SPI_USE_WAIT TRUE
#define SPI_SELECT_MODE SPI_SELECT_MODE_PAD
