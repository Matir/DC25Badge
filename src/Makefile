PROJNAME = dc25badge
MAKEFLAGS += -rR --no-print-directory
SHELL = /bin/bash

CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
OBJDUMP = arm-none-eabi-objdump

XBOARD = TEST
ifeq ($(XBOARD),SPARKFUN)
	TARGET = SAMD21G18A
else
	TARGET = SAMD21E18A
endif

INC = \
			./config \
			./usb \
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
			./asf/common/services/usb/udc \
			./asf/common/services/usb/class/cdc/device/ \
			./asf/common/services/usb/class/cdc/ \
			./asf/sam0/drivers/usb/ \
			./asf/common/boards \
			./asf/common/boards/user_board \
			./asf/sam0/drivers/extint \
			./asf/sam0/drivers/system/pinmux \
			./asf/common/services/ioport \
			./asf/sam0/drivers/sercom \
			./asf/sam0/drivers/sercom/spi \
			./asf/sam0/drivers/port \
			./asf/sam0/drivers/tc \
			./asf/sam0/drivers/extint \

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
			./asf/sam0/utils/syscalls/gcc/syscalls.o \
			./asf/common/services/usb/class/cdc/device/udi_cdc.o \
			./asf/common/services/usb/class/cdc/device/udi_cdc_desc.o \
			./asf/sam0/drivers/usb/stack_interface/usb_device_udd.o \
			./asf/common/services/usb/udc/udc.o \
			./asf/sam0/drivers/usb/usb_sam_d_r/usb.o \
			./asf/sam0/drivers/system/pinmux/pinmux.o \
			./asf/sam0/drivers/sercom/spi/spi.o \
			./asf/sam0/drivers/sercom/spi/spi_interrupt.o \
			./asf/sam0/drivers/sercom/sercom.o \
			./asf/sam0/drivers/sercom/sercom_interrupt.o \
			./asf/sam0/drivers/port/port.o \
			./asf/sam0/drivers/tc/tc_interrupt.o \
			./asf/sam0/drivers/tc/tc_sam_d_r_h/tc.o \
			./asf/sam0/drivers/extint/extint_callback.o \
			./asf/sam0/drivers/extint/extint_sam_d_r_h/extint.o \


COMMON_FLAGS = -mcpu=cortex-m0plus -mthumb

CFLAGS = $(COMMON_FLAGS) -Wall -Werror -std=gnu11 -g -O0 -pipe \
	-D__$(TARGET)__ -DTARGET=$(TARGET) -DSYSTICK_MODE -DARM_MATH_CM0PLUS \
	-Dprintf=iprintf -Wno-unused-but-set-variable -fno-strict-aliasing \
	-DXBOARD_$(XBOARD) -nostartfiles -DTC_ASYNC=true \
	-DEXTINT_CALLBACK_MODE=true \


CFLAGS += $(addprefix -I ,$(INC))

# Separate each function and data into its own separate section to allow
# # garbage collection of unused sections.
CFLAGS += -ffunction-sections -fdata-sections

LDFLAGS = $(COMMON_FLAGS) \
					-Wl,-T samd21e18a_flash.ld -Wl,--gc-sections -Wl,-Map=$(PROJNAME).map \
					--specs=nano.specs -Wl,--entry=Reset_Handler

PATTERNS=$(wildcard pattern/pattern_*.c)

OBJS = main.o \
			 usb/stdio_usb.o \
			 apa102c/apa102c.o \
			 pattern/pattern.o \
			 pattern/consts.o \
			 button/button.o \
			 $(PATTERNS:%.c=%.o) \
			 $(DEP_OBJS)

CONFIG_HEADERS = $(wildcard *.h) $(wildcard config/*.h)

PORT ?= ttyACM0

### Targets Begin ###

.PHONY: all
all: $(PROJNAME).bin

$(PROJNAME).bin: $(PROJNAME).elf
	$(OBJCOPY) -O binary $< $@

$(PROJNAME).elf: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c $(CONFIG_HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

pattern/consts.c: tools/gentable.py $(CONFIG_HEADERS)
	$(eval NUMPX=$(shell $(CC) -E $(CFLAGS) -I . -x c <(echo -e '#include <config.h>\nNUM_PIXELS') | tail -1))
	python tools/gentable.py $(NUMPX) 30 $@

$(PROJNAME).map: $(PROJNAME).elf

.PHONY: clean
clean:
	rm -f -- *.bin *.elf *.map
	find . -name tools -prune -o -name '*.o' -print | xargs rm

.PHONY: upload
upload: $(PROJNAME).bin bossa
	tools/BOSSA/bin/bossac --port=$(PORT) --info --erase --write --verify --reset $<

.PHONY: console
console:
	screen /dev/$(PORT) 115200

.PHONY: bootloader
bootloader:
	# Only for the 'E' series!
	make -C bootloader

.PHONY: burnin
burnin: bootloader
	echo "TODO"

.PHONY: openocd gdb
openocd:
	openocd -f ./openocd.cfg

gdb:
	gdb-multiarch -n -ex 'file ./$(PROJNAME).elf' \
		-ex 'target extended-remote :3333'

.PHONY: bossa
bossa:
	make -C tools/BOSSA

.PHONY: variables
variables:
	$(foreach v, $(.VARIABLES), $(info $(v) = $($(v))))
