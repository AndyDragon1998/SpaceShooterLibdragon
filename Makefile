all: SpaceShooterLibdragon.z64
.PHONY: all

BUILD_DIR = build
NAME = SpaceShooterLibdragon
EMULATOR = $(HOME)/N64Development/Emulator/ares-139/desktop-ui/out/ares

include $(N64_INST)/include/n64.mk

OBJS = $(BUILD_DIR)/main.o Data/stateManager.o Data/introState.o Data/menuState.o Data/gameState.o Data/overState.o

IMGS = Graphics/test.sprite

$(NAME).z64: N64_ROM_TITLE = "Space Shooter Libdragon"
$(NAME).z64: $(BUILD_DIR)/$(NAME).dfs

$(BUILD_DIR)/$(NAME).dfs: $(wildcard $(IMGS))
$(BUILD_DIR)/$(NAME).elf: $(OBJS)

run:
	$(EMULATOR) $(CURDIR)/*.z64
.PHONY: run

clean:
	rm -rf $(BUILD_DIR).z64 *.z64 Data/*.d Data/*.o
.PHONY: clean

-include $(wildcard $(BUILD_DIR)/*.d)
