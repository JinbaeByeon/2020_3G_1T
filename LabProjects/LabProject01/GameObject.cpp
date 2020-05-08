#include "stdafx.h"
#include "GameObject.h"

CGameObject::~CGameObject(void)
{
	if (m_pMesh) m_pMesh->Release();
}

XMMATRIX CGameObject::WorldTransform()
{
	return XMLoadFloat4x4(&m_WorldMatrix);
}

void CGameObject::Animate(float fElapsedTime)
{
	Rotate(m_fxRotationSpeed * fElapsedTime, m_fyRotationSpeed * fElapsedTime, m_fzRotationSpeed * fElapsedTime);
}

void XM_CALLCONV CGameObject::Rotate(float fPitch, float fYaw, float fRoll)
{
	XMMATRIX m_RotationMatrix = XMMatrixRotationRollPitchYaw(fPitch, fYaw, fRoll); 
	XMStoreFloat4x4(&m_WorldMatrix, XMMatrixMultiply(m_RotationMatrix,XMLoadFloat4x4(&m_WorldMatrix)));
}

void CGameObject::Render(HDC hDCFrameBuffer)
{
	HPEN hPen = ::CreatePen(PS_SOLID, 0, m_dwColor);
	HPEN hOldPen = (HPEN)::SelectObject(hDCFrameBuffer, hPen);

	if (m_pMesh) m_pMesh->Render(hDCFrameBuffer);

	::SelectObject(hDCFrameBuffer, hOldPen);
	::DeleteObject(hPen);
}