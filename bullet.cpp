#include "bullet.h"
#include"Novice.h"

bullet::bullet(int BposX, int BposY, int Bspeed, int Brasius, int isShot)
{
	BposX_ = BposX;
	BposY_ = BposY;
	Bspeed_ = Bspeed;
	Bradius_ = Brasius;
	isShot_ = isShot;

}


void bullet::SetPosition(int BposX, int BposY, int Bspeed)
{
	BposX_ = BposX;
	BposY_ = BposY;
	Bspeed_ = Bspeed;
}
void bullet::Update()
{
	if (isShot_ == 1) {
		BposY_ -= Bspeed_;
	}

	if (BposY_ < Bradius_ && isShot_ == 1) {
		isShot_ = 0;

	}
}

void bullet::Draw()
{
	if (isShot_ == 1) {

		Novice::DrawEllipse(BposX_, BposY_, Bradius_, Bradius_, 0.0f, RED, kFillModeSolid);
	}
}

