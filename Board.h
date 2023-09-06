#pragma once
#include "PieceData.h"

#include <array>

enum class BoardStatus
{
	WAIT,
	PROCESSING_ROTATE,		//�s�[�X��]
	PROCESSING_FLOATCHECK,	//���V�`�F�b�N
	PROCESSING_MATCHCHECK,	//�s�[�X�}�b�`�`�F�b�N
	GAMEOVER,				//�Q�[���I�[�o�[
};

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

	void StartPieceRotate(int selectX, int selectY);

	//�s�[�X��]�i���t���[�����s�j
	void RotatePiece(int selectX, int selectY);

	void DebugDraw();

	void CheckMatch();

	void CheckFloat();



	static const int BOARD_WIDTH = 6;
	static const int BOARD_HEIGHT = 11;

	int rotateX = 0, rotateY = 0;

private:
	std::array <std::array<PieceData, 6>, 11> boardData;

	BoardStatus boardStatus;

};

