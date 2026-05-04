#include"BulletBase.h"
void c_BulletBase::Init()
{
}

void c_BulletBase::Update()
{
    m_pos += m_move;

    // 画面外で消す
    if (m_pos.y > 360 || m_pos.y < -360)
    {
        m_aliveFlg = false;
    }
}

void c_BulletBase::Draw()
{
}

void c_BulletBase::Release()
{
}