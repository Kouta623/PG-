#include "enemy.h"
#include"Novice.h"
enemy::enemy(int EposX, int EposY, int Espeed)
{
	EposX_ = EposX;
	EposY_ = EposY;
	Espeed_ = Espeed;
	Eradius_ = 40;
	isAlive_ = 1;
}

enemy::~enemy()
{
}

void enemy::SetPosition(int EposX, int EposY, int Espeed)
{
	EposX_ = EposX;
	EposY_ = EposY;
	Espeed_ = Espeed;
	Eradius_ = 40;
}

void enemy::Update()
{
	EposX_ += Espeed_;

	if (EposX_ > 1280 - Eradius_) {
		Espeed_ *= -1;
	}

	if (EposX_ < 0 + Eradius_) {
		Espeed_ *= -1;

	}
}

void enemy::Draw()
{
	if (isAlive_ == 1) {
		Novice::DrawEllipse(EposX_, EposY_, Eradius_, Eradius_, 0.0f, RED, kFillModeSolid);
	}
}

