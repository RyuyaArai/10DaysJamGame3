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

	void Down();

	//�s�[�X���W�ݒ�
	void SetPos(int newX, int newY);

	int GetY() { return posY; }

	//�s�[�X����
	void Clear();

	//�`��
	void Draw();

	void DisplayPieceInfo(int displayX, int displayY);

	PIECE_COLOR GetColorNum() { return color; }

	static const int DRAWBASE_X = 354;
	static const int DRAWBASE_Y = 500;

	static const int PIECE_SIZE = 32;

	// ==���Z�q���I�[�o�[���[�h
	bool operator==(const PieceData& r) const
	{
		return color == r.color;
	}
	bool operator!=(const PieceData& r) const
	{
		return !(color == r.color);
	}


private:
	int posX = 0;
	int posY = 0;

	PIECE_COLOR color = PIECE_COLOR::PCOLOR_NONE;
};