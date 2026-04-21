#pragma
class c_Enemy
{
public:
	c_Enemy(){}
	~c_Enemy(){}

	void Init();
	void Update();
	void Draw();
	void Bullet();

private:

	//座標
	float m_x;
	float m_y;

	//サイズ
	float m_scaleX;
	float m_scaleY;

	//回転
	float m_angle;

	//下方向の加速度
	float m_moveY;

	//生きているか？
	bool m_enemyFlg;

	//行列
	Math::Matrix m_mat;
	KdTexture m_tex;

	//弾
	float m_bulletX;
	float m_bulletY;

	//弾が出るか？
	bool m_bulletFlg;

	//行列
	Math::Matrix m_bulletMat;
	KdTexture m_bulletTex;
};