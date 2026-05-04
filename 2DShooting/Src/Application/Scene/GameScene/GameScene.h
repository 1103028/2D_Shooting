#pragma once

#include "../BaseScene/BaseScene.h"

class Manager;
class c_Player;
class c_Enemy;
class GameScene : public BaseScene
{
public:
	GameScene() { Init(); }
	~GameScene(){}

	void Init()			override;
	void Update()		override;
	void DrawSprite()	override;
	void Release()		override;

	void EnemyHit();
	void PlayerHit();
	void PlayerEnemyHit();

	//全オブジェクトのリストを取得
	std::vector<std::shared_ptr<BaseScene>>GetObList()
	{
		return m_objList;
	}

private:
	
	std::vector<c_Enemy*>mp_enemy;
	c_Player* c_player;

	KdTexture m_tex;
	Math::Matrix m_mat;

	//全オブジェクトを可変長配列で管理
	std::vector<std::shared_ptr<BaseScene>>m_objList;
};