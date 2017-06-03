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
			./asf/common2/services/delay/sam0 \
			./asf/sam0/drivers/system/clock \
			./asf/sam0/drivers/system/clock/clock_samd21_r21_da_ha1 \
			./asf/sam0/drivers/system/interrupt \
			./asf/sam0/drivers/system/interrupt/system_interrupt_samd21 \
			./asf/common/services/sleepmgr \
			./asf/common/services/usb \
			./asf/common/utils/stdio/stdio_usb \
			./asf/common/services/usb/udc \
			./asf/common/services/usb/class/cdc/device/ \
			./asf/common/services/usb/class/cdc/ \
			./asf/sam0/drivers/usb/ \
			./asf/common/boards \
			./asf/common/boards/user_board \
			./asf/sam0/drivers/extint \
			./asf/sam0/drivers/system/pinmux \

DEP_OBJS = \
			./asf/common2/services/delay/sam0/systick_counter.o \
			./asf/sam0/utils/cmsis/samd21/source/system_samd21.o \
			./asf/sam0/utils/cmsis/samd21/source/gcc/startup_samd21.o \
			./asf/sam0/drivers/system/clock/clock_samd21_r21_da_ha1/clock.o \
			./asf/sam0/drivers/system/clock/clock_samd21_r21_da_ha1/gclk.o \
			./asf/common/utils/interrupt/interrupt_sam_nvic.o \
			./asf/common/services/sleepmgr/samd/sleepmgr.o \
			./asf/sam0/drivers/system/system.o \
			./asf/common/utils/stdio/read.o \
			./asf/common/utils/stdio/write.o \
			./asf/common/utils/stdio/stdio_usb/stdio_usb.o \
			./asf/sam0/utils/syscalls/gcc/syscalls.o \
			./asf/common/services/usb/class/cdc/device/udi_cdc.o \
			./asf/common/services/usb/class/cdc/device/udi_cdc_desc.o \
			./asf/sam0/drivers/usb/stack_interface/usb_device_udd.o \
			./asf/common/services/usb/udc/udc.o \
			./asf/sam0/drivers/usb/usb_sam_d_r/usb.o \
			./asf/sam0/drivers/system/pinmux/pinmux.o \


CFLAGS = -mcpu=cortex-m0plus -mthumb -Wall -Werror -std=gnu11 -g -O0 -pipe \
	-D__$(TARGET)__ -DTARGET=$(TARGET) -DSYSTICK_MODE -DARM_MATH_CM0PLUS \
	-Dprintf=iprintf -Wno-unused-but-set-variable -fno-strict-aliasing

CFLAGS += $(addprefix -I ,$(INC))

# Separate each function and data into its own separate section to allow
# # garbage collection of unused sections.
CFLAGS += -ffunction-sections -fdata-sections

LDSCRIPT = asf/sam0/utils/linker_scripts/samd21/gcc/$(shell echo $(TARGET)| tr A-Z a-z)_flash.ld

LDFLAGS = -Wl,-T $(LDSCRIPT) -Wl,--gc-sections -Wl,-Map=dc25badge.map \
					--specs=nano.specs

OBJS = main.o \
			 $(DEP_OBJS)

CONFIG_HEADERS = $(wildcard *.h) $(wildcard config/*.h)

PORT ?= ttyACM0

### Targets Begin ###

.PHONY: all
all: dc25badge.bin

dc25badge.bin: dc25badge.elf
	$(OBJCOPY) -O binary $< $@

dc25badge.elf: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c $(CONFIG_HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

dc25badge.map: dc25badge.elf

.PHONY: clean
clean:
	rm -f -- *.bin *.elf
	find . -name '*.o' -delete

.PHONY: upload
upload: dc25badge.bin
	bossac --port=$(PORT) --info --erase --write --verify --reset $<

.PHONY: console
console:
	screen /dev/$(PORT) 115200

.PHONY: variables
variables:
	$(foreach v, $(.VARIABLES), $(info $(v) = $($(v))))
