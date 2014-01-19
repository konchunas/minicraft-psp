#include <pspkernel.h>
#include <oslib/oslib.h>
#include <oslib/drawing.h>
#include <oslib/keys.h>
#include <pspprof.h>

//#include <SpriteSheet.h>
//#include <Color.h>
#include "crafting/Crafting.h"
#include "level/tile/Tile.h"
#include "item/resource/Resource.h"
#include "Sound.h"
#include "Game.h"
#include "Logger.h"

PSP_MODULE_INFO("Minicraft", 0, 1, 0);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER | THREAD_ATTR_VFPU);
PSP_HEAP_SIZE_KB(12*1024);

//SpriteSheet * sheet;
//int * pixels;
//OSL_IMAGE *spriteSheet;
//OSL_IMAGE *background;


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Init OSLib:
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int initOSLib(){
    oslInit(0);
    oslInitGfx(OSL_PF_5650, 1);
    oslInitAudio();
    oslSetFramerate(60);
    oslSetFrameskip(1);
    oslSetQuitOnLoadFailure(1);
    oslSetKeyAnalogToDPad(100);
    oslSetKeyAutorepeatMask(OSL_KEYMASK_CROSS |
    						OSL_KEYMASK_UP |
    						OSL_KEYMASK_RIGHT |
    						OSL_KEYMASK_DOWN |
    						OSL_KEYMASK_LEFT);
    oslSetKeyAutorepeatInit(30);
    oslSetKeyAutorepeatInterval(5);
    //oslSysBenchmarkDisplay();
    oslBenchmarkTest(OSL_BENCH_INIT);
    return 0;
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Main:
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    initOSLib();
    oslSetImageAutoSwizzle(false);

    //here we have initialization functions to prevent fiasco
    Logger::init();
    Sound::initSounds();
	Resource::init();
	Tile::init();
	Resource::initPlantable();	//plantable resources require some tiles to be already initialized
	Crafting::init();

    new Game();

    //Quit OSL:
    oslEndGfx();

    sceKernelExitGame();
    return 0;
}
