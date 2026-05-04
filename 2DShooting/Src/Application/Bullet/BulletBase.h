#pragma once

class c_BulletBase
{
public:
    c_BulletBase() {};
    virtual ~c_BulletBase() { Release(); };

    virtual void Init();
    virtual void Update();
    virtual void Draw();
    virtual void Release();

    Math::Vector2 GetPos() { return m_pos; } const
    bool GetAliveFlg() { return m_aliveFlg; }
    void SetAlive(bool flg) { m_aliveFlg = flg; }

protected:

    Math::Vector2 m_pos;//ç¿ïW
    Math::Vector2 m_move;//â¡ë¨ìx

    KdTexture m_bulletTex;
    Math::Matrix m_bulletMat;

    bool m_aliveFlg;
};