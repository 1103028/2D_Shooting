#include "ScoreScene.h"

#include"../SceneManager.h"

void ScoreScene::Init()
{
}

void ScoreScene::Update()
{

	if (GetAsyncKeyState('C') & 0x8000)
	{
		SceneManager::Instance().SetNextScene(SceneManager::SceneType::Title);
	}

}

void ScoreScene::DrawSprite()
{
	SHADER.m_spriteShader.DrawCircle(0, 0, 10);
}

void ScoreScene::Release()
{
}
