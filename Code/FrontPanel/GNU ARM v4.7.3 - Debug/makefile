################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include emlib/subdir.mk
-include CMSIS/efm32zg/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: FrontPanel.axf

# Tool invocations
FrontPanel.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m0plus -mthumb -T "FrontPanel.ld" -Xlinker --gc-sections -Xlinker -Map="FrontPanel.map" --specs=nano.specs -o FrontPanel.axf "./src/main.o" "./src/uart_connection.o" "./emlib/em_cmu.o" "./emlib/em_emu.o" "./emlib/em_gpio.o" "./emlib/em_i2c.o" "./emlib/em_int.o" "./emlib/em_rmu.o" "./emlib/em_rtc.o" "./emlib/em_system.o" "./emlib/em_timer.o" "./emlib/em_usart.o" "./emlib/em_wdog.o" "./CMSIS/efm32zg/startup_efm32zg.o" "./CMSIS/efm32zg/system_efm32zg.o" "./src/i2c_connection.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: FrontPanel.hex'
	arm-none-eabi-objcopy -O ihex "FrontPanel.axf" "FrontPanel.hex"
	@echo ' '

	@echo 'Building bin file: FrontPanel.bin'
	arm-none-eabi-objcopy -O binary "FrontPanel.axf" "FrontPanel.bin"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "FrontPanel.axf"
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) FrontPanel.axf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
