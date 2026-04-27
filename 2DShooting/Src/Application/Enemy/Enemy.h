#pragma once
class c_Bullet;
class c_Enemy
{
public:
	c_Enemy() {}
	~c_Enemy() { Release(); };

	void Init();
	void Update();
	void Draw();
	void Release();

private:

	std::vector<c_Bullet*> mp_bullet;

	//敵の数
	static const int m_num = 10;

	float m_bulletCount[m_num];//弾の数

	//座標
	Math::Vector2 m_pos[m_num];

	//サイズ
	float m_scaleX;
	float m_scaleY;

	//回転
	float m_angle;

	//下方向の加速度
	float m_moveY;

	//生きているか？
	bool m_enemyFlg[m_num];

	//行列
	Math::Matrix m_mat;
	KdTexture m_tex;

};