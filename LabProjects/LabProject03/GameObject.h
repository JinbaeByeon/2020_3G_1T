#pragma once

#include "Mesh.h"
#include "Camera.h"

class CGameObject
{
public:
	CGameObject() { }
	virtual ~CGameObject();

public:
	bool			m_bActive = true;

	XMFLOAT4X4		m_xmf4x4World = Matrix4x4::Identity();

    CMesh			*m_pMesh = NULL;        

	DWORD			m_dwColor = RGB(255, 0, 0);

	XMFLOAT3		m_xmf3MovingDirection = XMFLOAT3(0.f, 0.f, 1.f);
	float			m_fMovingSpeed = 0.f;
	float			m_fMovingRange = 0.f;

	XMFLOAT3		m_xmf3RotationAxis = XMFLOAT3(0.f, 1.f, 0.f);
	float			m_fRotationSpeed = 0.0f;
	
	XMFLOAT3		m_xmf3SizeBox;


public:
	void SetMesh(CMesh *pMesh) { m_pMesh = pMesh; if (pMesh) pMesh->AddRef(); }

	void SetActive(bool bActive) { m_bActive = bActive; }
	void SetColor(DWORD dwColor) { m_dwColor = dwColor; }

	void SetPosition(float x, float y, float z);
	void SetPosition(const XMFLOAT3& xmf3Position);

	void SetMovingDirection(const XMFLOAT3& xmf3MovingDirection);
	void SetMovingSpeed(float fSpeed) { m_fMovingSpeed = fSpeed; }
	void SetMovingRange(float fRange) { m_fMovingRange = fRange; }
	
	void SetRotationAxis(const XMFLOAT3& xmf3RotationAxis);
	void SetRotationSpeed(float fSpeed) { m_fRotationSpeed = fSpeed; }
	
	void Move(float x, float y, float z);
	void Move(const XMFLOAT3& vDirection, float fSpeed);
	
	void Rotate(float fPitch, float fYaw, float fRoll);
	void Rotate(const XMFLOAT3& xmf3Axis, float fAngle);

	bool IsVisible(CCamera* pCamera);
	BoundingBox& XMBBWorld();
	BoundingBox XMBBWorld() const;
	virtual void OnUpdateTransform() { }
	virtual void Animate(float fElapsedTime);
	virtual void Render(HDC hDCFrameBuffer, CCamera* pCamera);
};

class CMap : public CGameObject {
public:
	CMap();
};

class CBullet : public CGameObject { 
private:
	CGameObject* m_pTarget = NULL;
public:
	bool m_bTarget = false;
	float m_time = 0;
public:
	CBullet() {};
	void Animate(float fElapsedTime);
	void SetTarget(CGameObject* pObject);
	void Update(float fTimeElapsed);
};

class CGun : public CGameObject {
private:
	CBullet** m_ppBullets = NULL;
	int m_nBullets = 0;
	CGameObject* m_pTarget = NULL;
	bool m_bTarget = false;
public:
	CGun();
	void Shot();
	void Render(HDC hDCFrameBuffer, CCamera* pCamera);
	void Animate(float fElapsedTime);
	bool bCollisionBullets(BoundingBox& xmbbWolrd);
	void CheckBulletsInMap(BoundingBox& xmbbMap);
	void DeleteBullet(const int& idx);
	void SetTarget(CGameObject* pObject);
	void Update(float fTimeElapsed);
};
