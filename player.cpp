#include "player.h"
#include"Novice.h"

player::player(int posX, int posY, int speed)
{
	posX_ = posX;
	posY_ = posY;
	radius_ = 20;
	speed_ = speed;
	isAlive_ = 1;

	bullet_ = new bullet( 16, 16 , 20, 10, 0);
}

player::~player()
{

}

void player::SetPosition(int posX, int posY, int speed)
{
	posX_ = posX;
	posY_ = posY;
	radius_ = 20;
	speed_ = speed;

	bullet_ = new bullet(16, 16, 10, 10, 0);

}

void player::Update(char* keys, char* preKeys)
{
	if (keys[DIK_W]) {
		posY_ -= speed_;
	}

	if (keys[DIK_S]) {
		posY_ += speed_;

	}

	if (keys[DIK_A]) {
		posX_ -= speed_;

	}

	if (keys[DIK_D]) {
		posX_ += speed_;

	}




	///bullet

	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && bullet_->GetIsShot()==0) {

		bullet_->SetPosition(posX_, posY_, speed_);
		bullet_->SetIsShot(1);


	}

	bullet_->Update();
}

void player::Draw()
{
	if (isAlive_ == 1) {
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, WHITE, kFillModeSolid);
	}
	bullet_->Draw();

}

