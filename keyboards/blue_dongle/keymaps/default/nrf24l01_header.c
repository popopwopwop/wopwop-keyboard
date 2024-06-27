/**
 * Copyright (c) 2015 - present LibDriver All rights reserved
 * 
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. 
 *
 * @file      driver_nrf24l01.h
 * @brief     driver nrf24l01 header file
 * @version   1.0.0
 * @author    Shifeng Li
 * @date      2021-11-28
 *
 * <h3>history</h3>
 * <table>
 * <tr><th>Date        <th>Version  <th>Author      <th>Description
 * <tr><td>2021/11/28  <td>1.0      <td>Shifeng Li  <td>first upload
 * </table>
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @defgroup nrf24l01_driver nrf24l01 driver function
 * @brief    nrf24l01 driver modules
 * @{
 */

/**
 * @addtogroup nrf24l01_basic_driver
 * @{
 */

/**
 * @brief nrf24l01 bool enumeration definition
 */
typedef enum
{
    NRF24L01_BOOL_FALSE = 0x00,        /**< disable function */
    NRF24L01_BOOL_TRUE  = 0x01,        /**< enable function */
} nrf24l01_bool_t;

/**
 * @brief nrf24l01 config enumeration definition
 */
typedef enum
{
    NRF24L01_CONFIG_MASK_RX_DR  = 6,        /**< mask interrupt caused by RX_DR */
    NRF24L01_CONFIG_MASK_TX_DS  = 5,        /**< mask interrupt caused by TX_DS */
    NRF24L01_CONFIG_MASK_MAX_RT = 4,        /**< mask interrupt caused by MAX_RT */
    NRF24L01_CONFIG_EN_CRC      = 3,        /**< enable CRC */
    NRF24L01_CONFIG_CRCO        = 2,        /**< enable CRC encoding 2 bytes or 1 byte */
    NRF24L01_CONFIG_PWR_UP      = 1,        /**< power up */
} nrf24l01_config_t;

/**
 * @brief nrf24l01 mode enumeration definition
 */
typedef enum
{
    NRF24L01_MODE_TX = 0x00,        /**< tx mode */
    NRF24L01_MODE_RX = 0x01,        /**< rx mode */
} nrf24l01_mode_t;

/**
 * @brief nrf24l01 pipe enumeration definition
 */
typedef enum
{
    NRF24L01_PIPE_0 = 0,        /**< pipe 0 */
    NRF24L01_PIPE_1 = 1,        /**< pipe 1 */
    NRF24L01_PIPE_2 = 2,        /**< pipe 2 */
    NRF24L01_PIPE_3 = 3,        /**< pipe 3 */
    NRF24L01_PIPE_4 = 4,        /**< pipe 4 */
    NRF24L01_PIPE_5 = 5,        /**< pipe 5 */
} nrf24l01_pipe_t;

/**
 * @brief nrf24l01 address width enumeration definition
 */
typedef enum
{
    NRF24L01_ADDRESS_WIDTH_ILLEGAL = 0,       /**< illegal */
    NRF24L01_ADDRESS_WIDTH_3_BYTES = 1,       /**< 3 bytes */
    NRF24L01_ADDRESS_WIDTH_4_BYTES = 2,       /**< 4 bytes */
    NRF24L01_ADDRESS_WIDTH_5_BYTES = 3,       /**< 5 bytes */
} nrf24l01_address_width_t;

/**
 * @brief nrf24l01 data rate enumeration definition
 */
typedef enum
{
    NRF24L01_DATA_RATE_1M   = 0,        /**< 1 Mbps */
    NRF24L01_DATA_RATE_2M   = 1,        /**< 2 Mbps */
    NRF24L01_DATA_RATE_250K = 2,        /**< 250 Kbps */
} nrf24l01_data_rate_t;

/**
 * @brief nrf24l01 output power enumeration definition
 */
typedef enum
{
    NRF24L01_OUTPUT_POWER_NEGATIVE_18_DBM = 0,        /**< -18 dBm */
    NRF24L01_OUTPUT_POWER_NEGATIVE_12_DBM = 1,        /**< -12 dBm */
    NRF24L01_OUTPUT_POWER_NEGATIVE_6_DBM  = 2,        /**< -6 dBm */
    NRF24L01_OUTPUT_POWER_0_DBM          = 3,         /**< 0 dBm */
} nrf24l01_output_power_t;

/**
 * @brief nrf24l01 interrupt enumeration definition
 */
typedef enum
{
    NRF24L01_INTERRUPT_RX_DR   = 6,        /**< data ready rx fifo interrupt */
    NRF24L01_INTERRUPT_TX_DS   = 5,        /**< data sent rx fifo interrupt */
    NRF24L01_INTERRUPT_MAX_RT  = 4,        /**< maximum number of tx retransmits interrupt */
    NRF24L01_INTERRUPT_TX_FULL = 0,        /**< tx fifo full flag */
} nrf24l01_interrupt_t;

/**
 * @brief nrf24l01 fifo status enumeration definition
 */
typedef enum
{
    NRF24L01_FIFO_STATUS_TX_REUSE = 6,        /**< tx reuse */
    NRF24L01_FIFO_STATUS_TX_FULL  = 5,        /**< tx full */
    NRF24L01_FIFO_STATUS_TX_EMPTY = 4,        /**< tx empty */
    NRF24L01_FIFO_STATUS_RX_FULL  = 1,        /**< rx full */
    NRF24L01_FIFO_STATUS_RX_EMPTY = 0,        /**< rx empty */
} nrf24l01_fifo_status_t;

/**
 * @brief nrf24l01 handle structure definition
 */
typedef struct nrf24l01_handle_s
{
    uint8_t (*gpio_init)(void);                                                            /**< point to a gpio_init function address */
    // uint8_t (*gpio_deinit)(void);                                                          /**< point to a gpio_deinit function address */
    uint8_t (*gpio_write)(uint8_t value);                                                  /**< point to a gpio_write function address */
    uint8_t (*spi_init)(void);                                                             /**< point to a spi_init function address */
    // uint8_t (*spi_deinit)(void);                                                           /**< point to a spi_deinit function address */
    uint8_t (*spi_read)(uint8_t reg, uint8_t *buf, uint16_t len);                          /**< point to a spi_read function address */
    uint8_t (*spi_write)(uint8_t reg, uint8_t *buf, uint16_t len);                         /**< point to a spi_write function address */
    void (*delay_ms)(uint32_t ms);                                                         /**< point to a delay_ms function address */
    void (*debug_print)(const char *const fmt, ...);                                       /**< point to a debug_print function address */
    void (*receive_callback)(uint8_t type, uint8_t num, uint8_t *buf, uint8_t len);        /**< point to a receive_callback function address */
    uint8_t inited;                                                                        /**< inited flag */
    uint8_t finished;                                                                      /**< finished flag */
} nrf24l01_handle_t;

/**
 * @brief nrf24l01 information structure definition
 */
typedef struct nrf24l01_info_s
{
    char chip_name[32];                /**< chip name */
    char manufacturer_name[32];        /**< manufacturer name */
    char interface[8];                 /**< chip interface name */
    float supply_voltage_min_v;        /**< chip min supply voltage */
    float supply_voltage_max_v;        /**< chip max supply voltage */
    float max_current_ma;              /**< chip max current */
    float temperature_min;             /**< chip min operating temperature */
    float temperature_max;             /**< chip max operating temperature */
    uint32_t driver_version;           /**< driver version */
} nrf24l01_info_t;

/**
 * @}
 */

/**
 * @defgroup nrf24l01_link_driver nrf24l01 link driver function
 * @brief    nrf24l01 link driver modules
 * @ingroup  nrf24l01_driver
 * @{
 */

/**
 * @brief     initialize nrf24l01_handle_t structure
 * @param[in] HANDLE points to an nrf24l01 handle structure
 * @param[in] STRUCTURE is nrf24l01_handle_t
 * @note      none
 */
#define DRIVER_NRF24L01_LINK_INIT(HANDLE, STRUCTURE)         memset(HANDLE, 0, sizeof(STRUCTURE))

/**
 * @brief     link spi_init function
 * @param[in] HANDLE points to an nrf24l01 handle structure
 * @param[in] FUC points to a spi_init function address
 * @note      none
 */
#define DRIVER_NRF24L01_LINK_SPI_INIT(HANDLE, FUC)          (HANDLE)->spi_init = FUC

/**
 * @brief     link spi_deinit function
 * @param[in] HANDLE points to an nrf24l01 handle structure
 * @param[in] FUC points to a spi_deinit function address
 * @note      none
 */
#define DRIVER_NRF24L01_LINK_SPI_DEINIT(HANDLE, FUC)        (HANDLE)->spi_deinit = FUC

/**
 * @brief     link spi_read function
 * @param[in] HANDLE points to an nrf24l01 handle structure
 * @param[in] FUC points to a spi_read function address
 * @note      none
 */
#define DRIVER_NRF24L01_LINK_SPI_READ(HANDLE, FUC)          (HANDLE)->spi_read = FUC

/**
 * @brief     link gpio_write function
 * @param[in] HANDLE points to an nrf24l01 handle structure
 * @param[in] FUC points to a gpio_write function address
 * @note      none
 */
#define DRIVER_NRF24L01_LINK_SPI_WRITE(HANDLE, FUC)         (HANDLE)->spi_write = FUC

/**
 * @brief     link gpio_init function
 * @param[in] HANDLE points to an nrf24l01 handle structure
 * @param[in] FUC points to a gpio_init function address
 * @note      none
 */
#define DRIVER_NRF24L01_LINK_GPIO_INIT(HANDLE, FUC)         (HANDLE)->gpio_init = FUC

/**
 * @brief     link gpio_deinit function
 * @param[in] HANDLE points to an nrf24l01 handle structure
 * @param[in] FUC points to a gpio_deinit function address
 * @note      none
 */
#define DRIVER_NRF24L01_LINK_GPIO_DEINIT(HANDLE, FUC)       (HANDLE)->gpio_deinit = FUC

/**
 * @brief     link gpio_write function
 * @param[in] HANDLE points to an nrf24l01 handle structure
 * @param[in] FUC points to a gpio_write function address
 * @note      none
 */
#define DRIVER_NRF24L01_LINK_GPIO_WRITE(HANDLE, FUC)        (HANDLE)->gpio_write = FUC

/**
 * @brief     link delay_ms function
 * @param[in] HANDLE points to an nrf24l01 handle structure
 * @param[in] FUC points to a delay_ms function address
 * @note      none
 */
#define DRIVER_NRF24L01_LINK_DELAY_MS(HANDLE, FUC)          (HANDLE)->delay_ms = FUC

/**
 * @brief     link debug_print function
 * @param[in] HANDLE points to an nrf24l01 handle structure
 * @param[in] FUC points to a debug_print function address
 * @note      none
 */
#define DRIVER_NRF24L01_LINK_DEBUG_PRINT(HANDLE, FUC)       (HANDLE)->debug_print = FUC

/**
 * @brief     link receive_callback function
 * @param[in] HANDLE points to an nrf24l01 handle structure
 * @param[in] FUC points to a receive_callback function address
 * @note      none
 */
#define DRIVER_NRF24L01_LINK_RECEIVE_CALLBACK(HANDLE, FUC)  (HANDLE)->receive_callback = FUC

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif