#include "main.h"

//窗口信息
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	//窗口指针
	SDL_Window* window = NULL;
	
	//窗口所含有的屏幕
	SDL_Surface* screenSurface = NULL;

	//初始化SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}
	else
	{
		//创建窗口
		window = SDL_CreateWindow( "Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
		else
		{
			//获得surface
			screenSurface = SDL_GetWindowSurface( window );

			//把surface填充为白色
			SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
			
			//更新surface
			SDL_UpdateWindowSurface( window );

			//等待两秒钟
			SDL_Delay( 2000 );
		}
	}

	//摧毁窗口
	SDL_DestroyWindow( window );

	//退出SDL
	SDL_Quit();

	return 0;
}