#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#define OLC_PGE_APPLICATION

#include "../olcPixelGameEngine/olcPixelGameEngine.h"

// Based off the example, just renamed because it's the game, not an example...
class Game : public olc::PixelGameEngine
{
public:
	Game()
	{
		sAppName = "Game";
	}

public:
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// called once per frame
		for (int x = 0; x < ScreenWidth(); x++)
			for (int y = 0; y < ScreenHeight(); y++)
				Draw(x, y, olc::Pixel(rand() % 255, rand() % 255, rand()% 255));	
		return true;
	}
};


int main()
{
	Game game;
	if (game.Construct(256, 240, 4, 4))
		game.Start();

	return 0;
}