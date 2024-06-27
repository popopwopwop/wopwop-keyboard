#include_next "config.h"
#pragma once

#define NO_MATRIX
#define NO_USB
#undef SPI_SCK_PIN
#define SPI_SCK_PIN GP10
#undef SPI_MOSI_PIN
#define SPI_MOSI_PIN GP11
#undef SPI_MISO_PIN
#define SPI_MISO_PIN GP12 
// #undef SPI_SS_PIN
// #define SPI_SS_PIN GP13
