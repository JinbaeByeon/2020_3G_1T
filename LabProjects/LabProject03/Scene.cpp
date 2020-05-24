#include "stdafx.h"
#include "Scene.h"
#include "GraphicsPipeline.h"

CScene::~CScene()
{
}


void CScene::BuildObjects()
{
	CCubeMesh* pCubeMesh = new CCubeMesh(4.0f, 4.0f, 4.0f);

	m_nObjects = 5;
	m_ppObjects = new CGameObject * [m_nObjects];

	m_ppObjects[0] = new CGameObject();
	m_ppObjects[0]->SetMesh(pCubeMesh);
	m_ppObjects[0]->SetColor(RGB(255, 0, 0));
	m_ppObjects[0]->SetPosition(-13.5f, 0.0f, +14.0f);
	m_ppObjects[0]->SetRotationAxis(XMFLOAT3(1.0f, 1.0f, 0.0f));
	m_ppObjects[0]->SetRotationSpeed(90.0f);
	m_ppObjects[0]->SetMovingDirection(XMFLOAT3(1.0f, 0.0f, 0.0f));
	m_ppObjects[0]->SetMovingSpeed(0.5f);

	m_ppObjects[1] = new CGameObject();
	m_ppObjects[1]->SetMesh(pCubeMesh);
	m_ppObjects[1]->SetColor(RGB(0, 0, 255));
	m_ppObjects[1]->SetPosition(+13.5f, 0.0f, +14.0f);
	m_ppObjects[1]->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 1.0f));
	m_ppObjects[1]->SetRotationSpeed(180.0f);
	m_ppObjects[1]->SetMovingDirection(XMFLOAT3(-1.0f, 0.0f, 0.0f));
	m_ppObjects[1]->SetMovingSpeed(1.5f);

	m_ppObjects[2] = new CGameObject();
	m_ppObjects[2]->SetMesh(pCubeMesh);

	m_ppObjects[2]->SetColor(RGB(0, 255, 0));
	m_ppObjects[2]->SetPosition(0.0f, +5.0f, 20.0f);
	m_ppObjects[2]->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, 1.0f));
	m_ppObjects[2]->SetRotationSpeed(30.15f);
	m_ppObjects[2]->SetMovingDirection(XMFLOAT3(1.0f, -1.0f, 0.0f));
	m_ppObjects[2]->SetMovingSpeed(0.0f);
	m_ppObjects[3] = new CGameObject();
	m_ppObjects[3]->SetMesh(pCubeMesh);
	m_ppObjects[3]->SetColor(RGB(0, 255, 255));
	m_ppObjects[3]->SetPosition(0.0f, 0.0f, 40.0f);
	m_ppObjects[3]->SetRotationAxis(XMFLOAT3(0.0f, 0.0f, 1.0f));
	m_ppObjects[3]->SetRotationSpeed(40.6f);
	m_ppObjects[3]->SetMovingDirection(XMFLOAT3(0.0f, 0.0f, 1.0f));
	m_ppObjects[3]->SetMovingSpeed(0.0f);
	m_ppObjects[4] = new CGameObject();
	m_ppObjects[4]->SetMesh(pCubeMesh);
	m_ppObjects[4]->SetColor(RGB(128, 0, 255));
	m_ppObjects[4]->SetPosition(10.0f, 10.0f, 50.0f);
	m_ppObjects[4]->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 1.0f));
	m_ppObjects[4]->SetRotationSpeed(50.06f);
	m_ppObjects[4]->SetMovingDirection(XMFLOAT3(0.0f, 1.0f, 1.0f));
	m_ppObjects[4]->SetMovingSpeed(0.0f);

	m_pMap = new CMap();
}

void CScene::ReleaseObjects()
{
	for (int i = 0; i < m_nObjects; i++) if (m_ppObjects[i]) delete m_ppObjects[i];
	if (m_ppObjects) delete[] m_ppObjects;

	if (m_pMap) delete m_pMap;
}

void CScene::Animate(float fElapsedTime)
{
	for (int i = 0; i < m_nObjects; i++) m_ppObjects[i]->Animate(fElapsedTime);
	CheckCollision();
	if (m_pPlayer->m_xmf3Position.z <= -20.f || m_pPlayer->m_xmf3Position.z >= 20.f) {
		for (int i = 0; i < m_nObjects; ++i)
			m_ppObjects[i]->Move(0, 0, -m_pPlayer->m_xmf3Position.z);
		m_pPlayer->m_pCamera->Move(XMFLOAT3(0, 0, -m_pPlayer->m_xmf3Position.z));
		m_pPlayer->m_xmf3Position.z = 0;
	}
}

void CScene::Render(HDC hDCFrameBuffer, CCamera* pCamera)
{
	CGraphicsPipeline::SetViewport(&pCamera->m_Viewport);
	CGraphicsPipeline::SetViewProjectTransform(&pCamera->m_xmf4x4ViewProject);

	for (int i = 0; i < m_nObjects; i++)
	{
		if(m_ppObjects[i]->IsVisible(pCamera))
			m_ppObjects[i]->Render(hDCFrameBuffer, pCamera);
	}
	m_pMap->Render(hDCFrameBuffer, pCamera);
}

void CScene::CheckCollision()
{
	//맵 충돌검사
	if (!m_pPlayer->IsInMap(m_pMap->m_pMesh->m_xmBoundingBox)) {
		m_pPlayer->m_pCamera->Move(-m_pPlayer->m_xmf3Position.x, -m_pPlayer->m_xmf3Position.y, -m_pPlayer->m_xmf3Position.z);
		m_pPlayer->SetPosition(0, 0, 0);
	}

	// 객체 충돌검사
	for (int i = 0; i < m_nObjects; ++i)
		if (m_pPlayer->m_pGun->bCollisionBullets(m_ppObjects[i]->XMBBWorld()))
			;
		
}

bool CScene::isClickObject(int xMouse, int yMouse)
{
	int fLeft = m_pPlayer->m_pCamera->m_Viewport.m_nLeft;
	int fTop = m_pPlayer->m_pCamera->m_Viewport.m_nTop;
	int fHeight = m_pPlayer->m_pCamera->m_Viewport.m_nHeight;
	int fWidth = m_pPlayer->m_pCamera->m_Viewport.m_nWidth;
	
	float x = ((2.0f * (xMouse - fLeft)) / fWidth) - 1;
	float y = (-(2.0f * (yMouse - fTop)) / fHeight) + 1;
	XMVECTOR xmv3LayView = { x / m_pPlayer->m_pCamera->m_xmf4x4Project._11,y / m_pPlayer->m_pCamera->m_xmf4x4Project._22 ,1 };
	XMMATRIX xmmtxInversView = XMMatrixInverse(NULL, XMLoadFloat4x4(&m_pPlayer->m_pCamera->m_xmf4x4View));	
	XMVECTOR xmv3LayWorld = XMVector3TransformCoord(xmv3LayView, xmmtxInversView);

	XMVECTOR xmv3origin{ XMLoadFloat3(&m_pPlayer->m_pCamera->GetPosition()) };
	xmv3LayWorld = XMVectorSubtract(xmv3LayWorld, xmv3origin);

	float fDist, fDistNear = -1;
	int idx = -1;
	BoundingBox xmbbWorld;
	for (int i = 0; i < m_nObjects; ++i) {
		xmbbWorld = m_ppObjects[i]->XMBBWorld();
		//xmv3LayWorld = XMLoadFloat3(&XMFLOAT3(m_ppObjects[i]->m_xmf4x4World._41, m_ppObjects[i]->m_xmf4x4World._42, m_ppObjects[i]->m_xmf4x4World._43));
		//xmv3LayWorld = XMVector3Normalize(XMVectorSubtract(xmv3LayWorld, xmv3origin));
		
		if (xmbbWorld.Intersects(xmv3origin, xmv3LayWorld, fDist)) {
			if (fDistNear == -1 || fDist < fDistNear) {
				fDistNear = fDist;
				idx = i;
			}
		}
	}
	if (idx != -1)
		return true;
	return false;
}