#include <Novice.h>
#include"player.h"
#include"enemy.h"
const char kWindowTitle[] = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	enemy* enemy1 = new enemy(50,50,5);
	player* player1 = new player(640,360,7);

	float distX;
	float distY;
	float dist;
	int radius;

	float distX1;
	float distY1;
	float dist1;
	int radius1;

	int timer = 20; 
	int timer1 = 20; 
	int EAlive = 5;
	//int Alivetimer = 5;

	enum Scene {

		scene1,
		scene2,
		scene3,

	};
	Scene scene = scene1;
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		switch (scene)
		{
		case scene1:
			if (keys[DIK_SPACE]) {
				scene = scene2;
				
			}
			EAlive = 5;
			break;
		case scene2:

		


			//敵と弾
			distX = float(enemy1->GetPosX() - player1->bullet_->GetPosX());
			distY = float(enemy1->GetPosY() - player1->bullet_->GetPosY());
			dist = (distX * distX) + (distY * distY);
			radius = enemy1->GetRadius() + player1->bullet_->GetRadius();
			if (dist <= radius * radius && player1->bullet_->GetIsShot() == 1) {
				player1->bullet_->SetIsShot(0);
				timer = 50;
				enemy1->SetIsAlive(0);
				EAlive -=1;
			}
			if (timer > 0) {
				timer--;
				if (timer == 0) {
					enemy1->SetIsAlive(1);

				}
			}
			//敵と自機
			distX1 = float(enemy1->GetPosX() - player1->GetPosX());
			distY1 = float(enemy1->GetPosY() - player1->GetPosY());
			dist1 = (distX1 * distX1) + (distY1 * distY1);
			radius1 = enemy1->GetRadius() + player1->GetRadius();

			if (dist1 <= radius1 * radius1) {
				timer1 = 50;
				player1->SetIsAlive(0);
			}
			if (timer1 > 0) {
				timer1--;
				if (timer1 == 0) {
					player1->SetIsAlive(1);

				}
			}

			enemy1->Update();
			player1->Update(keys, preKeys);

			if (EAlive == 0) {
				scene=scene3;
			}
			break;
		case scene3:
			if (keys[DIK_RETURN]) {
				scene = scene1;
			}
			break;
		default:
			break;
		}
		
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		Novice::ScreenPrintf(10, 10, "%d", EAlive);
		switch (scene)
		{
		case scene1:
			Novice::DrawBox(0, 0, 1280,720, 0.0f, RED, kFillModeSolid);
			break;
		case scene2:
		enemy1->Draw();
		player1->Draw();
			break;
		case scene3:
			Novice::DrawBox(0, 0, 1280,720, 0.0f, BLUE, kFillModeSolid);

			break;
		default:
			break;
		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
