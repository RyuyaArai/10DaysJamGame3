#include "Board.h"

#include <algorithm>
#include <DxLib.h>

Board::Board()
{
}

Board::~Board()
{
}

void Board::Init()
{
	int y = 0;
	for (auto& by : boardData)
	{
		int x = 0;
		for (auto& bx : by) {
			bx.Init(x, y);
			x++;
		}
		y++;
	}
}

void Board::Update()
{

	//�����Ă���s�[�X�����m���ď���


	//�����Ă���s�[�X�����邩���m�F����



}

void Board::Draw()
{
	int y = 0;
	for (auto& by : boardData)
	{
		for (auto& bx : by) {
			bx.Draw();
		}
		y++;
		if (y == 10) {
			break;
		}
	}
}

void Board::UpAndGenerate()
{
	//�s�[�X�̍��W�f�[�^���㏸������
	for (auto& by : boardData)
	{
		for (auto& bx : by) {
			bx.Up();
		}
	}

	//���̂Ƃ��V��i��\����11��ځj�𒴂���s�[�X�����݂���ꍇ�Q�[���I�[�o�[�t���O����


	//�s�[�X�f�[�^���E�V�t�g����i�㏸�Ɠ��`�j
	std::shift_right(boardData.begin(), boardData.end(), 1);

	//�ŉ��i�ɐV���ȗv�f��������
	std::array<PieceData, 6> initdata;
	boardData[0] = initdata;
	
	int x = 0;
	for (auto& b : boardData[0]) {
		b.Generate(x, 0);
		x++;
	}

}

void Board::RotatePiece(int selectX, int selectY)
{
	//�I�𒆂̃s�[�X4��ێ��i�����A�E���A�E��A����j
	std::array<PieceData, 4> rotateP = {
		boardData[selectY][selectX],
		boardData[selectY][selectX + 1],
		boardData[selectY + 1][selectX + 1],
		boardData[selectY + 1][selectX] };

	//����->�E��
	rotateP[0].SetPos(selectX + 1, selectY);
	boardData[selectY][selectX + 1] = rotateP[0];
	//�E��->�E��
	rotateP[1].SetPos(selectX + 1, selectY + 1);
	boardData[selectY + 1][selectX + 1] = rotateP[1];
	//�E��->����
	rotateP[2].SetPos(selectX, selectY + 1);
	boardData[selectY + 1][selectX] = rotateP[2];
	//����->����
	rotateP[3].SetPos(selectX, selectY);
	boardData[selectY][selectX] = rotateP[3];

}

void Board::DebugDraw()
{

	int mouseX = 0, mouseY = 0;

	GetMousePoint(&mouseX, &mouseY);

	int y = 0;
	for (auto& by : boardData)
	{
		int x = 0;
		for (auto& bx : by) {

			if (mouseX > PieceData::DRAWBASE_X + x * 32 -16 && mouseX < PieceData::DRAWBASE_X + x * 32 + 32 - 16) {
				if (mouseY > PieceData::DRAWBASE_Y - y * 32 - 16 && mouseY < PieceData::DRAWBASE_Y - y * 32 + 32 - 16) {
					bx.DisplayPieceInfo(mouseX, mouseY);
				}
			}
			x++;
		}
		y++;
	}

	DrawFormatString(0, 0, GetColor(100, 100, 100), "x %d  y %d", mouseX, mouseY);
}

void Board::CheckMatch()
{
	//�����Ă���s�[�X���Ȃ����m�F



}
