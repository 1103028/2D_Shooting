#include "SceneManager.h"

#include"GameScene/GameScene.h"
#include"TitleScene/TitleScene.h"
#include"ScoreScene/ScoreScene.h"

void SceneManager::PreUpdate()
{
	//シーン切替
	if (m_currentSceneType != m_nextSceneType)
	{
		ChangeScene(m_nextSceneType);
	}
}

void SceneManager::Update()
{
	//ポリモーフィズム
	//同じ関数名であっても,呼び出すオブジェクトによって処理内容が変わる
	m_currentScene->Update();
}

void SceneManager::Draw()
{
	m_currentScene->DrawSprite();
}

void SceneManager::Init()
{
	ChangeScene(m_currentSceneType);
}

void SceneManager::Release()
{
}

void SceneManager::ChangeScene(SceneType _sceneType)
{
	//①次のシーンを作成②フラグを更新
	//①
	switch (_sceneType)
	{
	case SceneType::Title:
		//アップキャスト
		m_currentScene = std::make_shared<TitleScene>();
		break;
	case SceneType::Game:
		//アップキャスト
		m_currentScene = std::make_shared<GameScene>();
		break;
	case SceneType::Score:
		m_currentScene = std::make_shared<ScoreScene>();
		break;

		//初期化はここで行う
		//
	}
	//②
	m_currentSceneType = _sceneType;
}