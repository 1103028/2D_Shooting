#include"EnemyBase.h"
void c_EnemyBase::Init()
{
}

void c_EnemyBase::Update()
{
}

void c_EnemyBase::Draw()
{
}

void c_EnemyBase::Release()
{
}

void c_EnemyBase::OnHit()
{
	--m_hp;
	if (m_hp<=0)
	{
		m_hp = 0;

	}
}
