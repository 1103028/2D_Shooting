#include"Player.h"
#include"../Bullet/Bullet/Bullet.h"
#include "../Bullet/BulletBase.h"
#include "../Bullet/HomingBullet/HomingBullet.h"
#include"../Enemy/EnemyBase.h"
#include"../Enemy/Enemy.h"

void c_Player::Init()
{
	m_tex.Load("Texture/Ships/ship_0001.png");

	m_pos = { 0,-300 };
	m_move = { 5,5 };
	m_scaleX = 2.0f;
	m_scaleY = 2.0f;
	m_angle = 0;
	m_bulletCount = 20;
	m_aliveFlg = true;

	for (auto& b : mp_bullet)
	{
		delete b;
	}
	mp_bullet.clear();
}

void c_Player::Update()
{
	if (!m_aliveFlg)return;

	for (auto& b : mp_bullet)
	{
		b->Update();
	}

	//削除
	{
		mp_bullet.erase(
			std::remove_if(mp_bullet.begin(), mp_bullet.end(),
				[](c_BulletBase* b)
				{
					if (!b->GetAliveFlg())
					{
						delete b;
						return true;
					}
					return false;
				}),
			mp_bullet.end());
	}

	if (GetAsyncKeyState(VK_UP) & 0x8000)m_pos.y += m_move.y;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)m_pos.y -= m_move.y;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)m_pos.x -= m_move.x;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)m_pos.x += m_move.x;

	//0より大きければ引いていく
	if (m_bulletCount > 0)
	{
		m_bulletCount--;
	}
	//エンターキーで弾を打つ
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		//0より小さければ10にする
		if (m_bulletCount <= 0)
		{
			mp_bullet.push_back(new c_Bullet(m_pos, { 0,10 }));
			m_bulletCount = 20;
		}
	}

	//画面外判定

	//行列確定
	Math::Matrix S, R, T;
	S = Math::Matrix::CreateScale(m_scaleX, m_scaleY, 1);
	R = Math::Matrix::CreateRotationZ(DirectX::XMConvertToRadians(m_angle));
	T = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_mat = S * R * T;
}

void c_Player::Draw()
{
	if (!m_aliveFlg)return;

	//弾
	for (auto& b : mp_bullet)
	{
		b->Draw();
	}

	//プレイヤー
	Math::Rectangle rect = { 0,0,32,32 };
	Math::Color color = { 1,1,1,1.0f };

	//仮
	//SHADER.m_spriteShader.DrawBox(m_pos.x, m_pos.y, 5, 5, &color);

	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(&m_tex,0,0, &rect, &color);
	//リセット
	SHADER.m_spriteShader.SetMatrix(Math::Matrix::Identity);
}

void c_Player::ShotHoming( std::vector<c_EnemyBase*>& enemies)
{
	if (!m_aliveFlg) return;
	if (m_bulletCount > 0) return;

	c_EnemyBase* target = nullptr;
	float minDist = FLT_MAX;

	// 一番近い敵を探す
	for (auto e : enemies)
	{
		if (!e->GetAliveFlg()) continue;

		float dist = (e->GetPos() - m_pos).Length();

		if (dist < minDist)
		{
			minDist = dist;
			target = e;
		}
	}

	// 発射
	if (target)
	{
		mp_bullet.push_back(new c_HomingBullet(m_pos, target, (std::vector<c_EnemyBase*>*) & enemies));
		m_bulletCount = 20;
	}
}