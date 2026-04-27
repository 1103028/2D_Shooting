#include "main.h"
#include "Scene.h"
#include"Enemy/Enemy.h"
#include"Player/Player.h"

void Scene::Draw2D()
{
	
	c_player->Draw();
	c_enemy->Draw();
}

void Scene::Update()
{
	c_player->Update();
	c_enemy->Update();
}

void Scene::Init()
{
	srand(time(0));


	c_player = new c_Player();
	c_player->Init();
	c_enemy = new c_Enemy();
	c_enemy->Init();

}

void Scene::Release()
{

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
