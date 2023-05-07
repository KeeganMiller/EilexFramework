#pragma once
#include <string>
#include "framework.h"
#include "raylib.h"


class Game
{
public:
	Game();
	~Game();

	static void Initialize();
	static void Start();
	static void Update();
	static void Draw();
	static void Deintialize();

	static void CreateWindow(int windowWidth, int windowHeight, std::string windowTitle, bool fullscreen = false);
	static void ToggleWindowFullscreen(bool fullscreen);

	

	static void CloseGame();

	inline bool IsGameRunning() { return _IsRunning; }

	// Size of the window
	static int WindowWidth;
	static int WindowHeight;

	static std::string WindowTitle;					// Name of the window
	
	// Window Settings
	static bool IsFullscreen;

	static Color ClearColor;						// Reference to the color that renders when the drawing clears
	
private:
	static bool _IsRunning;							// Reference to if the game is running
};

