#pragma once

class cCamera;
class cGrid;
class cUIObject;

class cPlayer;

class cPlayScene
{
	cCamera*					m_pCamera;
	cGrid*						m_pGrid;

	cUIObject*					m_pUIRoot;
	LPD3DXSPRITE				m_pSprite;

	cPlayer*					m_pPlayer;

public:
	cPlayScene();
	~cPlayScene();

	void Setup();
	void Update();
	void Render();

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

};

