#pragma once
#include <DxLib.h>
class UI
{
public:
	UI();
	~UI();

	void Init();
	void Update();
	void AddScore(int addScore);
	void LevelUp();
	
	void DrawScore(int score);
	void DrawTime(int spawnRemain,int spawnTime);
	void DrawLevel(int level);
private:
	int score;
	int addScore;
	int time;
	
	bool levelUp;
	bool isRendition;
};

