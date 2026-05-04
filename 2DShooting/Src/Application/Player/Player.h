#pragma once

class c_Bullet;
class c_Player
{
public:
	c_Player() {}
	~c_Player() { Release(); };

	void Init();
	void Update();
	void Draw();
	void Release();

	Math::Vector2 GetPos() { return m_pos; };
	void SetAlive(bool flg) { m_aliveFlg = flg; }

	std::vector<c_Bullet*>& GetBulletList() { return mp_bullet; }

private:

	std::vector<c_Bullet*> mp_bullet;

	//画面
	float m_width = 1280;
	float m_height = 720;

	float m_bulletCount;//弾の数

	//座標
	Math::Vector2 m_pos;

	//サイズ
	float m_scaleX;
	float m_scaleY;

	//回転
	float m_angle;

	//加速度
	Math::Vector2 m_move;

	//生きているか？
	bool m_aliveFlg;

	//行列
	Math::Matrix m_mat;
	KdTexture m_tex;
};