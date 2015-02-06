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
all: SignalGeneratorMCU.axf

# Tool invocations
SignalGeneratorMCU.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -T "SignalGeneratorMCU.ld" -Xlinker --gc-sections -Xlinker -Map="SignalGeneratorMCU.map" -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -o SignalGeneratorMCU.axf "./src/AD9106.o" "./src/SPFD5408.o" "./src/main.o" "./src/spi.o" "./src/utils.o" "./emlib/em_assert.o" "./emlib/em_cmu.o" "./emlib/em_ebi.o" "./emlib/em_emu.o" "./emlib/em_gpio.o" "./emlib/em_system.o" "./emlib/em_usart.o" "./CMSIS/efm32wg/startup_gcc_efm32wg.o" "./CMSIS/efm32wg/system_efm32wg.o" "./BSP/bsp_bcc.o" "./BSP/bsp_stk.o" "./BSP/bsp_stk_leds.o" "./BSP/bsp_trace.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: SignalGeneratorMCU.hex'
	arm-none-eabi-objcopy -O ihex "SignalGeneratorMCU.axf" "SignalGeneratorMCU.hex"
	@echo ' '

	@echo 'Building bin file: SignalGeneratorMCU.bin'
	arm-none-eabi-objcopy -O binary "SignalGeneratorMCU.axf" "SignalGeneratorMCU.bin"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "SignalGeneratorMCU.axf"
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) SignalGeneratorMCU.axf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
