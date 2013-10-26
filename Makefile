TARGET = minicraft
OBJS = main.o SpriteSheet.o Color.o Game.o InputHandler.o InputHandler_Key.o \
	Screen.o Font.o \
	Typeable.o \
	Random.o \
	item/Item.o \
	item/resource/Resource.o \
	item/resource/PlantableResource.o \
	item/resource/FoodResource.o \
	item/ResourceItem.o \
	item/ToolItem.o \
	item/ToolType.o \
	item/FurnitureItem.o \
	menu/ListItem.o \
	menu/Menu.o \
	menu/InventoryMenu.o \
	menu/CraftingMenu.o \
	menu/LevelTransitionMenu.o \
	entity/Entity.o \
	entity/Mob.o \
	entity/Player.o \
	entity/Inventory.o \
	entity/ItemEntity.o \
	entity/Furniture.o \
	entity/Workbench.o \
	entity/Furnace.o \
	entity/Oven.o \
	crafting/Recipe.o \
	crafting/Crafting.o \
	crafting/ToolRecipe.o \
	crafting/FurnitureRecipe.o \
	crafting/ResourceRecipe.o \
	particle/Particle.o \
	particle/TextParticle.o \
	particle/SmashParticle.o \
	level/Level.o level/LevelGen.o \
	level/tile/Tile.o \
	level/tile/RockTile.o level/tile/GrassTile.o level/tile/WaterTile.o \
	level/tile/SandTile.o level/tile/FlowerTile.o level/tile/TreeTile.o \
	level/tile/StairsTile.o level/tile/SandTile.o level/tile/CactusTile.o \
	level/tile/SaplingTile.o level/tile/DirtTile.o level/tile/HoleTile.o \
	level/tile/LavaTile.o level/tile/FarmTile.o level/tile/WheatTile.o \
	level/tile/OreTile.o
	

INCDIR = 
CFLAGS = -O2 -G0 -Wall
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

BUILD_PRX=1

LIBDIR =
LDFLAGS =

MYLIBS=
STDLIBS= -lstdc++ -losl -lpng -lz \
         -lpsphprm -lpspsdk -lpspctrl -lpspumd -lpsprtc -lpsppower -lpspgu -lpspgum  -lpspaudiolib -lpspaudio -lpsphttp -lpspssl -lpspwlan \
         -lpspnet_adhocmatching -lpspnet_adhoc -lpspnet_adhocctl -lm -ljpeg 
LIBS=$(STDLIBS) $(MYLIBS)

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = Minicraft

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak

