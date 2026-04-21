#include"Enemy.h"

void c_Enemy::Init()
{
	//m_tex.Load();
	//m_bulletTex.Load();
}

void c_Enemy::Update()
{

	//敵 行列確定
	Math::Matrix S, R, T;
	S = Math::Matrix::CreateScale(m_scaleX, m_scaleY, 1);
	R = Math::Matrix::CreateRotationZ(DirectX::XMConvertToRadians(m_angle));
	T = Math::Matrix::CreateTranslation(m_x, m_y, 0);
	m_mat = S * R * T;

	//弾
	Math::Matrix BS, BR, BT;
	BS = Math::Matrix::CreateScale(m_scaleX, m_scaleY, 1);
	BR = Math::Matrix::CreateRotationZ(DirectX::XMConvertToRadians(m_angle));
	BT = Math::Matrix::CreateTranslation(m_bulletX, m_bulletY, 0);
	m_bulletMat = BS * BR * BT;
}

void c_Enemy::Draw()
{
	//敵
	Math::Rectangle rect = { 0,0,0,0 };
	Math::Color color = { 0,0,0,1.0f };

	//仮
	SHADER.m_spriteShader.DrawBox(m_x, m_y, 5, 5, &color);
	
	//SHADER.m_spriteShader.SetMatrix(m_mat);
	//SHADER.m_spriteShader.DrawTex(&m_tex,0,0, &rect, &color);

	//弾
	Math::Rectangle rc = { 0,0,0,0 };
	Math::Color cor = { 0,0,0,1.0f };

	//仮
	SHADER.m_spriteShader.DrawCircle(m_x, m_y, 10, &color);


	//SHADER.m_spriteShader.SetMatrix(m_bulletMat);
	//SHADER.m_spriteShader.DrawTex(&m_bulletTex, 0, 0, &rc, &cor);
}
