# STM32_Custom_Bootloader
Change the below params:
In STM32_Flash.ld bootloader file

    MEMORY
{
  RAM    (xrw)    : ORIGIN = 0x20000000,   LENGTH = 64K
  FLASH    (rx)    : ORIGIN = 0x8000000,   LENGTH = 16K
}

In STM32_Flash.ld application file

MEMORY
{
  RAM    (xrw)    : ORIGIN = 0x20000000,   LENGTH = 64K
  FLASH    (rx)    : ORIGIN = 0x8004400,   LENGTH = 47K
}

Upload the firmware into address (0x8000000) for bootloader.bin and (0x8004400) for application.bin