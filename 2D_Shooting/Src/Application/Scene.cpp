#include "main.h"
#include "Scene.h"
#include"Enemy/Enemy.h"
#include"Player/Player.h"

void Scene::Draw2D()
{
	
	c_player->Draw();
	for (int i = 0; i < c_enemy.size(); i++)
		c_enemy[i]->Draw();
}

void Scene::Update()
{
	c_player->Update();
	for (int i = 0; i < c_enemy.size(); i++)
		c_enemy[i]->Update();
}

void Scene::Init()
{
	srand(time(0));


	c_player = new c_Player();

	c_player->Init();
	for (int i = 0; i < c_enemy.size(); i++)
		c_enemy[i]->Init();

}

void Scene::Release()
{
	for (int i = 0; i < c_enemy.size(); i++)
		delete c_enemy[i];
	c_enemy.clear();
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
