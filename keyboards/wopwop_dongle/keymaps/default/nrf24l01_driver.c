#include "nrf24l01.c"
// #include "nrf24l01.h"
#include "spi_master.h"
#include "print.h"

#define CEpin GP14
#define CSNpin GP13

nrf24l01_handle_t NRFhandler;
uint8_t gpio_nrf24_init(void){
    gpio_set_pin_output(CEpin);
    gpio_write_pin_high(CEpin);
    gpio_set_pin_output(CSNpin);
    gpio_write_pin_high(CSNpin);
    return 0;
}

void delay_ms(uint32_t ms){
    chThdSleepMilliseconds(ms);
}


uint8_t nrf24_spi_init(void){
    spi_init();
    return 0;
}

uint8_t nrf24_spi_write(uint8_t reg, uint8_t *buf, uint16_t len){
    if(!spi_start(CSNpin, true, 1, 8)){
        return 1;
    }
    if(spi_write(reg) == SPI_STATUS_SUCCESS){
        if(spi_transmit(buf,len) == SPI_STATUS_SUCCESS){
            return 0;
        }
    }
    spi_stop();
    return 1;
}

uint8_t nrf24_spi_read(uint8_t reg, uint8_t *buf, uint16_t len){
    if(!spi_start(CSNpin, true, 1, 8)){
        return 1;
    }
    if(spi_write(reg) == SPI_STATUS_SUCCESS){
        if(spi_receive(buf ,len) == SPI_STATUS_SUCCESS){
            return 0;
        }
    }
    spi_stop();
    return 1;
}


uint8_t CE_write(uint8_t value){
    if(value){
        gpio_write_pin_high(CEpin);
    }
    else{
        gpio_write_pin_low(CEpin);
    }
    return 0;
}

static void nrf24_callback(uint8_t type, uint8_t num, uint8_t *buf, uint8_t len)
{
    switch (type)
    {
        case NRF24L01_INTERRUPT_RX_DR :
        {
            // uint8_t i;
            
            // nrf24l01_interface_debug_print("nrf24l01: irq receive with pipe %d with %d.\n", num, len);
            // for (i = 0; i < len; i++)
            // {
            //     nrf24l01_interface_debug_print("0x%02X ", buf[i]);
            // }
            // nrf24l01_interface_debug_print(".\n");
            
            break;
        }
        case NRF24L01_INTERRUPT_TX_DS :
        {
            //nrf24l01_interface_debug_print("nrf24l01: irq sent ok.\n");
            
            break;
        }
        case NRF24L01_INTERRUPT_MAX_RT :
        {
            //nrf24l01_interface_debug_print("nrf24l01: irq reach max retry times.\n");
            
            break;
        }
        case NRF24L01_INTERRUPT_TX_FULL :
        {
            break;
        }
        default :
        {
            break;
        }
    }
}

void keyboard_post_init_user(void){
    NRFhandler.gpio_init = &gpio_nrf24_init;
    NRFhandler.delay_ms = &delay_ms;
    NRFhandler.spi_init = &nrf24_spi_init;
    NRFhandler.gpio_write = &CE_write;
    NRFhandler.spi_write = &nrf24_spi_write;
    NRFhandler.spi_read = &nrf24_spi_read;
    NRFhandler.receive_callback = &nrf24_callback;
    //NRFhandler.debug_print = &print;
    //nrf24_spi_init();
    //nrf24l01_init(&NRFhandler);
    //nrf24l01_set_mode(&NRFhandler, NRF24L01_MODE_TX);
    spi_start(CSNpin, true, 1, 144);
}

void send_key(void){
    //uint8_t payload = KC_Q;
    uint8_t test_payload = 0b10101010;
    // nrf24l01_write_tx_payload(&NRFhandler, &payload, 1);
    if(spi_write(test_payload) == SPI_STATUS_SUCCESS){
        print("sent\n");
    }
    else{
        print("error\n");
    }
}