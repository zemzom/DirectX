#include "StdAfx.h"
#include "cMainGame.h"
#include "cCamera.h"
#include "cGrid.h"
#include "cPlayer.h"

cMainGame::cMainGame(void)
	: m_pCamera(NULL)
	, m_pGrid(NULL)
	, m_pPlayer(NULL)
{
}


cMainGame::~cMainGame(void)
{
	SAFE_DELETE(m_pCamera);
	SAFE_DELETE(m_pGrid);

	SAFE_RELEASE(m_pPlayer);

	g_pSkinnedMeshManager->Destroy();
	g_pObjectManager->Destroy();
	g_pFontManager->Destroy();
	g_pTextureManager->Destroy();
	g_pDeviceManager->Destroy();
}

void cMainGame::Setup()
{
	m_pPlayer = new cPlayer;
	m_pPlayer->Setup();
	
	m_pCamera = new cCamera;
	m_pCamera->Setup(&(m_pPlayer->GetPosition()));

	m_pGrid = new cGrid;
	m_pGrid->Setup();

	SetLight();

}

void cMainGame::Update()
{
	g_pTimeManager->Update();

	if (m_pPlayer && m_pCamera)
		m_pPlayer->Update(m_pCamera->GetCamRotAngle());

	if (m_pCamera)
		m_pCamera->Update();

}

void cMainGame::Render()
{
	g_pD3DDevice->Clear(NULL,
		NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(47, 121, 112),
		1.0f, 0);

	g_pD3DDevice->BeginScene();

	if(m_pGrid)
		m_pGrid->Render();
	
	if (m_pPlayer)
		m_pPlayer->Render();

	g_pD3DDevice->EndScene();

	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}

void cMainGame::SetLight()
{
	D3DLIGHT9 stLight;
	ZeroMemory(&stLight, sizeof(D3DLIGHT9));
	stLight.Type = D3DLIGHT_DIRECTIONAL;
	stLight.Ambient = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);
	stLight.Diffuse = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);
	stLight.Specular = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);
	D3DXVECTOR3 vDir(1.0f, -1.0f, 1.0f);
	D3DXVec3Normalize(&vDir, &vDir);
	stLight.Direction = vDir;
	g_pD3DDevice->SetLight(0, &stLight);
	g_pD3DDevice->LightEnable(0, true);

	g_pD3DDevice->SetRenderState(D3DRS_NORMALIZENORMALS, true);
}

void cMainGame::WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	if (m_pCamera)
	{
		m_pCamera->WndProc(hWnd, message, wParam, lParam);
	}

	switch(message)
	{
	case WM_LBUTTONDOWN:
		{
		}

		break;
	case WM_RBUTTONDOWN:
		{
		}
		
		break;
	}
}

void cMainGame::OnClick( cUIButton* pSender )
{
}
