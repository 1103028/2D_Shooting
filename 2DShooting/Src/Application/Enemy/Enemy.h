#pragma once
#include"../Enemy/EnemyBase.h"

class c_Bullet;
class c_Player;
class c_Enemy : public c_EnemyBase
{
public:
	c_Enemy() {}
	~c_Enemy() { Release(); }

	void Init()override;
	void Update()override;
	void Draw()override;
	void Release()override;

	void SetPlayer(c_Player* p) { m_player = p; }

	std::vector<c_Bullet*>& GetBulletList() { return mp_bullet; }

private:

	c_Player* m_player = nullptr;

	//可変長配列
	std::vector<c_Bullet*> mp_bullet;

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


};