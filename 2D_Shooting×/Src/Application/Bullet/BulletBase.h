#pragma once

class c_BulletBase
{
public:
    c_BulletBase() {};
    virtual ~c_BulletBase() {};

     virtual void Init();
     virtual void Update();
     virtual void Draw();
     virtual void Release();

protected: 

    Math::Vector2 m_pos;//ç¿ïW
    Math::Vector2 m_move;//â¡ë¨ìx

    KdTexture m_bulletTex;
    Math::Matrix m_bulletMat;
};