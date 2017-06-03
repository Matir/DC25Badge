CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
OBJDUMP = arm-none-eabi-objdump

TARGET = SAMD21G18A

INC = \
			./config \
			./asf/sam0/drivers/system \
			./asf/sam0/drivers/port/ \
			./asf/sam0/utils/cmsis/samd21/include \
			./asf/sam0/drivers/system/power/power_sam_d_r_h \
			./asf/sam0/drivers/system/reset/reset_sam_d_r_h \
			./asf/thirdparty/CMSIS/Include \
			./asf/sam0/utils/cmsis/samd21/source \
			./asf/sam0/utils/cmsis/samd21/include \
			./asf/sam0/utils \
			./asf/common/utils \
			./asf/sam0/utils/preprocessor \
			./asf/sam0/utils/header_files \
			./asf/sam0/drivers/system/pinmux \
			./asf/common2/services/delay \
			./asf/common2/services/delay/sam0/ \
			./asf/sam0/drivers/system/clock/ \
			./asf/sam0/drivers/system/clock/clock_samd21_r21_da_ha1/ \
			./asf/sam0/drivers/system/interrupt \
			./asf/sam0/drivers/system/interrupt/system_interrupt_samd21 \


DEP_OBJS = \
			./asf/common2/services/delay/sam0/systick_counter.o \
			./asf/sam0/utils/cmsis/samd21/source/system_samd21.o \
			./asf/sam0/utils/cmsis/samd21/source/gcc/startup_samd21.o \
			./asf/sam0/drivers/system/clock/clock_samd21_r21_da_ha1/clock.o \
			./asf/sam0/drivers/system/clock/clock_samd21_r21_da_ha1/gclk.o \
			./asf/common/utils/interrupt/interrupt_sam_nvic.o \


CFLAGS = -mcpu=cortex-m0plus -mthumb -Wall -Werror -std=c11 -g -O0 -pipe \
	-D__$(TARGET)__ -DTARGET=$(TARGET) -DSYSTICK_MODE -DARM_MATH_CM0PLUS

CFLAGS += $(addprefix -I ,$(INC))

# Separate each function and data into its own separate section to allow
# # garbage collection of unused sections.
CFLAGS += -ffunction-sections -fdata-sections

LDSCRIPT = asf/sam0/utils/linker_scripts/samd21/gcc/$(shell echo $(TARGET)| tr A-Z a-z)_flash.ld

LDFLAGS = -Wl,-T $(LDSCRIPT) -Wl,--gc-sections -Wl,-Map=dc25badge.map

OBJS = main.o \
			 $(DEP_OBJS)

.PHONY: all
all: dc25badge.bin

dc25badge.bin: dc25badge.elf
	$(OBJCOPY) -O binary $< $@

dc25badge.elf: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

dc25badge.map: dc25badge.elf


.PHONY: clean
clean:
	rm -f -- *.bin *.elf
	find . -name '*.o' -delete

.PHONY: variables
variables:
	$(foreach v, $(.VARIABLES), $(info $(v) = $($(v))))
