#pragma once


enum class PIECE_COLOR
{
	PCOLOR_NONE,
	PCOLOR_RED,
	PCOLOR_GREEM,
	PCOLOR_BLUE,
	PCOLOR_WHITE,
};

class PieceData
{
public:

	PieceData();
	~PieceData();

	void Init(int x, int y);

	//�s�[�X�𐶐�
	void Generate(int x,int y);

	//�s�[�X���㏸
	void Up();

	//�s�[�X���W�ݒ�
	void SetPos(int newX, int newY);

	//�s�[�X����
	void Clear();

	//�`��
	void Draw();

	void DisplayPieceInfo(int displayX, int displayY);

	static const int DRAWBASE_X = 354;
	static const int DRAWBASE_Y = 500;

private:
	int posX = 0;
	int posY = 0;

	PIECE_COLOR color = PIECE_COLOR::PCOLOR_NONE;
};