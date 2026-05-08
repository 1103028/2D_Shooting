#pragma once

class c_Bullet;
class c_EnemyBase
{
public:
	c_EnemyBase() {}
	virtual~c_EnemyBase() {}

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void Release();
	virtual void OnHit();

	virtual std::vector<c_BulletBase*>& GetBulletList() = 0;

	Math::Vector2 GetPos() const { return m_pos; }

	bool GetAliveFlg() { return m_aliveFlg; }

	void SetAlive(bool flg) { m_aliveFlg = flg; }

	bool IsDead()const { return m_hp <= 0; }

	void SetTexture(KdTexture* tex) { m_tex = tex; }

protected:

	Math::Vector2 m_pos;//À•W
	Math::Vector2 m_move;//‰Á‘¬“x
	bool m_aliveFlg;

	int m_hp = 0;

	//s—ñ
	Math::Matrix m_mat;
	KdTexture* m_tex = nullptr;
};