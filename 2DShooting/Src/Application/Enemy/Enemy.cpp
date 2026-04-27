#include"Enemy.h"
#include"../Bullet/Bullet/Bullet.h"

void c_Enemy::Init()
{
	m_tex.Load("Texture/Ships/ship_0018.png");

	//“G
	m_pos.x = rand() % 1280 - 640;
	m_pos.y = 350;
	m_scaleX = 1.0f;
	m_scaleY = 1.0f;
	m_move = { 0,5 };
	m_angle = 180;
	m_bulletCount = 10;
	m_alive = true;
}

void c_Enemy::Update()
{
	// ’eXV
	for (auto& b : mp_bullet)
	{
		b->Update();
	}

	if (!m_alive)return;

	// ƒN[ƒ‹ƒ^ƒCƒ€
	if (m_bulletCount > 0)
	{
		m_bulletCount--;
	}
	// ”­ŽË
	if (m_bulletCount <= 0)
	{
		mp_bullet.push_back(new c_Bullet(m_pos, { 0,-10 }));
		m_bulletCount = 20;
	}

	// ˆÚ“®
	m_pos.y -= m_move.y;


	//ˆê”Ô‰º‚És‚Á‚½‚ç
	if (m_pos.y < -360)
	{
		m_alive = false;
		//Šm—¦‚Å•œŠˆ
		if (rand() % 100 < 20)
		{
			m_alive = true;
			m_pos.x = rand() % 1280 - 640;
			m_pos.y = 350;
		}
	}

	//“G s—ñ
	Math::Matrix S, R, T;
	S = Math::Matrix::CreateScale(m_scaleX, m_scaleY, 1);
	R = Math::Matrix::CreateRotationZ(DirectX::XMConvertToRadians(m_angle));
	T = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_mat = S * R * T;
}


void c_Enemy::Draw()
{
	//’e
	for (auto& b : mp_bullet)
	{
		b->Draw();
	}

	//“G
	Math::Rectangle rect = { 0,0,32,32 };
	Math::Color color = { 1,1,1,1.0f };

	//‰¼
	//SHADER.m_spriteShader.DrawCircle(m_pos[i].x, m_pos[i].y, 5, &color);

	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(&m_tex, 0, 0, &rect, &color);
	//ƒŠƒZƒbƒg
	SHADER.m_spriteShader.SetMatrix(Math::Matrix::Identity);
}
void c_Enemy::Release()
{
	//’e
	for (auto& b : mp_bullet)
	{
		delete b;
	}
	mp_bullet.clear();
}
