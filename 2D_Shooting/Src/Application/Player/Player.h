#pragma
class c_Player
{
public:
	c_Player(){}
	~c_Player(){}

	void Init();
	void Update();
	void Draw();

private:

	//画面
	float m_width = 1280;
	float m_height = 720;

	//座標
	float m_x;
	float m_y;

	//サイズ
	float m_scaleX;
	float m_scaleY;

	//回転
	float m_angle;

	//加速度
	float m_moveX;
	float m_moveY;

	//生きているか？
	bool m_playerFlg;

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