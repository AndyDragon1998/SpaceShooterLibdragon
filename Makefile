BUILD_DIR = build
NAME = SpaceShooterLibdragon
EMULATOR = $(HOME)/N64Development/Emulator/ares-139/desktop-ui/out/ares
include $(N64_INST)/include/n64.mk

Background_png = $(wildcard Graphics/Backgrounds/*.png)

Background_conv = $(addprefix Graphics/Backgrounds/,$(notdir $(Background_png:%.png=%.sprite)))

Image_png = $(wildcard Graphics/Images/*.png)

Image_conv = $(addprefix Graphics/Images/,$(notdir $(Image_png:%.png=%.sprite)))

Sprite_png = $(wildcard Graphics/Sprites/*.png)

Sprite_conv = $(addprefix Graphics/Sprites/,$(notdir $(Sprite_png:%.png=%.sprite)))

AUDIOCONV_FLAGS ?=
MKSPRITE_FLAGS ?=

all: SpaceShooterLibdragon.z64

Graphics/Backgrounds/%.sprite: Graphics/Backgrounds/%.png
	@$(N64_MKSPRITE) $(MKSPRITE_FLAGS) -o Graphics/Backgrounds "$<"
	
Graphics/Images/%.sprite: Graphics/Images/%.png
	@$(N64_MKSPRITE) $(MKSPRITE_FLAGS) -o Graphics/Images "$<"
	
Graphics/Sprites/%.sprite: Graphics/Sprites/%.png
	@$(N64_MKSPRITE) $(MKSPRITE_FLAGS) -o Graphics/Sprites "$<"
	
OBJS = $(BUILD_DIR)/main.o Data/stateManager.o Data/introState.o Data/menuState.o Data/gameState.o Data/overState.o

$(BUILD_DIR)/$(NAME).dfs: $(Background_conv)
$(BUILD_DIR)/$(NAME).dfs: $(Image_conv)
$(BUILD_DIR)/$(NAME).dfs: $(Sprite_conv)

$(NAME).z64: N64_ROM_TITLE = "Space Shooter Libdragon"
$(NAME).z64: $(BUILD_DIR)/$(NAME).dfs
$(BUILD_DIR)/$(NAME).elf: $(OBJS)

run:
	$(EMULATOR) $(CURDIR)/*.z64
.PHONY: run

clean:
	rm -rf $(BUILD_DIR).z64 *.z64 Data/*.d Data/*.o 
	rm -rf Graphics/Backgrounds/*.sprite Graphics/Images/*.sprite Graphics/Sprites/*.sprite
	rm -rf $(BUILD_DIR)*
.PHONY: clean

-include $(wildcard $(BUILD_DIR)/*.d)
