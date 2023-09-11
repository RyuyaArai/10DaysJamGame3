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
	void DrawScoreRend();
	void DrawLevUpRend();
	void DrawGameOver();

	void AddScoreRendition();
	void LevelUpRendition();

	//init
	void CreateFontData();

	//fin
	void Finalize();

	//debug
	void DebugDraw(int mouseX,int mouseY);
private:
	int addScore;
	int time;
	int scoreRenditionTime;
	int levelUpRenditionTime;
	int fontQuantity;

	int renditionColor;
	int whiteColor;
	
	bool isLevelUp;
	bool isRendition;
	bool isScoRend;
	bool isLevRend;

	int fontData[];
};

