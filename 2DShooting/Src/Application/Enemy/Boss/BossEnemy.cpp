#include "BossEnemy.h"
#include"../../Bullet/SpreadBullet/SpreadBullet.h"
#include"../../Bullet/BulletBase.h"

void c_BossEnemy::Init()
{
	m_pos = {0,350};
	m_scaleX = 3.0f;
	m_scaleY = 3.0f;
	m_speed = 2;
	m_move = { 0,5 };
	m_angle = 180;
	m_bulletCount = 40;
	m_waitTime = rand() % 180 + 60;
	m_aliveFlg = true;
	m_hp = 30;

	//’e
	m_bulletNum = 5;
	m_bulletAngle = 60.0f;
	m_bulletSpeed = 3.0f;
}

void c_BossEnemy::Update()
{

	for (auto& b : mp_bullet)
	{
		b->Update();
	}
	//íœ
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

	//
	m_pos.x -= m_speed;

	if (m_pos.x < 100 || m_pos.x > 1180) {
		m_speed *= -1;
	}

	// ƒN[ƒ‹ƒ^ƒCƒ€
	if (m_bulletCount > 0)
	{
		m_bulletCount--;
	}

	// ”­Ë
	if (m_bulletCount <= 0)
	{
		float angleStep =
			m_bulletAngle / (m_bulletNum - 1);

		for (int i = 0; i < m_bulletNum; i++)
		{
			float angle =
				-m_bulletAngle / 2 + angleStep * i;

			float rad =
				DirectX::XMConvertToRadians(angle);

			Math::Vector2 move;

			move.x = sin(rad) * m_bulletSpeed;
			move.y = -cos(rad) * m_bulletSpeed;

			mp_bullet.push_back(
				new c_SpreadBullet(m_pos, move)
			);
		}

		m_bulletCount = 60;
	}

	//“G s—ñ
	Math::Matrix S, R, T;
	S = Math::Matrix::CreateScale(m_scaleX, m_scaleY, 1);
	R = Math::Matrix::CreateRotationZ(DirectX::XMConvertToRadians(m_angle));
	T = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_mat = S * R * T;
}

void c_BossEnemy::Draw()
{

	for (auto& b : mp_bullet)
	{
		b->Draw();
	}

	//“G
	Math::Rectangle rect = { 0,0,32,32 };
	Math::Color color = { 1,1,1,1.0f };

	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(m_tex, 0, 0, &rect, &color);
	//ƒŠƒZƒbƒg
	SHADER.m_spriteShader.SetMatrix(Math::Matrix::Identity);

	// HPƒQ[ƒW‚Ì•`‰æi‰æ–Êã•”‚ÉÔ‚¢ü‚ğ•`‚­—áj
	// Manager::DrawRect‚È‚Ç‚ÍŠÂ‹«‚É‡‚í‚¹‚Ä‘‚«Š·‚¦‚Ä‚­‚¾‚³‚¢
	Math::Rectangle hpRect = { 100, 20, (long)(m_hp * 20), 10 }; // HP‚É‡‚í‚¹‚Ä‰¡•‚ğL‚Î‚·
	Math::Color hpColor = { 1.0f, 0.2f, 0.2f, 1.0f };

	// ŠÈˆÕ“I‚È”wŒi”’˜g
	Math::Matrix barMat = Math::Matrix::CreateTranslation(100, 20, 0);
	SHADER.m_spriteShader.SetMatrix(barMat);
}

void c_BossEnemy::Release()
{

}
