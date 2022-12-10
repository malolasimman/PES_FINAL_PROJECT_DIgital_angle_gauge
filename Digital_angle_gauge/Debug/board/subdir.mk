################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../board/board.c \
../board/clock_config.c \
../board/peripherals.c \
../board/pin_mux.c 

C_DEPS += \
./board/board.d \
./board/clock_config.d \
./board/peripherals.d \
./board/pin_mux.d 

OBJS += \
./board/board.o \
./board/clock_config.o \
./board/peripherals.o \
./board/pin_mux.o 


# Each subdirectory must supply rules for building sources it contributes
board/%.o: ../board/%.c board/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DPRINTF_FLOAT_ENABLE=1 -DCR_PRINTF_CHAR -DSDK_DEBUGCONSOLE_UART -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"/Users/malolasimman.s.k/Documents/MCUXpressoIDE_11.6.1_8255/workspace/Digital_angle_gauge/board" -I"/Users/malolasimman.s.k/Documents/MCUXpressoIDE_11.6.1_8255/workspace/Digital_angle_gauge/source" -I"/Users/malolasimman.s.k/Documents/MCUXpressoIDE_11.6.1_8255/workspace/Digital_angle_gauge" -I"/Users/malolasimman.s.k/Documents/MCUXpressoIDE_11.6.1_8255/workspace/Digital_angle_gauge/drivers" -I"/Users/malolasimman.s.k/Documents/MCUXpressoIDE_11.6.1_8255/workspace/Digital_angle_gauge/CMSIS" -I"/Users/malolasimman.s.k/Documents/MCUXpressoIDE_11.6.1_8255/workspace/Digital_angle_gauge/utilities" -I"/Users/malolasimman.s.k/Documents/MCUXpressoIDE_11.6.1_8255/workspace/Digital_angle_gauge/startup" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-board

clean-board:
	-$(RM) ./board/board.d ./board/board.o ./board/clock_config.d ./board/clock_config.o ./board/peripherals.d ./board/peripherals.o ./board/pin_mux.d ./board/pin_mux.o

.PHONY: clean-board

