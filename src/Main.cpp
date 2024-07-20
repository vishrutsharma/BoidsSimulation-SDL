#include <SDL.h>
#include <iostream>
#include "BoidsController.h";
#include "Singleton.h"

const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 800;

SDL_Window* mWindow = NULL;
SDL_Renderer* mRenderer = NULL;
BoidsController mBoidController;

void Close()
{
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	mRenderer = NULL;
	mWindow = NULL;
	SDL_Quit();
}

bool Initialise()
{
	if (SDL_Init(SDL_INIT_VIDEO < 0))
	{
		std::cerr << "Failed to initialise SDL Video" << SDL_GetError() << std::endl;
		return false;
	}

	mWindow = SDL_CreateWindow("Boids",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (mWindow == NULL)
	{
		std::cerr << "Failed to create SDL Window" << SDL_GetError() << std::endl;
		SDL_Quit();
		return false;
	}

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
	if (mRenderer == NULL)
	{
		std::cerr << "Failed to create a Renderer" << SDL_GetError() << std::endl;
		SDL_DestroyWindow(mWindow);
		SDL_Quit();
		return false;
	}

	return true;
}


int SDL_main(int argc, char* argv[])
{
	if (!Initialise())
	{
		printf("Initialisation Failed");
		return 0;

	}

	mBoidController.Initialise();

	bool quit = false;
	SDL_Event mEvent;
	while (!quit)
	{
		while (SDL_PollEvent(&mEvent) != 0)
		{
			if (mEvent.type == SDL_QUIT)
			{
				quit = true;
			}
			else if (mEvent.type == SDL_MOUSEMOTION)
			{
				int x, y;
				SDL_GetMouseState(&x, &y);
				mBoidController.SetTarget(x, y);
			}
		}
	
		SDL_SetRenderDrawColor(mRenderer, 0x00, 0x00, 0x00, 0x00);
		SDL_RenderClear(mRenderer);
		Singleton::GetInstance().Update();
		mBoidController.Update(mRenderer);
		SDL_RenderPresent(mRenderer);
	}

	Close();
	return 0;
}