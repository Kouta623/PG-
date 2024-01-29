#pragma once
#include"bullet.h"
class player
{
public:
	player(int posX, int posY, int speed);
	~player();
	void Update(char* keys, char* preKeys);
	void Draw();


	int GetPosX() { return posX_; };
	int GetPosY() { return posY_; };
	int GetSpeed() { return speed_; };
	void SetSpeed(int speed) { speed_ = speed; }
	int GetRadius() { return radius_; };
	int GetIsAlive() { return isAlive_; }
	void SetPosition(int posX, int posY, int speed);
	void SetIsAlive(int isAlive) { isAlive_ = isAlive; }

	bullet* bullet_;
	int BSpeed_;
	int Bradius_;
	int isShot_;

private:	// メンバ変数
	int posX_;
	int posY_;
	int speed_;
	int radius_;
	int isAlive_;

};

