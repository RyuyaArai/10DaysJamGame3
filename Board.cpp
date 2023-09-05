#include "Board.h"

#include <vector>
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

	//�����Ă���s�[�X�����邩���m�F����
	CheckMatch();


	//�����Ă���s�[�X�����m���ď���
	CheckFloat();

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
			int psize = PieceData::PIECE_SIZE;
			if (mouseX > PieceData::DRAWBASE_X + x * psize -16 && mouseX < PieceData::DRAWBASE_X + x * psize + psize - (psize / 2)) {
				if (mouseY > PieceData::DRAWBASE_Y - y * psize - 16 && mouseY < PieceData::DRAWBASE_Y - y * psize + psize - (psize / 2)) {
					bx.DisplayPieceInfo(mouseX, mouseY);
				}
			}
			x++;
		}
		y++;
	}

	DrawFormatString(0, 0, GetColor(255, 255, 255), "x %d  y %d", mouseX, mouseY);
	DrawFormatString(0, 16, GetColor(255, 255, 255), "WASD :   box move");
	DrawFormatString(0, 32, GetColor(255, 255, 255), "space :  piece rotate (�����v���)");
	DrawFormatString(0, 48, GetColor(255, 255, 255), "U :  piece generate");
	DrawFormatString(0, 64, GetColor(255, 255, 255), "R :  reset");
}

void Board::CheckMatch()
{
	//�������s���s�[�X��ێ�
	std::vector<PieceData*> deletePieceBuff;

	//��������`�F�b�N
	for (int y = 0; y < BOARD_HEIGHT; y++) {
		for (int x = 0; x < BOARD_WIDTH; x++) {
			if (boardData[y][x].GetColorNum() == PIECE_COLOR::PCOLOR_NONE) {
				continue;
			}
			//��̃s�[�X���ێ�
			std::vector<PieceData*> upperMatchPiece;
			//�E�̃s�[�X���ێ�
			std::vector<PieceData*> rightMatchPiece;
			//�E�ňقȂ�F��������܂Ń��[�v
			for (int xx = x; xx < BOARD_WIDTH; xx++) {
				if (boardData[y][x] != boardData[y][xx]) { break; }
				rightMatchPiece.push_back(&boardData[y][xx]);
			}
			//��ňقȂ�F��������܂Ń��[�v
			for (int yy = y; yy < BOARD_HEIGHT; yy++) {
				if (boardData[y][x] != boardData[yy][x]) { break; }
				upperMatchPiece.push_back(&boardData[yy][x]);
			}

			//���ꂼ��3�ȏ゠��ꍇ�A�����R���e�i�ɕێ�
			if (upperMatchPiece.size() >= 3) {
				for (auto& up : upperMatchPiece) { deletePieceBuff.push_back(up); }
			}
			if (rightMatchPiece.size() >= 3) {
				for (auto& right : rightMatchPiece) { deletePieceBuff.push_back(right); }
			}
		}
	}

	//�s�[�X�������J�n
	for (auto& d : deletePieceBuff) {
		d->Clear();
	}

}

void Board::CheckFloat()
{
	for (int y = 1; y < BOARD_HEIGHT; y++) {
		for (int x = 0; x < BOARD_WIDTH; x++) {
			if (boardData[y][x].GetColorNum() == PIECE_COLOR::PCOLOR_NONE) { continue; }

			int newY = y;
			bool downFlag = false;
			//���s�[�X�̉��Ƀs�[�X�����݂��邩�A��ԉ��ɂ��܂ŉ����葱����
			while (boardData[newY - 1][x].GetColorNum() == PIECE_COLOR::PCOLOR_NONE){
				downFlag = true;
				newY--;
				if (newY == 0) { break; }
			}
			
			//�Vy���W�̈ʒu�̃s�[�X���ɑ�����A��y���W�̃s�[�X��none��
			if (downFlag) {
				boardData[newY][x] = boardData[y][x];
				boardData[newY][x].SetPos(x, newY);
				boardData[y][x].Clear();
			}

		}
	}





}
