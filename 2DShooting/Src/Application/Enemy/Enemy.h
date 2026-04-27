#pragma once
#include"../Enemy/EnemyBase.h"

class c_Bullet;
class c_Enemy : public c_EnemyBase
{
public:
	c_Enemy() {}
	~c_Enemy() { Release(); };

	void Init();
	void Update();
	void Draw();
	void Release();

private:

	//可変長配列
	std::vector<c_Bullet*> mp_bullet;

	float m_bulletCount;//弾の数

	//サイズ
	float m_scaleX;
	float m_scaleY;

	//回転
	float m_angle;

	//行列
	Math::Matrix m_mat;
	KdTexture m_tex;

};