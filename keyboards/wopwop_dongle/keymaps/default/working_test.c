#include "keyboard.h"
#include "action.h"
#include "timer.h"

// void actionQ(void){
//     bool pressed = true;
//     //uint16_t timer = timer_read();
//     keyevent_t event;
//     keypos_t pos;
//     action_t action = action_for_keycode(0x0014);
//     pos.col = 0;
//     pos.row = 0;

//     uint8_t timer = 0x0;
//     if(timer == 0){
//             event.key = pos;
//             event.time = timer_read() ;
//             event.type = 1 ;
//             event.pressed = pressed;
//         process_action(event,action);
//         pressed = !pressed;
//     }
//     ++timer;
// }

void housekeeping_task_kb(void) {
    bool pressed = true;
    keyrecord_t record;
    keyevent_t event;
    keypos_t pos;
    action_t action = action_for_keycode(0x0014);
    pos.col = 0;
    pos.row = 0;

    uint8_t timer = 0x0;
    if(timer == 0){
        //keyrecord_t recordP = *record;
        event.key = pos;
        event.time = timer_read() ;
        event.type = 1 ;
        event.pressed = pressed;

        record.event = event;
        
        process_action(&record, action);

        //process_action(&record,action);
        pressed = !pressed;
    }
    ++timer;
}
