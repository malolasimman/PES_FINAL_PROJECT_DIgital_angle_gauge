################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/Command_Processor.c \
../source/GPIO_RESET.c \
../source/I2C.c \
../source/MMA8451.c \
../source/PES_FINAL_PROJECT.c \
../source/PWM.c \
../source/State_Machine.c \
../source/Systick.c \
../source/TSI_Init.c \
../source/Test_MMA8451.c \
../source/Test_cbfifo.c \
../source/UART.c \
../source/cbfifo.c \
../source/mtb.c \
../source/semihost_hardfault.c \
../source/sysclock.c 

C_DEPS += \
./source/Command_Processor.d \
./source/GPIO_RESET.d \
./source/I2C.d \
./source/MMA8451.d \
./source/PES_FINAL_PROJECT.d \
./source/PWM.d \
./source/State_Machine.d \
./source/Systick.d \
./source/TSI_Init.d \
./source/Test_MMA8451.d \
./source/Test_cbfifo.d \
./source/UART.d \
./source/cbfifo.d \
./source/mtb.d \
./source/semihost_hardfault.d \
./source/sysclock.d 

OBJS += \
./source/Command_Processor.o \
./source/GPIO_RESET.o \
./source/I2C.o \
./source/MMA8451.o \
./source/PES_FINAL_PROJECT.o \
./source/PWM.o \
./source/State_Machine.o \
./source/Systick.o \
./source/TSI_Init.o \
./source/Test_MMA8451.o \
./source/Test_cbfifo.o \
./source/UART.o \
./source/cbfifo.o \
./source/mtb.o \
./source/semihost_hardfault.o \
./source/sysclock.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DPRINTF_FLOAT_ENABLE=1 -DCR_PRINTF_CHAR -DSDK_DEBUGCONSOLE_UART -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"/Users/malolasimman.s.k/Documents/MCUXpressoIDE_11.6.1_8255/workspace/Digital_angle_gauge/board" -I"/Users/malolasimman.s.k/Documents/MCUXpressoIDE_11.6.1_8255/workspace/Digital_angle_gauge/source" -I"/Users/malolasimman.s.k/Documents/MCUXpressoIDE_11.6.1_8255/workspace/Digital_angle_gauge" -I"/Users/malolasimman.s.k/Documents/MCUXpressoIDE_11.6.1_8255/workspace/Digital_angle_gauge/drivers" -I"/Users/malolasimman.s.k/Documents/MCUXpressoIDE_11.6.1_8255/workspace/Digital_angle_gauge/CMSIS" -I"/Users/malolasimman.s.k/Documents/MCUXpressoIDE_11.6.1_8255/workspace/Digital_angle_gauge/utilities" -I"/Users/malolasimman.s.k/Documents/MCUXpressoIDE_11.6.1_8255/workspace/Digital_angle_gauge/startup" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/Command_Processor.d ./source/Command_Processor.o ./source/GPIO_RESET.d ./source/GPIO_RESET.o ./source/I2C.d ./source/I2C.o ./source/MMA8451.d ./source/MMA8451.o ./source/PES_FINAL_PROJECT.d ./source/PES_FINAL_PROJECT.o ./source/PWM.d ./source/PWM.o ./source/State_Machine.d ./source/State_Machine.o ./source/Systick.d ./source/Systick.o ./source/TSI_Init.d ./source/TSI_Init.o ./source/Test_MMA8451.d ./source/Test_MMA8451.o ./source/Test_cbfifo.d ./source/Test_cbfifo.o ./source/UART.d ./source/UART.o ./source/cbfifo.d ./source/cbfifo.o ./source/mtb.d ./source/mtb.o ./source/semihost_hardfault.d ./source/semihost_hardfault.o ./source/sysclock.d ./source/sysclock.o

.PHONY: clean-source

