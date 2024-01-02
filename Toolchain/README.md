# STM32_Toolchain_VSC

Doing the following steps:
1. Extract .zip file
2. Make GCC_ARM variable in "Environment Variables" - System Variables
    value : "$ENV{TOOL_PATH}\stm32_toolchain\arm-gnu-toolchain-13.2.Rel1-mingw-w64-i686-arm-none-eabi\bin"
3. Add it into Path:
    Click New: "%GCC_ARM%"
4. Add Make path:
    "$ENV{MAKE_PATH}\stm32_toolchain\make-3.81\bin"
5. Add OpenOCD path:
    "$ENV{TOOL_PATH}\stm32_toolchain\OpenOCD-20231002-0.12.0\bin"
