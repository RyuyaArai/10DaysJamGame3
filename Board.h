#pragma once
#include "PieceData.h"

#include <array>

enum class BoardStatus
{
	WAIT,
	PROCESSING_ROTATE,		//ピース回転
	PROCESSING_FLOATCHECK,	//浮遊チェック
	PROCESSING_MATCHCHECK,	//ピースマッチチェック
	GAMEOVER,				//ゲームオーバー
};

//ボードの状態を管理するクラス
class Board
{
public:
	Board();
	~Board();

	void Init();

	void Update();

	void Draw();

	//ピース上昇
	void UpAndGenerate();

	void StartPieceRotate(int selectX, int selectY);

	//ピース回転（毎フレーム実行）
	void RotatePiece(int selectX, int selectY);

	void DebugDraw();

	void CheckMatch();

	void CheckFloat();

	void TimeControl();

	static const int BOARD_WIDTH = 6;
	static const int BOARD_HEIGHT = 11;

	int rotateX = 0, rotateY = 0;

private:
	std::array <std::array<PieceData, 6>, 11> boardData;

	BoardStatus boardStatus;

	//現在のレベル
	unsigned int level = 1;
	//フレームカウント
	unsigned int flameCount = 0;
	//生成間隔
	unsigned int spawnTime = 600;
	//生成間隔の減少率
	unsigned int spawnDifficlutyRate = 15;
	//生成ペース下限
	const unsigned int SPAWNTIME_MIN = 150;
	//生成ペース初期値
	const unsigned int SPAWNTIME_MAX = 600;

	//スコア
	unsigned int score = 0;
	//スコアベース
	unsigned int baseScore = 100;
	//スコア倍率（連鎖で上昇）
	float scoreScale = 1.0f;





};

