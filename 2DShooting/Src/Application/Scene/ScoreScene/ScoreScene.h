#pragma once

//継承の場合のみインクルードを許可する
#include "../BaseScene/BaseScene.h"

class ScoreScene : public BaseScene
{
public:
	ScoreScene() { Init(); }
	~ScoreScene() {}

	void Init()			override;
	void Update()		override;
	void DrawSprite()	override;
	void Release()		override;

private:

	KdTexture m_tex;
	Math::Matrix m_mat;

	float m_alpha = 1.0f;
	float m_addAlpha = -1;
};