#include "main.h"
#include "Scene.h"
#include"Enemy/Enemy.h"
#include"Player/Player.h"

void Scene::Draw2D()
{
	c_player->Draw();
	
//敵描画
	for (auto e : mp_enemy)
	{
		e->Draw();
	}
}

void Scene::Update()
{
	c_player->Update();

	//敵更新
	for (auto e : mp_enemy)
	{
		e->Update();
	}
}

void Scene::Init()
{
	srand(time(0));


	c_player = new c_Player();
	c_player->Init();

	for (int i = 0; i < 10; i++)
	{
		c_Enemy* e = new c_Enemy;
		e->Init();
		mp_enemy.push_back(e);
	}
}


void Scene::Release()
{

	for(auto e :mp_enemy)
	{
		delete e;
	}
	mp_enemy.clear();
}

void Scene::ImGuiUpdate()
{
	return;

	ImGui::SetNextWindowPos(ImVec2(20, 20), ImGuiSetCond_Once);
	ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiSetCond_Once);

	// デバッグウィンドウ
	if (ImGui::Begin("Debug Window"))
	{
		ImGui::Text("FPS : %d", APP.m_fps);
	}
	ImGui::End();
}
