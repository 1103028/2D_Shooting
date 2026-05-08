#pragma once

#include"../BulletBase.h"

class c_EnemyBase;
class c_Player;

class c_HomingBullet : public c_BulletBase
{
public:
	c_HomingBullet(const Math::Vector2 pos, c_EnemyBase* target, 
		std::vector<c_EnemyBase*>* enemies);
	~c_HomingBullet() {};

	void Init()override;
	void Update()override;
	void Draw()override;
	void Release()override;
protected:

	std::vector<c_EnemyBase*>* m_enemies = nullptr;
	c_EnemyBase* m_target = nullptr;
	c_Player* m_player = nullptr;

};