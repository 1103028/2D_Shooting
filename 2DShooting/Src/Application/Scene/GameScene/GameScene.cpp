#include "GameScene.h"

#include"../SceneManager.h"
#include"../../Enemy/Enemy.h"
#include"../../Player/Player.h"
#include"../../Manager/Manager.h"
#include"../../Bullet/Bullet/Bullet.h"
#include"../../Bullet/HomingBullet/HomingBullet.h"

void GameScene::Init()
{
	m_enemyTex.Load("Texture/Ships/ship_0018.png");

	srand(time(0));

	//プレイヤー初期化
	c_player = new c_Player();
	c_player->Init();

	//エネミー初期化
	for (int i = 0; i < 10; i++)
	{
		c_Enemy* e = new c_Enemy;
		e->SetTexture(&m_enemyTex);
		e->Init();

		e->SetPlayer(c_player);

		mp_enemy.push_back(e);
	}
}
void GameScene::Update()
{
	if (GetAsyncKeyState('X') & 0x8000)
	{
		SceneManager::Instance().SetNextScene(SceneManager::SceneType::Score);
	}

	//プレイヤー更新
	c_player->Update();

	//敵更新
	for (auto e : mp_enemy)
	{
		e->Update();
	}

	if (GetAsyncKeyState('A') & 0x8000)
	{
		c_player->ShotHoming(mp_enemy);
	}

	//当たり判定
	EnemyHit();
	PlayerHit();
	PlayerEnemyHit();
}

void GameScene::DrawSprite()
{
	c_player->Draw();

	//敵描画
	for (auto e : mp_enemy)
	{
		e->Draw();
	}

}

void GameScene::Release()
{

	for (auto e : mp_enemy)
	{
		delete e;
	}
	mp_enemy.clear();
}

//敵と弾の当たり判定
void GameScene::EnemyHit()
{
	auto& bullets = c_player->GetBulletList();

	for (auto& b : bullets)
	{
		for (auto& e : mp_enemy)
		{
			if (!e->GetAliveFlg()) continue;

			if (Manager::CircleHit(b->GetPos(), 10, e->GetPos(), 20))
			{
				e->OnHit();
				e->SetAlive(false);

				b->SetAlive(false);
				break; // 1発1ヒット
			}
		}
	}
}

//プレイヤーと弾の当たり判定
void GameScene::PlayerHit()
{
	if (!c_player) return;

	Math::Vector2 playerPos = c_player->GetPos();

	for (auto& e : mp_enemy)
	{
		auto& bullets = e->GetBulletList();

		for (auto& b : bullets)
		{
			if (Manager::CircleHit(playerPos, 20, b->GetPos(), 10))
			{
				c_player->SetAlive(false); // プレイヤー被弾
				b->SetAlive(false);
			}
		}
	}
}

void GameScene::PlayerEnemyHit()
{
	if (!c_player) return;

	Math::Vector2 playerPos = c_player->GetPos();

	for (auto& e : mp_enemy)
	{
		if (!e->GetAliveFlg()) continue;

		if (Manager::CircleHit(playerPos, 20, e->GetPos(), 20))
		{
			c_player->SetAlive(false); // プレイヤー被弾
			e->SetAlive(false);        // 敵も消す（好み）
		}
	}
}