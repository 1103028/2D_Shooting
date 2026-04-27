#pragma once
#include"../BulletBase.h"

class c_Bullet : public c_BulletBase
{
public:
	c_Bullet(const Math::Vector2 pos, const Math::Vector2 move);
	~c_Bullet() {};

	void Update();
	void Draw();
	void Release();
protected:

	Math::Vector2 m_pos;
	Math::Vector2 m_move;

	bool m_bulletFlg;
};