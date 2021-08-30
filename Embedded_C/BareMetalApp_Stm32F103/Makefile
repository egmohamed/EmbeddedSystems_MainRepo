Project_Name = Toggle_Led_Stm32F103
CC = arm-none-eabi-
CFLAGS = -c -mcpu=cortex-m3
Linker_Name = linkerScript_ArmCortex-M3.ld
Startup_Name = startup
INC = Inc\
SRC = $(wildcard src\*.c)
As  = $(wildcard *.s)
LIBS= $(wildcard *.a)
OBJ = $(SRC:.c=.o)
AsOBJ = $(As:.s=.o)

all: $(Project_Name).bin
	echo "============ Build Done ============"


%.o: %.c
	$(CC)gcc.exe $(CFLAGS) -I $(INC) $< -o $@
	
	
$(Project_Name).elf: $(OBJ) 
	$(CC)ld.exe -T $(Linker_Name) $< $(LIBS) -o $@

	
$(Project_Name).bin: $(Project_Name).elf
	$(CC)objcopy.exe -O binary $< $@
	
	
clean:
	rm *.elf *.bin
	
	
clean-all:
	rm *.o *.elf *.bin

