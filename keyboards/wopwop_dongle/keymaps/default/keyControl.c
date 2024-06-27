#include "keyboard.h"
#include "action.h"
#include "timer.h"
#include "gpio.h"
#include "print.h"
#include "nrf24l01_driver.c"
//#include "nrf24l01.c"

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


bool Bpressed=false;

#define BUTTON GP8
#define OUTLED GP25
void keyboard_pre_init_kb(void){
    gpio_set_pin_input_high(BUTTON);
    //gpio_set_pin_input(OUTLED);
    gpio_set_pin_output(OUTLED);
}


// transmit_test
void housekeeping_task_user(void) {

    if(gpio_read_pin(BUTTON) && !Bpressed){
        print("not hello\n");
        Bpressed=true;
        gpio_write_pin_high(OUTLED);
    }
    else if(!gpio_read_pin(BUTTON) && Bpressed){
        print("hello\n");
        Bpressed=false;
        //gpio_set_pin_input(OUTLED);
        gpio_write_pin_low(OUTLED);
    }
    send_key();
}
