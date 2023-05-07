#pragma once
#include <string>
#include "framework.h"


class Game
{
public:
	Game();
	~Game();

	void Initialize();
	void Start();
	void Update();
	void Draw();
	void Deintialize();

	static void CreateWindow(int windowWidth, int windowHeight, std::string windowTitle, bool fullscreen = false);
	static void ToggleWindowFullscreen(bool fullscreen);

	static int WindowWidth;
	static int WindowHeight;
	static std::string WindowTitle;
	static bool IsFullscreen;

	static void CloseGame();

	inline bool IsGameRunning() { return _IsRunning; }
	
private:
	static bool _IsRunning;
};

