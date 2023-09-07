#include "UI.h"

UI::UI()
{
}

UI::~UI()
{
}

void UI::Init()
{
	score = 0;
	addScore = 0;
	time = 0;
	levelUp = false;
	isRendition = false;
}

void UI::Update()
{

}

void UI::AddScore(int addScore)
{
	score += addScore;
	this->addScore = addScore;

	isRendition = true;
}

void UI::LevelUp()
{
	levelUp = true;
}

void UI::DrawScore(int score)
{
	if (isRendition == true) {
		//ÉXÉRÉAâ¡éZ
		isRendition = false;
	}
	DrawFormatString(0, 96, GetColor(255, 255, 255), "score : %.8d", score);

}

void UI::DrawTime(int spawnRemain,int spawnTime)
{
	DrawFormatString(0, 112, GetColor(255, 255, 255), "generate remain : %u", spawnRemain);
	DrawFormatString(0, 128, GetColor(255, 255, 255), "generate rate : %u", spawnTime / 60u);
}

void UI::DrawLevel(int level)
{
	DrawFormatString(0, 144, GetColor(255, 255, 255), "level : %u", level);
	if (levelUp == true) {

	}
}
