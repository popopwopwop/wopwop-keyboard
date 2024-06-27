#pragma once
#include_next <config.h>

#undef SPI_DRIVER
#define SPI_DRIVER SPID1
//#undef SPI_SCK_PIN
#define SPI_SCK_PIN GP10
//#undef SPI_MOSI_PIN
#define SPI_MOSI_PIN GP11
//#undef SPI_MISO_PIN
#define SPI_MISO_PIN GP12 