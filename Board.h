#pragma once
#include "PieceData.h"

#include <array>


//�{�[�h�̏�Ԃ��Ǘ�����N���X
class Board
{
public:
	Board();
	~Board();

	void Init();

	void Update();

	void Draw();

	//�s�[�X�㏸
	void UpAndGenerate();

	//�s�[�X��]
	void RotatePiece(int selectX, int selectY);

	void DebugDraw();

	void CheckMatch();



	static const int BOARD_WIDTH = 6;
	static const int BOARD_HEIGHT = 11;

private:
	std::array <std::array<PieceData, 6>, 11> boardData;

};

