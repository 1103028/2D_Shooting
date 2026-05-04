#pragma once

#include"../BulletBase.h"
class c_HomingBullet : public c_BulletBase
{
public:
	c_HomingBullet(const Math::Vector2 pos, const Math::Vector2 move);
	~c_HomingBullet() {};

	void Update();
	void Draw();
	void Release();
protected:

	bool m_bulletFlg;
};