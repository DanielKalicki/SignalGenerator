################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include emlib/subdir.mk
-include CMSIS/efm32wg/subdir.mk
-include BSP/subdir.mk
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
all: SignalGenerator.axf

# Tool invocations
SignalGenerator.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -T "SignalGenerator.ld" -Xlinker --gc-sections -Xlinker -Map="SignalGenerator.map" -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -o SignalGenerator.axf "./src/AD9106.o" "./src/main.o" "./emlib/em_assert.o" "./emlib/em_cmu.o" "./emlib/em_ebi.o" "./emlib/em_emu.o" "./emlib/em_gpio.o" "./emlib/em_system.o" "./emlib/em_usart.o" "./CMSIS/efm32wg/startup_efm32wg.o" "./CMSIS/efm32wg/system_efm32wg.o" "./BSP/bsp_bcc.o" "./BSP/bsp_stk.o" "./BSP/bsp_stk_leds.o" "./BSP/bsp_trace.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: SignalGenerator.hex'
	arm-none-eabi-objcopy -O ihex "SignalGenerator.axf" "SignalGenerator.hex"
	@echo ' '

	@echo 'Building bin file: SignalGenerator.bin'
	arm-none-eabi-objcopy -O binary "SignalGenerator.axf" "SignalGenerator.bin"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "SignalGenerator.axf"
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) SignalGenerator.axf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
