#define HEIGHT 90
#define WIDTH  160
#define SCALE 3

#define SCALED_WIDTH  480
#define SCALED_HEIGHT 270

#include <stdlib.h>
#include <ctime>
#include <math.h>

#include <oslib/oslib.h>
#include <sstream>

#include "Font.h"
#include "Color.h"
#include "Game.h"

#include "menu/Menu.h"
#include "menu/TitleMenu.h"
#include "menu/LevelTransitionMenu.h"
#include "menu/DeadMenu.h"
#include "menu/WonMenu.h"


Game::Game():
menu(NULL),
previousMenu(NULL),
frameskip(0),
wonTimer(0),
gameTime(0),
playerDeadTime(0),
hasWon(false),
levels(NULL),
player(NULL)
{
	image = oslCreateImage(WIDTH * SCALE, HEIGHT *SCALE, OSL_IN_RAM, OSL_PF_5650);

	colors = new ushort[256];
	pixels = (ushort*)image->data;
	input = new InputHandler();
	run();
}

Game::~Game() {
	delete[] colors;
}

void Game::resetGame()
{
	//cleanup previous game
	if (levels)
	{
		for (int i = 0; i < 5; i++)
		{
			delete levels[i];
		}
		delete[] levels;
	}

	playerDeadTime = 0;
	wonTimer = 0;
	gameTime = 0;
	hasWon = false;

	levels = new Level*[5];
	currentLevel = 3;

	levels[4] = new Level(128, 128, 1, NULL);
	levels[3] = new Level(128, 128, 0, levels[4]);
	levels[2] = new Level(128, 128, -1, levels[3]);
	levels[1] = new Level(128, 128, -2, levels[2]);
	levels[0] = new Level(128, 128, -3, levels[1]);

	level = levels[currentLevel];
	player = new Player(this, input);
	player->findStartPos(level);

	level->add(player);

	for (int i = 0; i < 5; i++)
	{
		levels[i]->trySpawn(5000);
	}
}

void Game::render()
{
	if (player)
	{
		int xScroll = player->x - screen->w / 2;
		int yScroll = player->y - (screen->h + 8) / 2;
		if (xScroll < 16) xScroll = 16;
		if (yScroll < 16) yScroll = 16;
		if (xScroll > level->w * 16 - screen->w - 16) xScroll = level->w * 16 - screen->w - 16;
		if (yScroll > level->h * 16 - screen->h - 16) yScroll = level->h * 16 - screen->h - 16;
		//WTF?
		// if this condition is set, then every tenth frame is handled for 30ms,
		//while others are handled in fine 1ms interval
		//if (currentLevel > 3)
		{
			//it is special substrate for sky level to create parallax effect
			int col = Color::get(20, 20, 121, 121);
				for (ushort y = 0; y < 14; y++)
					for (ushort x = 0; x < 24; x++)
					{
						screen->render(x * 8 - ((xScroll / 4) & 7), y * 8 - ((yScroll / 4) & 7), 0, col, 0);
					}
		}

		level->renderBackground(screen, xScroll, yScroll);
		level->renderSprites(screen, xScroll, yScroll);

		if (currentLevel != 0)	//HACK: rendering light in lava level causing CPU overhead
			if (currentLevel < 3)
			{
				lightScreen->clear(0);
				level->renderLight(lightScreen, xScroll, yScroll);
				screen->overlay(lightScreen, xScroll, yScroll);
			}
	}

	renderGui();

//	if (!hasFocus()) renderFocusNagger();

//	std::stringstream ss;
//	int milliseconds = oslBenchmarkTest(OSL_BENCH_GET);
//	ss << milliseconds;
//	Font::draw(ss.str(), screen, 0 , 0 , Color::get(-1, 555, 555, 555));
//
//	std::stringstream ss1;
//	ss1 << oslGetRamStatus().maxAvailable;
//	Font::draw(ss1.str(),screen, 80 , 0 , Color::get(-1, 555, 555, 555));
//
//	std::stringstream ss2;
//	ss2 << frames;
//	Font::draw(ss2.str(),screen, 0 , 40 , Color::get(-1, 555, 555, 555));

	oslLockImage(image);
//	for (int y = 0; y < screen->h; ++y)
//	{
////		memcpy((int*)(pixels + y * image->realSizeX),
////			   (int*)(screen->pixels + y * screen->w),
////			    screen->w * 4);
////	}
//		for (int x = 0; x < screen->w; ++x)
//		{
//			ushort cc = screen->pixels[x + y * screen->w];
//			pixels[x + y * image->realSizeX] = colors[cc];
//		}
//	}

	//nearest neighbor for scaling
	//and to move from screen to image
	//somewhat optimized
	short x_ratio = (short)((screen->w<<16)/(SCALED_WIDTH)) +1;
	short y_ratio = (short)((screen->h<<16)/(SCALED_HEIGHT)) +1;
	short x = -1, y = -1, prevX = -1;
	ushort cc;
	ushort * screenPixels = screen->pixels;
	for (short i = 0; i<SCALED_HEIGHT; ++i)
	{
		y = ((i*y_ratio)>>16);
		short yByScreenWidth = y * screen->w;
		int iByImageWidth = i * image->realSizeX;
		//oslDebug(image->realSizeX);
		for (short j = 0; j<SCALED_WIDTH; ++j)
		{
			x = ((j*x_ratio)>>16);
			if (x != prevX)
			{
				cc = colors[screenPixels[yByScreenWidth + x]];
				prevX = x;
			}
			pixels[iByImageWidth+j] = cc;
		}
	}
	oslUnlockImage(image);

	oslStartDrawing();
	oslDrawImageSimpleXY(image,0,0);
	oslEndDrawing();

}
void Game::renderGui()
{
	//Font::draw("game mode",screen,200,0,Color:: get(5, 555, 555, 555));
//	for (int y = 0; y < 2; y++) {
//		for (int x = 0; x < 20; x++) {
//			screen->render(x * 8, screen->h - 16 + y * 8, 0 + 12 * 32, Color::get(000, 000, 000, 000), 0);
//		}
//	}
	if (player)
	{
		for (int i = 0; i < 10; i++)
		{
			if (i < player->health)
				screen->render(i * 8, screen->h - 16, 0 + 12 * 32, Color::get(-1, 200, 500, 533), 0);
			else
				screen->render(i * 8, screen->h - 16, 0 + 12 * 32, Color::get(-1, 100, 000, 000), 0);

			if (player->staminaRechargeDelay > 0)
			{
				if (player->staminaRechargeDelay / 4 % 2 == 0)
					screen->render(i * 8, screen->h - 8, 1 + 12 * 32, Color::get(-1, 555, 000, 000), 0);
				else
					screen->render(i * 8, screen->h - 8, 1 + 12 * 32, Color::get(-1, 110, 000, 000), 0);
			} else {
				if (i < player->stamina)
					screen->render(i * 8, screen->h - 8, 1 + 12 * 32, Color::get(-1, 220, 550, 553), 0);
				else
					screen->render(i * 8, screen->h - 8, 1 + 12 * 32, Color::get(-1, 110, 000, 000), 0);
			}
		}
		if (player->activeItem != NULL)
		{
			player->activeItem->renderInventory(screen, 10 * 8, screen->h - 16);
		}
	}
	if (menu != NULL)
	{
		menu->render(screen);
	}
}

void Game::init()
{
		ushort pp = 0;
		for (ushort r = 0; r < 6; r++)
		{
			for (ushort g = 0; g < 6; g++)
			{
				for (ushort b = 0; b < 6; b++)
				{
					ushort rr = (r * 255 / 5);
					ushort gg = (g * 255 / 5);
					ushort bb = (b * 255 / 5);
					ushort mid = (rr * 30 + gg * 59 + bb * 11) / 100;

					ushort r1 = ((rr + mid * 1) / 2) * 230 / 255 + 10;
					ushort g1 = ((gg + mid * 1) / 2) * 230 / 255 + 10;
					ushort b1 = ((bb + mid * 1) / 2) * 230 / 255 + 10;
					ushort r2 = (r1 >> 3) & 0xFF;
					ushort g2 = (g1 >> 2) & 0xFF;
					ushort b2 = (b1 >> 3) & 0xFF;
					colors[pp++] = RGB16(r1,g1,b1);
				}
			}
		}
		//oslDebug("color %X",Color::get(555,222,141,444));
		//try {
		/*OSL_IMAGE * */spriteSheet = oslLoadImageFileGIF("icons.gif", OSL_IN_RAM | OSL_UNSWIZZLED, OSL_PF_8888);
		screen = new Screen(WIDTH, HEIGHT, new SpriteSheet(spriteSheet));
		lightScreen =  new Screen(WIDTH, HEIGHT, new SpriteSheet(spriteSheet));
		//oslDeleteImage(spriteSheet);

		setMenu(new TitleMenu());

		running = true;
	}

void Game::run()
{
	//long lastTime = time(0);
	//u64 last_tick;
	//sceRtcGetCurrentTick(&last_tick);
	//double unprocessed = 0;
	//double nsPerTick = 1000000000.0 / 60;
	frames = 0;
	ticks = 0;
	//long lastTimer1 = System.currentTimeMillis();
	bool shouldNotRender = false;
	init();

	while (running)
	{
		oslBenchmarkTest(OSL_BENCH_START);
		//u64 now_tick;
		//sceRtcGetCurrentTick(&now_tick);
		//if (now_tick - last_tick > 8000)
		//{
		//	last_tick = now_tick;
			ticks++;
			tick();
		//}

		//unprocessed += (now - lastTime) / nsPerTick;
		//lastTime = now;
		//bool shouldRender = true;
		//while (unprocessed >= 1) {

		//	unprocessed -= 1;
		//}

		//double negotiation, sorry
		if (!shouldNotRender)
		{
			frames++;
			//oslDebug("about to render");
			render();
			//oslDebug("rendered!");
		}
//		long now = time(0);
//		if (now - lastTime >= 1)
//		{
//			lastTime = now;
//			frames = 0;
//			ticks = 0;
//		}
		oslBenchmarkTest(OSL_BENCH_END);
		oslEndFrame();
		shouldNotRender = oslSyncFrame();


		input->handleKeys(oslReadKeys());
	}

}

void Game::tick()
{
	if (menu != NULL)
	{
		menu->tick();
	}
	else
	{
		if (!player->removed && !hasWon) gameTime++;

		if (player->removed)
		{
			playerDeadTime++;
			if (playerDeadTime > 60)
			{
				setMenu(new DeadMenu());
			}
		}
		else
		{
			if (pendingLevelChange != 0)
			{
				setMenu(new LevelTransitionMenu(pendingLevelChange));
				pendingLevelChange = 0;
			}
		}
		if (wonTimer > 0)
		{
			if (--wonTimer == 0)
			{
				setMenu(new WonMenu());
			}
		}
		level->tick();
		Tile::tickCount++;
	}
	input->tick();
}

void Game::setMenu(Menu * menu)
{
	//TODO remember current menu as previous and delete it later
//	if (this->menu)
//	{
//		this->previousMenu = this->menu;
//	}
	this->menu = menu;
	if (menu != NULL)
	{
		menu->init(this, input);
	}
//	if (previousMenu)
//	{
//		delete previousMenu;
//		previousMenu = NULL;
//	}
}

void Game::scheduleLevelChange(int dir)
{
	pendingLevelChange = dir;
}

void Game::changeLevel(int dir)
{
	level->remove(player);
	currentLevel += dir;
	level = levels[currentLevel];
	player->x = (player->x >> 4) * 16 + 8;
	player->y = (player->y >> 4) * 16 + 8;
	level->add(player);
}

void Game::won()
{
	wonTimer = 60 * 3;
	hasWon = true;
}

