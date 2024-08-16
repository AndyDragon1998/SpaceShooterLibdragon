BUILD_DIR = build
RES_DIR = Output
NAME = SpaceShooterLibdragon
EMULATOR = $(HOME)/N64Development/Emulator/ares-132/desktop-ui/out/ares
include $(N64_INST)/include/n64.mk

Background_png = $(wildcard Graphics/Backgrounds/*.png)

Background_conv = $(addprefix $(RES_DIR)/Graphics/Backgrounds/,$(notdir $(Background_png:%.png=%.sprite)))

Image_png = $(wildcard Graphics/Images/*.png)

Image_conv = $(addprefix $(RES_DIR)/Graphics/Images/,$(notdir $(Image_png:%.png=%.sprite)))

Sprite_png = $(wildcard Graphics/Sprites/*.png)

Sprite_conv = $(addprefix $(RES_DIR)/Graphics/Sprites/,$(notdir $(Sprite_png:%.png=%.sprite)))

BGM_wav = $(wildcard Audio/BGM/*.wav)

BGM_conv = $(addprefix $(RES_DIR)/Audio/BGM/,$(notdir $(BGM_wav:%.wav=%.wav64)))


AUDIOCONV_FLAGS ?=
MKSPRITE_FLAGS ?=

all: SpaceShooterLibdragon.z64

$(RES_DIR)/Intro.sprite: Graphics/Intro.png
	@mkdir -p $(dir $@)
	@$(N64_MKSPRITE) $(MKSPRITE_FLAGS) -o $(RES_DIR) "$<"

$(RES_DIR)/Graphics/Backgrounds/%.sprite: Graphics/Backgrounds/%.png
	@mkdir -p $(dir $@)
	@$(N64_MKSPRITE) $(MKSPRITE_FLAGS) -o $(RES_DIR)/Graphics/Backgrounds "$<"
	
$(RES_DIR)/Graphics/Images/%.sprite: Graphics/Images/%.png
	@mkdir -p $(dir $@)
	@$(N64_MKSPRITE) $(MKSPRITE_FLAGS) -o $(RES_DIR)/Graphics/Images "$<"
	
$(RES_DIR)/Graphics/Sprites/%.sprite: Graphics/Sprites/%.png
	@mkdir -p $(dir $@)
	@$(N64_MKSPRITE) $(MKSPRITE_FLAGS) -o $(RES_DIR)/Graphics/Sprites "$<"
	
$(RES_DIR)/Audio/BGM/%.wav64: Audio/BGM/%.wav
	@mkdir -p $(dir $@)
	@$(N64_AUDIOCONV) $(AUDIOCONV_FLAGS) -o $(RES_DIR)/Audio/BGM "$<"
	
OBJS = $(BUILD_DIR)/main.o Data/stateManager.o Data/introState.o Data/menuState.o Data/gameState.o Data/overState.o

$(BUILD_DIR)/$(NAME).dfs: $(RES_DIR)/Intro.sprite $(Background_conv) $(Image_conv) $(Sprite_conv) $(BGM_conv)

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
	rm -rf $(RES_DIR)*
.PHONY: clean

-include $(wildcard $(BUILD_DIR)/*.d)
