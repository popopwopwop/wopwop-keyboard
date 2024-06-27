// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "spi_master.h"
#include "print.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┐
     * │ A │
     * └───┘
     */
    [0] = LAYOUT_ortho_1x1(
        KC_A
    )
};

void housekeeping_task_user(void) {
#define test_payload  0b10101010
    spi_start(GP13, true, 1, 144);
    if(spi_write(test_payload) == SPI_STATUS_SUCCESS){
        print("success\n");
    }
    else{
        print("failed\n");
    }
    spi_stop();
}