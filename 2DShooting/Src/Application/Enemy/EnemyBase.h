#pragma once

class c_EnemyBase
{
public:
	c_EnemyBase(){}
	~c_EnemyBase(){}

    virtual void Init();
    virtual void Update();
    virtual void Draw();
    virtual void Release();

protected:

    Math::Vector2 m_pos;//ç¿ïW
    Math::Vector2 m_move;//â¡ë¨ìx
    bool m_alive;

};