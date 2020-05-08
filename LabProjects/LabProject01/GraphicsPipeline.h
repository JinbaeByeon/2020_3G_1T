#pragma once

#include "GameObject.h"
#include "Camera.h"

class CGraphicsPipeline
{
private:
	static CGameObject*		m_pGameObject;
	static CCamera*			m_pCamera;

public:
	static void SetGameObject(CGameObject* pGameObject) { m_pGameObject = pGameObject; }
	static void SetCamera(CCamera* pCamera) { m_pCamera = pCamera; }

	static XMVECTOR ScreenTransform(FXMVECTOR& v3Projection);
	static XMVECTOR Project(XMFLOAT3& f3Model);
	static XMVECTOR Transform(XMFLOAT3& f3Model);
};
