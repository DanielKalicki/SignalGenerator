################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/drivers/subdir.mk
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
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -T "SignalGeneratorMCU.ld" -Xlinker --gc-sections -Xlinker -Map="SignalGeneratorMCU.map" -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -o SignalGeneratorMCU.axf "./src/AD9106.o" "./src/SPFD5408.o" "./src/main.o" "./src/spi.o" "./src/utils.o" "./src/drivers/ethspi.o" "./src/drivers/rtcdrv.o" "./src/drivers/segmentlcd.o" "./emlib/em_acmp.o" "./emlib/em_adc.o" "./emlib/em_aes.o" "./emlib/em_assert.o" "./emlib/em_burtc.o" "./emlib/em_cmu.o" "./emlib/em_dac.o" "./emlib/em_dbg.o" "./emlib/em_dma.o" "./emlib/em_ebi.o" "./emlib/em_emu.o" "./emlib/em_gpio.o" "./emlib/em_i2c.o" "./emlib/em_idac.o" "./emlib/em_int.o" "./emlib/em_lcd.o" "./emlib/em_lesense.o" "./emlib/em_letimer.o" "./emlib/em_leuart.o" "./emlib/em_mpu.o" "./emlib/em_msc.o" "./emlib/em_opamp.o" "./emlib/em_pcnt.o" "./emlib/em_prs.o" "./emlib/em_rmu.o" "./emlib/em_rtc.o" "./emlib/em_system.o" "./emlib/em_timer.o" "./emlib/em_usart.o" "./emlib/em_vcmp.o" "./emlib/em_wdog.o" "./CMSIS/efm32wg/startup_gcc_efm32wg.o" "./CMSIS/efm32wg/system_efm32wg.o" "./BSP/bsp_bcc.o" "./BSP/bsp_stk.o" "./BSP/bsp_stk_leds.o" "./BSP/bsp_trace.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
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
