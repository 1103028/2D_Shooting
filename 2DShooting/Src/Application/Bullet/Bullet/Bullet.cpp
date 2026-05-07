#include "Bullet.h"

c_Bullet::c_Bullet(const Math::Vector2 pos, const Math::Vector2 move)
{
	m_bulletTex.Load("Texture/Tiles/tile_0000.png");
	m_pos = pos;
	m_move = move;
	m_aliveFlg = true;

	this->Update();
}
void c_Bullet::Init()
{
}
void c_Bullet::Update()
{
	c_BulletBase::Update();

	Math::Matrix S, R, T;

	S = Math::Matrix::CreateScale(1, 1, 1);
	R = Math::Matrix::CreateRotationZ(DirectX::XMConvertToRadians(0));
	T = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_bulletMat = S * R * T;
}

void c_Bullet::Draw()
{
	if (m_aliveFlg)
	{
		Math::Rectangle rc = { 0,0,16,16 };
		Math::Color col = { 1,1,1,1 };

		SHADER.m_spriteShader.SetMatrix(m_bulletMat);
		SHADER.m_spriteShader.DrawTex(&m_bulletTex, 0, 0, &rc, &col);

		SHADER.m_spriteShader.SetMatrix(Math::Matrix::Identity);
	}
}

void c_Bullet::Release()
{
	m_bulletTex.Release();
}