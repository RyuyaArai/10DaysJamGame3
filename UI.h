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
	void DrawTime(int spawnRemain);
	void DrawLevel(int level);

	//init
	void CreateFontData();

	//fin
	void Finalize();

	//debug
	void DebugDraw(int mouseX,int mouseY);
private:
	int score;
	int addScore;
	int time;
	int scoreRenditionTime;
	int levelUpRenditionTime;
	int fontQuantity = 2;
	
	bool isLevelUp;
	bool isRendition;

	int fontData[];
};

