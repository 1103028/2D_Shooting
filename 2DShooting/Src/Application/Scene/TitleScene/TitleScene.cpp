#include "TitleScene.h"

#include"../SceneManager.h"

void TitleScene::Init()
{
	m_tex.Load("Texture/TitleBack.png");

}

void TitleScene::Update()
{
	//点滅
	//m_alpha += m_addAlpha;
	//if (m_alpha>1.0f)
	//{
	//	m_alpha = 1.0f;
	//	m_addAlpha *= -1;
	//}
	//else if()
	//{
	//	m_alpha = 0.0f;
	//	m_addAlpha *= -1;
	//}

	if (GetAsyncKeyState('Z') & 0x8000)
	{
		SceneManager::Instance().SetNextScene(SceneManager::SceneType::Game);
	}

}

void TitleScene::DrawSprite()
{
	Math::Rectangle rc = { 0,0,1672,941 };
	Math::Color col = { 1.0f,1.0f,1.0f,1.0f };
	SHADER.m_spriteShader.SetMatrix(m_mat);
	SHADER.m_spriteShader.DrawTex(&m_tex, 0, 0, &rc, &col);
}

void TitleScene::Release()
{

}
