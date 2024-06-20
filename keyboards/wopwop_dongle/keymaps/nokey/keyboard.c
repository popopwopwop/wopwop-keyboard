#include "keyboard.h"
#include "action.h"
#include "timer.h"


void protocol_keyboard_task(){
    bool pressed = true;
    uint16_t time = timer_read();
    keyevent_t event;

    uint8_t time = 0x0;
    if(time == 0){
        event = {{1;2;}; timer_read() ; keyevent_type_t.KEY_EVENT ; pressed;};
        action_exec(event);
        pressed = !pressed;
    } 
    ++timer;
}