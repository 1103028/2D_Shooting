#include"Enemy.h"
#include"../Bullet/NormalBullet/Bullet.h"

void c_Enemy::Init()
{
	//m_tex.Load();

	//敵
	for (int i = 0; i < m_num; i++)
	{
		m_pos[i].x = rand() % 1280 - 640;
		//m_pos[i].x = 0;
		m_pos[i].y = 350;
		m_moveY = 5;
		m_bulletCount[i] = 10;
		m_enemyFlg[i] = true;
	}

	//弾
	for (auto& b : mp_bullet)
	{
		delete b;
	}
	mp_bullet.clear();
}

void c_Enemy::Update()
{
	// 弾更新
	for (auto& b : mp_bullet)
	{
		b->Update();
	}

	for (int i = 0; i < m_num; i++)
	{
		if (!m_enemyFlg[i]) continue;

		// クールタイム
		if (m_bulletCount[i] > 0)
		{
			m_bulletCount[i]--;
		}

		// 発射
		if (m_bulletCount[i] <= 0)
		{
			mp_bullet.push_back(new c_Bullet(m_pos[i], { 0,-10 }));
			m_bulletCount[i] = 10;
		}

		// 移動
		m_pos[i].y -= m_moveY;


		//一番下に行ったら
		if (m_pos[i].y < -360)
		{
			m_enemyFlg[i] = false;
		}

		//敵 行列
		Math::Matrix S, R, T;
		S = Math::Matrix::CreateScale(m_scaleX, m_scaleY, 1);
		R = Math::Matrix::CreateRotationZ(DirectX::XMConvertToRadians(m_angle));
		T = Math::Matrix::CreateTranslation(m_pos[i].x, m_pos[i].y, 0);
		m_mat = S * R * T;
	}
}

void c_Enemy::Draw()
{
	//弾
	for (auto& b : mp_bullet)
	{
		b->Draw();
	}

	for (int i = 0; i < m_num; i++)
	{
		//敵
		Math::Rectangle rect = { 0,0,0,0 };
		Math::Color color = { 0,0,0,1.0f };

		//仮
		SHADER.m_spriteShader.DrawCircle(m_pos[i].x, m_pos[i].y, 5, &color);

		//SHADER.m_spriteShader.SetMatrix(m_mat);
		//SHADER.m_spriteShader.DrawTex(&m_tex,0,0, &rect, &color);
	}
}
