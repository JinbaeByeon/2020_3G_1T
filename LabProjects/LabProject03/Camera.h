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

	//ī�޶� ��ȯ ���
	XMFLOAT4X4			m_xmf4x4View = Matrix4x4::Identity();
	//���� ���� ��ȯ ���
	XMFLOAT4X4			m_xmf4x4Project = Matrix4x4::Identity();
	//ī�޶� ��ȯ ��� * ���� ���� ��ȯ ���
	XMFLOAT4X4			m_xmf4x4ViewProject = Matrix4x4::Identity();

	CViewport			m_Viewport;

public:
	//ī�޶� ��ȯ ����� �����Ѵ�
	void GenerateViewMatrix();
	//���� ��ȯ ����� �����Ѵ�
	void GeneratePerspectiveProjectionMatrix(float fNearPlaneDistance, float fFarPlaneDistance, float fFOVAngle);
	
	void SetPosition(float x, float y, float z) { m_xmf4x4View._41 = x; m_xmf4x4View._42 = y; m_xmf4x4View._43 = z;}

	void SetViewport(int xStart, int yStart, int nWidth, int nHeight);
	void SetFOVAngle(float fFOVAngle);

	//3��Ī ī�޶󿡼� ī�޶� �ٶ󺸴� ������ �����Ѵ�. �Ϲ������� �÷��̾ �ٶ󺸵��� �����Ѵ�. 
	void SetLookAt(XMFLOAT3& xmf3LookAt, XMFLOAT3& xmf3Up);
	void SetLookAt(XMFLOAT3& xmf3Position, XMFLOAT3& xmf3LookAt, XMFLOAT3& xmf3Up);
	
	//ī�޶� xmf3Shift ��ŭ �̵��Ѵ�. 
	void Move(const XMFLOAT3& xmf3Shift);
	void Move(float x, float y, float z);
	
	//ī�޶� x-��, y-��, z-������ ȸ���Ѵ�.
	void Rotate(float fPitch = 0.0f, float fYaw = 0.0f, float fRoll = 0.0f);
	
	//ī�޶��� �̵�, ȸ���� ���� ī�޶��� ������ �����ϴ� �����Լ��̴�.
	void Update(CPlayer* pPlayer, XMFLOAT3& xmf3LookAt, float fTimeElapsed = 0.016f);
};
