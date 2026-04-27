#include"Enemy.h"
#include"../Bullet/Bullet/Bullet.h"

void c_Enemy::Init()
{
	//m_tex.Load();

	//“G
	for (int i = 0; i < m_num; i++)
	{
		m_pos[i].x = rand() % 1280 - 640;
		//m_pos[i].x = 0;
		m_pos[i].y = 350;
		m_moveY = 5;
		m_bulletCount[i] = 10;
		m_enemyFlg[i] = true;
	}

	//’e
	for (auto& b : mp_bullet)
	{
		delete b;
	}
	mp_bullet.clear();
}

void c_Enemy::Update()
{
	// ’eXV
	for (auto& b : mp_bullet)
	{
		b->Update();
	}

	for (int i = 0; i < m_num; i++)
	{
		if (!m_enemyFlg[i]) continue;

		// ƒN[ƒ‹ƒ^ƒCƒ€
		if (m_bulletCount[i] > 0)
		{
			m_bulletCount[i]--;
		}

		// ”­ŽË
		if (m_bulletCount[i] <= 0)
		{
			mp_bullet.push_back(new c_Bullet(m_pos[i], { 0,-10 }));
			m_bulletCount[i] = 10;
		}

		// ˆÚ“®
		m_pos[i].y -= m_moveY;


		//ˆê”Ô‰º‚És‚Á‚½‚ç
		if (m_pos[i].y < -360)
		{
			m_enemyFlg[i] = false;
		}

		//“G s—ñ
		Math::Matrix S, R, T;
		S = Math::Matrix::CreateScale(m_scaleX, m_scaleY, 1);
		R = Math::Matrix::CreateRotationZ(DirectX::XMConvertToRadians(m_angle));
		T = Math::Matrix::CreateTranslation(m_pos[i].x, m_pos[i].y, 0);
		m_mat = S * R * T;
	}
}

void c_Enemy::Draw()
{
	//’e
	for (auto& b : mp_bullet)
	{
		b->Draw();
	}

	for (int i = 0; i < m_num; i++)
	{
		//“G
		Math::Rectangle rect = { 0,0,0,0 };
		Math::Color color = { 0,0,0,1.0f };

		//‰¼
		SHADER.m_spriteShader.DrawCircle(m_pos[i].x, m_pos[i].y, 5, &color);

		//SHADER.m_spriteShader.SetMatrix(m_mat);
		//SHADER.m_spriteShader.DrawTex(&m_tex,0,0, &rect, &color);
	}
}
