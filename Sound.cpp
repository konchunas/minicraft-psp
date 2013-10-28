/*
 * Sound.cpp
 *
 *  Created on: 28 окт. 2013 г.
 *      Author: user
 */

#include "Sound.h"

Sound * Sound::playerHurt;
Sound * Sound::playerDeath;
Sound * Sound::monsterHurt;
Sound * Sound::test;
Sound * Sound::pickup;
Sound * Sound::bossdeath;
Sound * Sound::craft;

Sound::~Sound()
{
	// TODO Auto-generated destructor stub
}

Sound::Sound(const char * name)
{
	clip = oslLoadSoundFileWAV(name, OSL_FMT_NONE);
}

void Sound::initSounds()
{
	Sound::playerHurt = new Sound("sounds/playerhurt.wav");
	Sound::playerDeath = new Sound("sounds/death.wav");
	Sound::monsterHurt = new Sound("sounds/monsterhurt.wav");
	Sound::test = new Sound("sounds/test.wav");
	Sound::pickup = new Sound("/sounds/pickup.wav");
	Sound::bossdeath = new Sound("sounds/bossdeath.wav");
	Sound::craft = new Sound("sounds/craft.wav");
}

void Sound::play()
{
	oslPlaySound(clip, 0);
}
