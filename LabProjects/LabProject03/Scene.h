#pragma once

#include "GameObject.h"
#include "Camera.h"
#include "Player.h"

class CScene
{
public:
	CScene(CPlayer* pPlayer) { m_pPlayer = pPlayer; }
	virtual ~CScene();

private:
	int							m_nObjects = 0;
	CGameObject**				m_ppObjects = NULL;
	CGameObject*				m_pMap = NULL;
	CPlayer*					m_pPlayer = NULL;

public:
	virtual void BuildObjects();
	virtual void ReleaseObjects();

	virtual void Animate(float fElapsedTime);
	virtual void CheckCollision();
	virtual bool isClickObject(int xMouse, int yMouse);
	virtual void Render(HDC hDCFrameBuffer, CCamera* pCamera);
	virtual void OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam) {}
	virtual void OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam) {}
};

