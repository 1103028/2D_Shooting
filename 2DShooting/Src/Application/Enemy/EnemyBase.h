#pragma once

class c_EnemyBase
{
public:
	c_EnemyBase() {}
	virtual~c_EnemyBase() {}

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void Release();
	virtual void OnHit() {}

	Math::Vector2 GetPos() const { return m_pos; }
	bool GetAliveFlg() { return m_aliveFlg; }
	void SetAlive(bool flg) { m_aliveFlg = flg; }

protected:

	Math::Vector2 m_pos;//ç¿ïW
	Math::Vector2 m_move;//â¡ë¨ìx
	bool m_aliveFlg;

};