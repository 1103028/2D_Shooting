#pragma once

#include"../BulletBase.h"

class c_Enemy;
class c_Player;

class c_HomingBullet : public c_BulletBase
{
public:
	c_HomingBullet(const Math::Vector2 pos, c_Enemy* target, 
		std::vector<c_Enemy*>* enemies);
	~c_HomingBullet() {};

	void Init()override;
	void Update()override;
	void Draw()override;
	void Release()override;
protected:

	std::vector<c_Enemy*>* m_enemies = nullptr;
	c_Enemy* m_target = nullptr;
	c_Player* m_player = nullptr;

};