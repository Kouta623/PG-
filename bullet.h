#pragma once
class bullet
{

public:
	bullet(int BposX, int BposY, int Bspeed,int r,int isShot);
	void Update();
	void Draw();


	int GetPosX() { return BposX_; };
	int GetPosY() { return BposY_; };
	int GetSpeed() { return Bspeed_; };
	int GetIsShot() { return isShot_; }
	void SetSpeed(int Bspeed) { Bspeed_ = Bspeed; }
	void SetIsShot(int isShot) { isShot_ = isShot; }
	int GetRadius() { return Bradius_; };
	void SetPosition(int BposX, int BposY, int Bspeed);


private:
	int BposX_;
	int BposY_;
	int Bspeed_;
	int Bradius_;
	int isShot_;


};

