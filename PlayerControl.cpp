#include "PlayerControl.h"

#include "PieceData.h"

void PlayerControl::Init(Board* board)
{
	this->board = board;
}

void PlayerControl::UserControl()
{
	if (Input::IsKeyTrigger(KEY_INPUT_W) && selectY + 2 < Board::BOARD_HEIGHT) {
		selectY++;
	}
	if (Input::IsKeyTrigger(KEY_INPUT_S) && selectY > 0) {
		selectY--;
	}
	if (Input::IsKeyTrigger(KEY_INPUT_D) && selectX + 1 < Board::BOARD_WIDTH) {
		selectX++;
	}
	if (Input::IsKeyTrigger(KEY_INPUT_A) && selectX > 0) {
		selectX--;
	}

	if (Input::IsKeyTrigger(KEY_INPUT_SPACE)) {
		board->RotatePiece(selectX, selectY);
	}

}

void PlayerControl::Draw()
{
	DrawBox(PieceData::DRAWBASE_X + selectX * 32 - 16,
		PieceData::DRAWBASE_Y - selectY * 32 + 16,
		PieceData::DRAWBASE_X + (selectX + 1) * 32 + 16,
		PieceData::DRAWBASE_Y - (selectY + 1) * 32 - 16,
		GetColor(255, 255, 255), false);


}
