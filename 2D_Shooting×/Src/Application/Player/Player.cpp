#include"Player.h"
#include"../Bullet/NormalBullet/Bullet.h"

void c_Player::Init()
{
	//m_tex.Load();
	
	m_pos = {0,-300};
	m_move = { 5,5 };
	m_bulletCount = 10;

	for (auto& b : mp_bullet)
	{
		delete b;
	}
	mp_bullet.clear();
}

void c_Player::Update()
{
	for (auto& b:mp_bullet )
	{
		b->Update();
	}

	if (GetAsyncKeyState('W') & 0x8000)m_pos.y += m_move.y;
	if (GetAsyncKeyState('S') & 0x8000)m_pos.y -= m_move.y;
	if (GetAsyncKeyState('A') & 0x8000)m_pos.x -= m_move.x;
	if (GetAsyncKeyState('D') & 0x8000)m_pos.x += m_move.x;

	//0より大きければ引いていく
	if (m_bulletCount>0)
	{
		m_bulletCount--;
	}
	//エンターキーで弾を打つ
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		//0より小さければ10にする
		if (m_bulletCount<=0)
		{
			mp_bullet.push_back(new c_Bullet(m_pos, { 0,5 }));

			m_bulletCount = 10;
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
	//弾
	for (auto& b : mp_bullet)
	{
		b->Draw();
	}

	//プレイヤー
	Math::Rectangle rect = { 0,0,0,0 };
	Math::Color color = { 0,0,0,1.0f };

	//仮
	SHADER.m_spriteShader.DrawBox(m_pos.x, m_pos.y, 5, 5, &color);

	//SHADER.m_spriteShader.SetMatrix(m_mat);
	// 	//SHADER.m_spriteShader.DrawTex(&m_tex,0,0, &rect, &color);
}
