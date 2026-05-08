#include "HomingBullet.h"
#include "../../Enemy/Enemy.h"
#include"../../Enemy/EnemyBase.h"

c_HomingBullet::c_HomingBullet(const Math::Vector2 pos, c_EnemyBase* target,
	std::vector<c_EnemyBase*>* enemies)
{
	m_pos = pos;
	m_target = target;
	m_enemies = enemies;
	m_aliveFlg = true;

	m_bulletTex.Load("Texture/Tiles/tile_0006.png");

	this->Update();
}

void c_HomingBullet::Init()
{
}

void c_HomingBullet::Update()
{
	if (!m_aliveFlg) return;

	// ターゲットが死んだ or 無い → 再取得
	if (!m_target || !m_target->GetAliveFlg())
	{
		m_target = nullptr;
		float minDist = FLT_MAX;

		for (auto e : *m_enemies)
		{
			if (!e->GetAliveFlg()) continue;

			float dist = (e->GetPos() - m_pos).Length();

			if (dist < minDist)
			{
				minDist = dist;
				m_target = e;
			}
		}
	}

	// 敵がいないなら消える
	if (!m_target)
	{
		m_aliveFlg = false;
	}

	// ホーミング移動
	Math::Vector2 dir = m_target->GetPos() - m_pos;

	if (dir.Length() > 0)
	{
		dir.Normalize();
	}

	float speed = 5.0f;
	m_pos += dir * speed;

	// 画面外で消す
	if (m_pos.y > 360 || m_pos.y < -360)
	{
		m_aliveFlg = false;
	}

	// 行列
	Math::Matrix S, R, T;

	S = Math::Matrix::CreateScale(1, 1, 1);
	R = Math::Matrix::CreateRotationZ(DirectX::XMConvertToRadians(0));
	T = Math::Matrix::CreateTranslation(m_pos.x, m_pos.y, 0);
	m_bulletMat = S * R * T;
}

void c_HomingBullet::Draw()
{
	if (!m_aliveFlg) return;

	Math::Rectangle rc = { 0,0,16,16 };
	Math::Color col = { 1,1,1,1 };

	SHADER.m_spriteShader.SetMatrix(m_bulletMat);
	SHADER.m_spriteShader.DrawTex(&m_bulletTex, 0, 0, &rc, &col);
	SHADER.m_spriteShader.SetMatrix(Math::Matrix::Identity);
}

void c_HomingBullet::Release()
{
	m_bulletTex.Release();
}