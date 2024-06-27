#include "keyboard.h"
#include "action.h"
#include "timer.h"
#include "gpio.h"
#include "nrf24l01_driver.c"

// void housekeeping_task_kb(void) {
//     bool pressed = true;
//     keyrecord_t record;
//     keyevent_t event;
//     keypos_t pos;
//     action_t action = action_for_keycode(KC_MEDIA_PLAY_PAUSE);
//     pos.col = 0;
//     pos.row = 0;

//     uint8_t timer = 0x0;
//     if(timer == 0){
//         //keyrecord_t recordP = *record;
//         event.key = pos;
//         event.time = timer_read() ;
//         event.type = 1 ;
//         event.pressed = pressed;

//         record.event = event;
        
//         process_action(&record, action);

//         //process_action(&record,action);
//         pressed = !pressed;
//     }
//     ++timer;
// }

// #define OUTLED B9
// void keyboard_pre_init_kb(void){
//     nrf24_device(RECEIVER, RESET);
//     gpio_set_pin_output(OUTLED);
//     gpio_write_pin_high(OUTLED);
// }



// void housekeeping_task_kb(void) {
//     uint8_t payload=0b10101010;
//     uint8_t received_payload;
//     while(nrf24_receive(&received_payload, 1) == RECEIVE_FIFO_EMPTY);
//     if(received_payload==payload){
//         gpio_toggle_pin(OUTLED);
//         received_payload=0;
//     }
// }
// void housekeeping_task_kb(void) {
//     bool pressed = true;
//     keyrecord_t record;
//     keyevent_t event;
//     keypos_t pos;
//     action_t action = action_for_keycode(KC_Q);
//     pos.col = 0;
//     pos.row = 0;

//     uint8_t timer = 0x0;
//     if(timer == 0){
//         //keyrecord_t recordP = *record;
//         event.key = pos;
//         event.time = timer_read() ;
//         event.type = 1 ;
//         event.pressed = pressed;

//         record.event = event;
        
//         process_action(&record, action);

//         //process_action(&record,action);
//         pressed = !pressed;
//     }
//     ++timer;
// }
void housekeeping_task_kb(void) {
    // bool pressed = true;
    // keyrecord_t record;
    // keyevent_t event;
    // keypos_t pos;
    // action_t action = action_for_keycode(KC_Q);
    // pos.col = 0;
    // pos.row = 0;

    // uint8_t timer = 0x0;
    // if(timer == 0){
    //     event.key = pos;
    //     event.time = timer_read() ;
    //     event.type = 1 ;
    //     event.pressed = pressed;
    //     record.event = event;        
    //     process_action(&record, action);
    //     pressed = !pressed;
    // }
    // ++timer;
    //receive_key();
    send_key();
}