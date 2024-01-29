#pragma once
class enemy
{

	public:
		enemy(int EposX, int EposY, int Espeed);
		~enemy();
		void Update();
		void Draw();


		int GetPosX() { return EposX_; };
		int GetPosY() { return EposY_; };
		int GetSpeed() { return Espeed_; };
		int GetIsAlive() { return isAlive_; }
		void SetSpeed(int Espeed) { Espeed_ = Espeed; }
		void SetIsAlive(int isAlive) { isAlive_ = isAlive; }
		int GetRadius() { return Eradius_; };
		void SetPosition(int EposX, int EposY, int Espeed);


	private:	
		int EposX_;
		int EposY_;
		int Espeed_;
		int Eradius_;
		int isAlive_;

};

