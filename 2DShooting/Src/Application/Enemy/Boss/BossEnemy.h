#pragma once

#include"../EnemyBase.h"

class c_BulletBase;
class c_SpreadBullet;
class c_BossEnemy : public c_EnemyBase
{
public:
	c_BossEnemy() {};
	~c_BossEnemy() {};

	void Init()override;
	void Update()override;
	void Draw()override;
	void Release()override;

	std::vector<c_BulletBase*>& GetBulletList() { return mp_bullet; }


private:

	std::vector<c_BulletBase*> mp_bullet;

	float m_bulletCount;//弾の数

	//サイズ
	float m_scaleX;
	float m_scaleY;

	//回転
	float m_angle;

	//スピード
	float m_speed;

	//時間経過
	int m_waitTime;

	//弾の数
	int m_bulletNum;

	//角度
	float m_bulletAngle;

	float m_bulletSpeed;
};