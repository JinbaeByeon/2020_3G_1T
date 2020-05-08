#pragma once

#include "Mesh.h"

class CViewport
{
public:
	CViewport(int nLeft, int nTop, int nWidth, int nHeight) { m_nLeft = nLeft; m_nTop = nTop; m_nWidth = nWidth; m_nHeight = nHeight; }
	virtual ~CViewport() { }

	int							m_nLeft;
	int							m_nTop;
	int							m_nWidth;
	int							m_nHeight;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
class CCamera
{
public:
	CCamera();
	virtual ~CCamera();

private:

	XMFLOAT4X4					m_ViewMatrix = {
		1.0f,0.0f,0.0f,0.0f,
		0.0f,1.0f,0.0f,0.0f,
		0.0f,0.0f,1.0f,0.0f,
		0.0f,0.0f,0.0f,0.0f
	};
	XMFLOAT4X4					m_ProjectMatrix{};
	XMFLOAT4X4					m_ScreenMatrix{};

	float						m_fFOVAngle = 90.0f;
	float						m_fProjectRectDistance = 1.0f;

	CViewport*					m_pViewport = NULL;
	float						m_fAspectRatio = float(FRAMEBUFFER_WIDTH) / float(FRAMEBUFFER_HEIGHT);

public:
	XMMATRIX XM_CALLCONV GenerateViewTransform();
	XMMATRIX ProjectionTransform();
	XMMATRIX ScreenTransform();

	void SetPosition(float x, float y, float z) { m_ViewMatrix._41 = x; m_ViewMatrix._42 = y; m_ViewMatrix._43 = z;}

	void XM_CALLCONV SetViewport(int xStart, int yStart, int nWidth, int nHeight);
	void XM_CALLCONV SetFOVAngle(float fFOVAngle);

	void Move(float x, float y, float z);
	void MoveForward(float fdistance);
	void MoveStrafe(float fdistance);
	void MoveUpDown(float fdistance);
	void XM_CALLCONV Rotate(float fPitch, float fYaw, float fRoll);
};
