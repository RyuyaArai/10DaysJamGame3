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
	isLevelUp = false;
	isRendition = false;
	for (int i = 0; i < fontQuantity; i++) {
		fontData[i] = 0;
	}
	CreateFontData();
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
	isLevelUp = true;
}

void UI::DrawScore(int score)
{
	if (isRendition == true) {
		//スコア加算演出関数入れる
		isRendition = false;
	}
	DrawFormatString(0, 96, GetColor(255, 255, 255), "score : %.8d", score);

}

void UI::DrawTime(int spawnRemain)
{
	DrawFormatString(0, 112, GetColor(255, 255, 255), "spawnRemain : %u", spawnRemain);
	//DrawFormatString(0, 128, GetColor(255, 255, 255), "generate rate : %u", spawnTime / 60u);
}

void UI::DrawLevel(int level)
{
	DrawFormatString(0, 144, GetColor(255, 255, 255), "level : %u", level);
	if (isLevelUp == true) {
		//レベルアップ演出描画
		isLevelUp = false;
	}
}

void UI::CreateFontData()
{
	fontData[0] = CreateFontToHandle(NULL, -1, -1);
	fontData[1] = CreateFontToHandle("メイリオ", 24, -1,DX_FONTTYPE_ANTIALIASING);
}

void UI::Finalize()
{
	for (int i = 0; i < fontQuantity; i++) {
		DeleteFontToHandle(fontData[i]);
	}
}

void UI::DebugDraw(int mouseX,int mouseY)
{
	DrawFormatStringToHandle(0, 0, GetColor(255, 255, 255), fontData[1], "x %d  y %d", mouseX, mouseY);
	DrawFormatStringToHandle(0, 32, GetColor(255, 255, 255), fontData[1], "WASD :   box move");
	DrawFormatStringToHandle(0, 64, GetColor(255, 255, 255), fontData[1], "space :  piece rotate (反時計回り)");
	DrawFormatStringToHandle(0, 96, GetColor(255, 255, 255), fontData[1], "U :  piece generate");
	DrawFormatStringToHandle(0, 128, GetColor(255, 255, 255), fontData[1], "R :  reset");
	//DrawFormatStringToHandle(0, 0, GetColor(255, 255, 255), "x %d  y %d", mouseX, mouseY);
	/*DrawFormatString(0, 16, GetColor(255, 255, 255), "WASD :   box move");
	DrawFormatString(0, 32, GetColor(255, 255, 255), "space :  piece rotate (反時計回り)");
	DrawFormatString(0, 48, GetColor(255, 255, 255), "U :  piece generate");
	DrawFormatString(0, 64, GetColor(255, 255, 255), "R :  reset");*/
}
