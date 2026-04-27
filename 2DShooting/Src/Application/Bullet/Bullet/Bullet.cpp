#include "Bullet.h"

c_Bullet::c_Bullet(const Math::Vector2 pos, const Math::Vector2 move)
{
	m_pos = pos;
	m_move = move;
}
void c_Bullet::Update()
{
	m_pos += m_move;

	//àÍî‘â∫Ç…çsÇ¡ÇΩÇÁ
	if (m_pos.y < -360)
	{
		
	}

}

void c_Bullet::Draw()
{
	SHADER.m_spriteShader.DrawCircle(m_pos.x, m_pos.y, 10);
}

void c_Bullet::Release()
{
}