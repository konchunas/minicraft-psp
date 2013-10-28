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

typedef unsigned short ushort;

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
    oslInitGfx(OSL_PF_8888, 1);
    oslInitAudio();
    oslSetFrameskip(1);
    oslSetQuitOnLoadFailure(1);
    oslSetKeyAnalogToDPad(80);
    oslSetKeyAutorepeatMask(OSL_KEYMASK_CROSS);
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
    Sound::initSounds();
	Resource::init();
	Tile::init();
	Crafting::init();

    new Game();

    //Loads image:
    //spriteSheet = oslLoadImageFileGIF("icons.gif", OSL_IN_RAM | OSL_UNSWIZZLED, OSL_PF_8888);
    //sheet = new SpriteSheet(spriteSheet);



    //oslClearImage(background,RGBA(0,255,128,255));

    //int backgroundByteSize = background->totalSize;
    //memset(background->data, RGBA(255,255,128,255), backgroundByteSize);

    //pixels = (int*)background->data;
    //pixels = new int[backgroundByteSize];
    //memset(background->data,0,background->totalSize);

    //oslUnlockImage(background);

    //oslLockImage(background);
    //oslLockImage(spriteSheet);
    //render(0, 96, 3  + 10 * 32, Color::get(-1,555,555,555), 0);
    //oslUnlockImage(background);
    //oslUncacheImageData(background);


    //Load font:
//    OSL_FONT *pgfFont = oslLoadFontFile("flash0:/font/ltn0.pgf");
//    oslIntraFontSetStyle(pgfFont, 1.0, RGBA(255,255,255,255), RGBA(0,0,0,0), INTRAFONT_ALIGN_LEFT);
//    oslSetFont(pgfFont);
    //oslPrintf("%d %d",sheet->width, sheet->height);
    //while(!osl_quit){
    //   if (!skip){
    //        oslStartDrawing();
            //oslDrawImageXY(spriteSheet, 20, 20);

     //       oslDrawImageXY(background, 20, 20);

            //oslDrawString(0,0, __psp_cwd);


            //oslDrawString(180, 150, "Hello world");
            //oslDrawString(150, 250, "Press X to quit");

        //    oslEndDrawing();
        //}
        //oslEndFrame();
        //skip = oslSyncFrame();

        //oslReadKeys();
        //if (osl_keys->released.cross)
        //    oslQuit();
    //}
    //Quit OSL:
    oslEndGfx();

    sceKernelExitGame();
    return 0;
}
