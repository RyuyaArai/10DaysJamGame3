#include "UI.h"

UI::UI()
{
}

UI::~UI()
{
}

void UI::Init()
{
	addScore = 0;
	fontQuantity = 3;
	scoreRenditionTime = 0;
	levelUpRenditionTime = 0;
	isLevelUp = false;
	isRendition = false;

	renditionColor = GetColor(255, 239, 108);
	whiteColor = GetColor(255, 255, 255);
	for (int i = 0; i < fontQuantity; i++) {
		fontData[i] = 0;
	}
	CreateFontData();
}

void UI::Update()
{
	if (isRendition == true) {
		AddScoreRendition();
	}

}

void UI::AddScore(int addScore)
{
	this->addScore = addScore;
	isScoRend = true;
	isRendition = true;
}

void UI::LevelUp()
{
	isLevelUp = true;
}

void UI::DrawScore(int score)
{
	if (isRendition == true) {
		//スコア加算演出関数入れる
		DrawScoreRend();
	}
	DrawFormatStringToHandle(0, 120, whiteColor, fontData[1], "score : %.8d", score);

}

void UI::DrawTime(int spawnRemain)
{
	DrawFormatStringToHandle(0, 144, whiteColor, fontData[1], "spawnRemain : %u", spawnRemain);
	//DrawFormatString(0, 128, whiteColor, "generate rate : %u", spawnTime / 60u);
}

void UI::DrawLevel(int level)
{
	DrawFormatStringToHandle(0, 168, whiteColor, fontData[1], "level : %u", level);
	if (isLevelUp == true) {
		//レベルアップ演出描画
		isLevelUp = false;
	}
}

void UI::DrawScoreRend()
{
	if (isScoRend) {
	/*	DrawFormatStringToHandle(0, 96, whiteColor, fontData[1], "+%d", addScore);
	}
	else
	{*/
		DrawFormatStringToHandle(100, 96, renditionColor, fontData[1], "+%d", addScore);
	}

}

void UI::DrawLevUpRend()
{
}

void UI::DrawGameOver()
{
	DrawFormatStringToHandle(0, 80, whiteColor, fontData[2], "GAME OVER");
}

void UI::AddScoreRendition()
{
	scoreRenditionTime++;
	if (scoreRenditionTime > 30) {
		if (isScoRend){
			isScoRend = false;
			isRendition = false;
		}
		scoreRenditionTime = 0;
	}
}

void UI::LevelUpRendition()
{
	levelUpRenditionTime++;
	if (levelUpRenditionTime > 15) {
		if (!isLevRend) {
			isLevRend = true;
		}
		else {
			isLevRend = false;
		}
		levelUpRenditionTime = 0;
	}
}

void UI::CreateFontData()
{
	AddFontResourceEx("Resource/FontData/03SmartFontUI.otf", FR_PRIVATE, NULL);
	fontData[0] = CreateFontToHandle(NULL, -1, -1);
	fontData[1] = CreateFontToHandle("03SmartFontUI", 24, -1, DX_FONTTYPE_ANTIALIASING);
	fontData[2] = CreateFontToHandle("03SmartFontUI", 64, -1, DX_FONTTYPE_ANTIALIASING);
}

void UI::Finalize()
{
	for (int i = 0; i < fontQuantity; i++) {
		RemoveFontResourceEx("Resource/FontData/03SmartFontUI.otf", FR_PRIVATE, NULL);
		DeleteFontToHandle(fontData[i]);
	}
}

void UI::DebugDraw(int mouseX, int mouseY)
{
	/*DrawFormatStringToHandle(0, 0, whiteColor, fontData[1], "x %d  y %d", mouseX, mouseY);
	DrawFormatStringToHandle(0, 24, whiteColor, fontData[1], "WASD :   box move");
	DrawFormatStringToHandle(0, 48, whiteColor, fontData[1], "space :  piece rotate (反時計回り)");
	DrawFormatStringToHandle(0, 72, whiteColor, fontData[1], "U :  piece generate");
	DrawFormatStringToHandle(0, 96, whiteColor, fontData[1], "R :  reset");*/
	//DrawFormatStringToHandle(0, 0, whiteColor, "x %d  y %d", mouseX, mouseY);
	/*DrawFormatString(0, 16, whiteColor, "WASD :   box move");
	DrawFormatString(0, 32, whiteColor, "space :  piece rotate (反時計回り)");
	DrawFormatString(0, 48, whiteColor, "U :  piece generate");
	DrawFormatString(0, 64, whiteColor, "R :  reset");*/
}
