#include "stdafx.h"
#include "GameObject.h"
#include "GraphicsPipeline.h"
#include <random>

//////////////////////////
/*		CGameObject		*/
//////////////////////////
CGameObject::~CGameObject()
{
	if (m_pMesh) m_pMesh->Release();
}

void CGameObject::SetPosition(float x, float y, float z)
{
	m_xmf4x4World._41 = x;
	m_xmf4x4World._42 = y;
	m_xmf4x4World._43 = z;
}

void CGameObject::SetPosition(const XMFLOAT3& xmf3Position)
{
	m_xmf4x4World._41 = xmf3Position.x;
	m_xmf4x4World._42 = xmf3Position.y;
	m_xmf4x4World._43 = xmf3Position.z;
}

void CGameObject::SetMovingDirection(const XMFLOAT3& xmf3MovingDirection)
{
	XMStoreFloat3(&m_xmf3MovingDirection,
		XMVector3Normalize(XMLoadFloat3(&xmf3MovingDirection)));
}

void CGameObject::SetRotationAxis(const XMFLOAT3& xmf3RotationAxis)
{
	XMStoreFloat3(&m_xmf3RotationAxis,
		XMVector3Normalize(XMLoadFloat3(&xmf3RotationAxis)));
}

void CGameObject::Rotate(float fPitch, float fYaw, float fRoll)
{
	XMMATRIX m_RotationMatrix = XMMatrixRotationRollPitchYaw(fPitch, fYaw, fRoll); 
	XMStoreFloat4x4(&m_xmf4x4World, XMMatrixMultiply(m_RotationMatrix,XMLoadFloat4x4(&m_xmf4x4World)));
}

void CGameObject::Rotate(const XMFLOAT3& xmf3RotationAxis, float fAngle)
{
	XMMATRIX xmmtxRotate =
		XMMatrixRotationAxis(XMLoadFloat3(&xmf3RotationAxis),
			XMConvertToRadians(fAngle));
	XMStoreFloat4x4(&m_xmf4x4World, XMMatrixMultiply(xmmtxRotate,
		XMLoadFloat4x4(&m_xmf4x4World)));
}

void CGameObject::Move(const XMFLOAT3& vDirection, float fSpeed)
{
	SetPosition(m_xmf4x4World._41 + vDirection.x * fSpeed,
		m_xmf4x4World._42 + vDirection.y * fSpeed, m_xmf4x4World._43 +
		vDirection.z * fSpeed);
}

void CGameObject::Move(float x, float y, float z)
{
	m_xmf4x4World._41 += x;
	m_xmf4x4World._42 += y;
	m_xmf4x4World._43 += z;
}

void CGameObject::Animate(float fElapsedTime)
{
	if (m_bCollision) {
		for (int i = 0; i < 100; ++i)
			m_ppFragments[i]->Animate(fElapsedTime);
	}
	else {
		if (m_fRotationSpeed != 0.0f) Rotate(m_xmf3RotationAxis,
			m_fRotationSpeed * fElapsedTime);
		if (m_fMovingSpeed != 0.0f) Move(m_xmf3MovingDirection,
			m_fMovingSpeed * fElapsedTime);
	}
}

void CGameObject::Render(HDC hDCFrameBuffer, CCamera* pCamera)
{
	if (m_bCollision) {
		for (int i = 0; i < 100; ++i)
			m_ppFragments[i]->Render(hDCFrameBuffer,pCamera);
	}
	else {
		if (m_pMesh)
		{
			CGraphicsPipeline::SetWorldTransform(&m_xmf4x4World);
			HPEN hPen = ::CreatePen(PS_SOLID, 0, m_dwColor);
			HPEN hOldPen = (HPEN)::SelectObject(hDCFrameBuffer, hPen);
			m_pMesh->Render(hDCFrameBuffer);
			::SelectObject(hDCFrameBuffer, hOldPen);
			::DeleteObject(hPen);
		}
	}
}

bool CGameObject::IsVisible(CCamera* pCamera)
{
	bool bIsVisible = pCamera->IsInFrustum(XMBBWorld());
	
	return bIsVisible;
}

BoundingBox& CGameObject::XMBBWorld()
{
	BoundingBox xmbbModel = m_pMesh->m_xmBoundingBox;
	xmbbModel.Transform(xmbbModel, XMLoadFloat4x4(&m_xmf4x4World));
	return xmbbModel;
}

BoundingBox CGameObject::XMBBWorld() const
{
	BoundingBox xmbbModel = m_pMesh->m_xmBoundingBox;
	xmbbModel.Transform(xmbbModel, XMLoadFloat4x4(&m_xmf4x4World));
	return xmbbModel;
}

bool CGameObject::IsInMap(BoundingBox& xmbbMap)
{
	BoundingBox xmbbWorld = m_pMesh->m_xmBoundingBox;
	xmbbWorld.Transform(xmbbWorld, XMLoadFloat4x4(&m_xmf4x4World));

	return (xmbbMap.Contains(xmbbWorld) == DirectX::CONTAINS);
}

void CGameObject::Reset()
{
	if (!m_pMesh)
		SetMesh(new CCubeMesh());
	m_bActive = true;
	m_bCollision = false;
	if (m_ppFragments)
		delete[] m_ppFragments;
	m_ppFragments = NULL;
	m_time = 0;

	std::random_device rd;
	std::default_random_engine dre{rd()};
	std::uniform_real_distribution<float> urdFnormal(-1, 1);
	std::uniform_int_distribution<int> urd255(0, 255);
	std::uniform_int_distribution<int> urdPosX(-30, 30);
	std::uniform_int_distribution<int> urdPosY(-30, 30);
	std::uniform_int_distribution<int> urdPosZ(-200, 200);

	m_xmf4x4World = Matrix4x4::Identity();
	SetPosition(urdPosX(dre), urdPosY(dre), urdPosZ(dre));
	m_dwColor = RGB(urd255(dre) * (urd255(dre) % 2), urd255(dre) * (urd255(dre) % 2), urd255(dre) * (urd255(dre) % 2));

	m_xmf3MovingDirection = XMFLOAT3(urdFnormal(dre), urdFnormal(dre), urdFnormal(dre));
	m_fMovingSpeed = 5 + urd255(dre) % 20;

	m_xmf3RotationAxis = XMFLOAT3(urdFnormal(dre), urdFnormal(dre), urdFnormal(dre));
	m_fRotationSpeed = 10 + urd255(dre) % 100;
}

void CGameObject::Explode(float fTimeElapsed)
{
	if (m_ppFragments == NULL) {
		std::default_random_engine dre{};
		std::uniform_real_distribution<float> urdFloat(-1, 1);
		XMFLOAT3 xmf3Rand;
		m_ppFragments = new CGameObject * [100];
		for (int j = 0; j < 100; ++j) {
			xmf3Rand = { urdFloat(dre), urdFloat(dre), urdFloat(dre) };
			m_ppFragments[j] = new CGameObject();
			m_ppFragments[j]->SetMesh(new CCubeMesh(0.5f, 0.5f, 0.5f));
			m_ppFragments[j]->m_xmf4x4World = m_xmf4x4World;
			m_ppFragments[j]->SetColor(m_dwColor);
			m_ppFragments[j]->SetMovingSpeed(10.f);
			m_ppFragments[j]->SetMovingDirection(xmf3Rand);
			m_ppFragments[j]->SetRotationAxis(xmf3Rand);
			m_ppFragments[j]->SetRotationSpeed(50.f);
		}
	}
	m_time += fTimeElapsed;
	if (m_time >= 1) {
		Reset();
	}
}

//////////////////////////
/*		CGameObject		*/
//////////////////////////



//////////////////////
/*		CMap		*/
//////////////////////
CMap::CMap()
{
	SetMesh(new CMapMesh());
	SetColor(RGB(0, 0, 0));
}
//////////////////////
/*		CMap		*/
//////////////////////


///////////////////
/*		CGun	 */
///////////////////
CGun::CGun()
{
	m_ppBullets = new CBullet * [1000];
	m_fMovingSpeed = 100.f;
}

void CGun::Shot()
{
	m_ppBullets[m_nBullets] = new CBullet();
	m_ppBullets[m_nBullets]->SetMesh(new CCubeMesh(1.f,1.f,1.f));
	m_ppBullets[m_nBullets]->SetPosition(m_xmf4x4World._41, m_xmf4x4World._42, m_xmf4x4World._43);
	m_ppBullets[m_nBullets]->SetMovingDirection(m_xmf3MovingDirection);
	m_ppBullets[m_nBullets]->SetMovingRange(500.f);
	m_ppBullets[m_nBullets]->SetMovingSpeed(m_fMovingSpeed);
	m_ppBullets[m_nBullets]->SetRotationSpeed(100.f);
	m_ppBullets[m_nBullets]->SetRotationAxis(m_xmf3RotationAxis);
	if (m_bTarget) {
		m_ppBullets[m_nBullets]->SetTarget(m_pTarget);
		m_bTarget = false;
		m_pTarget = NULL;
	}
	++m_nBullets;
}

void CGun::Render(HDC hDCFrameBuffer, CCamera* pCamera)
{
	if (m_nBullets)
		for (int i = 0; i < m_nBullets; ++i)
			m_ppBullets[i]->Render(hDCFrameBuffer, pCamera);
}

void CGun::Animate(float fElapsedTime)
{
	for (int i = 0; i < m_nBullets; ++i) {
		m_ppBullets[i]->Animate(fElapsedTime);
		if (m_ppBullets[i]->m_time >= 5) {
			DeleteBullet(i);
		}
	}

}

bool CGun::bCollisionBullets(BoundingBox& xmbbWorld)
{
	for (int i = 0; i < m_nBullets; ++i) {
		if (m_ppBullets[i]->XMBBWorld().Contains(xmbbWorld) != DirectX::DISJOINT) {
			DeleteBullet(i);
			return true;
		}
	}
	return false;

}

void CGun::CheckBulletsInMap(BoundingBox& xmbbMap)
{
	for (int i = 0; i < m_nBullets; ++i) {
		if (xmbbMap.Contains(m_ppBullets[i]->XMBBWorld()) != DirectX::CONTAINS) {
			DeleteBullet(i);
		}
	}
	
}

void CGun::DeleteBullet(const int& idx)
{
	for (int i = idx; i < m_nBullets - 1; ++i) {
		m_ppBullets[i] = NULL;
		m_ppBullets[i] = m_ppBullets[i + 1];
	}
	--m_nBullets;
}

void CGun::SetTarget(CGameObject* pObject)
{
	m_pTarget = pObject;
	m_bTarget = true;
}
void CGun::DeleteTarget(CGameObject* pObject)
{
	if (m_pTarget == pObject) {
		m_pTarget = NULL;
		m_bTarget = false;
	}
	for (int i = 0; i < m_nBullets; ++i)
		if (m_ppBullets[i]->m_bTarget && m_ppBullets[i]->m_pTarget == pObject)
			m_ppBullets[i]->SetTarget(NULL);
}

void CGun::Update(float fTimeElapsed)
{
	for (int i = 0; i < m_nBullets; ++i)
		if (m_ppBullets[i]->m_bTarget && m_ppBullets[i]->m_time >= 0.2)
			m_ppBullets[i]->Update(fTimeElapsed);
}

void CGun::Move(float x, float y, float z)
{
	for (int i = 0; i < m_nBullets; ++i)
		m_ppBullets[i]->Move(x, y, z);
}

///////////////////
/*		CGun	 */
///////////////////


///////////////////////
/*		CBullet		 */
///////////////////////
void CBullet::Animate(float fElapsedTime)
{
	CGameObject::Animate(fElapsedTime);
	m_time += fElapsedTime;
}

void CBullet::SetTarget(CGameObject* pObject)
{
	if (pObject == NULL) {
		m_pTarget = NULL;
		m_bTarget = false;
	}
	else {
		m_pTarget = pObject;
		m_bTarget = true;
		SetColor(RGB(0, 0, 255));
	}
}

void CBullet::Update(float fTimeElapsed)
{
	XMVECTOR xmvPosition = XMLoadFloat3(&XMFLOAT3(m_xmf4x4World._41, m_xmf4x4World._42, m_xmf4x4World._43));
	XMVECTOR xmvTargetDir = XMLoadFloat3(&XMFLOAT3(m_pTarget->m_xmf4x4World._41, m_pTarget->m_xmf4x4World._42, m_pTarget->m_xmf4x4World._43));
	
	xmvTargetDir = XMVector3Normalize(XMVectorSubtract(xmvTargetDir, xmvPosition));
	XMVECTOR xmvDir = XMVector3Normalize(XMLoadFloat3(&m_xmf3MovingDirection));

	XMVECTOR xmvUp = XMVector3Normalize(XMVector3Cross(xmvDir, xmvTargetDir));
	float fAngle = XMVectorGetX(XMVector3AngleBetweenNormals(xmvDir, xmvTargetDir));
	fAngle *= fTimeElapsed * m_fMovingSpeed / 10;
	XMStoreFloat3(&m_xmf3MovingDirection, XMVector3Transform(xmvDir, XMMatrixRotationAxis(xmvUp, fAngle)));
}

///////////////////////
/*		CBullet		 */
///////////////////////