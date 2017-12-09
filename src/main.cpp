#include "main.h"

//窗口信息
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

Uint32 get_pixel32( SDL_Surface *surface, int x, int y )
{
    //转换像素为32位
    Uint32 *pixels = (Uint32 *)surface->pixels;
    
    //获取请求的像素
    return pixels[ ( y * surface->w ) + x ];
}
 
void put_pixel32( SDL_Surface *surface, int x, int y, Uint32 pixel )
{
    //转换像素为32位
    Uint32 *pixels = (Uint32 *)surface->pixels;
    
    //设置像素
    pixels[ ( y * surface->w ) + x ] = pixel;
}

//窗口指针
SDL_Window* window = NULL;
//窗口所含有的屏幕
SDL_Surface* screenSurface = NULL;

bool init()
{
	bool success = true;
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
		}
	}
	return success;
}

int main(int argc, char* args[])
{

	if(init())
	{
		bool quit = false;
		SDL_Event e;

		while(!quit)
		{
			while(SDL_PollEvent(&e)!=0)
			{
				if(e.type == SDL_QUIT)
				{
					quit = true;
				}
			}
			for(int i = 0;i<300;i++)
			{
				for(int j = 0;j<100;j++)
				{
					put_pixel32(screenSurface,i,j,100);
				}
			}
			SDL_UpdateWindowSurface(window);
		}
	}
	else{
		printf("失败\n");
	}

	//摧毁窗口
	SDL_DestroyWindow(window);

	//退出SDL
	SDL_Quit();

	return 0;
}