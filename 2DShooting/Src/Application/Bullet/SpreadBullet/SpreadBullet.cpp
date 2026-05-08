#include "SpreadBullet.h"
#include "../../Enemy/Enemy.h"
#include"../../Enemy/EnemyBase.h"

c_SpreadBullet::c_SpreadBullet(const Math::Vector2 pos, const Math::Vector2 move)
{
	m_bulletTex.Load("Texture/Tiles/tile_0006.png");
	m_pos = pos;
	m_move = move;
	this->Update();
}

void c_SpreadBullet::Init()
{
}

void c_SpreadBullet::Update()
{
	if (!m_aliveFlg) return;

	// ‰æ–ÊŠO‚ÅÁ‚·
	if (m_pos.y > 360 || m_pos.y < -360)
	{
		m_aliveFlg = false;
	}

	// s—ñ
	Math::Matrix S, R, T;

	S = Math::Matrix::CreateScale(1, 1, 1);
	R = Math::Matrix::CreateRotationZ(DirectX::XMConvertToRadians(0));
	T = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_bulletMat = S * R * T;
}

void c_SpreadBullet::Draw()
{
	if (!m_aliveFlg) return;

	Math::Rectangle rc = { 0,0,16,16 };
	Math::Color col = { 1,0,0,1 };

	SHADER.m_spriteShader.SetMatrix(m_bulletMat);
	SHADER.m_spriteShader.DrawTex(&m_bulletTex, 0, 0, &rc, &col);
	SHADER.m_spriteShader.SetMatrix(Math::Matrix::Identity);
}

void c_SpreadBullet::Release()
{
	m_bulletTex.Release();
}