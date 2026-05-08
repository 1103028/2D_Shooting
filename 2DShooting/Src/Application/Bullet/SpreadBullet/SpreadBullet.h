#pragma once
#include"../BulletBase.h"

class c_SpreadBullet : public c_BulletBase
{
public:
	c_SpreadBullet(const Math::Vector2 pos, const Math::Vector2 move);
	~c_SpreadBullet() {};

	void Init()override;
	void Update()override;
	void Draw()override;
	void Release()override;

protected:
};