#include"Enemy.h"
#include"../Bullet/Bullet/Bullet.h"

void c_Enemy::Init()
{
	//敵
	m_pos.x = rand() % 1280 - 640;
	m_pos.y = 350;
	m_scaleX = 1.0f;
	m_scaleY = 1.0f;
	m_speed = rand() % 5 + 2;
	m_move = { 0,5};
	m_angle = 180;
	m_bulletCount = 40;
	m_waitTime = rand() % 180 + 60;
	m_aliveFlg = true;
	m_hp = 5;
}

void c_Enemy::Update()
{
	// 弾更新
	for (auto& b : mp_bullet)
	{
		b->Update();
	}

	//削除
	{
		mp_bullet.erase(
			std::remove_if(mp_bullet.begin(), mp_bullet.end(),
				[](c_Bullet* b)
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

	//一番下に行ったら
	if (m_pos.y < -360)
	{
		m_hp = 0;
		m_aliveFlg = false;
	}


	if (!m_aliveFlg)return;

	// クールタイム
	if (m_bulletCount > 0)
	{
		m_bulletCount--;
	}
	// 発射
	if (m_bulletCount <= 0)
	{
		mp_bullet.push_back(new c_Bullet(m_pos, { 0,-10 }));
		m_bulletCount = 40;
	}

	// 移動
	if (m_waitTime > 0)
	{
		m_waitTime--;
	}
	else
	{
		// 落下開始
		m_pos.y -= m_speed;
	}

	if (!m_aliveFlg)
	{
		if (rand() % 100 < 2)
		{
			m_aliveFlg = true;

			m_pos.x = rand() % 1280 - 640;
			m_pos.y = 350;
		}
	}
	//敵 行列
	Math::Matrix S, R, T;
	S = Math::Matrix::CreateScale(m_scaleX, m_scaleY, 1);
	R = Math::Matrix::CreateRotationZ(DirectX::XMConvertToRadians(m_angle));
	T = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_mat = S * R * T;
}


void c_Enemy::Draw()
{
	if (!m_aliveFlg)return;

	//弾
	for (auto& b : mp_bullet)
	{
		b->Draw();
	}

	//敵
	Math::Rectangle rect = { 0,0,32,32 };
	Math::Color color = { 1,1,1,1.0f };

	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_tex, 0, 0, &rect, &color);
	//リセット
	SHADER.m_spriteShader.SetMatrix(Math::Matrix::Identity);
}
void c_Enemy::Release()
{
	//弾
	for (auto& b : mp_bullet)
	{
		delete b;
	}
	mp_bullet.clear();
}
