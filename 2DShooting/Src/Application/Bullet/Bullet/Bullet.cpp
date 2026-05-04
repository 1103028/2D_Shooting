#include "Bullet.h"

c_Bullet::c_Bullet(const Math::Vector2 pos, const Math::Vector2 move)
{
	m_pos = pos;
	m_move = move;
	m_aliveFlg = true;
}
void c_Bullet::Update()
{
	c_BulletBase::Update();
}

void c_Bullet::Draw()
{
	if (m_aliveFlg)
	{
		SHADER.m_spriteShader.DrawCircle(m_pos.x, m_pos.y, 10);
	}
}

void c_Bullet::Release()
{
}