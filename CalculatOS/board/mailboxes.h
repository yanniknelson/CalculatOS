
#pragma once

#define MAILBOX_BASE_ADDRESS                                0xB880
#define MAILBOX_0_READ_WRITE                                MAILBOX_BASE_ADDRESS
#define MAILBOX_0_PEEK                                      MAILBOX_BASE_ADDRESS + 0x10
#define MAILBOX_0_SENDER                                    MAILBOX_BASE_ADDRESS + 0x14
#define MAILBOX_0_STATUS                                    MAILBOX_BASE_ADDRESS + 0x18
#define MAILBOX_0_CONFIG                                    MAILBOX_BASE_ADDRESS + 0x1C
#define MAILBOX_1_READ_WRITE                                MAILBOX_BASE_ADDRESS + 0x20
#define MAILBOX_1_PEEK                                      MAILBOX_BASE_ADDRESS + 0x30
#define MAILBOX_1_SENDER                                    MAILBOX_BASE_ADDRESS + 0x34
#define MAILBOX_1_STATUS                                    MAILBOX_BASE_ADDRESS + 0x38
#define MAILBOX_1_CONFIG                                    MAILBOX_BASE_ADDRESS + 0x3C

#define MAILBOX_POWER_MANAGEMENT_CHANEL                     0
#define MAILBOX_FRAMEBUFFER_CHANEL                          1
#define MAILBOX_VIRTUAL_UART_CHANEL                         2
#define MAILBOX_VCHIQ_CHANEL                                3
#define MAILBOX_LEDS_CHANEL                                 4
#define MAILBOX_BUTTONS_CHANEL                              5
#define MAILBOX_TOUCH_SCREEN_CHANEL                         6
#define MAILBOX_PROPERTIES_ARM_TO_VC_CHANEL                 8
#define MAILBOX_PROPERTIES_VC_TO_ARM_CHANEL                 9

#define GET_CLOCK_STATE_TAG                                 0x30001
#define SET_CLOCK_STATE_TAG                                 0x38001
#define GET_CLOCK_RATE_TAG                                  0x30002
#define SET_CLOCK_RATE_TAG                                  0x38002
#define GET_LED_STATUS_TAG                                  0x30041
#define TEST_LED_STATUS_TAG                                 0x34041
#define SET_LED_STATUS_TAG                                  0x38041
#define GET_CLOCK_RATE_MEASURED_TAG                         0x30047
#define GET_MAX_CLOCK_RATE_TAG                              0x30004
#define GET_MIN_CLOCK_RATE_TAG                              0x30007
#define GET_TURBO_TAG                                       0x30009
#define SET_TURBO_TAG                                       0x38009

#define FRAMEBUFFER_ALLOCATE_BUFFER_TAG                     0x40001
#define FRAMEBUFFER_RELEASE_BUFFER_TAG                      0x48001
#define FRAMEBUFFER_BLANK_SCREEN_TAG                        0x40002
#define FRAMEBUFFER_GET_PHYS_DISPLAY_WIDTH_HEIGHT_TAG       0x40003
#define FRAMEBUFFER_TEST_PHYS_DISPLAY_WIDTH_HEIGHT_TAG      0x44003
#define FRAMEBUFFER_SET_PHYS_DISPLAY_WIDTH_HEIGHT_TAG       0x48003
#define FRAMEBUFFER_GET_VIRT_DISPLAY_WIDTH_HEIGHT_TAG       0x40004
#define FRAMEBUFFER_TEST_VIRT_DISPLAY_WIDTH_HEIGHT_TAG      0x44004
#define FRAMEBUFFER_SET_VIRT_DISPLAY_WIDTH_HEIGHT_TAG       0x48004
#define FRAMEBUFFER_GET_DEPTH_TAG                           0x40005
#define FRAMEBUFFER_TEST_DEPTH_TAG                          0x44005
#define FRAMEBUFFER_SET_DEPTH_TAG                           0x48005
#define FRAMEBUFFER_GET_PIXEL_ORDER_TAG                     0x40006
#define FRAMEBUFFER_TEST_PIXEL_ORDER_TAG                    0x44006
#define FRAMEBUFFER_SET_PIXEL_ORDER_TAG                     0x48006
#define FRAMEBUFFER_GET_ALPHA_MODE_TAG                      0x40007
#define FRAMEBUFFER_TEST_ALPHA_MODE_TAG                     0x44007
#define FRAMEBUFFER_SET_ALPHA_MODE_TAG                      0x48007
#define FRAMEBUFFER_GET_PITCH_TAG                           0x40008
#define FRAMEBUFFER_GET_VIRT_OFFSET_TAG                     0x40009
#define FRAMEBUFFER_TEST_VIRT_OFFSET_TAG                    0x44009
#define FRAMEBUFFER_SET_VIRT_OFFSET_TAG                     0x48009
#define FRAMEBUFFER_GET_OVERSCAN_TAG                        0x4000a
#define FRAMEBUFFER_TEST_OVERSCAN_TAG                       0x4400a
#define FRAMEBUFFER_SET_OVERSCAN_TAG                        0x4800a
#define FRAMEBUFFER_GET_PALETTE_TAG                         0x4000b
#define FRAMEBUFFER_TEST_PALETTE_TAG                        0x4400b
#define FRAMEBUFFER_SET_PALETTE_TAG                         0x4800b
#define FRAMEBUFFER_SET_CURSOR_INFO_TAG	                    0x40010
#define FRAMEBUFFER_SET_CURSOR_STATE_TAG                    0x40011
#define FRAMEBUFFER_SET_SCREEN_GAMA_TAG	                    0x40012
