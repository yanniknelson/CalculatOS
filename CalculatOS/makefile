
# Collect all the source files
SRCS = $(wildcard */*.cpp) $(wildcard *.cpp)
# Take all the files in SRC and replace the .c with a .o to refer to their generated object files
OBJS = $(SRCS:.cpp=.o)
# src compile flags, importantly no standard library
CFLAGS = -Wall -Wextra -O2 -ffreestanding -fno-rtti -fno-exceptions -nostdlib -nostartfiles

# require the the clean command be run and then the kernel8.img is generated
all: full-clean kernel8.img

# requires start.S exist. Generates start.o
start.o: start.S
	aarch64-elf-g++ $(CFLAGS) -c start.S -o start.o

# requires all of the .c files. Generates all of the object files for all of the sources
%.o: %.cpp
	aarch64-elf-g++ $(CFLAGS) -c $< -o $@

# requires start.o and all of the object files. Links everything into kernel8.elf and then produces kernel8.img
kernel8.img: start.o $(OBJS)
	aarch64-elf-ld -nostdlib -z nostartfiles start.o $(OBJS) -T link.ld -o kernel8.elf
	aarch64-elf-objcopy -O binary kernel8.elf kernel8.img
	make clean

# deletes kernel8.elf and all the object files
clean:
	rm kernel8.elf *.o >/dev/null 2>/dev/null || true
	rm kernel8.elf */*.o >/dev/null 2>/dev/null || true

full-clean: clean
	rm kernel8.img >/dev/null 2>/dev/null || true

# requires kernel8.img, runs quemu with the parameters required for raspberry pi 3 b
run: kernel8.img
	qemu-system-aarch64 -M raspi3b -kernel kernel8.img -serial stdio


# requires kernel8.img, runs quemu with the parameters required for raspberry pi 3 b
run-uart1: kernel8.img
	qemu-system-aarch64 -M raspi3b -kernel kernel8.img -serial null -serial stdio