#pragma once

#include "Mesh.h"

class CGameObject
{
public:
	CGameObject() { }
	~CGameObject();

private:
	XMFLOAT4X4				m_WorldMatrix = {
		1.0f,0.0f,0.0f,0.0f,
		0.0f,1.0f,0.0f,0.0f,
		0.0f,0.0f,1.0f,0.0f,
		0.0f,0.0f,0.0f,1.0f
	};


    CMesh					*m_pMesh = NULL;        
	DWORD					m_dwColor = RGB(255, 0, 0);

	float					m_fxRotationSpeed = 0.0f;
	float					m_fyRotationSpeed = 0.0f;
	float					m_fzRotationSpeed = 0.0f;

public:
	void SetMesh(CMesh *pMesh) { m_pMesh = pMesh; if (pMesh) pMesh->AddRef(); }

	void SetColor(DWORD dwColor) { m_dwColor = dwColor; }

	void SetPosition(float x, float y, float z) { m_WorldMatrix._41 = x; m_WorldMatrix._42 = y; m_WorldMatrix._43 = z; }
	void SetRotationSpeed(float x, float y, float z) { m_fxRotationSpeed = x; m_fyRotationSpeed = y; m_fzRotationSpeed = z; }

	void Move(float x, float y, float z) { m_WorldMatrix._41 += x; m_WorldMatrix._42 += y; m_WorldMatrix._43 += z; }
	void XM_CALLCONV Rotate(float x, float y, float z);

public:
	XMMATRIX WorldTransform();
	
	virtual void Animate(float fElapsedTime);
	virtual void Render(HDC hDCFrameBuffer);
};

