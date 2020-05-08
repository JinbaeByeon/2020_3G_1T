#include "stdafx.h"
#include "Camera.h"
#include "Mesh.h"
#include <iostream>
/////////////////////////////////////////////////////////////////////////////////////////////////////
//
CCamera::CCamera()
{
}

CCamera::~CCamera()
{
}

void XM_CALLCONV CCamera::SetViewport(int nLeft, int nTop, int nWidth, int nHeight)
{
	m_pViewport = new CViewport(nLeft, nTop, nWidth, nHeight);
	m_fAspectRatio = float(m_pViewport->m_nWidth) / float(m_pViewport->m_nHeight);

	float fHalfWidth = m_pViewport->m_nWidth * 0.5f;
	float fHalfHeight = m_pViewport->m_nHeight * 0.5f;
	XMMATRIX m_ScreenSpaceMatrix = {
		fHalfWidth,							0.0f,								0.0f, 0.0f,
		0.0f,								-fHalfHeight,						0.0f, 0.0f,
		0.0f,								0.0f,								0.0f,0.0f,
		m_pViewport->m_nLeft + fHalfWidth,	m_pViewport->m_nTop + fHalfHeight,	0.0f,1.0f };
	XMStoreFloat4x4(&m_ScreenMatrix, m_ScreenSpaceMatrix);
}

void XM_CALLCONV CCamera::SetFOVAngle(float fFOVAngle)
{
	m_fFOVAngle = fFOVAngle;
	m_fProjectRectDistance = float(1.0f / tan(DegreeToRadian(fFOVAngle * 0.5f)));
	
	XMStoreFloat4x4(&m_ProjectMatrix, XMMatrixPerspectiveFovLH(DegreeToRadian(m_fFOVAngle), m_fAspectRatio, 2.0f, 20.0f));
}

void CCamera::Move(float x, float y, float z)
{
	
	// 카메라의 Look,Up,Right 벡터에 따라서 이동
	if (x)
		MoveStrafe(x);
	if (y)
		MoveUpDown(y);
	if (z)
		MoveForward(z);
}

void CCamera::MoveForward(float fdistance)
{
	m_ViewMatrix._41 += m_ViewMatrix._31 * fdistance;
	m_ViewMatrix._42 += m_ViewMatrix._32 * fdistance;
	m_ViewMatrix._43 += m_ViewMatrix._33 * fdistance;
}
void CCamera::MoveStrafe(float fdistance)
{
	m_ViewMatrix._41 += m_ViewMatrix._11 * fdistance;
	m_ViewMatrix._42 += m_ViewMatrix._12 * fdistance;
	m_ViewMatrix._43 += m_ViewMatrix._13 * fdistance;
}
void CCamera::MoveUpDown(float fdistance)
{
	m_ViewMatrix._41 += m_ViewMatrix._21 * fdistance;
	m_ViewMatrix._42 += m_ViewMatrix._22 * fdistance;
	m_ViewMatrix._43 += m_ViewMatrix._23 * fdistance;
}


void XM_CALLCONV CCamera::Rotate(float fPitch, float fYaw, float fRoll)
{
	XMMATRIX m_RotationMatrix = XMMatrixRotationRollPitchYaw(XMConvertToRadians(fPitch), XMConvertToRadians(fYaw), XMConvertToRadians(fRoll));
	XMStoreFloat4x4(&m_ViewMatrix, XMMatrixMultiply(m_RotationMatrix, XMLoadFloat4x4(&m_ViewMatrix)));
}

XMMATRIX XM_CALLCONV CCamera::GenerateViewTransform()
{
	FXMVECTOR vEye = XMVectorSet(m_ViewMatrix._41, m_ViewMatrix._42, m_ViewMatrix._43, 1.0f);
	FXMVECTOR vLook = XMVectorSet(m_ViewMatrix._31, m_ViewMatrix._32, m_ViewMatrix._33, 1.0f);
	FXMVECTOR vUp = XMVectorSet(m_ViewMatrix._21, m_ViewMatrix._22, m_ViewMatrix._23, 1.0f);

	return XMMatrixLookToLH(vEye, vLook, vUp);
}

XMMATRIX CCamera::ProjectionTransform()
{
	return XMLoadFloat4x4(&m_ProjectMatrix);
}

XMMATRIX CCamera::ScreenTransform()
{
	return XMLoadFloat4x4(&m_ScreenMatrix);
}
