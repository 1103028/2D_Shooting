#pragma once

//前方宣言
class BaseScene;

//すべてのシーンを管理する
class SceneManager
{
public:
	
	//シーン情報
	//enum=列挙型・・・複数の定数をまとめて管理するための型
	//入る値は0から順番にint型で割り当てられる
	enum SceneType
	{
		Title,
		Game,
		Score
	};

	//Updateの前にすること↓
	void PreUpdate();
	void Update();
	void Draw();

	//外部から次のシーンをセットする関数
	//この関数ではシーンは切り替わらない
	void SetNextScene(SceneType _nextScene)
	{
		m_nextSceneType = _nextScene;
	}

	//現在のシーンを取得する関数
	SceneType GetCurrentScene() const
	{
		return m_currentSceneType;
	}

private:

	//初期化や解放は自分でやる
	void Init();
	void Release();

	//シーン切り替えの関数
	void ChangeScene(SceneType _sceneType);

	//現在のシーンを管理するポインタ変数
	std::shared_ptr<BaseScene>m_currentScene;

	//現在のシーンを管理するフラグ変数
	SceneType m_currentSceneType = SceneType::Title;

	//次のシーンを管理するフラグ変数
	SceneType m_nextSceneType = m_currentSceneType;

	//シングルトンパターン（デザインパターン）
	//実体が一つしかないことを証明するパターン
	//何でもかんでもシングルトンにしない
private:

	//外で変数宣言できない
	SceneManager() { Init(); }
	~SceneManager() { Release(); }

public:

	static SceneManager& Instance()
	{
		static SceneManager instance;
		return instance;
	}

};