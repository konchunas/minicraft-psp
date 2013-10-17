TARGET = minicraft
OBJS = main.o SpriteSheet.o Color.o Game.o InputHandler.o InputHandler_Key.o \
	Screen.o Font.o \
	Typeable.o \
	Random.o \
	menu/ListItem.o \
	entity/Entity.o \
	entity/Mob.o \
	entity/Player.o \
	level/Level.o level/LevelGen.o \
	level/tile/Tile.o \
	level/tile/RockTile.o level/tile/GrassTile.o level/tile/WaterTile.o \
	level/tile/SandTile.o level/tile/FlowerTile.o level/tile/TreeTile.o \
	level/tile/StairsTile.o level/tile/SandTile.o level/tile/CactusTile.o
	
	

INCDIR = 
CFLAGS = -O2 -G0 -Wall
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti -g
ASFLAGS = $(CFLAGS)

LIBDIR =
LDFLAGS =

MYLIBS=
STDLIBS= -lstdc++ -losl -lpng -lz \
         -lpsphprm -lpspsdk -lpspctrl -lpspumd -lpsprtc -lpsppower -lpspgu -lpspgum  -lpspaudiolib -lpspaudio -lpsphttp -lpspssl -lpspwlan \
         -lpspnet_adhocmatching -lpspnet_adhoc -lpspnet_adhocctl -lm -ljpeg 
LIBS=$(STDLIBS) $(MYLIBS)

BUILD_PRX=1

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = Minicraft

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak

