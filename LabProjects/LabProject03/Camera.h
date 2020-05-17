#pragma once

#include "Mesh.h"

class CViewport
{
public:
	CViewport() {}
	virtual ~CViewport() { }

	int							m_nLeft;
	int							m_nTop;
	int							m_nWidth;
	int							m_nHeight;

	void SetViewport(int nLeft, int nTop, int nWidth, int nHeight);
};

/////////////////////////////////////////////////////////////////////////////////////////////////////
//

class CPlayer;

class CCamera
{
public:
	CCamera();
	virtual ~CCamera();

private:
	XMFLOAT3			m_xmf3Position = XMFLOAT3(0.f, 0.f, 0.f);
	XMFLOAT3			m_xmf3Right = XMFLOAT3(1.0f, 0.0f, 0.0f);
	XMFLOAT3			m_xmf3Up = XMFLOAT3(0.0f, 1.0f, 0.0f);
	XMFLOAT3			m_xmf3Look = XMFLOAT3(0.0f, 0.0f, 1.0f);

	float				m_fFOVAngle = 90.0f;
	float				m_fProjectRectDistance = 1.0f;

	float				m_fAspectRatio = float(FRAMEBUFFER_WIDTH) / float(FRAMEBUFFER_HEIGHT);
public:

	//카메라 변환 행렬
	XMFLOAT4X4			m_xmf4x4View = Matrix4x4::Identity();
	//원근 투영 변환 행렬
	XMFLOAT4X4			m_xmf4x4Project = Matrix4x4::Identity();
	//카메라 변환 행렬 * 원근 투영 변환 행렬
	XMFLOAT4X4			m_xmf4x4ViewProject = Matrix4x4::Identity();

	CViewport			m_Viewport;

public:
	//카메라 변환 행렬을 생성한다
	void GenerateViewMatrix();
	//투영 변환 행렬을 생성한다
	void GeneratePerspectiveProjectionMatrix(float fNearPlaneDistance, float fFarPlaneDistance, float fFOVAngle);
	
	void SetPosition(float x, float y, float z) { m_xmf4x4View._41 = x; m_xmf4x4View._42 = y; m_xmf4x4View._43 = z;}

	void SetViewport(int xStart, int yStart, int nWidth, int nHeight);
	void SetFOVAngle(float fFOVAngle);

	//3인칭 카메라에서 카메라가 바라보는 지점을 설정한다. 일반적으로 플레이어를 바라보도록 설정한다. 
	void SetLookAt(XMFLOAT3& xmf3LookAt, XMFLOAT3& xmf3Up);
	void SetLookAt(XMFLOAT3& xmf3Position, XMFLOAT3& xmf3LookAt, XMFLOAT3& xmf3Up);
	
	//카메라를 xmf3Shift 만큼 이동한다. 
	void Move(const XMFLOAT3& xmf3Shift);
	void Move(float x, float y, float z);
	
	//카메라를 x-축, y-축, z-축으로 회전한다.
	void Rotate(float fPitch = 0.0f, float fYaw = 0.0f, float fRoll = 0.0f);
	
	//카메라의 이동, 회전에 따라 카메라의 정보를 갱신하는 가상함수이다.
	void Update(CPlayer* pPlayer, XMFLOAT3& xmf3LookAt, float fTimeElapsed = 0.016f);
};
